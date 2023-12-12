

#include <unistd.h>

int	is_blank(char c)
{
	return (c == ' ' || c == '\t');
}

void	rostring(char *s)
{
	int i = 0;
	int first_word_len = 0;

	while (s[i])
	{
		while (is_blank(s[i])) //skip first spaces
			i++;
		if (s[i] && !is_blank(s[i]))
		{
			if (first_word_len == 0) // if first word
			{
				while (s[i] && !is_blank(s[i])) //find len of first_word to use after rest
				{
					first_word_len++;
					i++;
				}
			}
			else	//rest of words printed first
			{
				while (s[i] && !is_blank(s[i]))
					write(1, &s[i++], 1);
				write(1, " ", 1);
			}
		}
	}
	// got to end of string, now need to write first word
	i = 0;
	while (is_blank(s[i])) //still need to skip spaces
		i++;
	while (first_word_len > 0)
	{
		write(1, &s[i++], 1);
		first_word_len--;
	}
}

int	main(int ac, char **av)
{	
	char	*str;
	int		i = 0;
	if (ac == 2)
	{
		str = av[1];
		rostring(str);
	}
	write(1, "\n", 1);
	return (0);
}