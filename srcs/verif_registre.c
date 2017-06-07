#include "../asm.h"

int verif_registre(char **line, int *pos, int v_sep)
{
	int r;

	r = 0;
	if(**line == 'r')
	{
		(*pos)++;
		(*line)++;
		r = ft_atoi(*line);
		if (r >=0 && r<= REG_NUMBER)
		{
			(*line)++;
			if (r > 9 & r <= 99)
				(*line)++;
			else if (r >= 100)
				*line = *line + 2;
			*line = ft_strtrim(*line);
			if (v_sep)
				return (verif_separator(line));
			else if (**line != '\0' && **line != '\n' && **line != COMMENT_CHAR)
				return (0);
			return(1);
		}
		else
			return (0); //erreur
	}
	return (0);
}