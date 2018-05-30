/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 14:55:16 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 14:55:16 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*a;

	i = 0;
	a = malloc(size);
	if (a == NULL)
		return (0);
	while (i < size)
	{
		((unsigned char*)a)[i] = 0;
		i++;
	}
	return (a);
}
