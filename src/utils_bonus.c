/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:05:47 by rfirat            #+#    #+#             */
/*   Updated: 2024/12/17 18:48:26 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*path;
	char	*path_part;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0 && envp[i])
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path_part = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path_part, cmd);
		free(path_part);
		if (access(path, F_OK) == 0)
			break ;
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	return (path);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;
	int		result;
	int		i;

	i = 0;
	cmd = ft_split(argv, ' ');
	if (!cmd)
		error("command splitting failed");
	path = find_path(cmd[0], envp);
	if (!path)
	{
		while (cmd[++i])
			free(cmd);
		error("command not found in PATH");
	}
	result = execve(path, cmd, envp);
	free(path);
	i = -1;
	while (cmd[++i])
		free(cmd);
	if (result == -1)
		error("execve failed");
}
