/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_o.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 15:57:27 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 18:03:08 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_oflagother_suite(t_print *lst, va_list ap)
{
	unsigned long int		c;
	unsigned long long int	d;

	if (lst->l == 1)
	{
		c = va_arg(ap, unsigned long int);
		lst->tmp = ft_itoa_base((uintmax_t)c, 8);
	}
	else if (lst->l > 1)
	{
		d = va_arg(ap, unsigned long long int);
		lst->tmp = ft_itoa_base((uintmax_t)d, 8);
	}
}

void	ft_oflagother(t_print *lst, va_list ap)
{
	unsigned short int		a;
	unsigned char			b;

	if (lst->h == 1)
	{
		a = (unsigned short int)va_arg(ap, unsigned int);
		lst->tmp = ft_itoa_base((uintmax_t)a, 8);
	}
	else if (lst->h > 1)
	{
		b = (unsigned char)va_arg(ap, unsigned int);
		lst->tmp = ft_itoa_base((uintmax_t)b, 8);
	}
	else if (lst->l != 0)
		ft_oflagother_suite(lst, ap);
}

int		ft_oflag(t_print *lst, va_list ap)
{
	uintmax_t	a;

	if (lst->h > 0)
	{
		ft_oflagother(lst, ap);
		return (1);
	}
	else if (lst->l > 0)
	{
		ft_oflagother(lst, ap);
		return (1);
	}
	else if (lst->z > 0)
	{
		lst->sz = va_arg(ap, size_t);
		lst->tmp = ft_itoa_base((uintmax_t)lst->sz, 8);
		return (1);
	}
	else if (lst->j > 0)
	{
		a = va_arg(ap, uintmax_t);
		lst->tmp = ft_itoa_base((uintmax_t)a, 8);
		return (1);
	}
	return (0);
}

void	ft_o_suite(t_print *lst, va_list ap)
{
	lst->tmp = ft_strdup(ft_itoa_base((uintmax_t)
				va_arg(ap, unsigned long int), 8));
	if (lst->precision != -1 || lst->flagdiece != 0)
		ft_affichage_to_x(lst);
	else if (lst->taille != 0 && lst->precision == -1)
		ft_execption(lst);
	else
		lst->a++;
}

void	ft_o(t_print *lst, va_list ap)
{
	if (lst->format[lst->a] == 'o')
	{
		if (ft_oflag(lst, ap) == 1)
			ft_affichage_to_x(lst);
		else
		{
			lst->tmp = ft_itoa_base((uintmax_t)
					va_arg(ap, unsigned int), 8);
			if (lst->precision != -1 || ft_atoi(lst->tmp) != 0
					|| lst->flagdiece != 0)
				ft_affichage_to_x(lst);
			else if (lst->taille != 0 && lst->precision == -1)
				ft_execption(lst);
			else
				lst->a++;
		}
	}
	else
		ft_o_suite(lst, ap);
}
