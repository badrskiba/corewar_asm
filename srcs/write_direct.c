#include "../asm.h"

 int find_adress(t_label *label,char **file)
{
	char *tmp;

	while (label)
	{
		tmp = ft_strsub(*file, 0, ft_strlen(label->line));
		if (ft_strcmp(label->line, tmp) == 0)
			{
				ft_printf("label->line: %s", label->line);
				ft_printf("tmp: %s\n", tmp);
				ft_printf("label->pos: %d", label->pos);
				ft_printf("count : %d\n", count);
				if (line == 0)
					return (label->pos);
				else if ( line > 0)
					return (label->pos - count + 1);
			}
		label = label->next;
	}
	return (0);
}

int	write_direct(char **file, int fd, t_label *label, int octet)
{
	int i;

	i = 0;
	if (**file == DIRECT_CHAR)
	{
		(*file)++;	
		if (**file == LABEL_CHAR)
		{
			(*file)++;
			i = find_adress(label, file);
		}
		else 
			i = ft_atoi(*file);
		if (octet == 4)
			i = invert_binary(i);
		else		
			i = invert_binary_2(i);
		write(fd, &i, octet);
		*file = ft_strtrim(*file);
		move_to_nextarg(file);
		count = count + octet;
		return (1);
	}
	return (0);
}