/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:53:56 by rfirat            #+#    #+#             */
/*   Updated: 2024/10/16 21:06:17 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[h])
	{
		n = 0;
		while (haystack[h] == needle[n] && haystack[h] && h < len)
		{
			h++;
			n++;
		}
		if (!needle[n])
			return ((char *)&haystack[h - n]);
		h = (h - n) + 1;
	}
	return (NULL);
}
