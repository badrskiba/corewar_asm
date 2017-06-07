#include "../asm.h"

static int find_nextarg(char *str, int args)
{
	int i;
	int a;

	i = 0;
	a = 0;
	while (str[i] != '\0')
	{
		if (str[i] == SEPARATOR_CHAR)
			a++;
		if (a == args - 1)
			{
				i++;
				a = i;
				break;
			}
		i++;
	}
	while (str[a] != '\0' && (str[a] == ' ' || str[a] == '\t'))
		a++;
	return (a);
}

static int get_opc_1(char *file, int i)
{
	int x;

	x = 0;
	if (file[i] == DIRECT_CHAR)
		x = 0x80;
	else if (file[i] == 'r')
		x = 0x40;
	else
		x = 0xc0;
	return (x);
}

static int get_opc_2(char *file, int i)
{
	int x;

	x = 0;
	if (file[i] == DIRECT_CHAR)
		x = 0x20;
	else if (file[i] == 'r')
		x = 0x10;
	else
		x = 0x30;
	return (x);
}
static int get_opc_3(char *file, int i)
{
	int x;

	x = 0;
	if (file[i] == DIRECT_CHAR)
		x = 0x8;
	else if (file[i] == 'r')
		x = 0x4;
	else
		x = 0xc;
	return (x);
}

int write_opc(int fd, int args, char *file)
{
	int i;
	int octet;
	
	i = 0;
	octet = 0;
	if (args == 1)
		octet = get_opc_1(file, 0);
	if (args == 2)
	{
		octet = get_opc_1(file, 0);
		octet = octet | get_opc_2(file,find_nextarg(file, 2));
	}
	if (args == 3)
	{
		octet = get_opc_1(file, 0);
		octet = octet | get_opc_2(file,find_nextarg(file, 2));
		octet = octet | get_opc_3(file,find_nextarg(file, 3));
	}
	write(fd, &octet, 1);
	count++;
	return (1);
}