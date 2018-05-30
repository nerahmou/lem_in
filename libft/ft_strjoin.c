/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 14:55:20 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 19:27:23 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_size;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	total_size = ft_strlen(s1) + ft_strlen(s2);
	if (!(res = malloc(sizeof(char) * (total_size + 1))))
		return (NULL);
	res[total_size] = '\0';
	while (*s1)
	{
		*res++ = *s1;
		s1++;
	}
	while (*s2)
	{
		*res++ = *s2;
		s2++;
	}
	return (res - total_size);
}
