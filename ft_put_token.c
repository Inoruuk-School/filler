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

int		check_token(int y, int x, t_filler *filler, char c, int fd)
{
	int 	x2;
	int 	y2;
	int 	check;
	char	c2;

	c2 = c == 'O' ? 'X' : 'O';
	y2 = 0;
	check = 0;
	while (check >= 0 && check <= 1 && y2 <= t_last_y)
	{
		x2 = 0;
		while (check >= 0 && check <= 1 && x2 <= t_last_x) // verif que ca va pas trop loin avec token.last_x et y a pas l air de fonctionner correctement
		{
			if (y + y2 <= f_size_y && x + x2 <= f_size_x && t_array(y2, x2) == '*' && (f_array(y+ y2, x + x2) == c || f_array(y+ y2, x + x2) == c + 32))
				check++;
			if (y + y2 <= f_size_y && x + x2 <= f_size_x && t_array(y2, x2) == '*' && (f_array(y+ y2, x + x2) == c2 || f_array(y+ y2, x + x2) == c2 + 32))
				check -= 2;
			x2++;
		}
		y2++;
	}
	if (check == 1)
	{
		f_print_x = (unsigned)x;
		f_print_y = (unsigned)y;
	}
	return (check == 1 ? 1 : 0);
}

int	put_token(t_filler *filler, int fd)
{
	int 	x;
	int 	y;
	int		check;
	char	c;

	y = 0;
	check = 1;
	c = (f_player == 0) ? 'O' : 'X';
	while(check && y + t_last_y < f_size_y)
	{
		x = 0;
		while (check && x + t_last_x < f_size_x)
		{
			if (check_token(y, x, filler, c, fd))
				check = 0;
			x++;
		}
		y++;
	}
	return (check == 0 ? 1 : 0);
}

int	put_token_bot(t_filler *filler, int fd)
{
	int 	x;
	int 	y;
	int		check;
	char	c;


	y = f_size_y - t_last_y - 1;
	check = 1;
	c = (f_player == 0) ? 'O' : 'X';
	while(check && y >= 0)
	{
		x = f_size_x - t_last_x - 1;
		while (check && x >= 0)
		{
			if (check_token(y, x, filler, c, fd))
				check = 0;
			x--;
		}
		y--;
	}
	return (check == 0 ? 1 : 0);
}