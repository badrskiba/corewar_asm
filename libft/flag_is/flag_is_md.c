/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_is_md.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:51:32 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/01/16 23:02:17 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_printf		*flag_is_md(t_printf *l, va_list *ap)
{
	intmax_t nb;

	nb = va_arg(*ap, intmax_t);
	l->str = ft_itoa_max(nb);
	return (l);
}
