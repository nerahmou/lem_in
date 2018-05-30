/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flagh.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 15:46:36 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 15:46:45 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_flagh_d(t_print *lst, va_list ap)
{
	long int		c;
	long long int	d;

	if (lst->h == 1)
	{
		d = va_arg(ap, long long int);
		lst->tmp = ft_itoa((intmax_t)d);
	}
	else if (lst->h > 1)
	{
		d = va_arg(ap, long long int);
		lst->tmp = ft_itoa((intmax_t)d);
	}
	else if (lst->l == 1)
	{
		c = va_arg(ap, long int);
		lst->tmp = ft_itoa((intmax_t)c);
	}
	else if (lst->l > 1)
	{
		d = va_arg(ap, long long int);
		lst->tmp = ft_itoa((intmax_t)d);
	}
}

void	ft_flagh(t_print *lst, va_list ap)
{
	short int		a;
	signed char		b;
	long int		c;
	long long int	d;

	if (lst->h == 1)
	{
		a = (short int)va_arg(ap, int);
		lst->tmp = ft_itoa((intmax_t)a);
	}
	else if (lst->h > 1)
	{
		b = (signed char)va_arg(ap, int);
		lst->tmp = ft_itoa((intmax_t)b);
	}
	else if (lst->l == 1)
	{
		c = va_arg(ap, long int);
		lst->tmp = ft_itoa((intmax_t)c);
	}
	else if (lst->l > 1)
	{
		d = va_arg(ap, long long int);
		lst->tmp = ft_itoa((intmax_t)d);
	}
}
