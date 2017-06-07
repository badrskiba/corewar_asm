/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 00:08:05 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/01/20 00:08:34 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_printf		*hash_flag(t_printf *l)
{
	if (l->o == 1 || l->mo == 1)
		l = make_char_before(l, 1, '0');
	if (l->x == 1)
		l = make_str_before(l, "0x");
	if (l->mx == 1)
		l = make_str_before(l, "0X");
	return (l);
}
