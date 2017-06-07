/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 14:35:55 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/02/14 04:40:25 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_printf		*simple_process(char *s, int i, t_printf *n)
{
	t_printf	*l;
	int			index;

	index = 0;
	l = init_printf_list(n);
	l->simple = 1;
	if (!(l->str = (char*)malloc(sizeof(char) * (i - n->end + 1))))
		return (NULL);
	while (n->end < i)
		l->str[index++] = s[n->end++];
	l->str[index] = '\0';
	return (l);
}

static t_printf		*ft_printf_bis(char *s, int i, t_printf *l, va_list *ap)
{
	if (i - l->end > 0)
		l = simple_process(s, i, l);
	l = str_flags(s, ++i, l);
	if (l->empty == 0)
	{
		l = flags_str(l, ap);
		if (l->empty == 0 && l->wchr == 0 && l->p == 0)
			l = more_flags(l);
	}
	return (l);
}

int					ft_printf(const char *format, ...)
{
	char		*s;
	int			i;
	t_printf	*l;
	va_list		ap;

	s = (char*)format;
	i = 0;
	l = NULL;
	va_start(ap, (char*)format);
	l = init_printf_list(l);
	l->str = ft_strdup("\0");
	while (s[i])
	{
		if (s[i] == '%')
		{
			l = ft_printf_bis(s, i, l, &ap);
			i = l->end;
		}
		else
			i++;
	}
	va_end(ap);
	if (i - l->end > 0)
		l = simple_process(s, i, l);
	return (print_ft_printf(l));
}
