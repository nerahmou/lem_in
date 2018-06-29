/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_chemins2.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 15:19:32 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 15:33:55 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void		*get_next_chemin(void *chemin)
{
	return (((t_chemins*)chemin)->next);
}

t_chemins	*insert(t_chemins *chemin, t_chemins *tmp, t_chemins *new)
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
	new->nb_connections = 0;
	new->nb_tosend = 0;
	new->next = NULL;
	tmp = chemin;
	if (tmp)
		chemin = insert(chemin, tmp, new);
	else
		chemin = new;
	return (chemin);
}

t_chemins	*delete_chemin(t_chemins *chemin)
{
	t_chemins	*prev;
	t_chemins	*high;
	t_chemins	*tmp;
	size_t		nb;

	tmp = chemin;
	high = tmp;
	nb = tmp->nb_connections;
	while (tmp->next)
	{
		if (tmp->next->nb_connections >= nb)
		{
			prev = tmp;
			nb = tmp->next->nb_connections;
			high = tmp->next;
		}
		tmp = tmp->next;
	}
	high == chemin ? (chemin = chemin->next) :
		(prev->next = high->next);
	high->salle = nettoyage_salle2(high->salle);
	free(high);
	high = NULL;
	return (chemin);
}
