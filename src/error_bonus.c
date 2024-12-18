/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:48:56 by rfirat            #+#    #+#             */
/*   Updated: 2024/12/18 08:06:33 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	error(char *err_msg)
{
	ft_putendl_fd(err_msg, 1);
	exit(EXIT_FAILURE);
}

void	input_error(void)
{
	ft_putendl_fd("============= ERROR =============", 1);
	ft_putendl_fd("$ ./pipex infile cmd1 cmd2 ... cmdn outfile", 1);
	ft_putendl_fd("$ ./pipex here_doc LIMITER cmd1 cmd2 file", 1);
	exit(EXIT_FAILURE);
}
