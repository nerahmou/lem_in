/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putwchar.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/18 11:50:02 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/10 14:01:46 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwchar(wchar_t c)
{
	int i;

	i = 0;
	if (c <= 0x7F)
		i += ft_putchar(c);
	else if (c <= 0x7FF)
	{
		i += ft_putchar(c >> 6 | 0xC0);
		i += ft_putchar((c & 0x3F) | 0x80);
	}
	else if (c <= 0xFFFF)
	{
		i += ft_putchar(c >> 12 | 0xE0);
		i += ft_putchar((c >> 6 & 0x3F) | 0x80);
		i += ft_putchar((c & 0x3F) | 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		i += ft_putchar(c >> 18 | 0xF0);
		i += ft_putchar((c >> 12 & 0x3F) | 0x80);
		i += ft_putchar((c >> 6 & 0x3F) | 0x80);
		i += ft_putchar((c & 0x3F) | 0x80);
	}
	return (i);
}
