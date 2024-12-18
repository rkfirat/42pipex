/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:45:22 by rfirat            #+#    #+#             */
/*   Updated: 2024/12/18 07:47:58 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libs/libft/libft.h"
# include "sys/wait.h"
# include "fcntl.h"

void	input_error(void);
void	error(char *error_message);
char	*find_path(char *cmd, char **envp);
void	execute(char *argv, char **envp);

#endif