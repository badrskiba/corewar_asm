/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 20:43:02 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/03/05 23:55:37 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static intmax_t		ft_func_atoi(const char *str, int positif)
{
	intmax_t	number;
	int			i;

	i = 0;
	number = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (positif == 1)
			number = number * 10 + (str[i] - '0');
		else if (positif == 0)
			number = number * 10 - (str[i] - '0');
		i++;
	}
	return (number);
}

intmax_t			ft_atoi(const char *str)
{
	intmax_t	number;
	int			i;

	number = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\v' || str[i] == '\t' ||
			str[i] == '\f' || str[i] == '\n' || str[i] == '\r')
		i++;
	if (str[i] >= '0' && str[i] <= '9')
		number = ft_func_atoi(str + i, 1);
	else if (str[i] == '-')
		number = ft_func_atoi(str + i + 1, 0);
	else if (str[i] == '+')
		number = ft_func_atoi(str + i + 1, 1);
	return (number);
}
