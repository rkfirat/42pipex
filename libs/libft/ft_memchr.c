/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:19:58 by rfirat            #+#    #+#             */
/*   Updated: 2024/10/16 21:06:33 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	ch;
	size_t			len;

	len = 0;
	p = (unsigned char *)ptr;
	ch = (unsigned char)c;
	while (len < n)
	{
		if (*p == ch)
			return (p);
		p++;
		len++;
	}
	return (NULL);
}
