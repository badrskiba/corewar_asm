/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_is_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:51:32 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/01/16 23:01:13 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_printf		*flag_is_i(t_printf *l, va_list *ap)
{
	if (l->l == 0 && l->ll == 0 && l->h == 0 && l->hh == 0
		&& l->j == 0 && l->z == 0)
		l->str = ft_itoa_max(va_arg(*ap, int));
	else if (l->l == 1 && l->ll == 0 && l->h == 0 && l->hh == 0
		&& l->j == 0 && l->z == 0)
		l->str = ft_itoa_max(va_arg(*ap, long));
	else if (l->l == 0 && l->ll == 1 && l->h == 0 && l->hh == 0
		&& l->j == 0 && l->z == 0)
		l->str = ft_itoa_max(va_arg(*ap, long long));
	else if (l->l == 0 && l->ll == 0 && l->h == 1 && l->hh == 0
		&& l->j == 0 && l->z == 0)
		l->str = ft_itoa_max((short)va_arg(*ap, int));
	else if (l->l == 0 && l->ll == 0 && l->h == 0 && l->hh == 1
		&& l->j == 0 && l->z == 0)
		l->str = ft_itoa_max((signed char)va_arg(*ap, int));
	else if (l->l == 0 && l->ll == 0 && l->h == 0 && l->hh == 0
		&& l->j == 1 && l->z == 0)
		l->str = ft_itoa_max(va_arg(*ap, intmax_t));
	else if (l->l == 0 && l->ll == 0 && l->h == 0 && l->hh == 0
		&& l->j == 0 && l->z == 1)
		l->str = ft_itoa_max(va_arg(*ap, size_t));
	return (l);
}
