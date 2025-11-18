/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 01:29:49 by rfirat            #+#    #+#             */
/*   Updated: 2025/11/19 02:21:42 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (0);
	while (s1[len] && s1[len] == s2[len] && len < n)
		len++;
	if (len == n)
		return (0);
	return ((unsigned char)s1[len] - (unsigned char)s2[len]);
}
