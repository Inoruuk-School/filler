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
#include "includes/filler.h"

void	aff(t_filler *filler, int fd)
{
	int i = 0;
	int j = 0;

	dprintf(fd, "player :%d\n", filler->player);
	dprintf(fd, "board :%dx%d\n", filler->size_y, filler->size_x);
	while (j++ < filler->size_x)
	{
		dprintf(fd, "%d", i = i > 9 ? 0 : i);
		i++;
	}
	dprintf(fd, "\n");
	i = 0;
	while (i < filler->size_y)
		dprintf(fd, "%s\n", filler->board[i++]);
	dprintf(fd, "\n");
	i = 0;
	while (i < filler->size_y)
	{
		j = 0;
		while (j < filler->size_x)
		{
			dprintf(fd, "%-6d ", F_MAP(i, j));
			j++;
		}
		i++;
		dprintf(fd, "\n");
	}
	dprintf(fd, "token :%dx%d\n", filler->token.size_y, filler->token.size_x);
	i = 0;
	while (i < filler->token.size_y)
		dprintf(fd, "%s\n", filler->token.token[i++]);
	dprintf(fd, "token last_y : %d\n", filler->token.last_y);
	dprintf(fd, "token last_x : %d\n", filler->token.last_x);
	dprintf(fd, "print x : %d\n", filler->print_x);
	dprintf(fd, "print y : %d\n", filler->print_y);
	dprintf(fd, "pos : %d\n", F_POS);
	dprintf(fd, "point %d\n", F_POINT);
	dprintf(fd, "\n");
}

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
	int			fd;//enlever
	int			i;
	t_filler	filler;

	fd = open("linee.txt", O_RDWR | O_TRUNC);//enelever
	i = 1;
	while (i)
	{
		parse(&filler);
		find_pos(&filler);
		put_token(&filler);
		ft_printf("%d %d\n", filler.print_y, filler.print_x);
		aff(&filler, fd);
		i = filler.point == -10000 ? 0 : 1;
		free_token(&filler);
	}
	close(fd);//enelever
	free_struct(&filler);
	return (0);
}
