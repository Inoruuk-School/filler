/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_transform.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asiaux <asiaux@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/22 06:19:53 by asiaux       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/22 06:19:53 by asiaux      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/filler.h"
/*
void	fill_map(t_filler *filler, int fd)
{
	int 	y;
	int 	x;

	y = 0;
	while (y < f_size_y)
	{
		x = 0;
//		ft_bzero(filler->point_map[y], sizeof(int) * f_size_x);
		while (x < f_size_x)
		{
			if (f_array(y, x) == f_player)
				f_map(y, x) = -10000;
			else if (f_array(y, x) == (f_player == 'O' ? 'X' : 'O'))
				f_map(y, x) = 10000;
			else
				f_map(y, x) = 0;
			dprintf(fd, "%-7d", f_map(y, x));
			x++;
		}
		dprintf(fd, "\n");
		y++;
	}
}*/