/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 01:41:38 by rfirat            #+#    #+#             */
/*   Updated: 2025/11/19 02:21:40 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char	*str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	size_t	index;
	size_t	temp;

	if (!s1)
		return (NULL);
	out = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	index = 0;
	temp = 0;
	if (!out)
		return (NULL);
	while (s1[index])
	{
		out[index] = s1[index];
		index++;
	}
	while (s2[temp])
	{
		out[index] = s2[temp];
		temp++;
		index++;
	}
	out[index] = '\0';
	return (out);
}
