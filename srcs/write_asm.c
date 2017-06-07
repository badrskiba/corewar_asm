#include "../asm.h"

void	move_to_nextarg(char **file)
{
	while (**file && **file != SEPARATOR_CHAR && **file != '\n')
		(*file)++;
	if (**file == '\n')
		return ;
	(*file)++;
	*file = ft_strtrim(*file);
	return ;
}

static char *file_name(char *str, header_t *header)
{
	char *tmp;

	tmp = ft_strsub(str, 0, ft_strlen(str) - 2);
	tmp = ft_strjoin(tmp, ".cor");
	return (tmp);
}

void write_asm(t_label *label, char *file, header_t *header, char *player)
{
	int fd;
	char *file1;

	fd = 0;
	file1 = file_name(player, header);
	if ((fd = open(file1, O_RDWR | O_CREAT | O_TRUNC | O_APPEND, 777)) > -1)
	{
		write_header(header, fd);
		write_instruction(label, file, fd);
	}
	return ;
}