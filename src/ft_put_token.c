/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_put_token.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asiaux <asiaux@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/13 04:01:10 by asiaux       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/13 04:01:10 by asiaux      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

void		check_points(t_filler *filler, int y, int x)
{
	int		x2;
	int		y2;
	int		point;

	y2 = 0;
	point = 0;
	while (y2 <= T_LAST_Y)
	{
		x2 = 0;
		while (x2 <= T_LAST_X)
		{
			if (T_ARRAY(y2, x2) == '*')
				point += F_MAP(y + y2, x + x2);
			x2++;
		}
		y2++;
	}
	if (point >= F_POINT)
	{
		F_POINT = point;
		F_PRINT_Y = (unsigned)y;
		F_PRINT_X = (unsigned)x;
	}
}

int			check_token(int y, int x, t_filler *filler, char c)
{
	int		x2;
	int		y2;
	int		check;
	char	c2;

	c2 = (char)(c == 'O' ? 'X' : 'O');
	y2 = 0;
	check = 0;
	while (check >= 0 && check <= 1 && y2 <= T_LAST_Y)
	{
		x2 = 0;
		while (check >= 0 && check <= 1 && x2 <= T_LAST_X)
		{
			if (T_ARRAY(y2, x2) == '*' && F_ARRAY(y + y2, x + x2) == c)
				check++;
			if (T_ARRAY(y2, x2) == '*' && F_ARRAY(y + y2, x + x2) == c2)
				check -= 2;
			x2++;
		}
		y2++;
	}
	return (check == 1 ? 1 : 0);
}

void		put_token(t_filler *filler)
{
	int		x;
	int		y;

	y = 0;
	while (y + T_LAST_Y < F_SIZE_Y)
	{
		x = 0;
		while (x + T_LAST_X < F_SIZE_X)
		{
			if (check_token(y, x, filler, F_PLAYER))
				check_points(filler, y, x);
			x++;
		}
		y++;
	}
}
