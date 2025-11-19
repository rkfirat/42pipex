/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:33:46 by rfirat            #+#    #+#             */
/*   Updated: 2025/11/19 10:23:05 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	pipex_error(char *str)
{
	if (str)
		perror(str);
	else
		perror("pipex");
	exit(1);
}

void	setup_heredoc(t_pipex *pipex)
{
	int		fd[2];
	char	*line;

	if (pipe(fd) == -1)
		pipex_error("pipe");
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
	*pipex = (t_pipex){pipex->argc, pipex->argv, pipex->envp, fd[0], -1, 1, 3};
}

void	setup_fd(t_pipex *pipex)
{
	pipex->infile = open(pipex->argv[1], O_RDONLY);
	if (pipex->infile == -1)
	{
		write(2, "The infile could not open\n", 26);
		exit(1);
	}
	pipex->outfile = open(pipex->argv[pipex->argc - 1],
			O_CREAT | O_APPEND | O_WRONLY);
	if (pipex->outfile == -1)
	{
		write(2, "The outfile could not open\n", 27);
		close(pipex->infile);
		exit(1);
	}
}

int	main(int argc, char *argv[], char **envp)
{
	t_pipex	pipex;

	if (argc < 5 || !envp)
		return (1);
	pipex = (t_pipex){argc, argv, envp, -1, -1, 0, 2};
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])))
	{
		if (argc < 6)
			pipex_error("Invalid Usage");
		setup_heredoc(&pipex);
		pipex.outfile = open(argv[argc - 1], O_WRONLY | O_APPEND | O_CREAT);
		if (pipex.outfile == -1)
		{
			write(2, "The outfile could not open\n", 27);
			close(pipex.infile);
			return (1);
		}
	}
	else
		setup_fd(&pipex);
	//pipex_run(pipex);
	return (0);
}
