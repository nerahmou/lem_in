/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putendl.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 14:55:18 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 14:55:18 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	int a;

	a = 0;
	if (s)
	{
		while (s[a])
		{
			ft_putchar(s[a]);
			a++;
		}
		ft_putchar('\n');
	}
}
