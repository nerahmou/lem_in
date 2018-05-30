/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_affichage_string.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/06 11:33:32 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 15:41:00 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_straddcarstring(t_print *lst, int car, int len)
{
	int		a;
	char	*str;
	int		i;
	char	*tmp;

	i = 0;
	a = len - (int)ft_strlen(lst->tmp);
	str = ft_strnew(a);
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

void	ft_precision_to_string(t_print *lst)
{
	if (lst->taille > (int)ft_strlen(lst->tmp))
	{
		if (lst->flagzero != 0)
			ft_straddcarstring(lst, '0', lst->taille);
		else
			ft_straddcarstring(lst, ' ', lst->taille);
	}
}

void	ft_modifieandwrite(t_print *lst)
{
	char *str;

	if (lst->precision != 0 && lst->precision < (int)ft_strlen(lst->tmp))
	{
		str = ft_strndup(lst->tmp, lst->precision);
		ft_strdel(&lst->tmp);
		lst->tmp = ft_strdup(str);
		ft_strdel(&str);
	}
	if (lst->taille > (int)ft_strlen(lst->tmp))
	{
		if (lst->flagzero != 0)
			ft_straddcarstring(lst, '0', lst->taille);
		else
			ft_straddcarstring(lst, ' ', lst->taille);
	}
}

void	ft_affichage_to_string(t_print *lst)
{
	if (lst->taille != 0 && lst->format[lst->a] != 'p')
		ft_precision_to_string(lst);
	ft_putstr(lst->tmp);
	lst->a++;
	lst->nb = lst->nb + (int)ft_strlen(lst->tmp);
	ft_strdel(&lst->tmp);
}
