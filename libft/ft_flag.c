/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flag.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 16:03:12 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 17:45:02 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_precision(t_print *lst)
{
	if (lst->format[lst->a] > '0' && lst->format[lst->a] <= '9')
	{
		lst->taille = ft_atoi(lst->format + lst->a);
		return (1);
	}
	else if (lst->format[lst->a] == '.')
	{
		lst->precision = ft_atoi(lst->format + lst->a + 1);
		if (lst->precision == 0)
			lst->precision = -1;
		return (1);
	}
	return (0);
}

int	ft_length(t_print *lst)
{
	if (lst->format[lst->a] == 'h')
	{
		lst->h++;
		return (1);
	}
	else if (lst->format[lst->a] == 'l')
	{
		lst->l++;
		return (1);
	}
	else if (lst->format[lst->a] == 'j')
	{
		lst->j++;
		return (1);
	}
	else if (lst->format[lst->a] == 'z')
	{
		lst->z++;
		return (1);
	}
	return (0);
}

int	ft_flag(t_print *lst)
{
	if (lst->format[lst->a] == '-')
	{
		lst->flagneg++;
		return (1);
	}
	if (lst->format[lst->a] == '#')
	{
		lst->flagdiece++;
		return (1);
	}
	if (ft_flag_suite(lst) == 1)
		return (1);
	return (0);
}
