
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int gcd(int a, int b)
{
	int n = a;

	while (n > 0)
	{
		if (a % n == 0 && b % n == 0)
			return (n);
		n--;
	}
	return (n);
}

int fast_gcd(int a, int b)
{
	if (a == 0)
		return (b);
	return (fast_gcd(b % a, a));
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int a = atoi(av[1]);
		int b = atoi(av[2]);
		printf("%d\n", fast_gcd(a, b));
	}
}
