/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_c.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 15:28:42 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 16:17:16 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_carwrite(t_print *lst, va_list ap)
{
	int c;

	c = va_arg(ap, int);
	lst->tmp = ft_strnew(1);
	lst->tmp[0] = c;
	ft_precision_to_string(lst);
	if (c != 0)
		ft_putstr(lst->tmp);
	else
	{
		ft_putstr(lst->tmp + 1);
		ft_putchar(c);
		lst->nb = lst->nb + (int)ft_strlen(lst->tmp + 1);
	}
	lst->a++;
	if (c != 0)
		lst->nb = lst->nb + (int)ft_strlen(lst->tmp);
	else
		lst->nb++;
	ft_strdel(&lst->tmp);
}

void	ft_straddcarunicode(t_print *lst, int car, int len, wchar_t c)
{
	int		a;
	char	*str;
	int		i;

	i = 0;
	a = len - ft_putwlen(c);
	str = ft_strnew(a);
	while (i < a)
	{
		str[i] = car;
		i++;
	}
	if (lst->flagneg == 0 || lst->taille != len)
	{
		ft_putstr(str);
		ft_putwchar(c);
		lst->nb = lst->nb + (int)ft_strlen(str) + ft_putwlen(c);
	}
	else if (lst->flagneg != 0 && len == lst->taille)
	{
		ft_putwchar(c);
		ft_putstr(str);
		lst->nb = lst->nb + (int)ft_strlen(str) + ft_putwlen(c);
	}
	ft_strdel(&str);
}

void	ft_affichage_unicode(t_print *lst, wchar_t c)
{
	if (lst->taille > ft_putwlen(c))
	{
		if (lst->flagzero != 0 && lst->flagneg == 0)
			ft_straddcarunicode(lst, '0', lst->taille, c);
		else
			ft_straddcarunicode(lst, ' ', lst->taille, c);
	}
	else
	{
		ft_putwchar(c);
		lst->nb = lst->nb + ft_putwlen(c);
	}
	lst->a++;
}

void	ft_carunicode(t_print *lst, va_list ap)
{
	wchar_t c;

	c = va_arg(ap, wchar_t);
	if ((MB_CUR_MAX <= 1 && c > 255) || (c >= 0xD800 && c <= 0xDFFF)
			|| c > 0x10FFFF || c < 0)
	{
		lst->nb = -1;
		lst->a++;
	}
	else
		ft_affichage_unicode(lst, c);
}

void	ft_c(t_print *lst, va_list ap)
{
	if (lst->format[lst->a] == 'c' && lst->l == 0)
		ft_carwrite(lst, ap);
	else
		ft_carunicode(lst, ap);
}
