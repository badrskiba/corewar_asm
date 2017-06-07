#include "../asm.h"

static int write_function_next_2(t_label *label, char **file, int fd, int opb)
{
	if ((opb == 10 || opb == 14) &&  (write_opc(fd, 3, *file)) &&
		(write_registre(file, fd) || write_indirect(file, fd, label) 
			|| write_direct(file, fd, label, 2))
	 	&&(write_registre(file, fd) || 
	 	write_direct(file, fd, label, 2)) &&  write_registre(file, fd))
		return (1);
	else if ((opb == 11) && write_opc(fd, 3, *file) && 
			(write_registre(file, fd)) && 
			(write_registre(file, fd) || write_indirect(file, fd, label) || 
			 write_direct(file, fd, label, 2))
			 && (write_direct(file, fd, label, 2) || write_registre(file, fd)))
		return (1);
	else if ((opb == 13) && write_opc(fd, 2, *file) && ((write_direct(file, fd, label, 4)) || 
		write_direct(file, fd, label, 2)) &&  write_registre(file, fd))
		return(1);
	else if ((opb == 16) && write_registre(file, fd))
		return (1);
	return(0);

}

static int write_function_next(t_label *label, char **file, int fd, int opb)
{
	if ((opb == 1) && (write_direct(file, fd, label, 4)))
		return(1);
	else if ((opb == 9 || opb == 12 || opb == 15) &&
	 (write_direct(file, fd, label, 2)))
		return(1);
	else if((opb == 2 || opb == 13) && (write_opc(fd, 2, *file)) 
	&& (write_direct(file, fd, label, 4) || (write_indirect(file, fd, label)))
	 && (write_registre(file, fd)))
		return(1);
	else if((opb == 3) && (write_opc(fd, 2, *file)) 
	&& (write_registre(file, fd)) && ((write_indirect(file, fd, label))
	 || (write_registre(file, fd))))
		return(1);
	else if ((opb == 5 || opb == 4) && (write_opc(fd, 3, *file)) 
		&& write_registre(file, fd)&& write_registre(file, fd)
		&& write_registre(file, fd))
		return (1);
	else if ((opb == 6 || opb == 7 || opb == 8) &&(write_opc(fd, 3, *file))&& (write_registre(file, fd)||
		write_indirect(file, fd, label)|| write_direct(file, fd, label, 4))
		&& (write_registre(file, fd) || write_indirect(file, fd, label)
			|| write_direct(file, fd, label, 4))
		&& (write_registre(file, fd)))
		return (1);
	if (write_function_next_2(label, file, fd, opb))
		return (1);
	return (0);
}

static void write_function(t_label *label, char **file, int fd)
{
	int opb;

	opb = 0;
	if ((opb = id_function(*file)))
		count++;
	if (opb == 2 || opb == 3 || opb == 7)
		*file = *file + 2;
	else if (opb == 4 || opb == 6 || opb == 5 || opb == 8 || opb == 10 ||
			 opb == 11 || opb == 13 || opb == 11 || opb == 16)
		*file = *file + 3;
	else if (opb == 15)
		*file = *file + 5;
	else
		*file = *file + 4;
	*file = ft_strtrim(*file);
	write(fd, &opb, 1);
	if (write_function_next(label, file, fd, opb))
		return;
	else
	{
		ft_printf("write instruction : %d\n", opb);
		//ft_printf("error write function");
		return ;
	}
}

void write_instruction(t_label *label, char *file, int fd)
{
	count = 0;
	line = 0;
	while (*file)
	{
		write_function(label, &file, fd);
		while(*file && *file != '\n')
			file++;
		file++;
		line ++;
	}
}