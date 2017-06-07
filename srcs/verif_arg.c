#include "../asm.h"

int verif_separator(char **line)
{
	if (**line != SEPARATOR_CHAR)
		return (0);
	(*line)++;
	*line = ft_strtrim(*line);
	return (1);
}

static int verif_arguments_next(char *line, int *pos, int opb)
{
	if ((opb == 10 || opb == 14) &&  (verif_registre(&line, pos,1)
	 || verif_indirect(&line, pos, 1)|| verif_direct(&line, pos, opb, 1))
	  && (verif_registre(&line, pos,1) || verif_direct(&line, pos, opb, 1) ) 
	  && verif_registre(&line, pos, 0))
		return (1);
	else if ((opb == 11) && (verif_registre(&line,pos,1) &&
		(verif_registre(&line,pos,1)|| verif_indirect(&line,pos, 1)|| 
		verif_direct(&line,pos, opb, 1))) && (verif_direct(&line,pos, opb, 0) 
		|| verif_registre(&line, pos, 0)))
		return (1);
	else if ((opb == 13) && (verif_direct(&line, pos, opb, 0)))
		return(1);
	else if ((opb == 16) && verif_registre(&line, pos, 0))
		return (1);
	return (0);
}

int verif_arguments(char *line, int *pos, int opb)
{
	if ((opb == 1 || opb == 9 || opb == 12 || opb == 15)
		&& verif_direct(&line, pos, opb, 0))
			return (1);
	else if((opb == 2 || opb == 13) && (verif_direct(&line, pos, opb, 1) || 
	verif_indirect(&line, pos, 1)) && verif_registre(&line, pos, 0))
		return(1);
	else if ((opb == 3) && (verif_registre(&line, pos, 1))
		&& (verif_indirect(&line, pos, 0) || verif_registre(&line, pos, 0)))
		return (1);
	else if ((opb == 4 || opb == 5) && verif_registre(&line, pos, 1)
	 && verif_registre(&line, pos, 1)&& verif_registre(&line, pos, 0))
		return (1);
	else if ((opb == 6 || opb == 7 || opb == 8) && (verif_registre(&line,pos,1)
	 || verif_indirect(&line, pos, 1)|| verif_direct(&line, pos, opb, 1)) 
	&& (verif_registre(&line,pos,1) || verif_indirect(&line, pos, 1) 
		|| verif_direct(&line, pos, opb, 1)) 
	&& verif_registre(&line, pos, 0))
		return (1);
	if (verif_arguments_next(line, pos, opb))
		return (1);
	return (0);
}