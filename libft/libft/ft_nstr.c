/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 20:49:18 by mtagaizi          #+#    #+#             */
/*   Updated: 2016/12/11 23:14:25 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_nstr(char *src)
{
	char *s;

	s = ft_memalloc(ft_strlen(src));
	ft_strcpy(s, src);
	return (s);
}
