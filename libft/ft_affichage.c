/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_affichage.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 17:50:34 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 17:22:46 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_replace(t_print *lst)
{
	int a;

	a = 0;
	while (lst->tmp[a] != '\0')
	{
		if (lst->tmp[a] == '-')
		{
			lst->tmp[a] = '0';
			lst->tmp[0] = '-';
		}
		a++;
	}
}

void	ft_straddcar(t_print *lst, int car, int len)
{
	int		a;
	char	*str;
	int		i;
	char	*tmp;

	i = 0;
	a = len - (int)ft_strlen(lst->tmp);
	str = ft_strnew(a);
	if (lst->flagplus > 0 && lst->flagzero != 0 && ft_atoi(lst->tmp) >= 0)
		a--;
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

void	ft_addplus(t_print *lst)
{
	char *str;

	if (ft_strchr(lst->tmp, '-') == NULL)
	{
		str = ft_strjoin("+", lst->tmp);
		ft_strdel(&lst->tmp);
		lst->tmp = ft_strdup(str);
		ft_strdel(&str);
	}
}

void	ft_precisiontoint(t_print *lst)
{
	if (lst->precision > (int)ft_strlen(lst->tmp))
	{
		if (lst->tmp[0] == '-')
			ft_straddcar(lst, '0', lst->precision + 1);
		else
			ft_straddcar(lst, '0', lst->precision);
		if (lst->flagzero == 0)
			ft_replace(lst);
	}
	if (lst->flagplus != 0 && lst->flagzero == 0)
		ft_addplus(lst);
	if (lst->taille > (int)ft_strlen(lst->tmp))
		ft_aff_suite(lst);
	if (lst->flagzero != 0)
		ft_replace(lst);
	if (lst->flagplus != 0 && lst->flagzero != 0)
		ft_addplus(lst);
}

void	ft_affichage(t_print *lst)
{
	if (lst->taille != 0 || lst->precision != 0 || lst->flagplus != 0)
		ft_precisiontoint(lst);
	else if (lst->flagspace > 0 && ft_atoi(lst->tmp) > 0)
		ft_straddcar(lst, ' ', ((int)ft_strlen(lst->tmp) + 1));
	ft_putstr(lst->tmp);
	lst->a++;
	lst->nb = lst->nb + (int)ft_strlen(lst->tmp);
	ft_strdel(&lst->tmp);
}
