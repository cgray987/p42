

#include <unistd.h>

void	hiddenp(char *probe, char *target)
{
	while (*probe)
	{	
		while (*probe != *target && *target) //increase target string if probe is not found
			++target;
		if (*target == '\0') // reached end of check string, did not find all in target
		{
			write(1, "0", 1);
			return ;			
		}
		++target;
		++probe;
	}
	write(1, "1", 1); // reached end of hidden string before or when check string ends, 
}						// all hidden chars found.

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		hiddenp(av[1], av[2]);
	}
	write(1, "\n", 1);
}