/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 14:55:17 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 14:55:17 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long i;

	i = 0;
	while (i != n)
	{
		if (((unsigned char*)s)[i] == (unsigned char)c)
			return (((unsigned char*)s) + i);
		i++;
	}
	return (NULL);
}
