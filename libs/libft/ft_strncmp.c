/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:47:50 by rfirat            #+#    #+#             */
/*   Updated: 2024/10/16 20:39:12 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
