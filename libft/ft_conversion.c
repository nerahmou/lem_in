/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_conversion.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 15:44:24 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 16:29:41 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_conversion(t_print *lst, va_list ap)
{
	if (lst->format[lst->a] == 'i' || lst->format[lst->a] == 'd'
			|| lst->format[lst->a] == 'D')
		ft_int(lst, ap);
	else if (lst->format[lst->a] == 'x' || lst->format[lst->a] == 'X')
		ft_x(lst, ap);
	else if (lst->format[lst->a] == 'o' || lst->format[lst->a] == 'O')
		ft_o(lst, ap);
	else if (lst->format[lst->a] == 'u' || lst->format[lst->a] == 'U')
		ft_u(lst, ap);
	else if (lst->format[lst->a] == 'S' || lst->format[lst->a] == 's')
		ft_string(lst, ap);
	else if (lst->format[lst->a] == 'c' || lst->format[lst->a] == 'C')
		ft_c(lst, ap);
	else if (lst->format[lst->a] == '%' || lst->format[lst->a] == 'p')
		ft_pourcent(lst, ap);
	else if (lst->taille != 0)
		ft_justtaille(lst);
}
