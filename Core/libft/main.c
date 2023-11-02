/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:28:38 by cgray             #+#    #+#             */
/*   Updated: 2023/11/02 12:06:23 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>
#include <stdio.h>
#include <string.h>

/*used for testing ft_strmapi*/
char	uppercase(unsigned int i, char c)
{
	return (ft_toupper(c));
}

/*used for testing ft_striteri*/
void	voiduppercase(unsigned int i, char *c)
{
	*c = ft_toupper(*c);
}

/*
main function to test each lib function
do not judge how messy this test function is
*/
int	main(void)
{
	char	c;
	char	delin;
	size_t	result;
	char	*testmemchr;
	char	*teststrdup;
	int		*buffer;
	char	*sub;
	char	*join;
	char	**split;
	int		num;
	char	*itoa;

	c = 'l';
	char string1[] = "Hello World";
	char string2[] = "qwerty";
	char string3[] = "ft_memset test";
	char string4[] = "abcdef";
	char string5[100] = "1234";
	char string6[] = "Foo Bar Baz";
	char string7[] = "Bar";
	char string8[] = "    ---12613261asdkl;fj634";
	char trim[] = "  ----.,test    --,.  ";
	char spaces[4] = " ,.-";
	char delin = ' ';
	num = -41235;

	printf("-CHARACTER FUNCTIONS-\n");
	printf("'%c' is alphanumeric: %d\n", c, ft_isalnum(c));
	printf("'%c' is alpha: %d\n", c, ft_isalpha(c));
	printf("'%c' is ascii: %d\n", c, ft_isascii(c));
	printf("'%c' is digit: %d\n", c, ft_isdigit(c));
	printf("'%c' is printable: %d\n", c, ft_isprint(c));
	printf("'%c' capitalize: %c\n", c, ft_toupper(c));
	printf("'%c' uncapitalize: %c\n\n", c, ft_tolower(c));

	printf("-MEM FUNCTIONS-\n");

	ft_memset(string3 + 6, '.', 2);
	printf("ft_memset s3: %s\n", string3);
	ft_bzero(string3, 1);
	printf("bzero s3: %s\n", string3);
	printf("before memcpy s2: %s\n", string2);
	ft_memcpy(string2, string1, 6);
	printf("memcpy s1 into s2: %s\n", string2);
	printf("before memmove s4: %s\n", string4);
	ft_memmove(string4, string1, 6);
	printf("memmove s1 into s4: %s\n", string4);
	testmemchr = ft_memchr(string1, c, 11);
	printf("memchr search '%c' in '%s': %s\n", c, string1, testmemchr);
	printf("memcmp s6'%s' - s7'%s': %d\n", string6, string7, ft_memcmp(string6,
			string7, 11));
	buffer = (int *)ft_calloc(20, sizeof(int));
	if (buffer)
		printf("calloc test: allocated 40 int\n\n");
	else
		printf("calloc failled\n\n");
	free(buffer);

	printf("-STRING FUNCTIONS-\n");

	printf("strchr search s1 for first position '%c': %s\n", c,
		ft_strchr(string1, c));
	printf("strrchr search s1 for last position '%c': %s\n", c,
		ft_strrchr(string1, '\0'));
	printf("string1 length: %zu\n", ft_strlen(string1));
	printf("ft_strncmp: %d\n", ft_strncmp("test", "tEst", 4));
	printf("strncmp: %d\n", strncmp("test", "tEst", 4));
	printf("before strlcpy s1'%s' s5'%s'\n", string1, string5);
	ft_strlcpy(string5, string1, 11);
	printf("strlcpy '%ld' characters s1 into s5: %s\n", ft_strlcpy(string5,
			string1, 11), string5);
	printf("before strlcat s1'%s' s5'%s'\n", string1, string5);
	result = ft_strlcat(string5, string1, 22);
	printf("strlcat '%ld' characters s1 into s5: %s\n", result, string5);
	printf("strnstr search '%s' in '%s': %s\n", string7, string6,
		ft_strnstr(string6, string7, 11));
	printf("atoi s8'%s': %d\n", string8, ft_atoi(string8));
	itoa = ft_itoa(num);
	printf("itoa '%d': %s\n", num, itoa);
	teststrdup = ft_strdup(string1);
	printf("strdup s1'%s' in teststrdup: %s\n", string1, teststrdup);
	sub = ft_substr(string1, 6, 5);
	printf("create substring 'sub' from s1'%s': %s\n", string1, sub);
	join = ft_strjoin(string1, string4);
	printf("strjoin s1'%s' + s4'%s': %s\n", string1, string4, join);
	printf("strtrim %s: %s\n", trim, ft_strtrim(trim, spaces));
	split = ft_split(string1, delin);
	printf("split s1'%s': {%s , %s}\n\n", string1, split[0], split[1]);

	printf("--FUNCTION FUNCTIONS--\n");

	printf("strmapi f(uppercase): %s\n", ft_strmapi("hello world", uppercase));
	ft_striteri(string1, voiduppercase);
	printf("striteri f(uppercase): %s\n", string1);
	return (0);
}
/* to compile seperately for testing:
gcc main.c libft.a
*/
