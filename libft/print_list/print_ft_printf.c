/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 14:41:42 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/02/14 16:50:08 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static t_printf	*reverse_ft_printf(t_printf *l)
{
	t_printf	*new;
	t_printf	*tmp;
	t_printf	*tmpp;

	new = NULL;
	tmpp = l;
	while (l)
	{
		tmp = new;
		new = printf_copy(l);
		new->next = tmp;
		l = l->next;
	}
	free_printf(&tmpp);
	return (new);
}

static t_printf	*make_len(t_printf *l)
{
	t_printf	*tmp;

	tmp = l;
	while (l)
	{
		if (l->wchr == 0 && l->str)
			l->len = ft_strlen(l->str);
		else if (l->wstr && l->wchr == 1)
		{
			l->len = ft_wstrlen(l->wstr) + l->num;
			if (l->wstr && l->zero == 0)
				while (l->num-- > 0)
					ft_putchar(' ');
			else if (l->wstr && l->zero == 1)
				while (l->num-- > 0)
					ft_putchar('0');
		}
		else
			l->len = 0;
		l = l->next;
	}
	return (tmp);
}

static void		print_printf_2(t_printf *l)
{
	if (l->num > 0)
		l->num--;
	if (l->c == 1 || l->mc == 1)
		l->len = 1 + l->num;
	if (l->zero == 0)
		while (l->num)
		{
			ft_putchar(' ');
			l->num--;
		}
	else
		while (l->num)
		{
			ft_putchar('0');
			l->num--;
		}
	ft_putchar(0);
}

static void		print_printf(t_printf *l)
{
	if (l->empty == 1)
	{
		if (l->s == 1 || l->ms == 1)
		{
			ft_putstr("(null)");
			l->len = 6;
		}
		else
			print_printf_2(l);
	}
	else
	{
		if (l->wchr == 0)
			ft_putstr(l->str);
		else
			ft_putwstr(l->wstr);
	}
}

int				print_ft_printf(t_printf *l)
{
	int			ret;
	t_printf	*tmp;

	ret = 0;
	l = reverse_ft_printf(l);
	l = make_len(l);
	tmp = l;
	while (l)
	{
		print_printf(l);
		ret = ret + l->len;
		l = l->next;
	}
	free_printf(&tmp);
	return (ret);
}
