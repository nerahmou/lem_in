/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/06 14:56:48 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 18:29:20 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlen(void *lst, void *(ptr)(void *))
{
	size_t length;
	void *tmp;

	length = 0;
	tmp = lst;
	while (tmp)
	{
		length++;
		tmp = ptr(tmp);
	}
	return (length);
}
