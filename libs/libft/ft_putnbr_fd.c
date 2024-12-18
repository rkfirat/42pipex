/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:21:29 by rfirat            #+#    #+#             */
/*   Updated: 2024/10/16 20:34:21 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		sayi;
	char	sayimetin[12];
	int		basamak;
	int		temp;

	basamak = 0;
	sayi = n;
	if (sayi == 0)
		write(fd, "0", 1);
	if (sayi == -2147483648)
		write(fd, "-2147483648", 11);
	else if (sayi < 0)
	{
		sayi = -sayi;
		write(fd, "-", 1);
	}
	while (sayi > 0)
	{
		temp = sayi % 10;
		sayi = sayi / 10;
		sayimetin[basamak] = temp + '0';
		basamak++;
	}
	while (basamak > 0)
		write(fd, &sayimetin[--basamak], 1);
}
