/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_coor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:11:40 by thorker           #+#    #+#             */
/*   Updated: 2019/01/22 19:34:38 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	find_z(t_coor *begin, t_vector *first_vector)
{
	int			z;
	t_vector	*for_search;

	for_search = first_vector;
	z = first_vector->z;
	while (for_search != 0)
	{
		if (z > for_search->z)
			z = for_search->z;
		for_search = for_search->next;
	}
	begin->z_min = z;
	for_search = first_vector;
	while (for_search != 0)
	{
		if (z < for_search->z)
			z = for_search->z;
		for_search = for_search->next;
	}
	begin->z_max = z;
}

t_coor	*coor_new(t_vector *first_vector, void *mlx_ptr, void *win_ptr)
{
	t_coor		*new_coor;

	if ((new_coor = (t_coor*)malloc(sizeof(t_coor))) == 0)
		return (0);
	new_coor->x0 = 600;
	new_coor->y0 = 400;
	new_coor->ox = 2.184;
	new_coor->oy = 0.03;
	new_coor->oz = 5.525;
	new_coor->xscl = 10;
	new_coor->yscl = 10;
	new_coor->zscl = 10;
	new_coor->mod = 'g';
	new_coor->win_ptr = win_ptr;
	new_coor->mlx_ptr = mlx_ptr;
	new_coor->begin = first_vector;
	find_z(new_coor, first_vector);
	return (new_coor);
}
