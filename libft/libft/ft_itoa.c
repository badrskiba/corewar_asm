/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 20:45:00 by mtagaizi          #+#    #+#             */
/*   Updated: 2016/12/23 15:07:22 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	combien_char(int i)
{
	int				o;
	int				c;

	c = 1;
	o = 1000000000;
	while (i / o == 0 && o > 1)
		o /= 10;
	while (o > 1)
	{
		o = o / 10;
		c++;
	}
	if (i > -1)
		return (c);
	else
		return (c + 1);
}

static void	prepare(int *i, int *o, unsigned int *j, int *n)
{
	*o = 1000000000;
	*i = 0;
	*j = *n;
}

char		*ft_itoa(int n)
{
	char			*strn;
	int				i;
	int				o;
	unsigned int	j;

	prepare(&i, &o, &j, &n);
	if ((strn = ft_strnew(combien_char(n))) == NULL)
		return (NULL);
	if (n < 0)
	{
		strn[0] = '-';
		i++;
		j = -n;
	}
	while (j / o == 0 && o > 1)
		o /= 10;
	while (o > 0)
	{
		strn[i] = (j / o) + '0';
		j = j % o;
		o /= 10;
		i++;
	}
	strn[i] = '\0';
	return (strn);
}
