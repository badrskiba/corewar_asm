/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:42:41 by mtagaizi          #+#    #+#             */
/*   Updated: 2016/12/23 15:05:53 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nlen(intmax_t n)
{
	short	np_conv;
	int		counter;

	np_conv = 0;
	counter = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		np_conv = 1;
		counter = 1;
	}
	while (n != 0)
	{
		counter++;
		n = n / 10;
	}
	return (counter);
}

char			*ft_itoa_max(intmax_t n)
{
	char	*s;
	int		nlen;
	short	np_conv;

	nlen = ft_nlen(n);
	np_conv = 1;
	if (n < 0)
		np_conv = -1;
	else if (n == 0)
		return (ft_nstr("0"));
	if (!(s = (char*)malloc(sizeof(char) * (nlen + 1))))
		return (NULL);
	s[nlen--] = '\0';
	while (n != 0)
	{
		s[nlen] = '0' + (n % 10) * np_conv;
		n = n / 10;
		nlen--;
	}
	if (np_conv == -1)
		s[nlen] = '-';
	return (s);
}
