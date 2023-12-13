unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int n = 0;
	if (a == 0 || b == 0)
		return (0);
	if (a > b)
			n = a;
	else
			n = b;
	while (1) //increase n until divisible by both
	{
		if (n % a == 0 && n % b == 0) // if n is divisible by a and b
			return (n);
		n++;
	}
}

#include <stdio.h>

int main(void)
{
	int a = 4;
	int b = 6;

	printf("lcm(%d,%d) = %d\n", a, b, lcm(a, b));
}