/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_char_before.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 00:03:51 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/01/20 00:07:19 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_printf		*make_char_before(t_printf *l, int len, char c)
{
	int		lens;
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	lens = ft_strlen(l->str);
	if (!(s = (char*)malloc(sizeof(char) * (lens + len + 1))))
		return (NULL);
	while (i < len)
		s[i++] = c;
	while (l->str[j])
		s[i++] = l->str[j++];
	s[i] = '\0';
	free(l->str);
	l->str = ft_strdup(s);
	free(s);
	return (l);
}
