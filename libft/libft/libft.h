/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:55:50 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/03/23 02:03:54 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 100000

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

/*
**	lem_in
*/
int						ft_chariter(char *s, char c);

/*
**	push_swap
*/
int						ft_isstrdigit(char *str);
int						spaces_in_str(char *s);
void					ft_free_z(char **z);
int						ft_ztrlen(char **z);

/*
**	itoa & atoi
*/
char					*ft_itoa_base(long nb, int base);
char					*ft_itoa_max(intmax_t n);
char					*ft_itoa(int n);
char					*ft_itoa_base_u(uintmax_t nb, int base);
intmax_t				ft_atoi(const char *str);
unsigned int			ft_atoi_base(char *str, int base);

/*
**	ft_printf
*/
char					*ft_strnn(char *s, int beg, int end);
char					*ft_strnnstr(int beg, int end, char *dst, char *src);
char					*before_stri(char *src, int end);
char					*char_to_str(int c);
char					*hide_char(char *s, int i);
int						*ft_wstrdup(int *s1);
int						*wchar_to_wstr(int c);
void					ft_putwchar(int chr);
void					ft_putwstr(int *s);
size_t					ft_wstrlen(int *s);

/*
**	get_next_line
*/
typedef struct			s_fdlist
{
	int					fd;
	char				*s;
	struct s_fdlist		*next;
}						t_fdlist;

int						get_next_line(int fd, char **line);
int						find_char(char *s, int c);

/*
**	libft
*/
typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

size_t					ft_strlcat(char *dst, const char *src, size_t size);
size_t					ft_strlen(const char *s);

int						ft_pow(int n, int pow);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isprint(int c);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_tolower(int c);
int						ft_toupper(int c);
int						ft_error(char *msg);

int						*ft_range(int min, int max);

char					*ft_nstr(char *src);
char					*ft_capitalize(char *s);
char					*ft_minimize(char *s);
char					*ft_strrev(char *s);
char					*ft_strnew(size_t size);
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
		char (*f)(unsigned int, char));
char					*ft_strsub(char const *s,
		unsigned int start, size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strdup(const char *s1);
char					*ft_strncpy(char *dst, const char *src, size_t len);
char					*ft_strstr(const char *big, const char *little);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strnstr(const char *big,
		const char *little, size_t len);

char					**ft_strsplit(char const *s, char c);

void					ft_putnl(int n);
void					ft_each_char(char *s, size_t n);
void					ft_init_int(int *i, int *j, int *k, int *l);
void					ft_init_sit(size_t *i, size_t *j, size_t *k, size_t *l);
void					ft_memdel(void **ap);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
void					ft_putchar(int c);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
void					ft_putnbr(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstdelone(t_list **alst,
		void (*del)(void *, size_t));
void					ft_bzero(void *s, size_t n);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void					ft_swap(int *a, int *b);
void					ft_foreach(int *tab, int length, void (*f)(int));
void					ft_sort_strs(int i, char **strs);
void					ft_revsort_strs(int i, char **strs);

void					*ft_realloc(void *src, size_t size);
void					*ft_memset(void *b, int c, size_t len);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst,
		const void *src, int c, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memalloc(size_t size);
void					*ft_memchr(const void *s, int c, size_t n);

t_list					*ft_lstnew(void const *content, size_t content_size);
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list					*ft_lstnew(void const *content, size_t content_size);

#endif
