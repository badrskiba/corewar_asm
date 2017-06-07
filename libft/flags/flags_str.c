/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:11:54 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/01/19 23:59:31 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static t_printf	*flags_str_bis(t_printf *l, va_list *ap)
{
	if (l->u == 1)
		l = flag_is_u(l, ap);
	else if (l->mu == 1)
		l = flag_is_mu(l, ap);
	else if (l->x == 1)
		l = flag_is_x(l, ap);
	else if (l->mx == 1)
		l = flag_is_mx(l, ap);
	else if (l->c == 1)
		l = flag_is_c(l, ap);
	else if (l->mc == 1)
		l = flag_is_mc(l, ap);
	else if (l->mm == 1)
		l = flag_is_m(l);
	return (l);
}

t_printf		*flags_str(t_printf *l, va_list *ap)
{
	if (l->s == 1)
		l = flag_is_s(l, ap);
	else if (l->ms == 1)
		l = flag_is_ms(l, ap);
	else if (l->p == 1)
		l = flag_is_p(l, ap);
	else if (l->d == 1)
		l = flag_is_d(l, ap);
	else if (l->md == 1)
		l = flag_is_md(l, ap);
	else if (l->i == 1)
		l = flag_is_i(l, ap);
	else if (l->o == 1)
		l = flag_is_o(l, ap);
	else if (l->mo == 1)
		l = flag_is_mo(l, ap);
	return (flags_str_bis(l, ap));
}
