/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:01:35 by rfirat            #+#    #+#             */
/*   Updated: 2024/10/16 21:06:08 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char	*b;
	size_t	len_dest;
	size_t	temp;
	size_t	new_size;

	b = (char *)src;
	len_dest = ft_strlen(dest);
	temp = 0;
	if (len_dest < size)
		new_size = len_dest + ft_strlen(b);
	else
		new_size = ft_strlen(b) + size;
	while (len_dest + 1 < size && b[temp] != '\0')
	{
		dest[len_dest] = b[temp];
		temp++;
		len_dest++;
	}
	dest[len_dest] = '\0';
	return (new_size);
}
