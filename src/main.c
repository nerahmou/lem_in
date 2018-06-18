/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/16 15:56:51 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/18 17:03:16 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

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
	colonie->chemins_un = NULL;
	colonie->graph_file = fopen("graph.out", "w");
	if (colonie->graph_file == NULL)
		exit(1);
	fprintf(colonie->graph_file, "graph my_graph\n{\n");
}

void	ft_lem_in(t_info *colonie)
{
	while (get_next_line(0, &colonie->line) && ft_strcmp("", colonie->line))
	{
		ft_add_text(colonie);
		ft_check_and_add(colonie);
		ft_strdel(&colonie->line);
	}
	fprintf(colonie->graph_file, "}\n");
	fclose(colonie->graph_file);
	if (check_min(colonie))
		;
//	ft_print_chemins(colonie->chemins);
	system("dot -T png -O graph.out");
	system("open graph.out.png");
}

int		main(void)
{
	t_info colonie;

	init_colonie(&colonie);
	ft_lem_in(&colonie);
	nettoyage_colonie(&colonie);
	return (0);
}
