/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:10:43 by mtagaizi          #+#    #+#             */
/*   Updated: 2016/12/11 23:12:21 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (alst)
	{
		while (*alst != NULL)
		{
			tmp = (*alst)->next;
			(*del)((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = tmp;
		}
		*alst = NULL;
	}
}
