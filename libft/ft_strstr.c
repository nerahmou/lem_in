/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 14:55:22 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 14:55:22 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int a;
	int b;
	int i;

	a = 0;
	b = 0;
	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[a] != '\0')
	{
		i = a;
		while (haystack[a] == needle[b])
		{
			if (needle[b + 1] == '\0')
				return (((char*)haystack) + (a - b));
			a++;
			b++;
		}
		a = i;
		b = 0;
		a++;
	}
	return (NULL);
}
