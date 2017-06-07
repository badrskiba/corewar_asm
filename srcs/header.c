/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 17:16:56 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/05/29 17:19:44 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

static int ft_strlenchr(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

static header_t *copy_into_header(char *line, header_t *header, int type)
{
	char *tmp;

	tmp = NULL;
	if (type == 0)
	{
		tmp = ft_strsub(line, 0, ft_strlenchr(line, '"'));
		ft_strncat(header->prog_name, tmp, PROG_NAME_LENGTH); 
	}
	else
	{
		tmp = ft_strsub(line, 0, ft_strlenchr(line, '"'));
		ft_strncat(header->comment, tmp, COMMENT_LENGTH);
	}
	if (tmp != NULL)
		free(tmp);
	return (header);
}

static int header_pos(char *line, int name, int comment, int tmp)
{
	int i;

	i = 0;
	if (tmp == 0)
		i = name;
	else
		i = comment;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '"')
		i++;
	return (i);
}


static header_t *copy_name_comment(char *line, header_t *header)
{
	int i;
	char *tmp;
	int name;
	int comment;

	name = ft_strlen(NAME_CMD_STRING);
	comment = ft_strlen(COMMENT_CMD_STRING);
	i = 0;
	tmp = NULL;

	if(!header->prog_name[0] && ft_strncmp(NAME_CMD_STRING, line, name) == 0)
	{
		i = header_pos(line, name, comment, 0); // avance le curseur jusqu'au 1er " 
		header = copy_into_header(&line[i], header, 0); // copy le nom du joueur jusqu'au dernier " non inclus
	}
	else if(!header->comment[0 && ft_strncmp(COMMENT_CMD_STRING, line, name) == 0])
	{
		i = header_pos(line, name, comment, 1); 
		header = copy_into_header(&line[i], header, 1);// copy le commentaire jusqu'au dernier " non inclus
	}
	return (header);
}

/*
Stocker le nom et le commentaire dans la struct(header), 
le nom et le commentaire sont forcement correct vu la partie check realiser au debut du main
*/
header_t	*header_name_comment(int fd, header_t *header)
{
	int i;
	int a;
	char *line;

	i = 0;
	a = 0;
	line = NULL;

	while (get_next_line(fd, &line) > 0)
	{
		if(line[0] != COMMENT_CHAR && line[0] != '\0')
		{
			while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
				i++;
			header = copy_name_comment(&line[i], header);
			a ++;
		}
		if (a == 2)
		break;
		free(line);
		line = NULL;
	}
	return (header);
}