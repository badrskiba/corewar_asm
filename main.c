/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 17:48:57 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/05/29 17:22:04 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int main(int ac, char **av)
{
	int			error;
	int 		index;
	header_t	*header;
	t_file		*file;

	index = 1;
	if ((error = check_param(ac, av)) < 0)
		return (error__(error));
	if ((error = check_file(ac, av)) != 1)
		return (error__(error));

/*
Le while permet de gerer plusieurs champions*/
	while (index < ac)
	{
		header = header_init();
		if (parsing_file(av[index++], header) == -1)
			ft_printf("put a valid champs");
		free(header);
		header = NULL;
	}
	//if (!(file = get_file(av[1], NULL)))
	//	return (error__(1));
	//if (parse_asm(file) == -1)
	//	return (-1);
	//free_file(&file);
	return (0);
}
