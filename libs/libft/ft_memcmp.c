/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:38:47 by rfirat            #+#    #+#             */
/*   Updated: 2024/10/16 20:33:02 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			len;

	len = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (len < n)
	{
		if (p1[len] != p2[len])
			return (p1[len] - p2[len]);
		len++;
	}
	return (0);
}
