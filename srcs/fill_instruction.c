#include "../asm.h"

 static int id_function_next(char *line)
 {
	if (ft_strncmp("ld", line, 2) == 0)
		return (2);
	if (ft_strncmp("sti", line, 3) == 0)
		return (11);
	if (ft_strncmp("st", line, 2) == 0)
		return (3);
	if (ft_strncmp("fork", line, 4) == 0)
		return (12);
	if (ft_strncmp("lldi", line, 4) == 0)
		return (14);
	if (ft_strncmp("lld", line, 3) == 0)
		return (13);
	if (ft_strncmp("lfork", line, 4) == 0)
		return (15);
	if (ft_strncmp("aff", line, 3) == 0)
		return (16);
	return (0);
 }
 
 int 	id_function(char *line)
 {
 	if (ft_strncmp("live", line, 4) == 0)
		return (1);
	if (ft_strncmp("add", line, 3) == 0)
		return (4);
	if (ft_strncmp("sub", line, 3) == 0)
		return (5);
	if (ft_strncmp("and", line, 3) == 0)
		return (6);
	if (ft_strncmp("or", line, 2) == 0)
		return (7);
	if (ft_strncmp("xor", line, 3) == 0)
		return (8);
	if (ft_strncmp("zjmp", line, 4) == 0)
		return (9);
	if (ft_strncmp("ldi", line, 3) == 0)
		return (10);
	return (id_function_next(line));
 }

static int check_instuction(char *line, int *pos)
{
	int opb;

	opb = 0;
	opb = id_function(line);
	if (opb == 0)
		return(0);//error opb
	if (opb != 1 && opb != 9 && opb != 12 && opb != 15 )
		*pos = *pos + 2;
	else
		(*pos)++;
	if (opb == 2 || opb == 3 || opb == 7)
		line = line + 2;
	else if (opb == 4 || opb == 6 || opb == 5 || opb == 8 || opb == 10 ||
			 opb == 11 || opb == 13 || opb == 11 || opb == 16)
		line = line + 3;
	else if (opb == 15)
		line = line + 5;
	else
		line = line + 4;
	line = ft_strtrim(line);
	if (verif_arguments(line, pos, opb) == 0)
		return (0);
	return (1);
}

 void fill_instruct(char *line, int *pos, int i, char **file)
{
	while(line[i] == ' ' || line[i] == '\t')
		i++;
	if(line[i] && line[i] != COMMENT_CHAR && check_instuction(&line[i], pos))
		{
			if(*file)
			{
				*file = ft_strjoin(*file, line + i);
				*file = ft_strjoin(*file, "\n");
			}
			else
			{
				*file = ft_strdup(line + i);
				*file = ft_strjoin(*file, "\n");
			}
		}
	free (line);
	return;
}