/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_aff_suite.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 17:14:29 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/29 20:05:39 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_flag_suite(t_print *lst)
{
	if (lst->format[lst->a] == '+')
	{
		lst->flagplus++;
		return (1);
	}
	if (lst->format[lst->a] == ' ')
	{
		lst->flagspace++;
		return (1);
	}
	if (lst->format[lst->a] == '0')
	{
		lst->flagzero++;
		return (1);
	}
	return (0);
}

void	ft_check_suite(t_print *lst)
{
	if (lst->precision != 0)
	{
		if (lst->precision == -1)
		{
			if (lst->format[lst->a + 1] == '0')
				lst->a = lst->a + 2;
			else
				lst->a++;
		}
		else
		{
			lst->a = lst->a + 1 +
				(int)ft_strlen(lst->str = ft_itoa((intmax_t)lst->precision));
			ft_strdel(&lst->str);
		}
	}
	else if (lst->taille != 0)
	{
		lst->a = lst->a +
			(int)ft_strlen(lst->str = ft_itoa((intmax_t)lst->taille));
		ft_strdel(&lst->str);
	}
	else
		lst->a = lst->a + 2;
}

void	ft_aff_suite(t_print *lst)
{
	if (lst->flagzero > 0 && lst->flagneg == 0 &&
			lst->flagplus == 0 && lst->precision == 0)
	{
		if (lst->flagspace > 0)
		{
			ft_straddcar(lst, '0', lst->taille - 1);
			ft_straddcar(lst, ' ', lst->taille);
		}
		else
			ft_straddcar(lst, '0', lst->taille);
	}
	else if (lst->flagplus > 0 && lst->flagzero != 0)
		ft_straddcar(lst, '0', lst->taille);
	else
		ft_straddcar(lst, ' ', lst->taille);
}
