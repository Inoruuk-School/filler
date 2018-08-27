/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asiaux <asiaux@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 01:37:25 by asiaux       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 01:37:25 by asiaux      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/filler.h"

void	find_pos(t_filler *filler)
{
	int		x;
	int		y;
	int		y_pos;
	int		y2_pos;
	char	c2;

	y = 0;
	y_pos = 0;
	y2_pos = 0;
	c2 = F_PLAYER == 'O' ? (char)'X' : (char)'O';
	while (y < F_SIZE_Y)
	{
		x = 0;
		while (x < F_SIZE_X)
		{
			if (F_ARRAY(y, x) == F_PLAYER)
				y_pos = y;
			if (F_ARRAY(y, x) == c2)
				y2_pos = y;
			x++;
		}
		y++;
	}
	F_POS = y_pos - y2_pos;
}

void	free_struct(t_filler *filler)
{
	int y;

	y = 0;
	while (y < F_SIZE_Y)
	{
		ft_bzero(F_PLINE(y), F_SIZE_X);
		free(F_PLINE(y));
		ft_strdel(&F_BLINE(y));
		y++;
	}
	free(F_BOARD);
	free(F_PMAP);
	free(filler);
}

void	free_token(t_filler *filler)
{
	int y;

	y = 0;
	while (y < T_SIZE_Y)
	{
		ft_bzero(T_LINE(y), T_SIZE_X);
		free(T_LINE(y));
		y++;
	}
	free(T_TOK);
}

int		main(void)
{
	int			i;
	t_filler	*filler;

	if (!(filler = ft_memalloc(sizeof(t_filler))))
		exit(0);
	i = 1;
	while (i)
	{
		parse(filler);
		find_pos(filler);
		put_token(filler);
		ft_printf("%d %d\n", F_PRINT_Y, F_PRINT_X);
		i = F_POINT == -10000 ? 0 : 1;
		free_token(filler);
	}
	free_struct(filler);
	return (0);
}
