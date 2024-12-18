/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:05:47 by rfirat            #+#    #+#             */
/*   Updated: 2024/12/18 20:35:03 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	free_cmd(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		free(cmd[i++]);
	free(cmd);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;
	int		result;

	cmd = ft_split(argv, ' ');
	if (!cmd)
		error("command splitting failed", 1);
	path = find_path(cmd[0], envp);
	if (!path)
	{
		free_cmd(cmd);
		error("command not found", 127);
	}
	result = execve(path, cmd, envp);
	free(path);
	if (result == -1)
	{
		free_cmd(cmd);
		error("command not found", 127);
	}
	free_cmd(cmd);
}

char	*find_pathc(char *cmd)
{
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*path;
	char	*path_part;

	if (find_pathc(cmd))
		return (find_pathc(cmd));
	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path_part = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path_part, cmd);
		free(path_part);
		if (access(path, F_OK) == 0)
			return (free_cmd(paths), path);
		free(path);
		i++;
	}
	return (free_cmd(paths), NULL);
}
