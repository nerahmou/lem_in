/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checkers.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 19:20:56 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/30 17:48:41 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./lem-in.h"

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
		if (ft_strcmp(tmp_co->connect, tab[1]) == 0)
				return (1);
		tmp_co = tmp_co->next;
	}
	return (0);
}



int 	ft_check_line(t_info *colonie)
{
	char **tmp;

	colonie->index = 0;
	tmp = ft_strsplit(colonie->line, ' ');
	if (ft_tablength(tmp) == 3)
		get_room(colonie, tmp);
	else if (ft_tablength(tmp) == 1 || tmp[0][0] == '#')
		get_other(colonie, tmp[0]);
	else
		ft_putendl("Pas assez d element dans le **tab");
	free_tab(tmp);
	return (0);
}		

void	ft_check_and_add(t_info *colonie)
{
	if (colonie->nb == 0)
	{
		if (check_digit(colonie->line) == 0)
			colonie->nb = ft_atoi(colonie->line);
		else
			exit(ft_printf("ERROR\n"));
	}
	else if (ft_check_line(colonie) == 1)
		exit(ft_printf("ERROR\n"));
}
