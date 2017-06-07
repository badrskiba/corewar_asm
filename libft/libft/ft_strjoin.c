/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 20:53:26 by mtagaizi          #+#    #+#             */
/*   Updated: 2016/11/11 16:34:32 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (s1 && s2)
	{
		i = ft_strlen(s1) + ft_strlen(s2);
		str = ft_strnew(i);
		if (str == NULL)
			return (NULL);
		i = 0;
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		j = -1;
		while (s2[++j])
			str[i + j] = s2[j];
		str[i + j] = '\0';
		return (str);
	}
	return (NULL);
}
