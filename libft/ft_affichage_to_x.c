/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_affichage_to_x.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 15:47:02 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 15:51:16 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_straddcarx(t_print *lst, int car, int len)
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
	if (lst->flagneg != 0 && (len == lst->taille || len + 2 == lst->taille))
		tmp = ft_strjoin(lst->tmp, str);
	else if (lst->flagneg == 0 || lst->taille != len)
		tmp = ft_strjoin(str, lst->tmp);
	else if (lst->flagneg != 0)
		tmp = ft_strjoin(str, lst->tmp);
	ft_strdel(&str);
	ft_strdel(&lst->tmp);
	lst->tmp = ft_strdup(tmp);
	ft_strdel(&tmp);
}

void	ft_addflag(t_print *lst)
{
	char *str;

	str = NULL;
	if (lst->flagdiece != 0 && ft_atoi(lst->tmp) != 0 &&
			(lst->format[lst->a] != 'u' || lst->format[lst->a] != 'U'))
	{
		if ((lst->format[lst->a] == 'o' || lst->format[lst->a] == 'O') &&
				lst->precision <= 0)
			str = ft_strjoin("0", lst->tmp);
		else if (lst->format[lst->a] != 'o' && lst->format[lst->a] != 'O')
			str = ft_strjoin("0x", lst->tmp);
		if (str)
		{
			ft_strdel(&lst->tmp);
			lst->tmp = ft_strdup(str);
			ft_strdel(&str);
		}
	}
}

void	ft_precision_to_x(t_print *lst)
{
	if (lst->precision > (int)ft_strlen(lst->tmp))
		ft_straddcarx(lst, '0', lst->precision);
	if (lst->flagdiece != 0 && lst->flagzero == 0)
		ft_addflag(lst);
	if (lst->taille > (int)ft_strlen(lst->tmp))
	{
		if (lst->flagdiece != 0 && lst->flagzero != 0 &&
				lst->flagzero != 0 && lst->precision == 0 && lst->flagneg == 0)
			ft_straddcarx(lst, '0', lst->taille - 2);
		else if (lst->flagneg != 0 && lst->flagzero != 0 && lst->flagdiece != 0)
			ft_straddcarx(lst, ' ', lst->taille - 2);
		else if (lst->flagzero != 0 && lst->precision == 0 && lst->flagneg == 0)
			ft_straddcarx(lst, '0', lst->taille);
		else
			ft_straddcarx(lst, ' ', lst->taille);
	}
	if (lst->flagdiece != 0 && lst->flagzero != 0)
		ft_addflag(lst);
}

void	ft_affichage_to_x(t_print *lst)
{
	int a;

	a = 0;
	if (lst->taille != 0 || lst->precision != 0 || lst->flagdiece != 0)
		ft_precision_to_x(lst);
	if (lst->format[lst->a] == 'X' || lst->format[lst->a] == 'O')
	{
		while (lst->tmp[a])
		{
			lst->tmp[a] = ft_toupper(lst->tmp[a]);
			a++;
		}
	}
	ft_putstr(lst->tmp);
	lst->a++;
	lst->nb = lst->nb + (int)ft_strlen(lst->tmp);
	ft_strdel(&lst->tmp);
}
