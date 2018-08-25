/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   define.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asiaux <asiaux@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/20 06:24:06 by asiaux       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/20 06:24:06 by asiaux      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/*
** in struct t_filler
*/

# define F_PLAYER filler->player
# define F_BOARD filler->board
# define F_BLINE(i) filler->board[i]
# define F_SIZE_Y filler->size_y
# define F_SIZE_X filler->size_x
# define F_ARRAY(y, x) filler->board[y][x]
# define F_PRINT_Y filler->print_y
# define F_PRINT_X filler->print_x
# define F_POS filler->pos
# define F_POINT filler->point
# define F_PMAP filler->point_map
# define F_MAP(y, x) filler->point_map[y][x]
# define F_PLINE(i) filler->point_map[i]

/*
** in struct t_token which is in t_filler
*/

# define T_SIZE_Y filler->token.size_y
# define T_SIZE_X filler->token.size_x
# define T_LAST_Y filler->token.last_y
# define T_LAST_X filler->token.last_x
# define T_LINE(i) filler->token.token[i]
# define T_ARRAY(y, x) filler->token.token[y][x]
# define T_TOK filler->token.token

#endif
