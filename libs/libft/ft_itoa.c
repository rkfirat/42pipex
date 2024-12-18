/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:56:46 by rfirat            #+#    #+#             */
/*   Updated: 2024/10/16 20:43:35 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	get_intlen(int n)
{
	unsigned int	count;

	count = 0;
	if (n <= 0)
		count += 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*out;
	long	temp;
	int		count;

	temp = (long)n;
	count = get_intlen(n);
	out = malloc(sizeof(char) * (count + 1));
	if (!out)
		return (NULL);
	if (temp < 0)
	{
		out[0] = '-';
		temp = -temp;
	}
	else if (temp == 0)
		out[0] = '0';
	out[count] = '\0';
	while (temp != 0)
	{
		out[count - 1] = (char)((temp % 10) + '0');
		temp /= 10;
		count--;
	}
	return (out);
}
