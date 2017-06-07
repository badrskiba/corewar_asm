/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:53:25 by mtagaizi          #+#    #+#             */
/*   Updated: 2016/12/11 23:14:13 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_minimize(char *s)
{
	char	*str;
	size_t	i;

	if ((str = (char*)malloc(sizeof(str) * ft_strlen(s))) == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = ft_tolower(s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
