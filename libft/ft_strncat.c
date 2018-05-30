/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 14:55:21 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 14:55:21 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned long a;
	unsigned long b;

	a = 0;
	b = 0;
	while (((unsigned char*)s1)[a] != '\0')
		a++;
	while (b != n && s2[b])
	{
		((unsigned char*)s1)[a] = ((unsigned char*)s2)[b];
		a++;
		b++;
	}
	((unsigned char*)s1)[a] = '\0';
	return (s1);
}
