/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 20:54:13 by mtagaizi          #+#    #+#             */
/*   Updated: 2016/11/11 16:35:53 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	i = 0;
	if (s && f)
	{
		while (s[i])
			i++;
		if ((str = (char*)malloc(sizeof(*str) * (i + 1))) == NULL)
			return (NULL);
		i = 0;
		while (s[i])
		{
			str[i] = f(s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
