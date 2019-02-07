/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:32:22 by thorker           #+#    #+#             */
/*   Updated: 2019/01/22 19:39:49 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double		*get_xy(t_coor *begin, t_vector *first, t_vector *last)
{
	double	*coor;

	if ((coor = (double*)malloc(sizeof(double) * 6)) == 0)
		return (0);
	coor[0] = cos(begin->oy) * cos(begin->oz) * first->x * begin->xscl -
		cos(begin->oy) * sin(begin->oz) * first->y * begin->yscl +
		sin(begin->oy) * first->z * begin->zscl + begin->x0;
	coor[1] = (sin(begin->ox) * sin(begin->oy) * cos(begin->oz) + cos(begin->ox)
			* sin(begin->oz)) * first->x * begin->xscl +
		(cos(begin->ox) * cos(begin->oz) - sin(begin->ox) * sin(begin->oy) *
		sin(begin->oz)) * first->y * begin->yscl -
		sin(begin->ox) * cos(begin->oy) * first->z * begin->zscl + begin->y0;
	coor[2] = cos(begin->oy) * cos(begin->oz) * last->x * begin->xscl -
		cos(begin->oy) * sin(begin->oz) * last->y * begin->yscl +
		sin(begin->oy) * last->z * begin->zscl + begin->x0;
	coor[3] = (sin(begin->ox) * sin(begin->oy) * cos(begin->oz) + cos(begin->ox)
		* sin(begin->oz)) * last->x * begin->xscl +
		(cos(begin->ox) * cos(begin->oz) - sin(begin->ox) * sin(begin->oy) *
		sin(begin->oz)) * last->y * begin->yscl -
		sin(begin->ox) * cos(begin->oy) * last->z * begin->zscl + begin->y0;
	coor[4] = first->z;
	coor[5] = last->z;
	return (coor);
}

t_vector	*put_first_line(t_coor *begin)
{
	t_vector *curr;

	curr = begin->begin;
	while (curr->next != 0 && curr->y == curr->next->y)
	{
		put_line(begin, get_xy(begin, curr, curr->next));
		curr = curr->next;
	}
	return (curr->next);
}

void		put_inst(t_coor *begin)
{
	mlx_string_put(begin->mlx_ptr, begin->win_ptr, 10, 10, 0xFFFFFF,
			"move: arrow");
	mlx_string_put(begin->mlx_ptr, begin->win_ptr, 10, 100, 0xFFFFFF,
			"color: r g b h");
	mlx_string_put(begin->mlx_ptr, begin->win_ptr, 10, 200, 0xFFFFFF,
			"sclae: + - (numpad)");
	mlx_string_put(begin->mlx_ptr, begin->win_ptr, 10, 300, 0xFFFFFF,
			"turn: ox: 8 2 oy: 6 4 oz: 9 1 (numpad)");
}

void		put_map(t_coor *begin)
{
	t_vector	*curr;
	t_vector	*top;

	curr = put_first_line(begin);
	top = begin->begin;
	while (curr != 0)
	{
		while ((curr->next != 0 && curr->y == curr->next->y) ||
				top->y == top->next->y)
		{
			put_line(begin, get_xy(begin, curr, top));
			if (curr->next != 0 && curr->y == curr->next->y)
			{
				put_line(begin, get_xy(begin, curr, curr->next));
				curr = curr->next;
			}
			if (top->y == top->next->y)
				top = top->next;
		}
		put_line(begin, get_xy(begin, curr, top));
		curr = curr->next;
		top = top->next;
	}
	put_inst(begin);
}
