/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   send_ants.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 15:09:32 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/28 15:14:03 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void		go_direct(t_info *colonie)
{
	int	nb_ants;

	nb_ants = 1;
	while (colonie->nb)
	{
		ft_printf("L%d-%s ", nb_ants++, colonie->chemins->salle->next->name);
		colonie->nb--;
	}
	ft_putchar('\n');
}

void		move_short(t_salle_2 **current, t_salle_2 *end, int index,
		int *ant_num)
{
	t_salle_2 *tmp;

	tmp = *current;
	if (tmp->index == index)
	{
		tmp->is_full--;
		tmp->next->is_full = ++(*ant_num);
		ft_printf("L%d-%s ", tmp->next->is_full, tmp->next->name);
	}
	else
	{
		if (tmp->next == end)
			tmp->next->is_full++;
		else
			tmp->next->is_full = tmp->is_full;
		ft_printf("L%d-%s ", tmp->is_full, tmp->next->name);
	}
}

void		go_short(t_info *colonie)
{
	int			nb_ants;
	int			ant_num;
	t_salle_2	*end;
	t_salle_2	*tmp;

	nb_ants = colonie->nb;
	ant_num = 0;
	end = get_last_salle2(colonie->chemins->salle);
	tmp = end->prev;
	colonie->chemins->salle->is_full = nb_ants;
	while (end->is_full != nb_ants)
	{
		while (tmp && end->is_full != nb_ants)
		{
			if (tmp->is_full)
				move_short(&tmp, end, colonie->start->index, &ant_num);
			tmp = tmp->prev;
		}
		tmp = end->prev;
		ft_putchar('\n');
	}
}
