/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asiaux <asiaux@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 02:21:51 by asiaux       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/21 03:37:58 by asiaux      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *tmp;
	unsigned char *tmp2;

	tmp = (unsigned char *)dst;
	tmp2 = (unsigned char *)src;
	while (n--)
		*tmp++ = *tmp2++;
	return (dst);
}
