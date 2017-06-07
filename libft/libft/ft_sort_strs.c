/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_strs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:14:45 by mtagaizi          #+#    #+#             */
/*   Updated: 2016/12/11 23:17:57 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_strs(int i, char **strs)
{
	int		a;
	char	*temp;

	a = 0;
	while (a < i - 1)
	{
		if (ft_strcmp(strs[a], strs[a + 1]) > 0)
		{
			temp = strs[a];
			strs[a] = strs[a + 1];
			strs[a + 1] = temp;
			return (ft_sort_strs(i, strs));
		}
		a++;
	}
	return ;
}
