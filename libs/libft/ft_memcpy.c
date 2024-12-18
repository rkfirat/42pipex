/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:13:33 by rfirat            #+#    #+#             */
/*   Updated: 2024/10/07 17:13:33 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*out, const void	*src, size_t len)
{
	size_t			i;
	unsigned char	*o;
	unsigned char	*s;

	i = 0;
	if (out == NULL && src == NULL)
		return ((void *)src);
	o = (unsigned char *) out;
	s = (unsigned char *) src;
	while (i++ < len)
		*o++ = *s++;
	return (out);
}
