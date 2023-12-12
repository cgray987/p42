
#include <unistd.h>

int ft_atoi(char *s)
{
	int num = 0;

	while (*s && *s >= '0' && *s <= '9')
	{
		num = num  10;
		num = num + *s - '0';
		++s;
	}
	return (num);
}

void	putnbr(int n)
{
	char c;

	if (n > 9)
	{
		putnbr(n / 10);
	}
	c = (n % 10) + '0';
	write(1, &c, 1);
}

void tabmult(char *str)
{
	int mult = 1;
	int num;

	num = ft_atoi(str);
	while (mult <= 9)
	{
		putnbr(mult);
		write( 1, " x ", 3);
		putnbr(num);
		write(1, " = ", 3);
		putnbr(mult * num);
		write(1, "\n", 1);
		++mult;
	}
}


int	main(int ac, char **av)
{
	if (ac == 2)
	{
		tabmult(av[1]);
	}
	else
		write(1, "\n", 1);
}