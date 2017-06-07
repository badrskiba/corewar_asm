/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 17:28:44 by mtagaizi          #+#    #+#             */
/*   Updated: 2016/12/23 18:14:32 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
******************************************************************
**																**
**	ft_strnn (char *s, int beg, int end) :						**
**	create and returns the malloc str from s[beg] to s[end]		**
**																**
******************************************************************
*/

char		*ft_strnn(char *s, int beg, int end)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (end - beg + 1))))
		return (NULL);
	while (beg <= end)
	{
		str[i] = s[beg];
		beg++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
