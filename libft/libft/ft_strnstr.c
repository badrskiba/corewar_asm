/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:08:46 by mtagaizi          #+#    #+#             */
/*   Updated: 2016/12/11 23:20:44 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	len2;

	if (!*little)
		return ((char *)big);
	len2 = ft_strlen(little);
	while (*big && n-- >= len2)
	{
		if (*big == *little && ft_memcmp(big, little, len2) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
