/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/16 15:56:51 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/30 18:24:25 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem-in.h"

void	init_colonie(t_info *colonie)
{
	colonie->nb = 0;
	colonie->index = 0;
	colonie->text = NULL;
	colonie->line = NULL;
	colonie->start = NULL;
	colonie->end = NULL;
	colonie->salle = NULL;

}

void	ft_lem_in(t_info *colonie)
{
	char *tmp;
	while (get_next_line(0, &tmp) && ft_strcmp("", tmp))
	{
		colonie->line = ft_strdup(tmp);
		ft_strdel(&tmp);
		ft_printf("%i\n", ft_strcmp("", colonie->line));
		ft_add_text(colonie);
		ft_check_and_add(colonie);
		ft_strdel(&colonie->line);
	}
//	ft_print_list(colonie);
//	ft_print_liaisons(colonie->salle);
	ft_putendl(colonie->text);
}

int 	main(void)
{
	t_info colonie;

	init_colonie(&colonie);
	ft_lem_in(&colonie);
	nettoyage_colonie(&colonie);
	return (0);
}
