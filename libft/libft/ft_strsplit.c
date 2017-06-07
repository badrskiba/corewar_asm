/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 20:56:31 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/03/23 03:11:34 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			pass_c(char const *s, char c, int *i)
{
	while (s[*i] == c)
		*i = *i + 1;
}

static int			word_nbr(char const *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	pass_c(s, c, &i);
	while (s[i])
	{
		if (s[i + 1] == '\0' && s[i] != c)
		{
			words++;
			i++;
		}
		else if (s[i] == c)
		{
			words++;
			pass_c(s, c, &i);
		}
		else
			i++;
	}
	return (words);
}

static int			nbr_let(char const *s, char c, int i)
{
	int j;

	j = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i = i + 1;
		j++;
	}
	return (j);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		word;
	int		i;
	int		j;

	ft_init_int(&word, &i, &i, &i);
	if (s == NULL)
		return (NULL);
	if (!(split = (char**)malloc(sizeof(*split) * (word_nbr(s, c) + 1))))
		return (NULL);
	pass_c(s, c, &i);
	while (word < word_nbr(s, c))
	{
		j = 0;
		if (!(split[word] = (char*)malloc(sizeof(**split)
			* (nbr_let(s, c, i) + 1))))
			return (NULL);
		while (s[i] != c && s[i] != '\0')
			split[word][j++] = s[i++];
		split[word][j] = '\0';
		pass_c(s, c, &i);
		word++;
	}
	split[word_nbr(s, c)] = NULL;
	return (split);
}
