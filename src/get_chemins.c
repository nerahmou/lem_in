/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_chemins.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/06 16:46:06 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 22:46:38 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

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
	return (chemin);
}

void		backtracking(t_salle *salle, t_chemins **chemin, t_salle_2 *tmp,
		int end)
{
	t_connection *tmp_co;

	if (ft_lstlen(*chemin, &get_next_chemin) > 200)
		return ;
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

t_chemins	*dup_chemin(t_chemins *chemin)
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
	t_salle			*start;
	t_salle_2		*tmp;
	t_connection	*tmp_co;

	chemin = NULL;
	tmp = NULL;
	start = colonie->start;
	tmp_co = colonie->start->co;
	while (tmp_co && ft_lstlen(chemin, &get_next_chemin) < 200)
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
