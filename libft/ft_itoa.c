/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 14:55:16 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 14:09:44 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(intmax_t n)
{
	int size;

	size = 0;
	if (n < 0)
		size++;
	while (n != 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

static char	*ft_malloc(intmax_t n)
{
	char *dst;

	if (n < 0)
		dst = ft_strnew(ft_intlen(n));
	else
		dst = ft_strnew(ft_intlen(n) + 1);
	return (dst);
}

static char	*ft_chiffre(intmax_t n)
{
	char *dst;

	dst = ft_malloc(0);
	dst[0] = n + 48;
	dst[1] = '\0';
	return (dst);
}

char		*ft_itoa(intmax_t n)
{
	intmax_t	a;
	char		*dst;

	if (n >= 0 && n <= 9)
		return (ft_chiffre(n));
	if (n == (intmax_t)-9223372036854775808ULL)
		return (dst = ft_strdup("-9223372036854775808"));
	dst = ft_malloc(n);
	a = ft_intlen(n) - 1;
	if (dst)
	{
		if (n < 0)
		{
			dst[0] = '-';
			n = n * -1;
		}
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
