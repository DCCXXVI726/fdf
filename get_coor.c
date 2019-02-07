/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:03:09 by thorker           #+#    #+#             */
/*   Updated: 2019/01/22 17:59:12 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char		conv_coor(t_vector **begin, char *line, int y)
{
	char	**split;
	int		i;

	if ((split = ft_strsplit(line, ' ')) == 0)
		return (0);
	i = -1;
	while (*(split + (++i)) != 0)
	{
		if (*begin != 0)
			if (ft_vctadd(begin, i, (-1 * y), ft_atoi(*(split + i))) == 0)
			{
				free(split);
				ft_vctdel(begin);
				return (0);
			}
		if (*begin == 0)
			if ((*begin = ft_vctnew(i, (-1 * y), ft_atoi(*(split + i)))) == 0)
			{
				free(split);
				return (0);
			}
	}
	free(split);
	return (1);
}

t_vector	*get_coor(char *file)
{
	int			fd;
	char		*line;
	int			k;
	t_vector	*begin;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (0);
	k = 0;
	begin = 0;
	while (get_next_line(fd, &line) != 0)
	{
		if ((conv_coor(&begin, line, k)) == 0)
		{
			free(line);
			close(fd);
			return (0);
		}
		k++;
		free(line);
	}
	close(fd);
	return (begin);
}
