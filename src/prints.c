/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   prints.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 19:15:10 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/12 19:16:04 by nerahmou    ###    #+. /#+    ###.fr     */
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
		ft_printf("Name : %s, index : %i, x = %i, y = %i\n", tmp->name,
				tmp->index, tmp->x, tmp->y);
		tmp = tmp->next;
	}
	ft_printf("start : %s, end : %s\n", colonie->start->name,
			colonie->end->name);
}

void	ft_print_chemins(t_chemins *chemin)
{
	t_chemins	*tmp_ch;
	t_salle_2	*tmp_salle;
	int			i;

	i = 0;
	tmp_ch = chemin;
	ft_printf("\n\n*****************************--CHEMINS--*****************************\n\n");
	while (tmp_ch != NULL)
	{
		i++;
		tmp_salle = tmp_ch->salle;
		ft_printf("LENGTH : [%zu]  | NB_CONNECT : {%zu} ", tmp_ch->length, tmp_ch->nb_connections);
		while (tmp_salle)
		{
			ft_printf("[%s] --->  ", tmp_salle->name);
			tmp_salle = tmp_salle->next;
		}
		ft_printf("[NULL]\n\n");
		tmp_ch = tmp_ch->next;
	}
	ft_printf("Nombre de chemins : (%i)\n", i);
}
