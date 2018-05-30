/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putendl_fd.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 14:55:18 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 14:55:18 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int a;

	a = 0;
	if (s)
	{
		while (s[a])
		{
			ft_putchar_fd(s[a], fd);
			a++;
		}
		ft_putchar_fd('\n', fd);
	}
}
