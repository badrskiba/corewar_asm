/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:56:23 by mtagaizi          #+#    #+#             */
/*   Updated: 2016/12/11 23:17:49 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*tab;
	int		i;

	i = 0;
	if (!min || !max || min >= max)
		return (NULL);
	tab = (int*)malloc(sizeof(int) * (max - min));
	if (!tab)
		return (NULL);
	else
	{
		while (i < (max - min))
		{
			tab[i] = min + i;
			i++;
		}
		return (tab);
	}
}
