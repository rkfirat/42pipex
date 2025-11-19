/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:34:08 by rfirat            #+#    #+#             */
/*   Updated: 2025/11/19 09:47:34 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**envp;
	int		infile;
	int		outfile;
	int		heredoc;
	int		first_cmd_index;
}			t_pipex;

typedef struct s_exec
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;
}			t_exec;

typedef struct s_path
{
	char	*path_env;
	char	**paths;
	char	*merged;
	int		i;
}			t_path;

char		*ft_strchr(const char *s, int c);
char		**free_array(char **ptr);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(const char *s1);
char		**ft_split(const char *s, char c);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);
char		*get_path(char **envp);
char		*cmd_merge(char *path, char *cmd);
void		pipex_error(char *str);
void		exec_child(char **argv, char *path, char **envp);
#endif
