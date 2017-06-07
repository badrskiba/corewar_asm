/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_asm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 18:37:31 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/05/29 17:16:41 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

static t_label *parse_line(int fd, char **file, int *pos)
{
	t_label *label;
	char *line;
	int i;
	int tmp_pos;

	line = NULL;
	label = NULL;
	i = 0;
	tmp_pos = 0;

	while (get_next_line(fd, &line) > 0)
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i] != COMMENT_CHAR && check_label(line) == 1)
		{
			label = init_label(label, line, tmp_pos);
			while(line[i] != LABEL_CHAR)
				i++;
			i++;
		}
		fill_instruct(line, &tmp_pos, i, file);
		i = 0;
		line = NULL;
	}
	*pos = tmp_pos;
	free(line);
	return (label);
}

int	parsing_file(char *player, header_t *header)
{
	int fd;
	char *file;
	int  i;
	int pos;
	t_label *label;

	file = NULL;
	i = 0;
	pos = 0;
	label = NULL;
	if ((fd = open(player, O_RDONLY)) == -1)
		return (-1);
	header = header_name_comment(fd, header); 
	label = parse_line(fd, &file, &pos);
	header->pos = pos;
	//ft_printf("file :\n %s", file);
	/*while (label)
	{
		ft_printf("label: %s\n", label->line);
		label = label->next;
	}*/
	if (verif_label(label, file) == -1)
		{
			ft_printf("erreur label non existing in .s\n");
			return(0);
		}
	write_asm(label, file, header, player);
	//free(label);
	//free(file);*/
	return (0);
}
