#include "../asm.h"

int single_label(t_label *label, char *line, int i)
{
	char *tmp;
	t_label *tmp1;
	
	tmp = ft_strsub(line, 0, i);
	tmp1 = label;
	if (label)
	{
		while (tmp1)
		{
			if (ft_strcmp(tmp1->line, tmp) == 0)
				return (0);
			tmp1 = tmp1->next;
		}
		return (1);
	}
	return (2);
}

static int verif_label_next(t_label *label, char *str)
{
	char *tmp;

	tmp = ft_strsub(str, 0, ft_strlen(label->line));
	while (label)
	{
		if (ft_strcmp(label->line, tmp) == 0)
			return (1);
		label = label->next;
	}
	//ft_printf("tmp :%s", tmp);
	ft_printf("none existing label\n"); //erreur nom label dans le .s
	return(0);
}

int verif_label(t_label *label, char *file)
{
	int i;

	i = 0;
	while (file[i] != '\0' && file[i] != LABEL_CHAR)
	{
			if (file[i] == LABEL_CHAR)
			{		
				i++;
				if (verif_label_next(label, &file[i]) == 0)
					return(0);
			}
			i++;
	}
	return (1);
}