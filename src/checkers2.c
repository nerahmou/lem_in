/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checkers2.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 15:04:57 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/28 15:08:46 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

int		check_whitespaces(char *str)
{
	if (str[0] == ' ' || str[ft_strlen(str) - 1] == ' ')
		return (1);
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

int		ft_check_line(t_info *colonie)
{
	char	**tmp;
	int		tab_len;

	if (check_whitespaces(colonie->line))
		ft_error(colonie);
	colonie->line_split = ft_strsplit(colonie->line, ' ');
	tmp = colonie->line_split;
	tab_len = ft_tablength(tmp);
	if (tab_len == 3)
	{
		if (get_room(colonie))
			ft_error(colonie);
	}
	else if (tab_len == 1 || tmp[0][0] == '#')
	{
		if (get_other(colonie, tmp[0], tab_len))
			ft_error(colonie);
	}
	else
		ft_error(colonie);
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
			ft_error(colonie);
	}
	else if (ft_check_line(colonie) == 1)
		ft_error(colonie);
}
