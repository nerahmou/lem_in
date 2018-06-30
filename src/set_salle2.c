/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   set_salle2.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/06 16:49:56 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/30 16:05:45 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

t_salle_2	*add_salle2(t_salle_2 *salle2, t_salle *salle)
{
	t_salle_2 *tmp;
	t_salle_2 *link;

	tmp = salle2;
	link = malloc(sizeof(t_salle_2));
	link->name = ft_strdup(salle->name);
	link->index = salle->index;
	link->is_full = 0;
	link->next = NULL;
	link->prev = NULL;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = link;
		link->prev = tmp;
	}
	else
		salle2 = link;
	return (salle2);
}

t_salle_2	*pop(t_salle_2 *salle)
{
	t_salle_2 *tmp;

	tmp = salle;
	while (tmp->next->next)
		tmp = tmp->next;
	nettoyage_salle2(tmp->next);
	tmp->next = NULL;
	return (salle);
}

int			find_index_salle2(t_salle_2 *salle, int index, int end)
{
	t_salle_2 *tmp;

	tmp = salle;
	while (tmp)
	{
		if (tmp->index == index && index != end)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_salle_2	*dupl(t_salle_2 *dest, t_salle_2 *src)
{
	t_salle_2 *tmp;
	t_salle_2 *new;

	new = malloc(sizeof(t_salle_2));
	new->index = src->index;
	new->name = ft_strdup(src->name);
	new->is_full = 0;
	new->next = NULL;
	new->prev = NULL;
	tmp = dest;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
	else
		dest = new;
	return (dest);
}

t_salle_2	*lstdup(t_salle_2 *salle)
{
	t_salle_2 *new;
	t_salle_2 *tmp;

	new = NULL;
	if (!salle)
		return (NULL);
	tmp = salle;
	while (tmp)
	{
		new = dupl(new, tmp);
		tmp = tmp->next;
	}
	return (new);
}
