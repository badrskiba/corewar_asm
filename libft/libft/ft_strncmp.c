/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 20:54:51 by mtagaizi          #+#    #+#             */
/*   Updated: 2016/12/11 23:27:06 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i + 1 < n && s1[i] == s2[i] && s1[i] != '\0')
		i++;
	if (s1[i] < 0 && s2[i] > -1)
		return (1);
	else if (s2[i] < 0 && s1[i] > -1)
		return (-1);
	else if (s1[i] == s2[i] || n == 0)
		return (0);
	return (s1[i] - s2[i]);
}
