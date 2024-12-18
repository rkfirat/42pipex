/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:45:22 by rfirat            #+#    #+#             */
/*   Updated: 2024/12/18 20:08:10 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libs/libft/libft.h"
# include "sys/wait.h"
# include "fcntl.h"
# include <signal.h>

void	execute(char *argv, char **envp);
char	*find_path(char *cmd, char **envp);
void	error(char *err_msg, int status);

#endif
