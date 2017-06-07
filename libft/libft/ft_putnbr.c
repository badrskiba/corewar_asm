/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:51:05 by mtagaizi          #+#    #+#             */
/*   Updated: 2016/12/11 23:15:32 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr(int n)
{
	int		index;
	int		tab[10];

	index = -1;
	if (n > 2147483647 || n < -2147483648)
		return ;
	else if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n == 0)
		ft_putchar(48);
	else if (n < 0)
	{
		n = n * -1;
		ft_putchar('-');
	}
	while (n > 0)
	{
		index++;
		tab[index] = (n % 10) + 48;
		n = n / 10;
	}
	while (index >= 0)
	{
		ft_putchar(tab[index--]);
	}
}
