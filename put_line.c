/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:42:39 by thorker           #+#    #+#             */
/*   Updated: 2019/01/22 17:18:05 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_swap(double *coor)
{
	double for_swap;

	for_swap = coor[0];
	coor[0] = coor[2];
	coor[2] = for_swap;
	for_swap = coor[1];
	coor[1] = coor[3];
	coor[3] = for_swap;
	for_swap = coor[4];
	coor[4] = coor[5];
	coor[5] = for_swap;
}

void	putyline(t_coor *begin, double *coor)
{
	double	grad;
	int		y;
	double	x;
	int		i;

	if (coor[1] > coor[3])
		ft_swap(coor);
	grad = (coor[2] - coor[0]) / (coor[3] - coor[1]);
	y = round(coor[1]);
	x = coor[0] + grad * (y - coor[1]);
	coor[0] = y;
	i = 0;
	while (y + i < coor[3])
		i++;
	coor[1] = y + i - 1;
	while (y < coor[3])
	{
		mlx_pixel_put(begin->mlx_ptr, begin->win_ptr, floor(x), y,
				bright(color(begin, coor, y), 1 - (x - floor(x))));
		mlx_pixel_put(begin->mlx_ptr, begin->win_ptr, floor(x) + 1, y,
				bright(color(begin, coor, y), x - floor(x)));
		y++;
		x = x + grad;
	}
}

void	putxline(t_coor *begin, double *coor)
{
	double	grad;
	int		x;
	double	y;
	int		i;

	if (coor[0] > coor[2])
		ft_swap(coor);
	grad = (coor[3] - coor[1]) / (coor[2] - coor[0]);
	x = round(coor[0]);
	y = coor[1] + grad * (x - coor[0]);
	coor[0] = x;
	i = 0;
	while (i + x < coor[2])
		i++;
	coor[1] = x + i - 1;
	while (x < coor[2])
	{
		mlx_pixel_put(begin->mlx_ptr, begin->win_ptr, x, floor(y),
				bright(color(begin, coor, x), 1 - (y - floor(y))));
		mlx_pixel_put(begin->mlx_ptr, begin->win_ptr, x, floor(y) + 1,
				bright(color(begin, coor, x), y - floor(y)));
		y = y + grad;
		x++;
	}
}

void	put_line(t_coor *begin, double *coor)
{
	if (fabs(coor[0] - coor[2]) > fabs(coor[1] - coor[3]))
		putxline(begin, coor);
	else
		putyline(begin, coor);
	free(coor);
}
