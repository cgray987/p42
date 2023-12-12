#include <stdlib.h>

int	count_strings(char *str) //count how many arrays needed from string
{
	int num_strings = 0;
	int	jump = 0;

	while (*str)
	{
		if (*str == ' ' || *str == '\t' || *str == '\n')
			jump = 0;
		else if (jump == 0)
		{
			jump = 1;
			num_strings++;
		}
		str++;
	}
	return (num_strings);
}

int	find_delin(char *str) //count chars to next delin
{
	int i = 0;

	while (*str && (*str != ' ' && *str != '\t' && *str != '\n'))
	{
		str++;
		i++;
	}
	return (i);
}


char	**ft_split(char *str)
{
	char **strings;
	int word_len;
	int i = 0;
	int j = 0;

	strings = (char **)malloc((count_strings(str) + 1)*sizeof(char *));
	while (*str)
	{
		if ((*str != ' ' && *str != '\t' && *str != '\n'))
		{
			j = 0;
			word_len = find_delin(str);
			strings[i] = (char *)malloc(word_len + 1);
			if (!strings[i])
				return (0);
			while (j < word_len)
				strings[i][j++] = *str++;
			strings[i][word_len] = '\0';
			i++;
		}
		else
			str++;
	}
	strings[i] = NULL;
	return (strings);
}
// count and malloc number of strings
//malloc length of string to next delin
//copy into new string, null terminate strings, skip spaces
//null terminate array
#include <stdio.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int		i;
	char	**split;
	i = 0;
	split = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed risus. Suspendisse");
	while (split[i] != NULL)
	{
		printf("%s\n", split[i]);
		i++;
	}
	i = 0;
}
