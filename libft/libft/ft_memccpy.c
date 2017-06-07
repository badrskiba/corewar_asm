/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:56:19 by mtagaizi          #+#    #+#             */
/*   Updated: 2016/12/11 23:13:10 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*s;
	char		*d;
	char		x;
	size_t		i;

	i = n;
	d = dst;
	s = (void*)src;
	x = c;
	while (i-- > 0)
		if ((*d++ = *s++) == x)
			return (d);
	return (NULL);
}
