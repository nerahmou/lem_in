/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 14:55:22 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 14:55:22 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_cpy(char *dst, const char *s, int a, int b)
{
	int c;

	c = 0;
	while (b < a)
	{
		dst[c] = s[b];
		b++;
		c++;
	}
	dst[c] = '\0';
	return (dst);
}

char		*ft_strtrim(char const *s)
{
	int		a;
	int		b;
	int		c;
	char	*dst;

	if (s)
	{
		a = ft_strlen(s);
		b = 0;
		c = 0;
		while (s[a - 1] == ' ' || s[a - 1] == '\n' || s[a - 1] == '\t')
			a--;
		while (s[b] == ' ' || s[b] == '\n' || s[b] == '\t')
			b++;
		if (s[b] == '\0')
			return (ft_strdup(s + b));
		c = a - b;
		if (!(dst = ft_strnew(c)))
			return (NULL);
		return (ft_cpy(dst, s, a, b));
	}
	return (0);
}
