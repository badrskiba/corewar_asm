/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 16:48:00 by mtagaizi          #+#    #+#             */
/*   Updated: 2016/12/23 18:13:49 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	takes the string and returns an int base 10
*/

static int			find_number(char c, int base)
{
	int			i;
	static char	tab[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
	'9', 'A', 'B', 'C', 'D', 'E', 'F'};

	i = 0;
	while (i < base)
	{
		if (c == tab[i])
			return (i);
		i++;
	}
	return (-1);
}

static unsigned int	ft_now(char *str, int base)
{
	int i;
	int	number;
	int newnumber;

	i = 0;
	number = 0;
	newnumber = 0;
	str = ft_capitalize(str);
	while (ft_isdigit(str[i]) == 1 || (str[i] >= 'A' && str[i] <= 'F'))
	{
		if ((newnumber = find_number(str[i], base)) == -1)
		{
			ft_putendl_fd("Error : ft_atoi_base", 2);
			return (-1);
		}
		number = number * base + newnumber;
		i++;
	}
	return (number);
}

unsigned int		ft_atoi_base(char *str, int base)
{
	int		i;
	int		negatif;

	i = 0;
	if (base > 16)
		return (0);
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\t' || str[i] == '\r' || str[i] == '\f')
		i++;
	negatif = 0;
	if (str[i] == '-')
	{
		negatif = 1;
		i++;
	}
	return (ft_now(str + i, base));
}
