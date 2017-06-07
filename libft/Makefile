NAME = libftprintf.a

CC = gcc 

FLAGS = -Wall -Wextra -Werror

SRC_NAME = 	libft/ft_putnl.c\
            libft/ft_ztrlen.c\
            libft/ft_chariter.c\
            libft/ft_free_z.c\
            libft/spaces_in_str.c\
            libft/get_next_line.c\
	   		libft/ft_isstrdigit.c\
	   		libft/ft_error.c\
	   		libft/ft_putwchar.c\
            libft/ft_putwstr.c\
            libft/ft_nstr.c\
            libft/ft_realloc.c\
            libft/ft_wstrdup.c\
            libft/wchar_to_wstr.c\
            libft/ft_wstrlen.c\
            libft/ft_pow.c\
            libft/ft_itoa_base.c\
            libft/ft_capitalize.c\
            libft/ft_minimize.c\
            libft/ft_each_char.c\
            libft/ft_init_int.c\
            libft/ft_init_sit.c\
            libft/ft_atoi.c\
            libft/ft_atoi_base.c\
            libft/ft_bzero.c\
            libft/ft_isalnum.c\
            libft/ft_isalpha.c\
            libft/ft_isascii.c\
            libft/ft_isdigit.c\
            libft/ft_isprint.c\
            libft/ft_itoa.c\
            libft/ft_itoa_max.c\
            libft/ft_lstadd.c\
            libft/ft_lstdel.c\
            libft/ft_lstdelone.c\
            libft/ft_lstiter.c\
            libft/ft_lstmap.c\
            libft/ft_lstnew.c\
            libft/ft_memalloc.c\
            libft/ft_memccpy.c\
            libft/ft_memchr.c\
            libft/ft_memcmp.c\
            libft/ft_memcpy.c\
            libft/ft_memdel.c\
            libft/ft_memmove.c\
            libft/ft_memset.c\
            libft/ft_putchar.c\
            libft/ft_putchar_fd.c\
            libft/ft_putendl.c\
            libft/ft_putendl_fd.c\
            libft/ft_putnbr.c\
            libft/ft_putnbr_fd.c\
            libft/ft_putstr.c\
            libft/ft_putstr_fd.c\
            libft/ft_strcat.c\
            libft/ft_strchr.c\
            libft/ft_strclr.c\
            libft/ft_strcmp.c\
            libft/ft_strcpy.c\
            libft/ft_strdel.c\
            libft/ft_strdup.c\
            libft/ft_strequ.c\
            libft/ft_striter.c\
            libft/ft_striteri.c\
            libft/ft_strjoin.c\
            libft/ft_strlcat.c\
            libft/ft_strlen.c\
            libft/ft_strmap.c\
            libft/ft_strmapi.c\
            libft/ft_strncat.c\
            libft/ft_strncmp.c\
            libft/ft_strncpy.c\
            libft/ft_strnequ.c\
            libft/ft_strnew.c\
            libft/ft_strnstr.c\
            libft/ft_strrchr.c\
            libft/ft_strsplit.c\
            libft/ft_strstr.c\
            libft/ft_strsub.c\
            libft/ft_strtrim.c\
            libft/ft_tolower.c\
            libft/ft_toupper.c\
            libft/ft_swap.c\
            libft/ft_foreach.c\
            libft/ft_range.c\
            libft/ft_sort_strs.c\
            libft/ft_revsort_strs.c\
            libft/ft_strrev.c\
            libft/before_stri.c\
            libft/ft_itoa_base_u.c\
            libft/char_to_str.c\
            libft/ft_strnnstr.c\
            libft/ft_strnn.c\
            libft/hide_char.c\
            flag_is/flag_is_c.c\
			flag_is/flag_is_d.c\
			flag_is/flag_is_i.c\
			flag_is/flag_is_m.c\
			flag_is/flag_is_mc.c\
			flag_is/flag_is_md.c\
			flag_is/flag_is_mo.c\
			flag_is/flag_is_ms.c\
			flag_is/flag_is_mu.c\
			flag_is/flag_is_mx.c\
			flag_is/flag_is_o.c\
			flag_is/flag_is_p.c\
			flag_is/flag_is_s.c\
			flag_is/flag_is_u.c\
			flag_is/flag_is_x.c\
			flags/check_char.c\
			flags/flags_str.c\
			init/init_printf_list.c\
			print_list/print_ft_printf.c\
			print_list/free_printf.c\
			print_list/printf_copy.c\
			flags/str_flags.c\
			flags/more_flags.c\
			flags/hash_flags.c\
			flags/make_str_before.c\
			flags/make_char_before.c\
			flags/make_char_after.c\
			ft_printf.c

OBJ_NAME = $(SRC_NAME:.c=.o)

all: $(NAME)
	@true
	
compiling:
	@echo "\033[0;33mLibft: Compiling..."

$(NAME): $(OBJ_NAME) ./ft_printf.h ./libft/libft.h
	@ar rc $(NAME) $(OBJ_NAME)
	@echo "\033[0m"
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "_\c"


clean:
	@rm -rf $(OBJ_NAME)
	@echo "\033[0;31mLibft: .o files deleted\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[0;32mLibft: Full clean done\033[0m"

re: fclean all

.PHONY: all clean fclean re
