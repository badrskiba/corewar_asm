/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 05:20:30 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/03/14 20:53:27 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct			s_printf
{
	char				*str;
	wchar_t				*wstr;
	char				character;
	int					len;
	char				wchr;
	int					end;
	char				simple;
	char				empty;

	char				hash;
	char				plus;
	char				min;
	char				space;
	char				zero;
	int					num;
	char				precision;
	char				pspace;
	char				pzero;
	int					pnum;

	char				l;
	char				ll;
	char				h;
	char				hh;
	char				j;
	char				z;

	char				s;
	char				ms;
	char				p;
	char				d;
	char				md;
	char				i;
	char				o;
	char				mo;
	char				u;
	char				mu;
	char				x;
	char				mx;
	char				c;
	char				mc;
	char				mm;

	struct s_printf		*next;
}						t_printf;

/*
**---------------------------
**	init
*/
t_printf				*init_printf_list(t_printf *next);
/*
**---------------------------
*/

/*
**---------------------------
**	flags
*/
t_printf				*hash_flag(t_printf *l);
t_printf				*make_str_before(t_printf *l, char *s);
t_printf				*make_char_after(t_printf *l, int len, char c);
t_printf				*make_char_before(t_printf *l, int len, char c);

t_printf				*check_char(char c, t_printf *l);
t_printf				*str_flags(char *s, int i, t_printf *next);
t_printf				*flags_str(t_printf *l, va_list *ap);

t_printf				*more_flags(t_printf *l);
/*
**---------------------------
*/

/*
**---------------------------
**	print_list
*/
t_printf				*printf_copy(t_printf *l);
int						print_ft_printf(t_printf *l);
void					free_printf(t_printf **l);
/*
**---------------------------
*/

/*
**---------------------------
**	flag_is
*/
t_printf				*flag_is_s(t_printf *l, va_list *ap);
t_printf				*flag_is_ms(t_printf *l, va_list *ap);
t_printf				*flag_is_c(t_printf *l, va_list *ap);
t_printf				*flag_is_mc(t_printf *l, va_list *ap);
t_printf				*flag_is_d(t_printf *l, va_list *ap);
t_printf				*flag_is_md(t_printf *l, va_list *ap);
t_printf				*flag_is_i(t_printf *l, va_list *ap);
t_printf				*flag_is_o(t_printf *l, va_list *ap);
t_printf				*flag_is_mo(t_printf *l, va_list *ap);
t_printf				*flag_is_x(t_printf *l, va_list *ap);
t_printf				*flag_is_mx(t_printf *l, va_list *ap);
t_printf				*flag_is_u(t_printf *l, va_list *ap);
t_printf				*flag_is_mu(t_printf *l, va_list *ap);
t_printf				*flag_is_m(t_printf *l);
t_printf				*flag_is_p(t_printf *l, va_list *ap);
/*
**---------------------------
*/

int						ft_printf(const char *format, ...);

#endif
