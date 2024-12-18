/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:01:35 by rfirat            #+#    #+#             */
/*   Updated: 2024/10/16 21:18:18 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	temp;

	if (size == 0)
	{
		return (ft_strlen(src));
	}
	temp = 0;
	while (temp < size - 1 && src[temp] != '\0')
	{
		dest[temp] = src[temp];
		temp++;
	}
	dest[temp] = '\0';
	return (ft_strlen(src));
}
