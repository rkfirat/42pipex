/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:33:46 by rfirat            #+#    #+#             */
/*   Updated: 2025/11/19 16:02:39 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	setup_fd(t_pipex *pipex)
{
	pipex->infile = open(pipex->argv[1], O_RDONLY, 0644);
	if (pipex->infile == -1)
	{
		write(2, "The infile could not open\n", 26);
		exit(1);
	}
	pipex->outfile = open(pipex->argv[pipex->argc - 1],
			O_CREAT | O_TRUNC | O_WRONLY, 0644);
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
	pipex = (t_pipex){argc, argv, envp, -1, -1, 0, 2, 0};
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])))
	{
		if (argc < 6)
			pipex_error("Invalid Usage", 2);
		setup_heredoc(&pipex);
		pipex.outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 644);
		if (pipex.outfile == -1)
		{
			write(2, "The outfile could not open\n", 27);
			close(pipex.infile);
			return (1);
		}
	}
	else
		setup_fd(&pipex);
	pipex_run(pipex);
	return (pipex.status % 255);
}
