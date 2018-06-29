/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   travel.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/18 14:29:41 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 16:31:15 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_send_ants(t_info *colonie, int line, int i)
{
	t_salle_2	*salle;
	t_chemins	*tmp;
	char		*res;

	tmp = colonie->chemins_un;
	res = move_ants(tmp, line);
	while (tmp)
	{
		salle = on_salle(tmp, 0);
		salle = salle->next;
		if (i <= colonie->nb)
		{
			salle->is_full = i;
			res = add_res(salle->is_full, salle->name, res);
			i++;
		}
		tmp = tmp->next;
	}
	ft_aff_and_fr(res);
	if (res)
		ft_strdel(&res);
	return (i);
}

void		go_uniq(t_info *colonie)
{
	int			i;
	int			line;
	t_chemins	*tmp;

	i = 1;
	line = 0;
	tmp = colonie->chemins_un;
	while (check_end(colonie->chemins_un, colonie->nb))
	{
		i = ft_send_ants(colonie, line, i);
		line++;
		ft_putchar('\n');
	}
}

int			get_max_nbmov(t_chemins *chemins)
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

int			get_mov_uniq(t_chemins *chemins_un, int nb_ants)
{
	t_chemins	*tmp;
	int			shortest;

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

void		select_path(t_info *colonie)
{
	int	short_path_mov;
	int	shortest;
	int	nb_movements_uniq;

	shortest = colonie->chemins->length;
	short_path_mov = shortest - 2 + colonie->nb;
	nb_movements_uniq = get_mov_uniq(colonie->chemins_un, colonie->nb);
	if (shortest == 2)
		go_direct(colonie);
	else if (short_path_mov <= nb_movements_uniq)
		go_short(colonie);
	else
		go_uniq(colonie);
}
