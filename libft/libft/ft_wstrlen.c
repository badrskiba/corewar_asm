/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:50:39 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/01/23 14:21:10 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wstrlen(int *s)
{
	int		i;
	int		o;

	o = 0;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] > 128)
			o = o + 1;
		if (s[i] > 2000)
			o = o + 1;
		if (s[i] > 65000)
			o = o + 1;
		i++;
	}
	return (i + o);
}
