/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 20:56:58 by mtagaizi          #+#    #+#             */
/*   Updated: 2016/11/11 16:39:01 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;
	size_t			j;
	size_t			o;

	i = 0;
	j = -1;
	o = (size_t)start + len;
	if (s == NULL)
		return (NULL);
	if (o > ft_strlen(s))
		return (NULL);
	else
	{
		if (!(str = ft_strnew(len)))
			return (NULL);
		while (i < start)
			i++;
		while (s[i + ++j] != '\0' && j < len)
			str[j] = s[i + j];
		str[j] = '\0';
		return (str);
	}
}
