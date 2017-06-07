/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name_com.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 04:31:01 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/05/29 17:24:43 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

static int	check_after_nc(char *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i++] != '\"')
		return (-1);
	while (s[i] != '\"' && s[i])
		i++;
	if (s[i++] == '\"')
	{
		while (s[i] == ' ' || s[i] == '\t')
			i++;
		if (s[i] == '\0')
			return (1);
		return (-1);
	}
	else
		return (-1);
	return (1);
}

static int	check_str(char *str)
{
	static int	name = 0;
	static int	com = 0;
	int			i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\v' || str[i] == '\t' ||
			str[i] == '\f' || str[i] == '\n' || str[i] == '\r')
		i++;
	if (ft_strncmp((str + i), ".name", 5) == 0 && name == 0)
	{
		name = 1;
		if (check_after_nc(str + i + 5) == 1)
			return (1);
		return (-1);
	}
	else if (ft_strncmp((str + i), ".comment", 8) == 0 && com == 0)
	{
		com = 1;
		if (check_after_nc(str + i + 8) == 1)
			return (1);
		return (-1);
	}
	return (-1);
}

int			check_name_com(t_file *file)
{
	int n_line;

	n_line = 0;
	while(n_line < 2 && file)
	{
		if (check_str(file->line) == -1)
		{
			ft_printf("Err\n");
			return (-1);
		}
		n_line++;
		file = file->next;
	}
	return (0);
}
