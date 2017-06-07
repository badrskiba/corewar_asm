/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 17:49:02 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/05/29 17:22:57 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/ft_printf.h"
# include "../op.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef	struct 		s_file
{
	char			*line;
	int				index;
	int				instruct;
	struct s_file	*next;
}					t_file;

typedef struct 		s_label
{
	char 			*line;
	int 			pos;
	struct s_label	*next;
}					t_label;

int 				count;
int 				line;
/*
typedef enum 		e_cmds
{

}					t_cmds;
*/

void				free_file(t_file **file);
t_file				*get_file(char *file_name, t_file *file);
int					parse_asm(t_file *file);
int					check_file(int ac, char **av);
int					check_param(int ac, char **av);
int					check_name_com(t_file *file);
int					error__(int er);

int					parsing_file(char *player, header_t *header);
header_t			*header_init(void);
header_t			*header_name_comment(int fd, header_t *head);
int					check_label(char *file);
t_label 			*init_label(t_label *label, char *line, int pos);
void 				fill_instruct(char *line, int *pos, int i, char **file);
int 				id_function(char *line);
int 				verif_arguments(char *line, int *pos, int opb);
int 				verif_separator(char **line);
int 				verif_direct(char **line, int *pos,int opb, int v_sep);
int 				verif_indirect(char **line, int *pos, int v_sep);
int 				verif_registre(char **line, int *pos, int v_sep);
int 				verif_label(t_label *label, char *file);
int 				single_label(t_label *label, char *line, int i);
void 				write_asm(t_label *label, char *file, header_t *header, char *player);
void				move_to_nextarg(char **file);
int					invert_binary(int x);
int					invert_binary_2(int x);
void 				write_header(header_t *header, int fd);
void 				write_instruction(t_label *label, char *file, int fd);
int 				find_adress(t_label *label,char **file);
int 				write_opc(int fd, int args, char *file);
int					write_direct(char **file, int fd, t_label *label, int octet);
int					write_indirect(char **file, int fd, t_label *label);
int 				write_registre(char **file, int fd);
#endif
