/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   clears.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/30 14:36:19 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/03 18:32:29 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem-in.h"

t_connection *nettoyage_connections(t_connection *connection)
{
	t_connection *tmp;

	while (connection)
	{
//		ft_strdel(&connection->connect);
		tmp = connection->next;
//		free(connection);
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

void	*nettoyage_colonie(t_info *colonie)
{
	ft_strdel(&colonie->text);
	ft_strdel(&colonie->line);
//	ft_strdel(&colonie->start);
//	ft_strdel(&colonie->end);
	free_tab(colonie->line_split);
	colonie->salle = nettoyage_salles(colonie->salle);
	return (NULL);
}

void	free_tab(char **tab)
{
	int i;
//	int a;

	i = 0;
//	a = 0;
	if (tab)
	{
//		i = ft_tablength(tab);
	while (tab[i])
		ft_strdel(&tab[i++]);
	free(tab);
	}
}


