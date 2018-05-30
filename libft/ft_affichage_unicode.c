/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_affichage_unicode.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/10 15:16:20 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 15:40:25 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_straddcarprecision(t_print *lst, int car, int len, wchar_t *str)
{
	int		a;
	char	*tmp;
	int		i;

	i = 0;
	a = len - ft_strnwlen(str, lst->precision);
	tmp = ft_strnew(a);
	while (i < a)
	{
		tmp[i] = car;
		i++;
	}
	if (lst->flagneg == 0 || lst->taille != len)
	{
		ft_putstr(tmp);
		lst->nb = lst->nb + (int)ft_strlen(tmp) +
			ft_putnwstr(str, lst->precision);
	}
	else if (lst->flagneg != 0 && len == lst->taille)
	{
		lst->nb = lst->nb + (int)ft_strlen(tmp) +
			ft_putnwstr(str, lst->precision);
		ft_putstr(tmp);
	}
	ft_strdel(&tmp);
}

void	ft_precision_unicode(t_print *lst, wchar_t *str)
{
	if (lst->taille > ft_strnwlen(str, lst->precision))
	{
		if (lst->flagzero != 0 && lst->flagneg == 0)
			ft_straddcarprecision(lst, '0', lst->taille, str);
		else
			ft_straddcarprecision(lst, ' ', lst->taille, str);
	}
	else
		lst->nb = lst->nb + ft_putnwstr(str, lst->precision);
}
