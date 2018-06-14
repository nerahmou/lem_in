/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checkers.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 19:20:56 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 17:22:23 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./lem-in.h"

int		check_min(t_info *colonie)
{
	if (ft_lstlen(colonie->salle, get_next_salle) < 2)
		return (ft_printf("pas asssezz de salle\n"));
	if (!colonie->start || !colonie->end)
		return (ft_printf("pas de start ou end\n"));
	colonie->chemins = get_paths(colonie);
//	ft_print_chemins(colonie->chemins);
	if (!ft_lstlen(colonie->chemins, &get_next_chemin))
		return (ft_printf("pas de chemin possible de start a end\n"));
	return (0);
}

int		check_digit(char *line)
{
	int i;

	i = 0;
	while (line[i])
		if (ft_isdigit(line[i++]) == 0)
			return (1);
	if (ft_strlen(line) >= 10 && ft_strcmp(line, "2147483647") > 0)
		return (1);
	return (0);
}

int		duplicate_room(t_info *colonie)
{
	t_salle	*head;
	t_salle	*tmp;

	tmp = colonie->salle;
	while (tmp)
	{
		head = colonie->salle;
		tmp  = tmp->next;
		while (tmp && head)
		{
			if (ft_strcmp(tmp->name, head->name) == 0 && tmp != head)
				return (1);
			if (tmp->x == head->x && tmp->y == head->y && tmp != head)
				return (1);
			head = head->next;
		}
	}
	return (0);
}

int		room_exist(t_salle *salle, char *tab)
{
	while (salle)
	{
		if (!ft_strcmp(salle->name, tab))
			return (0);
		salle = salle->next;
	}
	return (1);
}

int		duplicate_liaison(t_salle *salle, char **tab)
{
	t_salle		*tmp;
	t_connection *tmp_co;

	tmp = salle;
	while (ft_strcmp(tmp->name, tab[0]) != 0)
		tmp = tmp->next;
	tmp_co = tmp->co;
	while (tmp_co)
	{
		if (ft_strcmp(tmp_co->salle->name, tab[1]) == 0)
				return (1);
		tmp_co = tmp_co->next;
	}
	return (0);
}

static	int check_whitespaces(char *str)
{
	if (str[0] == ' ' || str[ft_strlen(str) - 1] == ' ')
		return (1);
	return (0);
}

int 	ft_check_line(t_info *colonie)
{
	char	**tmp;
	int		tab_len;

	if (check_whitespaces(colonie->line))
		exit(ft_printf("ERROR commande inconnue\n", nettoyage_colonie(colonie)));
	colonie->line_split = ft_strsplit(colonie->line, ' ');
	tmp = colonie->line_split;
	tab_len = ft_tablength(tmp);
	if (tab_len == 3)
	{
		if (get_room(colonie))
			exit(ft_printf("ERROR room existante ou x y\n", nettoyage_colonie(colonie)));
	}
	else if (tab_len == 1 || tmp[0][0] == '#')
	{
		if (get_other(colonie, tmp[0], tab_len))
			exit(ft_printf("ERROR commande inconnue\n", nettoyage_colonie(colonie)));
	}
	else
		exit(ft_printf("ERROR commande inconnue\n", nettoyage_colonie(colonie)));
	free_tab(tmp);
	colonie->line_split = NULL;
	return (0);
}

void	ft_check_and_add(t_info *colonie)
{
	if (colonie->nb == 0)
	{
		if (check_digit(colonie->line) == 0)
			colonie->nb = ft_atoi(colonie->line);
		else
			exit(ft_printf("ERROR non digital\n", nettoyage_colonie(colonie)));
	}
	else if (ft_check_line(colonie) == 1)
			exit(ft_printf("ERROR\n", nettoyage_colonie(colonie)));
}
