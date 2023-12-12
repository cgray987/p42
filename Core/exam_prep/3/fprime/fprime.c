
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	is_prime(int num)
{
	int i = 2;

	while (i < num)
	{
		if (num % i == 0) // if num is divisible, not prime
			return (0);
		++i;
	}
	return (1);
}

void	fprime(int num)
{
	int factor = 2;
	int first = 0;

	if (num == 1)
		printf("1");
	while (factor <= num)
	{
		if (num % factor == 0 && is_prime(factor)) //num has prime factor
		{
			if (first == 0)
				printf("%d", factor);
			else
				printf("*%d", factor);
			first = 1;
			num /= factor; //prime factor found, divide num by factor for next
		}
		else
			++factor;
	}
}
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		fprime(atoi(av[1]));
	}
	printf("\n");
}