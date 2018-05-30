/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pourcent.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/06 11:31:01 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 16:46:25 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_straddcar_p(t_print *lst, int car, int len)
{
	int		a;
	char	*str;
	int		i;
	char	*tmp;

	i = 0;
	a = len - (int)ft_strlen(lst->tmp);
	str = ft_strnew(a + 1);
	while (i < a)
	{
		str[i] = car;
		i++;
	}
	if (lst->flagneg == 0 || lst->taille != len)
		tmp = ft_strjoin(str, lst->tmp);
	else if (lst->flagneg != 0 && len == lst->taille)
		tmp = ft_strjoin(lst->tmp, str);
	ft_strdel(&str);
	ft_strdel(&lst->tmp);
	lst->tmp = ft_strdup(tmp);
	ft_strdel(&tmp);
}

void	ft_addprefixe(t_print *lst)
{
	char *str;

	if (ft_atoi(lst->tmp) == 0 && lst->precision == -1)
		str = ft_strjoin("0x", "");
	else
		str = ft_strjoin("0x", lst->tmp);
	ft_strdel(&lst->tmp);
	lst->tmp = ft_strdup(str);
	ft_strdel(&str);
}

void	ft_modifieandwrite_p(t_print *lst)
{
	if (lst->precision != 0 && lst->precision > (int)ft_strlen(lst->tmp))
	{
		ft_straddcar_p(lst, '0', lst->precision);
	}
	if (lst->taille == 0)
		ft_addprefixe(lst);
	if (lst->taille > (int)ft_strlen(lst->tmp))
	{
		if (lst->flagzero != 0 && lst->precision == 0)
		{
			ft_straddcar_p(lst, '0', lst->taille - 2);
			ft_addprefixe(lst);
		}
		else
		{
			ft_addprefixe(lst);
			ft_straddcar_p(lst, ' ', lst->taille);
		}
	}
	else if (lst->taille != 0)
		ft_addprefixe(lst);
}

void	ft_pourcent(t_print *lst, va_list ap)
{
	uintmax_t a;

	if (lst->format[lst->a] == '%')
	{
		lst->tmp = ft_strdup("%");
		ft_affichage_to_string(lst);
	}
	else if (lst->format[lst->a] == 'p')
	{
		a = va_arg(ap, uintmax_t);
		if (a == 0)
			lst->tmp = ft_strdup("0");
		else
			lst->tmp = ft_itoa_base(a, 16);
		ft_modifieandwrite_p(lst);
		ft_affichage_to_string(lst);
	}
}
