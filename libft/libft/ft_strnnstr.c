/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnnstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 17:44:19 by mtagaizi          #+#    #+#             */
/*   Updated: 2016/12/23 18:14:39 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
******************************************************************
**																**
**	ft_strnnstr (beg, end, dst, src) :							**
**	it puts the src in dst from dst[beg] tp dst[end]			**
**																**
******************************************************************
*/

char		*ft_strnnstr(int beg, int end, char *dst, char *src)
{
	return (ft_strjoin(ft_strjoin(before_stri(dst, beg), src), dst + end + 1));
}
