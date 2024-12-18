/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:11:28 by rfirat            #+#    #+#             */
/*   Updated: 2024/10/07 17:11:28 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void	*s, size_t len)
{
	size_t			i;
	unsigned char	*pt;

	i = 0;
	pt = (unsigned char *)s;
	while (i < len)
		pt[i++] = 0;
	return (s);
}
