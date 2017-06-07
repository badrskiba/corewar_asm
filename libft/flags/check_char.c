/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:23:27 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/01/19 23:59:09 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
**	UxXcC%
*/

static t_printf	*check_char_3(char c, t_printf *l)
{
	if (c == 'U')
		l->mu = 1;
	else if (c == 'x')
		l->x = 1;
	else if (c == 'X')
		l->mx = 1;
	else if (c == 'c')
		l->c = 1;
	else if (c == 'C')
		l->mc = 1;
	else if (c == '%')
		l->mm = 1;
	return (l);
}

/*
**	sSpdDioOu
*/

static t_printf	*check_char_2(char c, t_printf *l)
{
	if (c == 's')
		l->s = 1;
	else if (c == 'S')
		l->ms = 1;
	else if (c == 'p')
		l->p = 1;
	else if (c == 'd')
		l->d = 1;
	else if (c == 'D')
		l->md = 1;
	else if (c == 'i')
		l->i = 1;
	else if (c == 'o')
		l->o = 1;
	else if (c == 'O')
		l->mo = 1;
	else if (c == 'u')
		l->u = 1;
	return (check_char_3(c, l));
}

/*
**	l ll h hh j z
*/

static t_printf	*check_char_1(char c, t_printf *l)
{
	if (c == 'l' && l->l == 0)
	{
		l->l = 1;
		l->hh = 0;
		l->h = 0;
	}
	else if (c == 'l' && l->l == 1)
	{
		l->l = 0;
		l->hh = 0;
		l->h = 0;
		l->ll = 1;
	}
	else if (c == 'j')
		l->j = 1;
	else if (c == 'z' && l->j == 0)
		l->z = 1;
	else if (c == 'h' && l->h == 0 && l->j == 0 && l->z == 0)
		l->h = 1;
	else if (c == 'h' && l->h == 1 && l->j == 0 && l->z == 0)
	{
		l->h = 0;
		l->hh = 1;
	}
	return (check_char_2(c, l));
}

/*
**	#+- 02. 02
*/

static t_printf	*check_char_0(char c, t_printf *l)
{
	if (c == '.')
	{
		l->precision = 1;
		l->pnum = 0;
	}
	else if (c == ' ' && l->precision == 1)
		l->pspace = 1;
	else if (c == '0' && l->precision == 1)
		l->pnum = l->pnum * 10;
	else if (c != '0' && ft_isdigit(c) == 1 && l->precision == 1)
		l->pnum = l->pnum * 10 + c - '0';
	return (check_char_1(c, l));
}

t_printf		*check_char(char c, t_printf *l)
{
	if (c == '#' && l->d == 0)
		l->hash = 1;
	else if (c == '+')
		l->plus = 1;
	else if (c == '-')
		l->min = 1;
	else if (c == ' ' && l->precision == 0)
	{
		l->zero = 0;
		l->space = 1;
	}
	else if (c == '0' && l->precision == 0 && l->num == 0)
		l->zero = 1;
	else if (c == '0' && l->precision == 0 && l->num != 0)
		l->num = l->num * 10;
	else if (c != '0' && ft_isdigit(c) == 1 && l->precision == 0)
		l->num = l->num * 10 + c - '0';
	return (check_char_0(c, l));
}
