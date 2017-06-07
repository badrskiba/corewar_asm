/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_str_before.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 00:04:22 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/01/20 00:11:48 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_printf		*make_str_before(t_printf *l, char *s)
{
	int		lens;
	int		lenls;
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	lens = ft_strlen(s);
	lenls = ft_strlen(l->str);
	if (!(str = (char*)malloc(sizeof(char) * (lens + lenls + 1))))
		return (NULL);
	while (s[++i])
		str[i] = s[i];
	while (l->str[j])
		str[i++] = l->str[j++];
	str[i] = '\0';
	free(l->str);
	l->str = ft_strdup(str);
	free(str);
	return (l);
}
