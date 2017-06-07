/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_is_ms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:51:32 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/01/19 16:38:42 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_printf		*flag_is_ms(t_printf *l, va_list *ap)
{
	if (!(l->wstr = ft_wstrdup(va_arg(*ap, int*))))
		l->empty = 1;
	l->wchr = 1;
	return (l);
}
