/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:20:24 by mtagaizi          #+#    #+#             */
/*   Updated: 2016/12/11 23:19:56 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ldst;
	size_t	lsrc;
	int		a;

	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	a = 0;
	if (size < ldst)
		return (size + lsrc);
	while ((ldst + a + 1) < size && src[a] != '\0')
	{
		dst[ldst + a] = src[a];
		a++;
	}
	dst[ldst + a] = '\0';
	return (ldst + lsrc);
}
