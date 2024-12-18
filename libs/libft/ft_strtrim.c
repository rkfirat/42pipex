/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:20:40 by rfirat            #+#    #+#             */
/*   Updated: 2024/10/16 20:33:48 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*out;

	out = NULL;
	if (s1 && set)
	{
		start = 0;
		end = ft_strlen(s1);
		while (s1[start] && ft_strchr(set, s1[start]))
			start++;
		while (s1[end - 1] && ft_strchr(set, s1[end - 1]))
			end--;
		if (start >= end)
		{
			out = (char *)malloc(sizeof(char));
			if (out)
				out[0] = '\0';
			return (out);
		}
		out = (char *)malloc(sizeof(char) * (end - start + 1));
		if (out)
			ft_strlcpy(out, (char *)&s1[start], end - start + 1);
	}
	return (out);
}
