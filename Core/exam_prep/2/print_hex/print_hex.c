
#include <unistd.h>


int	main(int ac, char **av)
{
	if (ac == 2)
	{
		print_hex(av[1]);
	}
	write(1, "\n", 1);
}