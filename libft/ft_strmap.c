/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 14:55:20 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 14:55:20 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		a;
	char	*dst;

	a = 0;
	if (s && *s && f)
	{
		if (!(dst = ft_strnew(ft_strlen(s))))
			return (0);
		while (s[a])
		{
			dst[a] = f(s[a]);
			a++;
		}
		dst[a] = '\0';
		return (dst);
	}
	else
		return (0);
}
