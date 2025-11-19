/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_setup_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:34:21 by rfirat            #+#    #+#             */
/*   Updated: 2025/11/19 16:03:32 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
		pipex_error("dup2", 1);
	if (dup2(outfile_fd, STDOUT_FILENO) == -1)
		pipex_error("dup2", 1);
	if (pipex.infile != -1)
		close(pipex.infile);
	if (pipex.outfile != -1)
		close(pipex.outfile);
	argv = ft_split(cmd, ' ');
	if (!argv || !argv[0])
	{
		free_array(argv);
		pipex_error("Invalid Path\n", 2);
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

void	pipex_prep_child(t_pipex pipex, t_exec *exec)
{
	exec->pid = fork();
	if (exec->pid == -1)
		pipex_error("fork", 1);
	if (exec->pid == 0)
	{
		if (exec->i != pipex.argc - 2)
		{
			close(exec->fd[0]);
			prep_child(pipex.argv[exec->i], pipex, exec->infile, exec->fd[1]);
		}
		else
			prep_child(pipex.argv[exec->i], pipex, exec->infile, pipex.outfile);
	}
}

void	pipex_run(t_pipex pipex)
{
	t_exec	exec;

	exec.infile = pipex.infile;
	exec.i = pipex.first_cmd_index;
	while (exec.i <= pipex.argc - 2)
	{
		if (pipe(exec.fd) == -1)
			pipex_error("pipe", 1);
		pipex_prep_child(pipex, &exec);
		close(exec.fd[1]);
		if (exec.infile != pipex.infile && exec.infile != -1)
			close(exec.infile);
		exec.infile = exec.fd[0];
		exec.i++;
	}
	while (wait(&pipex.status) > 0)
		;
	if (exec.infile != pipex.infile && exec.infile != -1)
		close(exec.infile);
}

void	setup_heredoc(t_pipex *pipex)
{
	int fd[2];
	char *line;

	if (pipe(fd) == -1)
		pipex_error("pipe", 2);
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (!line)
			break ;
		if (ft_strlen(line) == 0)
			break ;
		if (!ft_strncmp(line, pipex->argv[2], ft_strlen(line) - 1))
		{
			free(line);
			break ;
		}
		write(fd[1], line, ft_strlen(line));
		write(fd[1], "\n", 1);
		free(line);
	}
	close(fd[1]);
	*pipex = (t_pipex){pipex->argc, pipex->argv, pipex->envp, fd[0], -1, 1, 3, 0};
}