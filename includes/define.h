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

# define f_player filler->player
# define f_board filler->board
# define f_line(i) filler->board[i]
# define f_size_y filler->size_y
# define f_size_x filler->size_x
# define f_array(y, x) filler->board[y][x]
# define f_print_y filler->print_y
# define f_print_x filler->print_x
# define f_pos filler->pos
# define f_point filler->point
# define f_map(y, x) filler->point_map[y][x]

/*
** in struct t_token which is in t_filler
*/

# define t_size_y filler->token.size_y
# define t_size_x filler->token.size_x
# define t_last_y filler->token.last_y
# define t_last_x filler->token.last_x
# define t_line(i) filler->token.token[i]
# define t_array(y, x) filler->token.token[y][x]
# define t_tok filler->token.token


#endif