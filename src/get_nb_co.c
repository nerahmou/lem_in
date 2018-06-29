/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_nb_co.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/29 12:13:07 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 20:10:47 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	get_nb_co_suite(t_chemins *tmp_ch, t_chemins *head, int *ret)
{
	t_salle_2	*salle_head;
	t_salle_2	*salle_chemin;

	salle_head = head->salle->next;
	while (salle_head->next)
	{
		salle_chemin = tmp_ch->salle->next;
		while (salle_chemin->next)
		{
			if (salle_chemin->index == salle_head->index)
			{
				*ret = 1;
				tmp_ch->nb_connections++;
			}
			salle_chemin = salle_chemin->next;
		}
		salle_head = salle_head->next;
	}
	salle_head = salle_head->next;
}

int		get_nb_co(t_chemins **chemin)
{
	t_chemins	*tmp_ch;
	t_chemins	*head;
	int			ret;

	tmp_ch = *chemin;
	ret = 0;
	while (tmp_ch)
	{
		head = *chemin;
		while (head)
		{
			if (head == tmp_ch)
				;
			else
				get_nb_co_suite(tmp_ch, head, &ret);
			head = head->next;
		}
		tmp_ch = tmp_ch->next;
	}
	return (ret);
}
