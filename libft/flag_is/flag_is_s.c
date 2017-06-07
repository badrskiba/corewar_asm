/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_is_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:51:32 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/01/19 16:40:33 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_printf		*flag_is_s(t_printf *l, va_list *ap)
{
	char *tmp;

	if (l->empty == 0)
	{
		if (l->s == 1 && l->l == 0 && l->ll == 0)
		{
			if (!(tmp = va_arg(*ap, char*)))
				l->empty = 1;
			l->str = ft_strdup(tmp);
		}
		else if (l->s == 1 && (l->l == 1 || l->ll == 1))
			return (flag_is_ms(l, ap));
	}
	return (l);
}
