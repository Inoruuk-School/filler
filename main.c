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

void		aff(t_filler *filler, int fd)
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
			dprintf(fd, "%-6d ", f_map(i, j));
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
	dprintf(fd, "pos : %d\n", f_pos);
	dprintf(fd, "point %d\n", f_point);
	dprintf(fd, "\n");
}

void	find_pos(t_filler *filler)
{
	int 	x;
	int 	y;
	int 	y_pos;
	int 	y2_pos;
	char 	c2;

	y = 0;
	y_pos = 0;
	y2_pos = 0;
	c2 = f_player == 'O' ? (char)'X' : (char)'O';
	while (y < f_size_y)
	{
		x = 0;
		while  (x < f_size_x)
		{
			if (f_array(y, x) == f_player)
				y_pos = y;
			if (f_array(y, x) == c2)
				y2_pos = y;
			x++;
		}
		y++;
	}
	f_pos = y_pos - y2_pos;
}

void	free_struct(t_filler *filler)
{
	int y;

	y = 0;
	while (y < f_size_y)
	{
		ft_bzero(f_pline(y), f_size_x);
		free(f_pline(y));
		ft_strdel(&f_bline(y));
		y++;
	}
	free(f_board);
	free(f_pmap);
}

void	free_token(t_filler *filler)
{
	int y;

	y = 0;
	while (y < t_size_y)
	{
		ft_bzero(t_line(y), t_size_x);
		free(t_line(y));
		y++;
	}
	free(t_tok);
}

int 	main()
{
	int fd;
	int i;
	t_filler filler;

	fd = open("linee.txt", O_RDWR | O_TRUNC);
	i = 1;
	while (i)
	{
		parse(&filler, fd);
		find_pos(&filler);
		i = put_token(&filler, fd);
		if (i)
			ft_printf("%d %d\n", filler.print_y, filler.print_x);
		else
			ft_printf("0 0\n");
		aff(&filler, fd);
		i = filler.point == -10000 ? 0 : 1;
		free_token(&filler);
	}
	close(fd);
	free_struct(&filler);
	return (0);
}
