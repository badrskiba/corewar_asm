/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_is_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:51:32 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/01/23 13:30:30 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_printf		*flag_is_x(t_printf *l, va_list *ap)
{
	if (l->l == 0 && l->ll == 0 && l->h == 0 && l->hh == 0
		&& l->j == 0 && l->z == 0)
		l->str = ft_itoa_base_u(va_arg(*ap, unsigned int), 16);
	else if (l->l == 1 && l->ll == 0 && l->h == 0 && l->hh == 0
		&& l->j == 0 && l->z == 0)
		l->str = ft_itoa_base_u(va_arg(*ap, uintmax_t), 16);
	else if (l->l == 0 && l->ll == 1 && l->h == 0 && l->hh == 0
		&& l->j == 0 && l->z == 0)
		l->str = ft_itoa_base_u(va_arg(*ap, unsigned long long), 16);
	else if (l->l == 0 && l->ll == 0 && l->h == 1 && l->hh == 0
		&& l->j == 0 && l->z == 0)
		l->str = ft_itoa_base_u((unsigned short)va_arg(*ap, unsigned int), 16);
	else if (l->l == 0 && l->ll == 0 && l->h == 0 && l->hh == 1
		&& l->j == 0 && l->z == 0)
		l->str = ft_itoa_base_u((unsigned char)va_arg(*ap, unsigned int), 16);
	else if (l->l == 0 && l->ll == 0 && l->h == 0 && l->hh == 0
		&& l->j == 1 && l->z == 0)
		l->str = ft_itoa_base_u(va_arg(*ap, uintmax_t), 16);
	else if (l->l == 0 && l->ll == 0 && l->h == 0 && l->hh == 0
		&& l->j == 0 && l->z == 1)
		l->str = ft_itoa_base_u(va_arg(*ap, size_t), 16);
	return (l);
}
