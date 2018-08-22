/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asiaux <asiaux@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/16 02:51:47 by asiaux       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/16 02:51:47 by asiaux      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <cxxabi.h>
# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "define.h"

/*
** struct token
**----------------
** @token : is the current token
** @size y : number of lines
** @size_x : number of char/lines
*/

typedef struct				s_token
{
	char			 		**token;
	unsigned int			size_y : 8;
	unsigned int			size_x : 8;
	unsigned int			last_x : 8;
	unsigned int			last_y : 8;
}							t_token;

/*
** struct filler
**----------------
** @board : is the current board of filler
** @uint8_t player : uint8_t : 1 ~ bool, if 0 player 1, if 1 player 2
** @size y : number of lines
** @size_x : number of char/lines
*/


typedef struct			s_filler
{
	char 				**board;
	unsigned int		player : 1;
	unsigned int		size_y : 8;
	unsigned int		size_x : 8;
	unsigned int		print_x : 8;
	unsigned int		print_y : 8;
	int 				pos;
    t_token             token;
}						t_filler;

void					parse(t_filler *first, int fd);
int						put_token(t_filler *filler, int fd);
int						put_token_bot(t_filler *filler, int fd);

#endif
