/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checkers.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 14:57:32 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/28 15:09:02 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

int		check_min(t_info *colonie)
{
	if (ft_lstlen(colonie->salle, get_next_salle) < 2)
		ft_error(colonie);
	if (!colonie->start || !colonie->end)
		ft_error(colonie);
	colonie->chemins = get_paths(colonie);
	if (!ft_lstlen(colonie->chemins, &get_next_chemin))
		ft_error(colonie);
	ft_printf("%s\n\n", colonie->text);
	select_path(colonie);
	return (0);
}

int		duplicate_room(t_info *colonie)
{
	t_salle	*head;
	t_salle	*tmp;

	tmp = colonie->salle;
	while (tmp)
	{
		head = colonie->salle;
		tmp = tmp->next;
		while (tmp && head)
		{
			if (ft_strcmp(tmp->name, head->name) == 0 && tmp != head)
				return (1);
			if (tmp->x == head->x && tmp->y == head->y && tmp != head)
				return (1);
			head = head->next;
		}
	}
	return (0);
}

int		room_exist(t_salle *salle, char *tab)
{
	while (salle)
	{
		if (!ft_strcmp(salle->name, tab))
			return (0);
		salle = salle->next;
	}
	return (1);
}

int		duplicate_liaison(t_salle *salle, char **tab)
{
	t_salle			*tmp;
	t_connection	*tmp_co;

	tmp = salle;
	while (ft_strcmp(tmp->name, tab[0]) != 0)
		tmp = tmp->next;
	tmp_co = tmp->co;
	while (tmp_co)
	{
		if (ft_strcmp(tmp_co->salle->name, tab[1]) == 0)
			return (1);
		tmp_co = tmp_co->next;
	}
	return (0);
}
