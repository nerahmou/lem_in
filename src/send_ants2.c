/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   send_ants2.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 15:14:17 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 16:31:13 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

t_salle_2	*on_salle(t_chemins *chemin, int line)
{
	t_salle_2	*tmp;
	t_chemins	*che;
	int			i;

	i = 0;
	che = chemin;
	tmp = che->salle;
	while (tmp->next && i != line)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}

int			check_end(t_chemins *chemin, int nb)
{
	t_chemins	*tmp;
	t_salle_2	*salle;
	int			i;

	i = 0;
	tmp = chemin;
	while (tmp)
	{
		salle = tmp->salle;
		while (salle->next)
			salle = salle->next;
		if (salle->is_full > i)
			i = salle->is_full;
		tmp = tmp->next;
	}
	if (i < nb)
		return (1);
	return (0);
}

char		*add_res(int i, char *name, char *res)
{
	char *dst;
	char *tmp;

	tmp = ft_itoa(i);
	dst = ft_strjoin("L", tmp);
	ft_strdel(&tmp);
	tmp = ft_strdup(dst);
	ft_strdel(&dst);
	dst = ft_strjoin(tmp, "-");
	ft_strdel(&tmp);
	tmp = ft_strdup(dst);
	ft_strdel(&dst);
	dst = ft_strjoin(tmp, name);
	ft_strdel(&tmp);
	tmp = ft_strdup(dst);
	ft_strdel(&dst);
	dst = ft_strjoin(tmp, " ");
	ft_strdel(&tmp);
	tmp = ft_strdup(dst);
	ft_strdel(&dst);
	dst = ft_strjoin(res, tmp);
	ft_strdel(&tmp);
	ft_strdel(&res);
	return (dst);
}

char		*move_ants(t_chemins *chemin, int line)
{
	t_salle_2	*salle;
	t_chemins	*tmp;
	char		*str;
	int			i;

	i = line + 1;
	tmp = chemin;
	str = ft_strdup("");
	while (--i != 0)
	{
		tmp = chemin;
		while (tmp)
		{
			salle = on_salle(tmp, i);
			if (salle->next && salle->is_full != 0)
			{
				salle->next->is_full = salle->is_full;
				salle->is_full = 0;
				salle = salle->next;
				str = add_res(salle->is_full, salle->name, str);
			}
			tmp = tmp->next;
		}
	}
	return (str);
}

void		ft_aff_and_fr(char *str)
{
	char	*tmp;
	char	*res;

	tmp = ft_strdup(str);
	res = ft_strtrim(tmp);
	ft_putstr(res);
	if (res)
		ft_strdel(&res);
	if (tmp)
		ft_strdel(&tmp);
}
