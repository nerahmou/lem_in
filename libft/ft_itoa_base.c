/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 16:56:42 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 12:03:30 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(uintmax_t value, int base)
{
	int				i;
	uintmax_t		nb;
	char			*res;

	nb = value;
	i = 0;
	while (nb > 0)
	{
		nb /= base;
		i++;
	}
	if (!(res = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	res[i--] = '\0';
	nb = value;
	while (i >= 0)
	{
		res[i] = (nb % base) >= 10 ? (nb % base) + 97 - 10 : (nb % base) + 48;
		nb /= base;
		i--;
	}
	if (value == 0)
		res[0] = '0';
	return (res);
}
