/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_chemins.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/06 16:46:06 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 17:24:25 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem-in.h"

void *get_next_chemin(void *chemin)
{
	return (((t_chemins*)chemin)->next);
}

t_chemins *insert(t_chemins *chemin, t_chemins *tmp, t_chemins *new)
{
	t_chemins *prev;

	while (tmp->next && new->length > tmp->length)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == chemin && new->length < tmp->length)
	{
		new->next = tmp;
		chemin = new;
	}
	else if (new->length < tmp->length)
	{
		new->next = prev->next;
		prev->next = new;
	}
	else
	{
		new->next = tmp->next;
		tmp->next = new;
	}
	return (chemin);
}

t_chemins	*push_chemin(t_chemins *chemin, t_salle_2 *salle)
{
	t_chemins *tmp;
	t_chemins *new;

	new = malloc(sizeof(t_chemins));
	new->salle = lstdup(salle);
	new->length = ft_lstlen(new->salle, &get_next_salle2);
	new->next = NULL;
	tmp = chemin;
	if (tmp)
		chemin = insert(chemin, tmp, new);
	else
		chemin = new;
	return (chemin);
}

void	backtracking(t_salle *salle, t_chemins **chemin, t_salle_2 *tmp, int end)
{
	t_connection *tmp_co;

	if (salle->index == end)
	{
		tmp = add_salle2(tmp, salle);
		*chemin = push_chemin(*chemin, tmp);
		tmp = pop(tmp);
	}
	else
	{
		tmp_co = salle->co;
		while (tmp_co)
		{
			if (!find_index_salle2(tmp, tmp_co->salle->index, end))
			{
				tmp = add_salle2(tmp, salle);
				backtracking(tmp_co->salle, chemin, tmp , end);
				tmp = pop(tmp);
			}
			tmp_co = tmp_co->next;
		}
	}
}

t_chemins	*get_paths(t_info *colonie)
{
	t_chemins	*chemin;
	t_salle		*start;
	t_salle_2  	*tmp;

	chemin = NULL;
	tmp = NULL;
	start = colonie->start;
	while (start->co)
	{
		tmp = add_salle2(tmp, start);
		backtracking(start->co->salle, &chemin, tmp, colonie->end->index);
		tmp = nettoyage_salle2(tmp);
		start->co = start->co->next;
	}
	return (chemin);
}
