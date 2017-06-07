/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 03:08:17 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/05/29 17:16:30 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

header_t	*header_init(void)
{
	header_t *new;

	if (!(new = (header_t*)malloc(sizeof(header_t))))
		return (NULL);
	new->magic = COREWAR_EXEC_MAGIC;
	new->prog_size = 0;
	new->pos = 0;
	ft_bzero(new->prog_name, PROG_NAME_LENGTH);
	ft_bzero(new->comment, COMMENT_LENGTH);
	return (new);
}

t_label 	*init_label(t_label *label, char *line, int pos)
{
	int 	i;
	t_label *new;

	if (!(new = malloc(sizeof(t_label))))
		return (NULL);
	i = 0;
	line = ft_strtrim(line);
	new->line = NULL;
	new->pos = 0;
	new->next = NULL;
	while (line[i] != LABEL_CHAR)
		i++;
	if (single_label(label, line, i) == 0)
		{
			ft_printf("erreur_double_label");
			return (0);//erreur
		}
	new->line = ft_strsub(line, 0, i);
	new->line = ft_strjoin(new->line, "\0");
	new->pos = pos;
	new->next = label;
	return (new);
}