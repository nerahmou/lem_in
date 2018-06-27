/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   travel.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/18 14:29:41 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/27 20:34:28 by edbernie    ###    #+. /#+    ###.fr     */
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

t_salle_2	*on_salle(t_chemins *chemin, int line)
{
	t_salle_2	*tmp;
	t_chemins	*che;
	int			i;

	i = 0;
	che = chemin;
	tmp = che->salle;
	while (tmp->next && i != line)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}

int			check_end(t_chemins *chemin, int nb)
{
	t_chemins	*tmp;
	t_salle_2	*salle;
	int			i;

	i = 0;
	tmp = chemin;
	while (tmp)
	{
		salle = tmp->salle;
		while (salle->next)
			salle = salle->next;
		if (salle->is_full > i)
			i = salle->is_full;
		tmp = tmp->next;
	}
	if (i < nb)
		return (1);
	return (0);
}

char		*add_res(int i, char *name, char *res)
{
	char *dst;
	char *tmp;

	tmp = ft_itoa(i);
	dst = ft_strjoin("L", tmp);
	ft_strdel(&tmp);
	tmp = ft_strdup(dst);
	ft_strdel(&dst);
	dst = ft_strjoin(tmp, "-");
	ft_strdel(&tmp);
	tmp = ft_strdup(dst);
	ft_strdel(&dst);
	dst = ft_strjoin(tmp, name);
	ft_strdel(&tmp);
	tmp = ft_strdup(dst);
	ft_strdel(&dst);
	dst = ft_strjoin(tmp, " ");
	ft_strdel(&tmp);
	tmp = ft_strdup(dst);
	ft_strdel(&dst);
	dst = ft_strjoin(res, tmp);
	ft_strdel(&tmp);
	ft_strdel(&res);
	return (dst);
}

char		*move_ants(t_chemins *chemin, int line)
{
	t_salle_2	*salle;
	t_chemins	*tmp;
	char		*str;
	int			i;

	i = line + 1;
	tmp = chemin;
	str = ft_strdup("");
	while (--i != 0)
	{
		tmp = chemin;
		while (tmp)
		{
			salle = on_salle(tmp, i);
			if (salle->next && salle->is_full != 0)
			{
				salle->next->is_full = salle->is_full;
				salle->is_full = 0;
				salle = salle->next;
				str = add_res(salle->is_full, salle->name, str);
			}
			tmp = tmp->next;
		}
	}
	return (str);
}

void		ft_aff_and_fr(char *str)
{
	char	*tmp;
	char	*res;

	tmp = ft_strdup(str);
	res = ft_strtrim(tmp);
	ft_putstr(res);
	ft_strdel(&res);
	ft_strdel(&tmp);
}

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
	ft_print_chemins(colonie->chemins_un);
	ft_printf("{%d} | {%d}\n", short_path_mov, nb_movements_uniq);
	if (shortest == 2)
		go_direct(colonie);
	else if (short_path_mov <= nb_movements_uniq)
		go_short(colonie);
	else
		go_uniq(colonie);
}
