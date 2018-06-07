/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/16 15:56:51 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 17:22:39 by nerahmou    ###    #+. /#+    ###.fr     */
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
	colonie->line_split = NULL;
	colonie->start = NULL;
	colonie->end = NULL;
	colonie->salle = NULL;
	colonie->chemins = NULL;

}

void	ft_lem_in(t_info *colonie)
{
	while (get_next_line(0, &colonie->line) && ft_strcmp("", colonie->line))
	{
		ft_add_text(colonie);
		ft_check_and_add(colonie);
		ft_strdel(&colonie->line);
	}
	//ft_print_liaisons(colonie->salle);
	if (check_min(colonie))
	;//	exit(ft_printf("ERROR minimun invalide\n", nettoyage_colonie(colonie)));
	

//	ft_print_list(colonie);
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
