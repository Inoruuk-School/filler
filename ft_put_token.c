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

#include "includes/filler.h"

void	check_points(t_filler *filler, int y, int x, int fd)
{
	int 	x2;
	int 	y2;
	int 	point;

	y2 = 0;
	point = 0;
	while (y2 <= t_last_y)
	{
		x2 = 0;
		while (x2 <= t_last_x)
		{
			if (t_array(y2, x2) == '*')
				point += f_map(y + y2, x + x2);
			x2++;
		}
		y2++;
	}
	if (point >= f_point)
	{
		f_point = point;
		f_print_y = (unsigned)y;
		f_print_x = (unsigned)x;
	}
}

int		check_token(int y, int x, t_filler *filler, char c, int fd)
{
	int 	x2;
	int 	y2;
	int 	check;
	char	c2;

	c2 =(char)(c == 'O' ? 'X' : 'O');
	y2 = 0;
	check = 0;
	while (check >= 0 && check <= 1 && y2 <= t_last_y)
	{
		x2 = 0;
		while (check >= 0 && check <= 1 && x2 <= t_last_x)
		{
			if (t_array(y2, x2) == '*' && f_array(y + y2, x + x2) == c)
//			if (y + y2 <= f_size_y && x + x2 <= f_size_x && t_array(y2, x2) ==\
			'*' && (f_array(y + y2, x + x2) == c || f_array(y+ y2, x + x2) == c + 32))
				check++;
			if (t_array(y2, x2) == '*' && f_array(y + y2, x + x2) == c2)
//			if (y + y2 <= f_size_y && x + x2 <= f_size_x && t_array(y2, x2) ==\
			'*' && (f_array(y + y2, x + x2) == c2 || f_array(y+ y2, x + x2) == c2 + 32))
				check -= 2;
			x2++;
		}
		y2++;
	}	return (check == 1 ? 1 : 0);
}

int	put_token(t_filler *filler, int fd)
{
	int 	x;
	int 	y;
	int		check;

	y = 0;
	check = 1;
	while(check && y + t_last_y < f_size_y)
	{
		x = 0;
		while (check && x + t_last_x < f_size_x)
		{
			if (check_token(y, x, filler, f_player, fd))
				check_points(filler, y, x, fd);
			x++;
		}
		y++;
	}
	check = 0;
	return (check == 0 ? 1 : 0);
}
