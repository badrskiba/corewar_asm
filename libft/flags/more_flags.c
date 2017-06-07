/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 23:42:15 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/02/14 16:05:44 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		isitnull(char *s)
{
	if (s[0] == '(' && s[1] == 'n' && s[2] == 'u' && s[3] == 'l' && s[4] == 'l'
		&& s[5] == ')' && s[6] == '\0')
		return (1);
	return (0);
}

static t_printf	*more_flags_3(t_printf *l, int atoin, int no)
{
	if (l->space == 1 && l->num == 0 && l->mm == 0 && l->plus == 0 &&
		l->u == 0 && l->mu == 0 && atoin >= 0 && l->c == 0 && l->mc == 0 &&
		isitnull(l->str) == 0 && l->str[0] != '\0')
		make_char_before(l, 1, ' ');
	if (l->precision == 1 && ft_atoi(l->str) == 0 && l->hash == 0 &&
		(l->x == 1 || l->mx == 1 || l->o == 1 || l->mo == 1 ||
		l->d == 1 || l->md == 1) && no == 0)
		l->str[0] = '\0';
	if (l->num != 0 && l->zero == 0 && l->min == 0)
		make_char_before(l, (l->num - ft_strlen(l->str)), ' ');
	if (l->num != 0 && l->min == 1)
		make_char_after(l, (l->num - ft_strlen(l->str)), ' ');
	if (l->str[0] == '0' && l->zero == 1 && l->space == 1)
		l->str[0] = ' ';
	return (l);
}

static t_printf	*more_flags_2(t_printf *l, int atoin, int n, int no)
{
	if (l->pnum != 0 && l->s == 0 && l->ms == 0 && l->c == 0
			&& l->mc == 0 && l->mm == 0)
	{
		n = l->pnum - ft_strlen(l->str);
		if (atoin < 0)
			n++;
		make_char_before(l, n, '0');
		if (atoin < 0 && l->u == 0 && l->mu == 0 && l->x == 0 &&
			l->mx == 0 && l->o == 0 && l->mo == 0)
		{
			l->str[0] = '-';
			l->str[n] = '0';
		}
	}
	if (l->plus == 1 && atoin >= 0 && l->o == 0 && l->mo == 0 && l->s == 0)
		make_char_before(l, 1, '+');
	if (l->hash == 1 && ft_atoi(l->str) == 0 && l->precision == 1 &&
		(l->x == 1 || l->mx == 1))
		l->str[ft_strlen(l->str) - 1] = '\0';
	return (more_flags_3(l, atoin, no));
}

static t_printf	*more_flags_1(t_printf *l, int atoin, int n, int no)
{
	if (l->num != 0 && l->zero == 1 && l->min == 0)
	{
		n = l->num - ft_strlen(l->str) - l->plus;
		make_char_before(l, n, '0');
		if (atoin < 0 && l->u == 0 && l->mu == 0 && l->x == 0 &&
			l->mx == 0 && l->o == 0 && l->mo == 0)
		{
			l->str[0] = '-';
			l->str[n] = '0';
		}
	}
	if ((l->s == 1 || l->ms == 1) && l->precision == 1)
		l->str[l->pnum] = '\0';
	if (l->hash == 1 && atoin != 0)
	{
		if (!(l->str[0] == '0' && l->str[1] == '0'))
			l = hash_flag(l);
		else
			l->str[1] = 'x';
	}
	return (more_flags_2(l, atoin, n, no));
}

t_printf		*more_flags(t_printf *l)
{
	int atoin;
	int n;
	int no;

	no = 0;
	n = 0;
	atoin = 0;
	if (l->zero == 1 && l->num != 0 && l->precision == 1 && l->pnum != 0)
		no = 1;
	if (l->min == 1)
		l->zero = 0;
	if (l->str[0] != '\0')
		atoin = ft_atoi(l->str);
	if (atoin == 0 && (l->i == 1 || l->u == 1) && l->precision == 1)
		l->str[0] = 0;
	if (atoin < 0)
		l->plus = 0;
	if (l->zero == 1 && l->precision == 1)
		l->zero = 0;
	return (more_flags_1(l, atoin, n, no));
}
