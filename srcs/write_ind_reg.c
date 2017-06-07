#include "../asm.h"

int	write_indirect(char **file, int fd, t_label *label)
{
	int i;

	i = 0;
	if (**file != LABEL_CHAR && !ft_isdigit(**file) && **file != '-')
		return (0);
	if (**file == LABEL_CHAR)
	{
		(*file)++;	
		i = find_adress(label, file);
	}
	else
		i = ft_atoi(*file);
	i = invert_binary_2(i);
	write(fd, &i, IND_SIZE);
	count = count + IND_SIZE;
	move_to_nextarg(file);
	return (1);
}

int write_registre(char **file, int fd)
{
	int i;

	i = 0;
	if (**file != 'r')
		return (0);
	(*file)++;
	i = ft_atoi(*file);
	//ft_printf("%d\n", i);
	write(fd, &i,  REG_SIZE);
	count = count + REG_SIZE;
	move_to_nextarg(file);
	return(1);
}