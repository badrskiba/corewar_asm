/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_z.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:53:17 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/03/06 15:55:08 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_z(char **z)
{
	int		i;
	int		count;

	i = 0;
	count = ft_ztrlen(z);
	while (i < count)
		free(z[i++]);
	free(z);
}
