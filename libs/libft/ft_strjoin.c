/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:42:43 by rfirat            #+#    #+#             */
/*   Updated: 2024/10/16 20:38:28 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
