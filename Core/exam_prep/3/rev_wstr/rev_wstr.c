#include <unistd.h>

void	rev_wstr(char	*s)
{
	int i = 0;
	char	*rev;

	while (s[i]) // goto end of str
		i++;
	i--;
	while (s[i--]) //iterate backwards
	{
		if (s[i - 1] == ' ') // space found at next (prev) char
		{
			rev = &s[i]; //temp str w/ same position to print forwards
			while (*rev && *rev != ' ')
			{
				write(1, rev, 1);
				rev++;
			}
			write(1, " ", 1);
		}
		else if (i == 0) //at beginning of string, print first word
		{
			rev = &s[i];
			while (*rev && *rev != ' ')
			{
				write(1, rev, 1);
				rev++;
			}
			write(1, " ", 1);
		}
	}
}

int	main(int ac, char **av)
{	
	char	*str;
	int		i = 0;
	if (ac == 2)
	{
		str = av[1];
		rev_wstr(str);
	}
	write(1, "\n", 1);
	return (0);
}