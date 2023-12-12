
#include <unistd.h>
int		ft_atoi(char *s)
{
	int n = 0;


	while (*s)
	{
		n = n * 10;
		n = n + *s - '0';
		++s;
	}
	return (n);
}

void	print_hex(int num)
{
	char *set = "0123456789abcdef";
	
	if (num >= 16)
		print_hex(num / 16); //if greater than 16 send first digit back thru function
	write(1, &set[num % 16], 1); //write last digit to terminal
}


int	main(int ac, char **av)
{
	if (ac == 2)
	{
		print_hex(ft_atoi(av[1]));
	}
	write(1, "\n", 1);
}