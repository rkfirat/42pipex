/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:30:27 by rfirat            #+#    #+#             */
/*   Updated: 2024/10/16 20:33:20 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
