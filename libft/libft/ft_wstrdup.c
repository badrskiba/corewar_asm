/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:37:35 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/01/19 14:20:16 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_wstrdup(int *s1)
{
	int *s;
	int i;

	i = 0;
	if (!(s1))
		return (NULL);
	s = (int*)ft_memalloc(ft_wstrlen(s1));
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = 0;
	return (s);
}
