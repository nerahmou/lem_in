/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_justtaille.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/09 15:31:20 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 15:54:57 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_strjustaddcar(t_print *lst, int car, int len)
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
	if (lst->flagneg == 0 || lst->taille != len)
		tmp = ft_strjoin(str, lst->tmp);
	else if (lst->flagneg != 0 && len == lst->taille)
		tmp = ft_strjoin(lst->tmp, str);
	ft_strdel(&str);
	ft_strdel(&lst->tmp);
	lst->tmp = ft_strdup(tmp);
	ft_strdel(&tmp);
}

void	ft_justtaille(t_print *lst)
{
	lst->tmp = ft_strdup("");
	if (lst->flagneg != 0)
	{
		ft_putchar(lst->format[lst->a]);
		lst->a++;
		lst->nb++;
	}
	if (lst->flagzero != 0)
		ft_strjustaddcar(lst, '0', lst->taille - 1);
	else
		ft_strjustaddcar(lst, ' ', lst->taille - 1);
	ft_putstr(lst->tmp);
	lst->nb = lst->nb + (int)ft_strlen(lst->tmp);
}
