/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strndup.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/06 14:16:23 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/06 14:25:16 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int n)
{
	char	*dest;
	int		a;
	int		b;

	a = n;
	if (s1)
	{
		dest = (char*)malloc(sizeof(*dest) * (a + 1));
		if (dest == NULL)
			return (0);
		b = 0;
		while (b < a)
		{
			dest[b] = s1[b];
			b++;
		}
		dest[b] = '\0';
		return (dest);
	}
	return (NULL);
}
