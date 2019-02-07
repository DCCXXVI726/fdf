/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 17:03:03 by thorker           #+#    #+#             */
/*   Updated: 2019/01/22 19:40:04 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	proj(t_coor *begin, int key)
{
	if (key == 18)
	{
		begin->ox = 2.404;
		begin->oy = 0.03;
		begin->oz = 5.525;
	}
	if (key == 19)
	{
		begin->ox = 2.184;
		begin->oy = 0.03;
		begin->oz = 5.525;
	}
}

void	move(t_coor *begin, int key)
{
	if (key == 123)
		begin->x0 = begin->x0 - MOVE;
	if (key == 124)
		begin->x0 = begin->x0 + MOVE;
	if (key == 125)
		begin->y0 = begin->y0 + MOVE;
	if (key == 126)
		begin->y0 = begin->y0 - MOVE;
}

void	scl(t_coor *begin, int key)
{
	if (key == 69 || key == 2)
		begin->xscl = begin->xscl * SCALE;
	if (key == 69 || key == 1)
		begin->yscl = begin->yscl * SCALE;
	if (key == 69 || key == 116)
		begin->zscl = begin->zscl * SCALE;
	if (key == 78 || key == 0)
		begin->xscl = begin->xscl / SCALE;
	if (key == 78 || key == 13)
		begin->yscl = begin->yscl / SCALE;
	if (key == 78 || key == 121)
		begin->zscl = begin->zscl / SCALE;
}

double	circle(double ang)
{
	if (ang > 3.14 * 2)
		ang = ang - 3.14 * 2;
	else if (ang < 0)
		ang = ang + 3.14 * 2;
	return (ang);
}

void	turn(t_coor *begin, int key)
{
	if (key == 91)
		begin->ox = begin->ox + ANGLE;
	if (key == 84)
		begin->ox = begin->ox - ANGLE;
	if (key == 88)
		begin->oy = begin->oy + ANGLE;
	if (key == 86)
		begin->oy = begin->oy - ANGLE;
	if (key == 92)
		begin->oz = begin->oz + ANGLE;
	if (key == 83)
		begin->oz = begin->oz - ANGLE;
	begin->ox = circle(begin->ox);
	begin->oy = circle(begin->oy);
	begin->oz = circle(begin->oz);
	ft_putnbrln(begin->ox * 1000);
	ft_putnbrln(begin->oy * 1000);
	ft_putnbrln(begin->oz * 1000);
}
