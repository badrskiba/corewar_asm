/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_is_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:51:32 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/01/19 16:40:00 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_printf		*flag_is_c(t_printf *l, va_list *ap)
{
	int ch;

	ch = -1;
	if (l->c == 1 && (l->l == 0 && l->ll == 0))
	{
		ch = (char)va_arg(*ap, int);
		if (ch == 0)
			l->empty = 1;
	}
	if (l->c == 1 && (l->l == 1 || l->ll == 1))
	{
		return (flag_is_mc(l, ap));
	}
	if (l->empty == 0 && l->wchr == 0)
		l->str = char_to_str(ch);
	else if (l->empty == 0 && l->wchr == 1)
		l->wstr = wchar_to_wstr(ch);
	return (l);
}
