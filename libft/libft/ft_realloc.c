/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:43:42 by mtagaizi          #+#    #+#             */
/*   Updated: 2016/12/23 18:05:28 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *src, size_t size)
{
	free(src);
	src = NULL;
	if (!(src = (void*)malloc(sizeof(*src) * size)))
		return (NULL);
	ft_bzero(src, size);
	return (src);
}
