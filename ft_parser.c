/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parser.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asiaux <asiaux@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 09:13:37 by asiaux       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 09:13:37 by asiaux      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/filler.h"

/*
** Function : playerNboard
** -----------------
** @param filler : struct t_filler where everything is stocked
** used only once to know which player is which
** line is always on STDOUT
*/

void	playerNboard(t_filler *filler)
{
	char	*line;
	int 	i;

	if (get_next_line(0, &line))
	{
	/*	f_player = line[10] == '1' ? 'O' : 'X'; */f_player = line[10] == '1' ? 0 : 1;
		free(line);
	}
	if (get_next_line(0, &line) && ft_strnstr(line, "Plateau", 7))
	{
		i = 8;
		f_size_y = (unsigned)ft_atoi(&line[i]);
		while (line[i] != ' ')
			i++;
		f_size_x = (unsigned)ft_atoi(&line[i]);
	}
	if (!(f_board = (char **)malloc(sizeof(char *) * f_size_y)))// && \
		!(filler->point_map = (int **)malloc(sizeof(int *) * f_size_y)))
		exit(0);
	i = -1;
	while (i++ < f_size_y)
		if (!(f_line(i) = (char *)malloc(sizeof(char) * f_size_x)))// && \
			!(filler->point_map[i] = (int *)malloc(sizeof(int) * f_size_x)))
			exit(0);
}

/*
** Function : board_cpy
** ---------------------
** @param filler
** Copy each given line on STDOUT with GNL to the struct
*/

void	board_cpy(t_filler *filler)
{
	int		i;
	char	*tmp;
	char	*line;

	i = 0;
	while (i < filler->size_y && get_next_line(0, &line))
	{
		if (!ft_strnstr(line, "    ", 4) && !ft_strnstr(line, "Plateau", 7))
		{
			tmp = 1 + ft_strchr(line, ' ');
			ft_strcpy(filler->board[i], tmp);
			i++;
		}
		free(line);
	}
}

/*
** Function : resize
** @param filler
** search the last '*' in each column and lines
** used to get the 'true size' of the token
*/

void	resize(t_filler *filler)
{
	unsigned i;
	unsigned j;

	j = 0;
	t_last_x = 0;
	t_last_y = 0;
	while (j < t_size_y)
	{
		i = 0;
		while (i < t_size_x)
		{
			if (i > t_last_x && filler->token.token[j][i] == '*')
				t_last_x = i;
			if (j > t_last_y && filler->token.token[j][i] == '*')
				t_last_y = j;
			i++;
		}
		j++;
	}
}

/*
** Function : token_cpy
** @param filler
** Create the full size token and copy each line to the newly created array
** Get the 'true size later'
*/

void	token_cpy(t_filler *filler, int fd)
{
	char	*tmp;
	char 	*line;
	int 	i;

	if (get_next_line(0, &line) && ft_strnstr(line, "Piece", 5))
	{
		tmp = ft_strchr(line, ' ');
		t_size_y = (unsigned)atoi(tmp++);
		tmp = ft_strchr(tmp, ' ');
		t_size_x = (unsigned)atoi(tmp);
		if (!(t_tok = (char **)malloc(sizeof(char *) * t_size_y)))
			exit(0);
		free(line);
	}
	i = 0;
	while (i < t_size_y && get_next_line(0, &line))
	{
		if (!(t_line(i) = (char *)malloc(sizeof(char) * t_size_x)))
			exit(0);
//		if (!ft_strnstr(line, "    ", 4))
			ft_strncpy(t_line(i), line, t_size_x);
//		dprintf(fd, "\nline : %s cpy : %s\n\n", line, t_line(i));
		i++;
		free(line);
	}
	resize(filler);
}

/*
** Function : parse
** ------------------
** @param filler struct where everything needed is
** parse STDOUT
*/

void	parse(t_filler *filler, int fd)
{
	static int 	first_parse = 1;

	if (first_parse)
	{
		playerNboard(filler);
		first_parse = 0;
	}
	board_cpy(filler);
	token_cpy(filler, fd);
}
