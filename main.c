/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:19:24 by thorker           #+#    #+#             */
/*   Updated: 2019/01/22 19:04:57 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_map(t_coor *begin, int key, void (*f)(t_coor *, int))
{
	f(begin, key);
	mlx_clear_window(begin->mlx_ptr, begin->win_ptr);
	put_map(begin);
}

int		deal_key(int key, t_coor *begin)
{
	if (key == 15 || key == 5 || key == 11 || key == 4)
		change_map(begin, key, ch_color);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		change_map(begin, key, move);
	if (key == 91 || key == 84 || key == 86 || key == 88 || key == 92 ||
			key == 83)
		change_map(begin, key, turn);
	if (key == 69 || key == 78 || key == 0 || key == 1 || key == 2 || key == 13
			|| key == 116 || key == 121)
		change_map(begin, key, scl);
	if (key == 18 || key == 19)
		change_map(begin, key, proj);
	if (key == 53)
	{
		ft_vctdel(&(begin->begin));
		free(begin);
		exit(0);
	}
	return (0);
}

int		main(int ac, char **av)
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_vector	*first_vector;
	t_coor		*begin;

	if (ac != 2)
	{
		ft_putendl("usage: ./fdf file_name");
		return (0);
	}
	if ((first_vector = get_coor(av[1])) == 0)
		return (0);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1500, 1000, "726");
	if ((begin = coor_new(first_vector, mlx_ptr, win_ptr)) == 0)
	{
		ft_vctdel(&first_vector);
		return (0);
	}
	put_map(begin);
	mlx_hook(win_ptr, 2, 0, deal_key, begin);
	mlx_loop(mlx_ptr);
}
