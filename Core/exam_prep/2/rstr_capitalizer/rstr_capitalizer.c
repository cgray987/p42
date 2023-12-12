
#include <unistd.h>

void	rcapitalize_str(char *str)
{
	while (*str != '\0')
	{
		while (*str != '\0' && (*str == ' ' || *str == '\t'))
		{
			write(1, str, 1);
			++str;
		}

		while (*str != '\0' && *str != ' ' && *str != '\t')
		{
			if (*str >= 'a' && *str <= 'z'
			&& (*(str + 1) == '\0' || *(str + 1) == ' ' || *(str + 1) == '\t'))
				*str = *str - ('a' - 'A');
			else if (*str >= 'A' && *str <= 'Z' && *(str + 1) != '\0'
			&& *(str + 1) != ' ' && *(str + 1) != '\t')
				*str = *str + ('a' - 'A');
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
			rcapitalize_str(av[i]);
			av++;
		}
	}
}