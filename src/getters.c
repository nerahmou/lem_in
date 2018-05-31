/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   getters.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 19:16:35 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/31 13:41:36 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./lem-in.h"

int		get_room(t_info *colonie)
{
	t_salle *tmp;
	char	**salle;

	tmp = colonie->salle;
	salle = colonie->line_split;
	if (salle[0][0] == 'L' || check_digit(salle[1]) || check_digit(salle[2]))
		return (1);
	colonie->salle = add_donne(tmp, salle);
	if (duplicate_room(colonie) == 1)
		return (1);
	return (0);
}


int		get_tubes(t_info *colonie, char *tubes)
{
	char **tab;

	if (!colonie->start || !colonie->end)
		exit(ft_printf("ERROR\n", nettoyage_colonie(colonie)));
	colonie->line_split = ft_strsplit(tubes, '-');
	tab = colonie->line_split;
	if (ft_tablength(tab) != 2)
		exit(ft_printf("ERROR\n", nettoyage_colonie(colonie)));
	if (room_exist(colonie->salle, tab[0]) || room_exist(colonie->salle, tab[1]))
		exit(ft_printf("ERROR\n", nettoyage_colonie(colonie)));
	if (duplicate_liaison(colonie->salle, tab))
		ft_putendl("Liaison existante");
	add_liaison(colonie->salle, tab, 1);
	free_tab(tab);
	colonie->line_split = NULL;
	return (0);
}

char *get_other_next(t_info *colonie)
{
	char **tab;
	char *tmp;

	ft_strdel(&colonie->line);
	get_next_line(0, &colonie->line);
	ft_add_text(colonie);
	if (ft_check_line(colonie))
		exit(ft_printf("ERROR\n", nettoyage_colonie(colonie)));
	tab = ft_strsplit(colonie->line, ' ');
	if (tab[0][0] == '#')
	{
		free_tab(tab);
		return(NULL);
	}
	tmp = ft_strdup(tab[0]);
	free_tab(tab);
	colonie->line_split = NULL;
	return (tmp);
}

int	get_other(t_info *colonie, char *other)
{
	if (strcmp(other, "##start") == 0)
		colonie->start = get_other_next(colonie);
	else if (strcmp(other, "##end") == 0)
		colonie->end = get_other_next(colonie);
	else if (other[0] == '#' && other[1] != '#')
		;
	else if (ft_strchr_occur(other, '-') == 1)
		get_tubes(colonie, other);
	else
		return (1);
	return (0);
}
