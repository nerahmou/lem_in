/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   prints.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 19:15:10 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/03 18:50:19 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./lem-in.h"

void	ft_print_liaisons(t_salle *salle)
{
	t_salle *tmp;

	tmp = salle;
	ft_printf("\n\n*****************************--LIAISONS--*****************************\n\n");
	while (tmp != NULL)
	{
		ft_printf("ROOM : %s\n\n", tmp->name);
		while (tmp->co)
		{	
			ft_printf("\tLiaison : %s-%s\n", tmp->name, tmp->co->salle->name);
			tmp->co = tmp->co->next;
		}
		tmp = tmp->next;
	}
}

void	ft_print_list(t_info *colonie)
{
	t_salle *tmp;

	if (!colonie->salle)
		return ;
	tmp = colonie->salle;
	ft_printf("\n\n*****************************--ROOMS--*****************************\n\n");
	while (tmp != NULL)
	{
		ft_printf("Name : %s, index : %i, x = %i, y = %i\n", tmp->name, tmp->index, tmp->x, tmp->y);
		tmp = tmp->next;
	}
	ft_printf("start : %s, end : %s\n", colonie->start->name, colonie->end->name);
}
