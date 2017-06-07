#include "../asm.h"

void write_header(header_t *header, int fd)
{
	int i;

	i = -1;
	header->magic = invert_binary(header->magic);
	write(fd, &header->magic, 4);
	ft_putstr_fd(header->prog_name, fd);
	while (++i < PROG_NAME_LENGTH - ft_strlen(header->prog_name))
		write(fd, "\0", 1);
	header->pos = invert_binary(header->pos);
	write(fd, "\0\0\0\0", 4);
	write(fd, &header->pos, 4);
	ft_putstr_fd(header->comment, fd);
	i = -1;
	while(++i < COMMENT_LENGTH - ft_strlen(header->comment) + 4)
		write(fd, "\0", 1);
}