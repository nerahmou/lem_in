/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_int.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 15:52:22 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 17:52:01 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_intflag(t_print *lst, va_list ap)
{
	if (lst->h > 0)
	{
		ft_flagh(lst, ap);
		return (1);
	}
	else if (lst->l > 0)
	{
		ft_flagh(lst, ap);
		return (1);
	}
	else if (lst->z > 0)
	{
		lst->sz = va_arg(ap, size_t);
		lst->tmp = ft_itoa((intmax_t)lst->sz);
		return (1);
	}
	else if (lst->j > 0)
	{
		lst->i = va_arg(ap, intmax_t);
		lst->tmp = ft_itoa(lst->i);
		return (1);
	}
	return (0);
}

int		ft_int_d_flag(t_print *lst, va_list ap)
{
	if (lst->h > 0)
	{
		ft_flagh_d(lst, ap);
		return (1);
	}
	else if (lst->l > 0)
	{
		ft_flagh_d(lst, ap);
		return (1);
	}
	else if (lst->z > 0)
	{
		lst->sz = va_arg(ap, size_t);
		lst->tmp = ft_itoa((intmax_t)lst->sz);
		return (1);
	}
	else if (lst->j > 0)
	{
		lst->i = va_arg(ap, intmax_t);
		lst->tmp = ft_itoa(lst->i);
		return (1);
	}
	return (0);
}

void	ft_int(t_print *lst, va_list ap)
{
	if (lst->format[lst->a] != 'D')
	{
		if (ft_intflag(lst, ap) == 1)
			ft_affichage(lst);
		else
		{
			lst->tmp = ft_itoa((intmax_t)va_arg(ap, int));
			if (lst->precision != -1)
				ft_affichage(lst);
			else if (lst->taille != 0 && lst->precision == -1)
				ft_execption(lst);
			else if (lst->precision == -1 && ft_atoi(lst->tmp) != 0)
				ft_affichage(lst);
			else
				lst->a++;
		}
	}
	else if (lst->format[lst->a] == 'D')
	{
		lst->tmp = ft_itoa((intmax_t)va_arg(ap, long long int));
		ft_affichage(lst);
	}
}
