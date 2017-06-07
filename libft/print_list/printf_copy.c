/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:32:47 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/02/14 16:51:01 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static t_printf	*printf_copy_2(t_printf *l, t_printf *new)
{
	new->character = l->character;
	new->zero = l->zero;
	new->len = l->len;
	new->num = l->num;
	new->pnum = l->pnum;
	new->precision = l->precision;
	new->s = l->s;
	new->ms = l->ms;
	new->c = l->c;
	new->mc = l->mc;
	new->wchr = l->wchr;
	new->simple = l->simple;
	new->empty = l->empty;
	return (new);
}

t_printf		*printf_copy(t_printf *l)
{
	t_printf	*new;

	if (!(new = (t_printf*)malloc(sizeof(*new))))
		return (NULL);
	if (l->str)
		new->str = ft_strdup(l->str);
	else
		new->str = NULL;
	if (l->wstr)
		new->wstr = ft_wstrdup(l->wstr);
	else
		new->wstr = NULL;
	return (printf_copy_2(l, new));
}
