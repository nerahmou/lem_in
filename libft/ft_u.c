/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_u.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/06 10:32:10 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 18:06:30 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_uflagother(t_print *lst, va_list ap)
{
	unsigned short int		a;
	unsigned char			b;
	unsigned long int		c;
	unsigned long long int	d;

	if (lst->h == 1)
	{
		a = (unsigned short int)va_arg(ap, unsigned int);
		lst->tmp = ft_itoa((uintmax_t)a);
	}
	else if (lst->h > 1)
	{
		b = (unsigned char)va_arg(ap, unsigned int);
		lst->tmp = ft_uitoa((uintmax_t)b);
	}
	else if (lst->l == 1)
	{
		c = va_arg(ap, unsigned long int);
		lst->tmp = ft_uitoa((uintmax_t)c);
	}
	else if (lst->l > 1)
	{
		d = va_arg(ap, unsigned long long int);
		lst->tmp = ft_uitoa((uintmax_t)d);
	}
}

int		ft_uflag(t_print *lst, va_list ap)
{
	uintmax_t	a;

	if (lst->h > 0)
	{
		ft_uflagother(lst, ap);
		return (1);
	}
	else if (lst->l > 0)
	{
		ft_uflagother(lst, ap);
		return (1);
	}
	else if (lst->z > 0)
	{
		lst->sz = va_arg(ap, size_t);
		lst->tmp = ft_uitoa((uintmax_t)lst->sz);
		return (1);
	}
	else if (lst->j > 0)
	{
		a = va_arg(ap, uintmax_t);
		lst->tmp = ft_uitoa((uintmax_t)a);
		return (1);
	}
	return (0);
}

void	ft_u_suite(t_print *lst, va_list ap)
{
	lst->tmp = ft_uitoa((uintmax_t)
			va_arg(ap, unsigned long int));
	if (lst->precision != -1)
		ft_affichage_to_x(lst);
	else
		lst->a++;
}

void	ft_u(t_print *lst, va_list ap)
{
	if (lst->format[lst->a] == 'u')
	{
		if (ft_uflag(lst, ap) == 1)
			ft_affichage_to_x(lst);
		else
		{
			lst->tmp = ft_uitoa((uintmax_t)
					va_arg(ap, unsigned int));
			if (lst->precision != -1)
				ft_affichage_to_x(lst);
			else
				lst->a++;
		}
	}
	else
		ft_u_suite(lst, ap);
}
