/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brigh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 22:19:59 by thorker           #+#    #+#             */
/*   Updated: 2019/01/22 17:19:53 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ch_color(t_coor *begin, int key)
{
	if (key == 4)
		begin->mod = 'h';
	if (key == 15)
		begin->mod = 'r';
	if (key == 5)
		begin->mod = 'g';
	if (key == 11)
		begin->mod = 'b';
}

int		color(t_coor *begin, double *coor, double x)
{
	int	top_color;
	int	bot_color;

	if (begin->mod == 'h')
	{
		if (begin->z_max == begin->z_min)
			return (0xFFFFFF);
		top_color = 0xFFFFFF + (0xFF0000 - 0xFFFFFF) *
			(coor[5] - begin->z_min) / (begin->z_max - begin->z_min);
		bot_color = 0xFFFFFF + (0xFF0000 - 0xFFFFFF) *
			(coor[4] - begin->z_min) / (begin->z_max - begin->z_min);
		if (coor[4] == coor[5])
			return (top_color);
		return (bot_color + (top_color - bot_color) *
				(x - coor[0]) / (coor[1] - coor[0]));
	}
	if (begin->mod == 'r')
		return (0xFF0000);
	if (begin->mod == 'g')
		return (0x00FF00);
	if (begin->mod == 'b')
		return (0x0000FF);
	return (0);
}

int		bright(int color, double bri)
{
	int r;
	int g;
	int b;

	b = color % 256;
	g = color / 256 % 256;
	r = (color / 256) / 256;
	r = (int)(r * bri);
	g = (int)(g * bri);
	b = (int)(b * bri);
	color = b + g * 256 + r * 256 * 256;
	return (color);
}
