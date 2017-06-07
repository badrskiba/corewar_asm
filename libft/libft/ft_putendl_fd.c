/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:52:39 by mtagaizi          #+#    #+#             */
/*   Updated: 2016/12/21 00:30:56 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	if (!s)
	{
		ft_putendl_fd("(null)", fd);
		return ;
	}
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}
