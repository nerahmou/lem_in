/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnwstr.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/10 15:19:35 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 16:01:03 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnwstr(wchar_t *str, int a)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (str[i] && (nb + ft_putwlen(str[i])) <= a)
	{
		if (MB_CUR_MAX <= 1 && str[i] > 127 && str[i] <= 255)
			nb += write(1, &str[i], 1);
		if (!((MB_CUR_MAX <= 1 && str[i] > 255) ||
					(str[i] >= 0xD800 && str[i] <= 0xDFFF) ||
					str[i] > 0x10FFFF || str[i] < 0))
			nb += ft_putwchar(str[i]);
		i++;
	}
	return (nb);
}
