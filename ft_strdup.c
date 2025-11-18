/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 01:32:35 by rfirat            #+#    #+#             */
/*   Updated: 2025/11/19 02:22:11 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *s1)
{
	char	*out;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	out = malloc(len + 1);
	if (!out)
		return (NULL);
	while (i < len)
	{
		out[i] = s1[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}
