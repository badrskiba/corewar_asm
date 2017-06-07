/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_is_mc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:51:32 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/01/19 16:21:12 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_printf		*flag_is_mc(t_printf *l, va_list *ap)
{
	int ch;

	ch = va_arg(*ap, int);
	if (ch == 0)
		l->empty = 1;
	l->wchr = 1;
	if (l->empty == 0)
		l->wstr = wchar_to_wstr(ch);
	return (l);
}
