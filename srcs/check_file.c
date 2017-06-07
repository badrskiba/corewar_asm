/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 18:37:05 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/05/29 17:38:35 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

static t_file	*add_tofile(char *line, t_file *next, t_file *file)
{
	int index;

	index = 1;
	if (!(file = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	if (next)
		index = next->index + 1;
	file->index = index;
	file->next = next;
	file->line = ft_strdup(line);
	return (file);
}

static t_file	*reverse_file(t_file *old, t_file *new)
{
	while (old)
	{
		new = add_tofile(old->line, new, NULL);
		old = old->next;
	}
	return (new);
}

int				check_file(int ac, char **av)
{
	int 	index;
	char	*txt;
	int		fd;
	t_file	*file;

	file = NULL;
	index = 1;
	if (av[1] && ft_strcmp(av[1], "-a") == 0)
		index = 2;
	fd = open(av[index], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Fichier introuvable\n");
		return -5;
	}
	while (get_next_line(fd, &txt) == 1){
		if (ft_strcmp(ft_strtrim(txt),"") != 0){
			//ft_printf("%s\n", txt);
			file = add_tofile(txt, file, NULL);
		}
	}
	if (!file)
		return(ft_printf("Error\n"));
	file = reverse_file(file, NULL);
	if (check_name_com(file) == -1)
		return (-1);
	return (1);
}
