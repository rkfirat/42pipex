/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 02:09:24 by rfirat            #+#    #+#             */
/*   Updated: 2025/11/19 13:21:01 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **envp)
{
	int	i;

	if (!envp)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*cmd_merge(char *path, char *cmd)
{
	char	*tmp;
	char	*merged;

	tmp = ft_strjoin(path, "/");
	if (!tmp)
		return (NULL);
	merged = ft_strjoin(tmp, cmd);
	free(tmp);
	return (merged);
}

void	pipex_error(char *str, int i)
{
	if (i == 1)
		perror(str);
	else
		write(2, str, ft_strlen(str));
	exit(1);
}

void	exec_child(char **argv, char *path, char **envp)
{
	execve(path, argv, envp);
	pipex_error(path, 1);
	free(path);
	free_array(argv);
	exit(EXIT_FAILURE);
}
