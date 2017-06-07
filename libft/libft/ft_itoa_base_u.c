/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:55:24 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/01/23 13:40:31 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	itoa base :
**
**		base min : 2
**		base max : 16
*/

size_t		ft_nlen(uintmax_t nb, int base)
{
	size_t i;

	i = 0;
	while (nb > 1)
	{
		i++;
		nb = nb / base;
	}
	return (i + 3);
}

static char	*next_static(char *tmp, char **src, char **tab)
{
	tmp = ft_strrev(*src);
	free(*tab);
	free(*src);
	return (tmp);
}

char		*ft_itoa_base_u(uintmax_t nb, int base)
{
	char			*tab;
	char			*src;
	char			*tmp;
	unsigned long	i;
	short			n;

	i = 0;
	n = 0;
	tmp = NULL;
	tab = ft_strdup("0123456789abcdef");
	if (nb == 0 || !nb)
		return (ft_nstr("0"));
	if (base > 16 || base < 2)
		return (NULL);
	if (!(src = (char*)malloc(sizeof(char) * ft_nlen(nb, base))))
		return (NULL);
	if (nb == 0)
		return (ft_strdup("0"));
	while (nb != 0)
		if ((src[i++] = tab[nb % base]))
			nb = nb / base;
	if (n == 1)
		src[i++] = '-';
	src[i] = 0;
	return (next_static(tmp, &src, &tab));
}
