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

void	fill_left(t_filler *filler, int y, int x)
{
	int				top;
	int				bot;
	unsigned int	point;
	unsigned int	raw;

	point = F_SIZE_X + F_SIZE_Y;
	while (x >= 0)
	{
		top = y;
		bot = y;
		raw = point;
		while (--top >= 0 && raw--)
			if (F_MAP(top, x) != -20000 && F_MAP(top, x) != -10000)
				F_MAP(top, x) += raw;
		raw = point;
		while (++bot < F_SIZE_Y && raw--)
			if (F_MAP(bot, x) != -20000 && F_MAP(bot, x) != -10000)
				F_MAP(bot, x) += raw;
		if (F_MAP(y, x) != -20000 && F_MAP(y, x) != -10000)
			F_MAP(y, x) += point;
		x--;
		point--;
	}
}

void	fill_right(t_filler *filler, int y, int x)
{
	int top;
	int bot;
	int point;
	int raw;

	point = F_SIZE_X + F_SIZE_Y;
	while (++x < F_SIZE_X)
	{
		top = y;
		bot = y;
		raw = point;
		while (--top >= 0 && raw--)
			if (F_MAP(top, x) != -20000 && F_MAP(top, x) != -10000)
				F_MAP(top, x) += raw;
		raw = point;
		while (bot < F_SIZE_Y && raw--)
		{
			if (F_MAP(bot, x) != -20000 && F_MAP(bot, x) != -10000)
				F_MAP(bot, x) += raw;
			bot++;
		}
		point--;
	}
}

void	fill_map2(t_filler *filler)
{
	int				y;
	int				x;
	char			c;
	static int		check = 1;

	y = 0;
	c = (char)(F_PLAYER == 'O' ? 'x' : 'o');
	while (y < F_SIZE_Y)
	{
		x = 0;
		while (x < F_SIZE_X)
		{
			if (F_ARRAY(y, x) == c || check)
			{
				check = 0;
				fill_right(filler, y, x);
				fill_left(filler, y, x);
			}
			x++;
		}
		y++;
	}
}

void	fill_map(t_filler *filler)
{
	int				y;
	int				x;
	char			c;
	static int		check = 1;

	y = 0;
	c = (char)(F_PLAYER == 'O' ? 'x' : 'o');
	while (y < F_SIZE_Y)
	{
		x = 0;
		while (x < F_SIZE_X)
		{
			if (F_ARRAY(y, x) == F_PLAYER)
				F_MAP(y, x) = -10000;
			else if (F_ARRAY(y, x) != '.')
				F_MAP(y, x) = -20000;
			x++;
		}
		y++;
	}
	fill_map2(filler);
}

void	find_new(t_filler *filler, char *line, int y)
{
	int		x;
	char	c;

	x = 0;
	c = (char)(F_PLAYER == 'O' ? 'X' : 'O');
	while (line[x] != '\0')
	{
		if (line[x] == c && F_ARRAY(y, x) == '.')
			line[x] = (char)(c + 32);
		x++;
	}
}
