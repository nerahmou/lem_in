/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_x.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 16:01:58 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 15:32:13 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_xflagother(t_print *lst, va_list ap)
{
	unsigned short int		a;
	unsigned char			b;
	unsigned long int		c;
	unsigned long long int	d;

	if (lst->h == 1)
	{
		a = (unsigned short int)va_arg(ap, unsigned int);
		lst->tmp = ft_itoa_base((uintmax_t)a, 16);
	}
	else if (lst->h > 1)
	{
		b = (unsigned char)va_arg(ap, unsigned int);
		lst->tmp = ft_itoa_base((uintmax_t)b, 16);
	}
	else if (lst->l == 1)
	{
		c = va_arg(ap, unsigned long int);
		lst->tmp = ft_itoa_base((uintmax_t)c, 16);
	}
	else if (lst->l > 1)
	{
		d = va_arg(ap, unsigned long long int);
		lst->tmp = ft_itoa_base((uintmax_t)d, 16);
	}
}

int		ft_xflag(t_print *lst, va_list ap)
{
	uintmax_t	a;

	if (lst->h > 0)
	{
		ft_xflagother(lst, ap);
		return (1);
	}
	else if (lst->l > 0)
	{
		ft_xflagother(lst, ap);
		return (1);
	}
	else if (lst->z > 0)
	{
		lst->sz = va_arg(ap, size_t);
		lst->tmp = ft_itoa_base((uintmax_t)lst->sz, 16);
		return (1);
	}
	else if (lst->j > 0)
	{
		a = va_arg(ap, uintmax_t);
		lst->tmp = ft_itoa_base((uintmax_t)a, 16);
		return (1);
	}
	return (0);
}

void	ft_execption(t_print *lst)
{
	ft_strdel(&lst->tmp);
	lst->tmp = ft_strdup("");
	ft_affichage_to_x(lst);
}

void	ft_x(t_print *lst, va_list ap)
{
	if (lst->format[lst->a] == 'x' || lst->format[lst->a] == 'X')
	{
		if (ft_xflag(lst, ap) == 1)
			ft_affichage_to_x(lst);
		else
		{
			lst->tmp = ft_itoa_base((uintmax_t)
						va_arg(ap, unsigned int), 16);
			if (lst->precision != -1)
				ft_affichage_to_x(lst);
			else if (lst->taille != 0 && lst->precision == -1)
				ft_execption(lst);
			else
				lst->a++;
		}
	}
}
