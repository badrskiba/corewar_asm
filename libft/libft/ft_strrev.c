/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:47:52 by mtagaizi          #+#    #+#             */
/*   Updated: 2016/12/11 23:27:19 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	size_t	len;
	char	*str;
	size_t	i;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s) + 1;
	i = 0;
	if (!(str = (char *)malloc(sizeof(*str) * len)))
		return (NULL);
	len = len - 2;
	while ((int)len - 1 != -2)
		str[i++] = s[len--];
	str[i++] = '\0';
	return (str);
}
