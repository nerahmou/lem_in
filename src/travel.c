/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   travel.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/18 14:29:41 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 15:57:19 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

/*
 **-----------------algo when the start and the end are linked------------------
 */

void	go_direct(t_info *colonie)
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

/*
 **--------------------------algo for the shortest path-------------------------
 */

void	move_short(t_salle_2 **current, t_salle_2 *end, int index, int *ant_num)
{
	t_salle_2 *tmp;

	tmp = *current;
	if (tmp->index == index)
	{
		tmp->is_full--;
		tmp->next->is_full = ++(*ant_num) ;
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

void	go_short(t_info *colonie)
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

/*
 **--------------------------algo for the uniq paths----------------------------
 */

void	go_uniq(t_info *colonie)
{
	int			nb_ants;
	int			ant_num;
	int			nb_end;
	int			tour;
	int			i;
	t_chemins	*chemins_un;
	t_salle_2	*tmp;

	nb_ants = colonie->nb;
	ant_num = 0;
	nb_end = 0;
	colonie->chemins_un->salle->is_full = nb_ants;
	tour = 0;
	while (nb_end != nb_ants)
	{
		chemins_un = colonie->chemins_un;
		if (tour == (int)get_last_chemin(chemins_un)->length - 1)
			tour = 0;
		while (chemins_un)
		{
			i = 0;
			tmp = get_last_salle2(colonie->chemins_un->salle)->prev;
			while (i < tour/* && tmp*/)
			{
				tmp = tmp->prev;
				i++;
			}
			if (tmp->is_full)
			{
				if (tmp->index == colonie->start->index)
				{
					if (chemins_un->nb_tosend && colonie->chemins_un->salle->is_full)
					{
						chemins_un->nb_tosend--;
						colonie->chemins_un->salle->is_full--;
						tmp->next->is_full = ++ant_num;
						ft_printf("L%d-%s ", tmp->next->is_full, tmp->next->name);
					}
				}
				else
				{
					if (tmp->next->next == NULL)
						nb_end++;
					else
						tmp->next->is_full = tmp->is_full;
					ft_printf("L%d-%s ", tmp->is_full, tmp->next->name);
				}
			}
			chemins_un = chemins_un->next;
		}
		tour++;
		ft_putchar('\n');
	}

}

/*
 **-------select the uniq path which has the max number of moves------
 */

int	get_max_nbmov(t_chemins *chemins)
{
	t_chemins	*tmp;
	size_t		moves_max;

	tmp = NULL;
	moves_max = chemins->nb_tosend + (chemins->length - 2);
	if (chemins->next)
	{
		tmp = chemins->next;
		while (tmp)
		{
			if (tmp->nb_tosend + (tmp->length - 2) > moves_max)
				moves_max = tmp->nb_tosend + (tmp->length - 2);
			tmp = tmp->next;
		}
	}
	return ((int)moves_max);
}

/*
 **---function that will used to get the number of for all uniq paths and compare if
 **the uniq paths are better than the shortest---
 */

int	get_mov_uniq(t_chemins *chemins_un, int	nb_ants)
{
	t_chemins	*tmp;
	int		shortest;

	tmp = chemins_un;
	if (!chemins_un)
		return (-1);
	shortest = chemins_un->length - 1;
	nb_ants += shortest;
	while (nb_ants > shortest)
	{
		while (tmp && nb_ants > shortest)
		{
			if (nb_ants > (int)tmp->length - 1)
			{
				tmp->nb_tosend++;
				nb_ants--;
			}
			tmp = tmp->next;
		}
		tmp = chemins_un;
	}
	return (get_max_nbmov(chemins_un));
}

void	select_path(t_info *colonie)
{
	int	short_path_mov;
	int	shortest;
	int	nb_movements_uniq;

	shortest = colonie->chemins->length;
	short_path_mov = shortest - 2 + colonie->nb;
	nb_movements_uniq = get_mov_uniq(colonie->chemins_un, colonie->nb);
//	ft_print_chemins(colonie->chemins_un);
//	nb_movements_uniq = 10;
//	ft_printf("{%d} | {%d}\n", short_path_mov, nb_movements_uniq);
	if (shortest == 2)
		go_direct(colonie);
	else if (short_path_mov <= nb_movements_uniq)
		go_short(colonie);
	else
		;//go_uniq(colonie);
}
