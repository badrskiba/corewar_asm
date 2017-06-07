
int		invert_binary(int x)
{
	x = ((x << 24) & 0xff000000)|((x << 8) & 0xff0000)
	|((x >> 8) & 0xff00);
	return (x);
}

int		invert_binary_2(int x)
{
	x = ((x << 8) & 0xff00) | ((x >> 8) & 0xff);
	return (x);
}