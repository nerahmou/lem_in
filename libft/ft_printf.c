/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 15:53:07 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 15:32:58 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_initialize(t_print *lst)
{
	lst->flagplus = 0;
	lst->flagneg = 0;
	lst->flagzero = 0;
	lst->flagspace = 0;
	lst->flagdiece = 0;
	lst->taille = 0;
	lst->precision = 0;
	lst->h = 0;
	lst->l = 0;
	lst->j = 0;
	lst->z = 0;
}

void	ft_check(t_print *lst, va_list ap)
{
	lst->a++;
	ft_initialize(lst);
	while (ft_flag(lst) != 0)
		lst->a++;
	while (ft_precision(lst) != 0)
		ft_check_suite(lst);
	while (ft_length(lst) != 0)
		lst->a++;
	ft_conversion(lst, ap);
}

int		ft_read(t_print *lst, va_list ap)
{
	lst->a = 0;
	while (lst->format[lst->a])
	{
		if (lst->format[lst->a] == '%')
		{
			ft_check(lst, ap);
		}
		else
		{
			lst->nb += ft_putwchar((wchar_t)lst->format[lst->a]);
			lst->a++;
		}
	}
	return (lst->nb);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	t_print	lst;

	lst.nb = 0;
	lst.a = 0;
	ft_initialize(&lst);
	lst.format = ft_strdup(format);
	va_start(ap, format);
	lst.nb = ft_read(&lst, ap);
	va_end(ap);
	ft_strdel(&lst.format);
	return (lst.nb);
}
