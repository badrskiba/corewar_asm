/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 22:42:09 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/02/14 16:39:58 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
******************************************************************
**								**
**	int							**
**	find_char(char *s, int c);				**
**								**
**	Search in s if the character c exist			**
**	If the character doesn't exist in s it returns -1	**
**	If the character is in s, it the returns the 		**
**	index of the first one in s.				**
**								**
******************************************************************
*/

int				find_char(char *s, int c)
{
	int i;

	i = -1;
	if (s)
		while (s[++i])
			if (s[i] == c)
				return (i);
	return (-1);
}

/*
******************************************************************
**								**
**	char*							**
**	get_fd(char *s, int fd);				**
**								**
**	Recursive function.					**
**								**
**	Reads the fd until it finds a '\n' in the buffer	**
**	then it returns the the result : strjoin between s 	**
**	and the buffer.						**
**	If it doesn't find a '\n' in the buffer and if the 	**
**	buffer isn't over, it recal itself with result 		**
**	in the place of s.					**
**								**
******************************************************************
*/

static char		*get_fd(char *s, int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*result;

	if (!s)
		s = ft_strdup("\0");
	ret = read(fd, &buf, BUFF_SIZE);
	if (ret < 0)
		return (NULL);
	buf[ret] = '\0';
	result = ft_strjoin(s, buf);
	free(s);
	if (find_char(buf, 10) == -1 && ret == BUFF_SIZE)
		return (get_fd(result, fd));
	return (result);
}

/*
******************************************************************
**								**
**	t_fdlist*						**
**	new_fdlist(int fd, t_fdlist **next);			**
**								**
**	Create a newlist for this fd, makes fd = fd in it 	**
**	and s = get_fd and next = next and makes the 		**
**	pointed next as the new fd.				**
**								**
******************************************************************
*/

static t_fdlist	*new_fdlist(int fd, t_fdlist **next)
{
	t_fdlist	*l;

	if (!(l = (t_fdlist*)malloc(sizeof(t_fdlist))))
		return (NULL);
	l->fd = fd;
	l->s = NULL;
	if (!(l->s = get_fd(l->s, fd)))
		return (NULL);
	l->next = *next;
	*next = l;
	return (l);
}

/*
******************************************************************
**								**
**	t_fdlist*						**
**	find_fd(t_fdlist *f, int fd, t_fdlist **static_l);	**
**								**
**	Finds the right fdlist that have fd == fd and		**
**	return it.						**
**	If it doesn't exist, it returns a call to 		**
**	new_fdlist(fd, static_l)				**
**								**
******************************************************************
*/

static t_fdlist	*find_fd(t_fdlist *f, int fd, t_fdlist **static_l)
{
	while (f)
	{
		if (f->fd == fd)
			return (f);
		f = f->next;
	}
	return (new_fdlist(fd, static_l));
}

/*
******************************************************************
**								**
**	int							**
**	get_next_line(int fd, char **line);			**
**								**
**	Takes an fd and puts a new line of it in the 		**
**	pointed line.						**
**	It returns 0 if the file is finished, 1 if there is 	**
**	still something to read, and -1 if an error 		**
**	occured.						**
**								**
******************************************************************
*/

int				get_next_line(int fd, char **line)
{
	static t_fdlist	*static_l = NULL;
	t_fdlist		*tmp_l;
	int				i;

	if (fd < 0)
		return (-1);
	if ((tmp_l = find_fd(static_l, fd, &static_l)) == NULL)
		return (-1);
	if (find_char(tmp_l->s, '\n') == -1)
		if (!(tmp_l->s = get_fd(tmp_l->s, fd)))
			return (-1);
	if (tmp_l->s[0] == '\0')
		return (0);
	*line = ft_strdup(tmp_l->s);
	free(tmp_l->s);
	if ((i = find_char((*line), '\n')) > -1)
	{
		tmp_l->s = ft_strdup((*line) + i + 1);
		(*line)[i] = '\0';
	}
	else
		tmp_l->s = ft_strdup("\0");
	return (1);
}
