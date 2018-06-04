/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   getters.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 19:16:35 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/04 21:03:26 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./lem-in.h"

static t_salle_2	nettoyage_salle2(t_salle_2 *salle)
{
	t_salle_2 *tmp;

	while (salle)
	{
		ft_strdel(&salle->name);
		tmp = salle->next;
		free(salle);
		salle = NULL;
		salle = tmp;
	}
	return (NULL);
}

static void	init_chemin(t_chemins *chemin)
{
	chemin->salle = NULL;
	chemin->next = NULL;
}

static t_salle_2 *add_salle2(t_salle_2 *salle2, t_salle *salle)
{
	t_salle_2 *tmp;
	t_salle_2 *link;

	tmp = salle2;

	link = malloc(sizeof(t_salle_2));
	link->name = ft_strdup(salle->name);
	link->index = salle->index;
	link->is_full = 0;
	link->next = NULL;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = link;
	}
	else
		salle_2 = link;
	return (salle_2);
}

static	t_salle_2 *pop(t_salle_2 *salle)
{
	t_salle_2 *tmp;
	t_salle_2 *tmp_2;

	tmp = salle;
	while (tmp->next->next)
		tmp = tmp->next;
	nettoyage_salle2(tmp->next);
	tmp->next = NULL;
	return (salle);
}

static	t_salle_2 *get_last_salle2(t_salle_2 *salle)
{
	t_salle_2 *tmp;

	tmp = salle;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

static t_salle_2 *lstdup(t_salle_2 *salle)
{
	t_salle_2 *new;
	t_salle *tmp;

	if (!salle)
		return NULL;
	tmp = salle;
	while (tmp)
	{
		new = add_salle2(new, tmp);
		tmp = tmp-.next;
	}
	return (new);
}

static	t_chemins	*push_chemin(t_chemins *chemin, t_salle_2 *salle)
{
	t_chemins *tmp;
	t_chemins *new;

	new = malloc(sizeof(t_chemins));
	new->salle = lstdup(salle);
	new->next = NULL;
	tmp = chemin;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		chemin = new;
	return (chemin);
}







static void	backtracking(t_salle *salle, t_chemins *chemin, t_salle_2 *salle_2, int end)
{
	while (salle->co && salle->co->index != end && salle->co->index != get_last_salle2(salle_2)->index)
	{
		salle_2 = add_salle2(salle_2, salle);
		backtracking(salle->co->salle, chemin, end);
		salle_2 = pop(salle_2);
	}
	chemin = push_chemin(chemin, salle_2);
}


int		get_paths(t_info *colonie, t_salle *prev)
{
	t_chemins	chemin;
	t_salle		*start;
	t_salle_2  	*tmp;

	init_chemin(&chemin);
	start = colonie->start;
	while (start->co)
	{
		tmp = add_salle2(tmp, start);
		backtracking(start->co, &chemin, tmp, colonie->end->index);
		tmp = nettoyage_salle2(tmp);
		start->co = start->co->next;
	}
}





void	*get_next_salle(void *lst)
{
	t_salle *tmp = ((t_salle*)lst)->next;

	return (tmp);
}

t_salle	*get_room_by_name(t_salle *salle, char *name)
{
	t_salle *tmp;

	tmp = salle;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int		get_room(t_info *colonie)
{
	t_salle *tmp;
	char	**salle;

	tmp = colonie->salle;
	salle = colonie->line_split;
	if (salle[0][0] == 'L' || check_digit(salle[1]) || check_digit(salle[2]))
		return (1);
	colonie->salle = add_salle(tmp, salle, colonie->index);
	if (duplicate_room(colonie) == 1)
		return (1);
	colonie->index++;
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
	else
		add_liaison(colonie->salle, tab, 1);
	free_tab(tab);
	colonie->line_split = NULL;
	return (0);
}

t_salle *get_other_next(t_info *colonie)
{
	char	**tab;
	t_salle *tmp;


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
	tmp = get_room_by_name(colonie->salle, tab[0]);
	free_tab(tab);
	colonie->line_split = NULL;
	return (tmp);
}

int	get_other(t_info *colonie, char *other, int tab_len)
{
	if (ft_strcmp(other, "##start") == 0 && tab_len == 1)
		colonie->start = get_other_next(colonie);
	else if (strcmp(other, "##end") == 0 && tab_len == 1)
		colonie->end = get_other_next(colonie);
	else if (other[0] == '#' && other[1] != '#')
		;
	else if (ft_strchr_occur(other, '-') == 1 && tab_len == 1)
		get_tubes(colonie, other);
	else
		return (1);
	return (0);
}
