/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_string.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/06 13:59:26 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 16:46:27 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_straddcarunicodestring(t_print *lst, int car, int len, wchar_t *str)
{
	int		a;
	char	*tmp;
	int		i;

	i = 0;
	a = len - ft_strwlen(str);
	tmp = ft_strnew(a);
	while (i < a)
	{
		tmp[i] = car;
		i++;
	}
	if (lst->flagneg == 0 || lst->taille != len)
	{
		ft_putstr(tmp);
		ft_putwstr(str);
		lst->nb = lst->nb + (int)ft_strlen(tmp) + ft_strwlen(str);
	}
	else if (lst->flagneg != 0 && len == lst->taille)
	{
		ft_putwstr(str);
		ft_putstr(tmp);
		lst->nb = lst->nb + (int)ft_strlen(tmp) + ft_strwlen(str);
	}
	ft_strdel(&tmp);
}

void	ft_affichage_unicode_string(t_print *lst, wchar_t *str)
{
	if (lst->precision != 0 && lst->precision < ft_strwlen(str))
		ft_precision_unicode(lst, str);
	else if (lst->taille > ft_strwlen(str))
	{
		if (lst->flagzero != 0 && lst->flagneg == 0)
			ft_straddcarunicodestring(lst, '0', lst->taille, str);
		else
			ft_straddcarunicodestring(lst, ' ', lst->taille, str);
	}
	else
	{
		ft_putwstr(str);
		lst->nb = lst->nb + ft_strwlen(str);
	}
	lst->a++;
}

void	ft_unicode_string(t_print *lst, va_list ap)
{
	wchar_t *str;

	str = va_arg(ap, wchar_t *);
	if (str == NULL)
	{
		lst->tmp = ft_strdup("(null)");
		ft_modifieandwrite(lst);
		ft_affichage_to_string(lst);
	}
	else
		ft_affichage_unicode_string(lst, str);
}

void	ft_write(t_print *lst, va_list ap)
{
	lst->tmp = ft_strdup(va_arg(ap, char *));
	if (lst->tmp == NULL)
		lst->tmp = ft_strdup("(null)");
	ft_modifieandwrite(lst);
	ft_putstr(lst->tmp);
	lst->a++;
	lst->nb = lst->nb + (int)ft_strlen(lst->tmp);
	ft_strdel(&lst->tmp);
}

void	ft_string(t_print *lst, va_list ap)
{
	if (lst->format[lst->a] == 's' && lst->l == 0)
		ft_write(lst, ap);
	else
		ft_unicode_string(lst, ap);
}
