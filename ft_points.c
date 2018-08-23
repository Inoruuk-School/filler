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

void	fill_left(t_filler *filler, int y, int x, int fd)
{
	int 		top;
	int 		bot;
	unsigned 	point;
	unsigned 	raw;

	point = f_size_x + f_size_y;
	while (x >= 0)
	{
		top = y;
		bot = y;
		raw = point;
		while (--top >= 0 && raw--)
			if (f_map(top, x) != -20000 && f_map(top, x) != -10000)
				f_map(top, x) += raw;
		raw = point;
		while (++bot < f_size_y && raw--)
			if (f_map(bot, x) != -20000 && f_map(bot, x) != -10000)
				f_map(bot, x) += raw;
		if (f_map(y, x) != -20000 && f_map(y, x) != -10000)
			f_map(y, x) += point;
		x--;
		point--;
	}
	dprintf(fd, "fill left done\n");
}

void	fill_right(t_filler *filler, int y, int x, int fd)
{
	int top;
	int bot;
	int point;
	int raw;

	point = f_size_x + f_size_y;
	while (++x < f_size_x)
	{
		top = y;
		bot = y;
		raw = point;
		while (--top >= 0 && raw--)
			if (f_map(top, x) != -20000 && f_map(top, x) != -10000)
				f_map(top, x) += raw;
		raw = point;
		while (bot < f_size_y && raw--)
		{
			if (f_map(bot, x) != -20000 && f_map(bot, x) != -10000)
				f_map(bot, x) += raw;
			bot++;
		}
		point--;
	}
	dprintf(fd, "fill right done\n");
}

void	fill_map(t_filler *filler, int fd)
{
	int 			y;
	int				x;
	char 			c;
	static int		check = 1;

	y = 0;
	c =  (char)(f_player == 'O' ? 'x' : 'o');
	while (y < f_size_y)
	{
		x = 0;
		while (x < f_size_x)
		{
			if (f_array(y, x) == f_player)
				f_map(y, x) = -10000;
			else if (f_array(y, x) != '.')
				f_map(y, x) = -20000;
			x++;
		}
		y++;
	}
	y = 0;
	while (y < f_size_y)
	{
		x = 0;
		while (x < f_size_x)
		{
			if (f_array(y, x) == c || check)
			{
				check = 0;
				fill_right(filler, y, x, fd);
				fill_left(filler, y, x, fd);
			}
			x++;
		}
		y++;
	}
}

void	find_new(t_filler *filler, char *line, int y, int fd)
{
	int 	x;
	char 	c;

	x = 0;
	c = (char)(f_player == 'O' ? 'X' : 'O');
	while (line[x] != '\0')
	{
		if (line[x] == c && f_array(y, x) == '.')
			line[x] = (char)(c + 32);
		x++;
	}
}
