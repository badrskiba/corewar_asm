/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:37:35 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/01/03 15:43:10 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *s;

	if (!(s1))
		return (NULL);
	s = ft_memalloc(ft_strlen(s1));
	ft_strcpy(s, s1);
	return (s);
}
