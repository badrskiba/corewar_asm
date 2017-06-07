/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 14:41:42 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/01/24 00:15:06 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		free_printf(t_printf **l)
{
	t_printf	*tmp;

	while (*l)
	{
		tmp = *l;
		if ((*l)->str)
			free((*l)->str);
		if ((*l)->wstr)
			free((*l)->wstr);
		*l = (*l)->next;
		free(tmp);
	}
}
