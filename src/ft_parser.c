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

#include "../includes/filler.h"

/*
** Function : playerNboard
** -----------------
** @param filler : struct t_filler where everything is stocked
** used only once to know which player is which
** line is always on STDOUT
*/

void	playernboard(t_filler *filler)
{
	char	*line;
	int		i;

	if (get_next_line(0, &line) == 1)
		F_PLAYER = (char)(line[10] == '1' ? 'O' : 'X');
	ft_strdel(&line);
	if (get_next_line(0, &line) == 1 && ft_strnstr(line, "Plateau", 7))
	{
		i = 8;
		F_SIZE_Y = (unsigned)ft_atoi(&line[i]);
		F_SIZE_X = (unsigned)ft_atoi(ft_strchr(&line[i], ' '));
	}
	ft_strdel(&line);
	if (!(F_BOARD = ft_memalloc(sizeof(char *) * F_SIZE_Y)))
		exit(0);
	if (!(F_PMAP = ft_memalloc(sizeof(int *) * F_SIZE_Y)))
		exit(0);
	i = -1;
	while (++i < F_SIZE_Y)
	{
		if (!(F_BLINE(i) = ft_strnew(F_SIZE_X)))
			exit(0);
		if (!(F_PLINE(i) = ft_memalloc(sizeof(int) * F_SIZE_X)))
			exit(0);
	}
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
			tmp = line;
			tmp = 1 + ft_strchr(tmp, ' ');
			find_new(filler, tmp, i);
			ft_strncpy(F_BLINE(i), tmp, F_SIZE_X);
			i++;
		}
		ft_strdel(&line);
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
	T_LAST_X = 0;
	T_LAST_Y = 0;
	while (j < T_SIZE_Y)
	{
		i = 0;
		while (i < T_SIZE_X)
		{
			if (i > T_LAST_X && filler->token.token[j][i] == '*')
				T_LAST_X = i;
			if (j > T_LAST_Y && filler->token.token[j][i] == '*')
				T_LAST_Y = j;
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

void	token_cpy(t_filler *filler)
{
	char	*tmp;
	char	*line;
	int		i;

	if (get_next_line(0, &line) && ft_strnstr(line, "Piece", 5))
	{
		tmp = line;
		tmp = ft_strchr(tmp, ' ');
		T_SIZE_Y = (unsigned)atoi(tmp++);
		tmp = ft_strchr(tmp, ' ');
		T_SIZE_X = (unsigned)atoi(tmp);
		if (!(T_TOK = ft_memalloc(sizeof(char *) * T_SIZE_Y)))
			exit(0);
	}
	ft_strdel(&line);
	i = 0;
	while (i < T_SIZE_Y && get_next_line(0, &line) == 1)
	{
		if (!(T_LINE(i) = ft_strdup(line)))
			exit(0);
		ft_strdel(&line);
		i++;
	}
	resize(filler);
}

/*
** Function : parse
** ------------------
** @param filler struct where everything needed is
** parse STDOUT
*/

void	parse(t_filler *filler)
{
	static	int	first_parse = 1;

	if (first_parse)
	{
		playernboard(filler);
		first_parse = 0;
	}
	F_POINT = -10000;
	board_cpy(filler);
	token_cpy(filler);
	fill_map(filler);
}
