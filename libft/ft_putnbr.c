/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:34:11 by thorker           #+#    #+#             */
/*   Updated: 2018/11/27 21:34:56 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int c)
{
	char k;

	if (c == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (c < 0)
		{
			c = c * (-1);
			write(1, "-", 1);
		}
		if (c / 10 == 0)
		{
			k = c + '0';
			write(1, &k, 1);
		}
		else
		{
			ft_putnbr(c / 10);
			k = c % 10 + '0';
			write(1, &k, 1);
		}
	}
}
