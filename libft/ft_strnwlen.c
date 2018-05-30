/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnwlen.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 14:44:53 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 15:19:05 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnwlen(wchar_t *str, int a)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (str[i] && (nb + ft_putwlen(str[i])) <= a)
	{
		if (MB_CUR_MAX <= 1 && str[i] > 127 && str[i] <= 255)
			nb++;
		if (!((MB_CUR_MAX <= 1 && str[i] > 255) ||
					(str[i] >= 0xD800 && str[i] <= 0xDFFF) ||
					str[i] > 0x10FFFF || str[i] < 0))
			nb += ft_putwlen(str[i]);
		i++;
	}
	return (nb);
}
