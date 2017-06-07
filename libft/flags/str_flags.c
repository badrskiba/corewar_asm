/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:49:23 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/01/19 23:59:41 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_printf		*str_flags(char *s, int i, t_printf *next)
{
	t_printf	*l;

	l = init_printf_list(next);
	while (s[i] == ' ' || s[i] == '#' || s[i] == '-' || s[i] == '+' ||
		s[i] == '.' || ft_isdigit(s[i]) == 1 || s[i] == 'h' || s[i] == 'l' ||
		s[i] == 'j' || s[i] == 'z')
	{
		l = check_char(s[i], l);
		l->end = i;
		i++;
	}
	if (s[i] == 's' || s[i] == 'S' || s[i] == 'p' || s[i] == 'd' ||
		s[i] == 'D' || s[i] == 'i' || s[i] == 'o' || s[i] == 'O' ||
		s[i] == 'u' || s[i] == 'U' || s[i] == 'x' || s[i] == 'X' ||
		s[i] == 'c' || s[i] == 'C' || s[i] == '%')
	{
		l = check_char(s[i], l);
		l->end = ++i;
	}
	else
	{
		l->empty = 1;
		l->end = i;
	}
	return (l);
}
