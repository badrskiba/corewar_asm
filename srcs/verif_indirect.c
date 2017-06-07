#include "../asm.h"

static int verif_indirect_next(char **line, int *pos, int v_sep)
{
	(*line)++;
	while(**line && ft_strchr(LABEL_CHARS,**line))
		(*line)++;
	*line = ft_strtrim(*line);
	*pos = *pos + 2;
	if (v_sep)
		return (verif_separator(line));
	else if (**line != '\0' && **line != '\n' && **line != COMMENT_CHAR)
		return (0);//erreur arg
	return (1);
}

int verif_indirect(char **line, int *pos, int v_sep)
{
	if (**line == '-')
		(*line)++;
	if (ft_isdigit(**line))
	{
		(*line)++;
		while(**line && ft_isdigit(**line))
			(*line)++;
		*line = ft_strtrim(*line);
		*pos = *pos + 2;
		if (v_sep)
			return (verif_separator(line));
		if (**line != '\0' && **line != '\n' && **line != COMMENT_CHAR)
			return (0);//erreur arg
		return (1);
	}
	else if (**line == LABEL_CHAR)
		return (verif_indirect_next(line, pos, v_sep));
	return(0);
}
