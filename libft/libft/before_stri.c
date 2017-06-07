/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_stri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 18:02:41 by mtagaizi          #+#    #+#             */
/*   Updated: 2016/12/23 18:18:25 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	before_stri
**	returns a new str from src before src[end]
*/

char		*before_stri(char *src, int end)
{
	int		i;
	char	*s;

	i = 0;
	if (!(s = (char*)malloc(sizeof(char) * (end + 1))))
		return (NULL);
	while (i < end)
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
