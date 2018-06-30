/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   send_ants.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 15:09:32 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/30 16:04:48 by nerahmou    ###    #+. /#+    ###.fr     */
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
		ft_printf("L%d-%s", nb_ants++, colonie->chemins->salle->next->name);
		if (colonie->nb > 1)
			ft_putchar(' ');
		colonie->nb--;
	}
	ft_putchar('\n');
}

void		move_short(t_salle_2 **current, t_salle_2 *end, int index,
		int **ant_num)
{
	t_salle_2 *tmp;

	tmp = *current;
	if (tmp->index == index)
	{
		tmp->is_full--;
		tmp->next->is_full = ++(**ant_num);
		ft_printf("L%d-%s", tmp->next->is_full, tmp->next->name);
	}
	else
	{
		if (tmp->next == end)
			tmp->next->is_full++;
		else
			tmp->next->is_full = tmp->is_full;
		ft_printf("L%d-%s", tmp->is_full, tmp->next->name);
		tmp->is_full = 0;
	}
}

int			get_whitespaces(t_salle_2 *salle)
{
	t_salle_2	*tmp;
	int			i;

	tmp = salle;
	i = 0;
	while (tmp)
	{
		if (tmp->is_full)
			i++;
		tmp = tmp->prev;
	}
	return (i);
}

int			is_full(t_salle_2 *tmp, t_salle_2 *end, int index, int *ant_num)
{
	if (tmp->is_full)
	{
		move_short(&tmp, end, index, &ant_num);
		return (1);
	}
	return (0);
}

void		go_short(t_info *colonie)
{
	int			nb_ants;
	int			ant_num;
	t_salle_2	*end;
	t_salle_2	*tmp;
	int			spaces;

	nb_ants = colonie->nb;
	ant_num = 0;
	end = get_last_salle2(colonie->chemins->salle);
	tmp = end->prev;
	colonie->chemins->salle->is_full = nb_ants;
	while (end->is_full != nb_ants)
	{
		spaces = get_whitespaces(tmp);
		while (tmp && end->is_full != nb_ants)
		{
			if (is_full(tmp, end, colonie->start->index, &ant_num)
					&& --spaces > 0)
				ft_putchar(' ');
			tmp = tmp->prev;
		}
		tmp = end->prev;
		ft_putchar('\n');
	}
}
