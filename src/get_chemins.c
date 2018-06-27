/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_chemins.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/06 16:46:06 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 15:50:33 by edbernie    ###    #+. /#+    ###.fr     */
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

int			get_nb_co(t_chemins **chemin)
{
	t_chemins	*tmp_ch;
	t_chemins	*head;
	t_salle_2	*salle_chemin;
	t_salle_2	*salle_head;
	int			ret;

	tmp_ch = *chemin;
	ret = 0;
	while (tmp_ch)
	{
		head = *chemin;
		while (head)
		{
			if (head == tmp_ch)
			{
			}
			else
			{
				salle_head = head->salle->next;
				while (salle_head->next)
				{
					salle_chemin = tmp_ch->salle->next;
					while (salle_chemin->next)
					{
						if (salle_chemin->index == salle_head->index)
						{
							ret = 1;
							tmp_ch->nb_connections++;
						}
						salle_chemin = salle_chemin->next;
					}
					salle_head = salle_head->next;
				}
				salle_head = salle_head->next;
			}
			head = head->next;
		}
		tmp_ch = tmp_ch->next;
	}
	return (ret);
}

t_chemins	*delete_chemin(t_chemins *chemin)
{
	t_chemins	*prev;
	t_chemins	*high;
	t_chemins	*tmp;
	size_t			nb;

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
	high == chemin ? (chemin = chemin->next) : (prev->next = high->next);
	high->salle = nettoyage_salle2(high->salle);
	free(high);
	high = NULL;
	return (chemin);
}

void		init_nb_co(t_chemins **chemin)
{
	t_chemins *tmp;

	tmp = *chemin;
	while (tmp)
	{
		tmp->nb_connections = 0;
		tmp = tmp->next;
	}
}

t_chemins	*get_uniq(t_chemins *chemin)
{
	while (get_nb_co(&chemin) != 0)
	{
		chemin = delete_chemin(chemin);
		init_nb_co(&chemin);
	}
	return(chemin);
}

void		backtracking(t_salle *salle, t_chemins **chemin, t_salle_2 *tmp,
		int end)
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
				backtracking(tmp_co->salle, chemin, tmp, end);
				tmp = pop(tmp);
			}
			tmp_co = tmp_co->next;
		}
	}
}

t_chemins    *dup_chemin(t_chemins *chemin)
{
	t_chemins *tmp;
	t_chemins *new;

	tmp = chemin;
	new = NULL;
	while (tmp)
	{
		new = push_chemin(new, tmp->salle);
		tmp = tmp->next;
	}
	return (new);
}

t_chemins	*get_paths(t_info *colonie)
{
	t_chemins		*chemin;
//	t_chemins
	t_salle			*start;
	t_salle_2		*tmp;
	t_connection	*tmp_co;
//	if (chemin_un)
//			;
	chemin = NULL;
	tmp = NULL;
	start = colonie->start;
	tmp_co = colonie->start->co;
	while (tmp_co)
	{
		tmp = add_salle2(tmp, start);
		backtracking(tmp_co->salle, &chemin, tmp, colonie->end->index);
		tmp = nettoyage_salle2(tmp);
		tmp_co = tmp_co->next;
	}
	colonie->chemins_un = dup_chemin(chemin);
	colonie->chemins_un = get_uniq(colonie->chemins_un);
	return (chemin);
}
