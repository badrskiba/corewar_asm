#include "../asm.h"

static int verif_direct_next(char **line, int v_sep)
{
	if (**line == LABEL_CHAR)
	{
		(*line)++;
		while (**line && ft_strchr(LABEL_CHARS, **line))
			(*line)++;
		*line = ft_strtrim(*line);
		if (v_sep)
			return (verif_separator(line));
		else if (**line != '\0' && **line != '\n' && **line != COMMENT_CHAR)
			return (0);
		return (1);
	}
	else
	{
		if (**line == '-')
			(*line)++;
		while (**line && ft_isdigit(**line))
			(*line)++;
		*line = ft_strtrim(*line);
		if (v_sep)
			return (verif_separator(line));
		else if (**line != '\0' && **line != '\n' && **line != COMMENT_CHAR)
			return (0);
		return(1);
	}
}

int verif_direct(char **line, int *pos,int opb, int v_sep)
{
	if (**line == DIRECT_CHAR)
	{	
		(*line)++;
		if ((opb >= 1 && opb <= 8) || opb == 13)
			*pos = *pos + 4;
		else
			*pos = *pos + 2;
		if((**line != LABEL_CHAR) && !(**line >= '0' && **line <= '9') && **line !='-')
			return(0);
		else
			return (verif_direct_next(line, v_sep));
	}
	return (0);
}

