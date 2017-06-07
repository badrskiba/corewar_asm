/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:22:25 by mtagaizi          #+#    #+#             */
/*   Updated: 2016/12/23 18:20:58 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int n, int pow)
{
	int nb;

	nb = n;
	if (pow == 1)
		return (n);
	else if (pow == 0)
		return (1);
	else if (pow < 0)
	{
		ft_putendl_fd(
			"Error :ft_pow(n, pow) doesn't work for negative values for pow"
			, 2);
		return (0);
	}
	while (pow > 1)
	{
		nb = nb * n;
		pow--;
	}
	return (nb);
}
