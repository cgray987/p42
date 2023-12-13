
#include <unistd.h>

void	capitalize_str(char *str)
{
	while (*str)
	{
		while (*str && (*str == ' ' || *str == '\t')) // print first spaces in str
		{
			write(1, str, 1);
			++str;
		}
		if (*str)
		{
			if (*str >= 'a' && *str <= 'z') // if first letter after space is lower capitalize
				*str = *str - ('a' - 'A');
			write(1, str, 1);
			++str;
		}	
		while (*str && (*str != ' ' && *str != '\t'))
		{
			if (*str >= 'A' && *str <= 'Z') // lowercase every other letter
				*str = *str - ('A' - 'a');
			write(1, str, 1);
			++str;
		}
	}
	write(1, "\n", 1);
}


int main(int ac, char **av)
{
	int i = 1;
	if (ac > 1)
	{
		while (av[i])
		{
			capitalize_str(av[i]);
			av++;
		}
	}
}