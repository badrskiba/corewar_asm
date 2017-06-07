/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 18:37:10 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/05/26 04:16:42 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

int	check_param(int ac, char **av)
{
	int len;
	int	n_f;
	int	a;
	
	n_f = 0;
	a = 1;
	if (ac < 2 || ac > 3)
		return (-1);
	if (av[1] && ft_strcmp(av[1], "-a") == 0)
	{
		n_f = 2;
		a = 2;
		if (!av[2])
			return (-1);
	}
	else if (av[2] && ft_strcmp(av[2], "-a") == 0)
	{
		n_f = 1;
		a = 2;
	}
	else
		n_f = 1;
	return (a);
}
