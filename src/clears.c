/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   clears.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/30 14:36:19 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/30 18:12:00 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem-in.h"

t_connection *nettoyage_connections(t_connection *connection)
{
	t_connection *tmp;

	while (connection)
	{
		ft_strdel(&connection->connect);
		tmp = connection->next;
		free(connection);
		connection = NULL;
		connection = tmp;
	}
	return NULL;
}
t_salle *nettoyage_salles(t_salle *salle)
{
	t_salle *tmp;

	while (salle)
	{
		ft_strdel(&salle->name);
		salle->co = nettoyage_connections(salle->co);
		tmp = salle->next;
		free(salle);
		salle = NULL;
		salle = tmp;
	}
	return NULL;
}

void	nettoyage_colonie(t_info *colonie)
{
	ft_strdel(&colonie->text);
	ft_strdel(&colonie->start);
	ft_strdel(&colonie->end);
	ft_strdel(&colonie->line);
	colonie->salle = nettoyage_salles(colonie->salle);
}

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		ft_strdel(&tab[i++]);
	free(tab);
	tab = NULL;
}


