/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:31:42 by rfirat            #+#    #+#             */
/*   Updated: 2024/10/16 20:37:22 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*out;
	size_t	out_len;
	size_t	index;

	if (!str)
		return (NULL);
	if (start >= ft_strlen(str) || len == 0)
		return (ft_strdup(""));
	index = 0;
	out_len = ft_strlen(str + start);
	if (out_len > len)
		out_len = len;
	out = malloc(sizeof(char) * (out_len + 1));
	if (!out)
		return (NULL);
	while (index < out_len)
	{
		out[index] = str[start + index];
		index++;
	}
	out[index] = '\0';
	return (out);
}
