/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:58:44 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/01/18 17:40:47 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	itoa base :
**
**		base min : 2
**		base max : 16
*/

static char	*next_static(char *tmp, char **src, char **tab)
{
	tmp = ft_strrev(*src);
	free(*tab);
	free(*src);
	return (tmp);
}

char		*ft_itoa_base(long nb, int base)
{
	char	*tab;
	char	*src;
	char	*tmp;
	long	i;
	short	n;

	i = 0;
	n = 0;
	tmp = NULL;
	tab = ft_nstr("0123456789abcdef");
	if (base > 16 || base < 2)
		return (NULL);
	if (!(src = (char*)malloc(sizeof(char) * 1000)))
		return (NULL);
	if (nb == 0)
		return (ft_strdup("0"));
	if (nb < 0)
		if ((n = 1))
			nb = nb * -1;
	while (nb != 0)
		if ((src[i++] = tab[nb % base]))
			nb = nb / base;
	if (n == 1)
		src[i++] = '-';
	return (next_static(tmp, &src, &tab));
}
