/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_is_mu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:51:32 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/01/23 13:43:09 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_printf		*flag_is_mu(t_printf *l, va_list *ap)
{
	l->str = ft_itoa_base_u(va_arg(*ap, uintmax_t), 10);
	return (l);
}
