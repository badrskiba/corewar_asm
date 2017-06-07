/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:08:52 by mtagaizi          #+#    #+#             */
/*   Updated: 2016/12/11 23:12:50 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_liste;
	t_list	*tet_liste;

	if (!(new_liste = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	tet_liste = (*f)(lst);
	new_liste = tet_liste;
	while (lst->next != NULL)
	{
		new_liste->next = (*f)(lst->next);
		new_liste = new_liste->next;
		lst = lst->next;
	}
	return (tet_liste);
}
