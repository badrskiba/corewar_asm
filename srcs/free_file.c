/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 18:37:38 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/05/26 04:16:51 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

void	free_file(t_file **file)
{
	t_file	*tmp;

	tmp = NULL;
	while ((*file))
	{
		tmp = (*file)->next;
		free((*file)->line);
		(*file)->line = NULL;
		(*file)->index = 0;
		(*file)->instruct = 0;
		free((*file));
		(*file) = tmp;
	}
}
