/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 12:41:02 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/03/17 12:41:33 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isstrdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] == '-' && ft_isdigit(str[i + 1]) == 0)
			return (0);
		if (ft_isdigit(str[i]) == 0 && str[i] != ' ' && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}
