/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_char_after.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 00:04:00 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/01/20 00:07:02 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_printf		*make_char_after(t_printf *l, int len, char c)
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
	while (l->str[j])
		s[i++] = l->str[j++];
	while (i < len + lens)
		s[i++] = c;
	s[i] = '\0';
	free(l->str);
	l->str = ft_strdup(s);
	free(s);
	return (l);
}
