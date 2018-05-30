/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 14:55:15 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/16 18:24:39 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long a;
	long nb;
	long neg;

	a = 0;
	nb = 0;
	neg = 0;
	while (str[a] == ' ' || (str[a] >= 9 && str[a] <= 13))
		a++;
	if (str[a] == '-')
	{
		neg++;
		a++;
	}
	if (str[a] == '+' && str[a - 1] != '-')
		a++;
	while (str[a] >= '0' && str[a] <= '9')
	{
		nb = (nb * 10) + (str[a] - 48);
		a++;
	}
	if (neg == 1)
		return (-nb);
	else
		return (nb);
}
