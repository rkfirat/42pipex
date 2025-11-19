/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 00:42:02 by rfirat            #+#    #+#             */
/*   Updated: 2025/11/19 10:14:46 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path_loop(t_path path, char *cmd)
{
	path.i = 0;
	while (path.paths[path.i])
	{
		path.merged = cmd_merge(path.paths[path.i], cmd);
		if (!path.merged)
			break ;
		if (access(path.merged, X_OK) == 0)
		{
			free_array(path.paths);
			return (ft_strdup(path.merged));
		}
		free(path.merged);
		path.i++;
	}
	free_array(path.paths);
	return (NULL);
}

char	*find_cmd_path(char *cmd, char **envp)
{
	t_path	path;

	if (!cmd || !*cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	path.path_env = get_path(envp);
	if (!path.path_env)
		return (NULL);
	path.paths = ft_split((const char *)path.path_env, ':');
	if (!path.paths)
		return (NULL);
	path.merged = find_path_loop(path, cmd);
	if (path.merged)
		return (path.merged);
	return (NULL);
}

void	prep_child(char *cmd, t_pipex pipex, int infile_fd, int outfile_fd)
{
	char	**argv;
	char	*path;

	if (dup2(infile_fd, STDIN_FILENO) == -1)
		pipex_error("dup2");
	if (dup2(outfile_fd, STDOUT_FILENO) == -1)
		pipex_error("dup2");
	if (pipex.infile != -1)
		close(pipex.infile);
	if (pipex.outfile != -1)
		close(pipex.outfile);
	argv = ft_split(cmd, ' ');
	if (!argv || !argv[0])
	{
		free_array(argv);
		pipex_error("Invalid Command");
	}
	path = find_cmd_path(argv[0], pipex.envp);
	if (!path)
	{
		write(2, "Command Not Found\n", 18);
		free_array(argv);
		exit(127);
	}
	exec_child(argv, path, pipex.envp);
}

void	pipex_run(t_pipex pipex)
{
	t_exec	exec;

	if (pipe(exec.fd) == -1)
		pipex_error("pipe");
	exec.pid1 = fork();
	if (exec.pid1 == -1)
		pipex_error("fork");
	if (exec.pid1 == 0)
	{
		close(exec.fd[0]);
		prep_child(pipex.argv[2], pipex, pipex.infile, exec.fd[1]);
	}
	exec.pid2 = fork();
	if (exec.pid2 == 0)
	{
		close(exec.fd[1]);
		prep_child(pipex.argv[2], pipex, exec.fd[0], pipex.outfile);
	}
	close(exec.fd[0]);
	close(exec.fd[1]);
	waitpid(-1, NULL, 0);
}

int	main(int argc, char *argv[], char **envp)
{
	t_pipex	pipex;

	if (!envp || argc != 5)
		return (1);
	pipex = (t_pipex){.argc = argc, .argv = argv, .envp = envp, -1, -1};
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile == -1)
	{
		write(2, "The infile could not open\n", 26);
		return (1);
	}
	pipex.outfile = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT);
	if (pipex.outfile == -1)
	{
		write(2, "The outfile could not open\n", 27);
		close(pipex.infile);
		return (1);
	}
	pipex_run(pipex);
	if (pipex.infile != -1)
		close(pipex.infile);
	if (pipex.outfile != -1)
		close(pipex.outfile);
	return (0);
}
