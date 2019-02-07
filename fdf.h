/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:41:20 by thorker           #+#    #+#             */
/*   Updated: 2019/01/22 19:40:21 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include "libft.h"
# include <mlx.h>
# include <math.h>
# define SCALE 1.01
# define MOVE 10
# define ANGLE 3.14 / 100

typedef struct	s_coor
{
	double		x0;
	double		y0;
	double		ox;
	double		oy;
	double		oz;
	double		xscl;
	double		yscl;
	double		zscl;
	void		*mlx_ptr;
	void		*win_ptr;
	t_vector	*begin;
	int			z_min;
	int			z_max;
	char		mod;
}				t_coor;
void			proj(t_coor *begin, int key);
void			ch_color(t_coor *begin, int key);
void			turn(t_coor *begin, int key);
void			move(t_coor *begin, int key);
t_coor			*coor_new(t_vector *first_vector, void *mlx_ptr, void *win_ptr);
void			scl(t_coor *begin, int key);
void			put_map(t_coor *begin);
int				color(t_coor *begin, double *coor, double x);
int				bright(int color, double bri);
t_vector		*get_coor(char *file);
void			put_line(t_coor *begin, double *coor);
#endif
