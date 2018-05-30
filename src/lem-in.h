/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem-in.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/24 11:18:08 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/30 17:49:48 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

typedef struct			s_connection
{
	char				*connect;
	struct s_connection *next;
}						t_connection;

typedef struct 			s_salle
{
	int		 			index;
	char				*name;
	int					x;
	int					y;
	t_connection		*co;
	struct s_salle 		*next;
}						t_salle;

typedef struct			s_info
{
	int					nb;
	int					index;
	char				*line;
	char				*text;
	char				*start;
	char				*end;
	t_salle				*salle;
}						t_info;

void			ft_add_text(t_info *tab);
void			add_liaison(t_salle *salle, char **tab, int first_liaison);
t_salle			*add_donne(t_salle *colonie, char **salle);

int		check_digit(char *line);
int		duplicate_room(t_info *colonie);
int		room_exist(t_salle *salle, char *tab);
int		duplicate_liaison(t_salle *salle, char **tab);
int 	ft_check_line(t_info *colonie);
void	ft_check_and_add(t_info *colonie);

int		get_room(t_info *colonie, char **salle);
int		get_tubes(t_info *colonie, char *tubes);
int		get_other(t_info *colonie, char *other);
char	*get_other_next(t_info *colonie);

void	ft_print_liaisons(t_salle *salle);
void	ft_print_list(t_info *colonie);

void			free_tab(char **tab);
t_connection	*nettoyage_connections(t_connection *connection);
t_salle			*nettoyage_salles(t_salle *salle);
void			nettoyage_colonie(t_info *colonie);
#endif
