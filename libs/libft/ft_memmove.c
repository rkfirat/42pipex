/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:30:43 by rfirat            #+#    #+#             */
/*   Updated: 2024/10/16 20:38:03 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *out, void *src, size_t len)
{
	unsigned char		*o;
	unsigned char		*s;
	size_t				i;

	s = (unsigned char *)src;
	o = (unsigned char *)out;
	i = 0;
	if (!s && !o)
		return (s);
	if (s < o)
	{
		while (++i <= len)
			o[len - i] = s[len - i];
	}
	else
	{
		while (len-- > 0)
			*(o++) = *(s++);
	}
	return (out);
}
