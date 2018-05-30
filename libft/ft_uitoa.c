/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_uitoa.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 13:27:27 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 18:12:10 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(uintmax_t n)
{
	int size;

	size = 0;
	while (n != 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

static char	*ft_malloc(uintmax_t n)
{
	char *dst;

	dst = ft_strnew(ft_intlen(n) + 1);
	return (dst);
}

static char	*ft_chiffre(uintmax_t n)
{
	char *dst;

	dst = ft_malloc(0);
	dst[0] = n + 48;
	dst[1] = '\0';
	return (dst);
}

char		*ft_uitoa(uintmax_t n)
{
	uintmax_t	a;
	char		*dst;

	if (n <= 9)
		return (ft_chiffre(n));
	dst = ft_malloc(n);
	a = ft_intlen(n) - 1;
	if (dst)
	{
		dst[a + 1] = '\0';
		while (n > 0)
		{
			dst[a] = '0' + (n % 10);
			n = n / 10;
			a--;
		}
	}
	return (dst);
}
