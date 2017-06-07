/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:51:05 by mtagaizi          #+#    #+#             */
/*   Updated: 2016/12/11 23:16:39 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		index;
	int		tab[10];

	index = -1;
	if (n > 2147483647 || n < -2147483648)
		return ;
	else if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n == 0)
		ft_putchar_fd(48, fd);
	else if (n < 0)
	{
		n = n * -1;
		ft_putchar_fd('-', fd);
	}
	while (n > 0)
	{
		index++;
		tab[index] = (n % 10) + 48;
		n = n / 10;
	}
	while (index >= 0)
	{
		ft_putchar_fd(tab[index--], fd);
	}
}
