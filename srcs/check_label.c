#include "../asm.h"

int		check_label(char *file)
{
	int i;

	i = 0;
	file = ft_strtrim(file);
	while(file[i] && ft_strchr(LABEL_CHARS, file[i]))
		i++;
	if(file[i] == LABEL_CHAR)
	{
		while (file[i] == ' ' || file[i] == '\t')
			i++;
		if (file[i] == '\n'|| file[i] == '\0' || file[i] == COMMENT_CHAR)
			return (1);
		return(1);
	}
	return (0);
}