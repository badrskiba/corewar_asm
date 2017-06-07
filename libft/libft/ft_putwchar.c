/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 20:38:08 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/02/15 16:11:22 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar(int chr)
{
	if (chr <= 127)
		ft_putchar(chr);
	else if (chr <= 2047)
	{
		ft_putchar((chr >> 6) + 192);
		ft_putchar((chr & 63) + 128);
	}
	else if (chr <= 65535)
	{
		ft_putchar((chr >> 12) + 224);
		ft_putchar(((chr >> 6) & 63) + 128);
		ft_putchar((chr & 63) + 128);
	}
	else if (chr <= 1114111)
	{
		ft_putchar((chr >> 18) + 240);
		ft_putchar(((chr >> 12) & 63) + 128);
		ft_putchar(((chr >> 6) & 63) + 128);
		ft_putchar((chr & 63) + 128);
	}
}
