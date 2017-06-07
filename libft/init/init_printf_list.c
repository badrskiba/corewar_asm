/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_printf_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 05:52:04 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/01/19 23:59:49 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static t_printf	*init_printf_list_bis(t_printf *next, t_printf *new_list)
{
	new_list->l = 0;
	new_list->ll = 0;
	new_list->h = 0;
	new_list->hh = 0;
	new_list->j = 0;
	new_list->z = 0;
	new_list->s = 0;
	new_list->ms = 0;
	new_list->p = 0;
	new_list->d = 0;
	new_list->md = 0;
	new_list->i = 0;
	new_list->o = 0;
	new_list->mo = 0;
	new_list->u = 0;
	new_list->mu = 0;
	new_list->x = 0;
	new_list->mx = 0;
	new_list->c = 0;
	new_list->mc = 0;
	new_list->mm = 0;
	new_list->next = next;
	return (new_list);
}

t_printf		*init_printf_list(t_printf *next)
{
	t_printf	*new_list;

	if (!(new_list = (t_printf*)malloc(sizeof(*new_list))))
		return (NULL);
	new_list->str = NULL;
	new_list->wstr = NULL;
	new_list->character = 0;
	new_list->len = 0;
	new_list->wchr = 0;
	new_list->end = 0;
	new_list->simple = 0;
	new_list->empty = 0;
	new_list->hash = 0;
	new_list->plus = 0;
	new_list->min = 0;
	new_list->space = 0;
	new_list->zero = 0;
	new_list->num = 0;
	new_list->precision = 0;
	new_list->pspace = 0;
	new_list->pzero = 0;
	new_list->pnum = 0;
	return (init_printf_list_bis(next, new_list));
}
