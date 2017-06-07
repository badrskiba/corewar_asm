/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_is_mx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:51:32 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/01/18 17:48:48 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static t_printf	*next_static(t_printf *l, va_list *ap, uintmax_t nb, char *tmp)
{
	if (l->l == 0 && l->ll == 0 && l->h == 0 && l->hh == 1
		&& l->j == 0 && l->z == 0)
		nb = (unsigned char)va_arg(*ap, unsigned int);
	else if (l->l == 0 && l->ll == 0 && l->h == 0 && l->hh == 0
		&& l->j == 1 && l->z == 0)
		nb = va_arg(*ap, uintmax_t);
	else if (l->l == 0 && l->ll == 0 && l->h == 0 && l->hh == 0
		&& l->j == 0 && l->z == 1)
		nb = va_arg(*ap, size_t);
	tmp = ft_itoa_base_u(nb, 16);
	l->str = ft_capitalize(tmp);
	free(tmp);
	return (l);
}

t_printf		*flag_is_mx(t_printf *l, va_list *ap)
{
	uintmax_t	nb;
	char		*tmp;

	nb = 0;
	tmp = NULL;
	if (l->l == 0 && l->ll == 0 && l->h == 0 && l->hh == 0
		&& l->j == 0 && l->z == 0)
		nb = va_arg(*ap, unsigned int);
	else if (l->l == 1 && l->ll == 0 && l->h == 0 && l->hh == 0
		&& l->j == 0 && l->z == 0)
		nb = va_arg(*ap, unsigned long);
	else if (l->l == 0 && l->ll == 1 && l->h == 0 && l->hh == 0
		&& l->j == 0 && l->z == 0)
		nb = va_arg(*ap, unsigned long long);
	else if (l->l == 0 && l->ll == 0 && l->h == 1 && l->hh == 0
		&& l->j == 0 && l->z == 0)
		nb = (unsigned short)va_arg(*ap, unsigned int);
	return (next_static(l, ap, nb, tmp));
}
