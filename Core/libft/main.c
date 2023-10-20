/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:28:38 by cgray             #+#    #+#             */
/*   Updated: 2023/10/20 15:38:02 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include "libft.h"
/*
main function to test each lib function
do not judge how messy this test function is
*/
int	main(void)
{
	char	c = 'l';
	char	string1[] = "Hello World";
	char	string2[] = "qwerty";
	char	string3[] = "ft_memset test";
	char	string4[] = "abcdef";
	char	string5[] = "1234";
	char	string6[] = "Foo Bar Baz";
	char	string7[] = "Bar";
	char	string8[] = "    ---12613261asdkl;fj634";
	char	*testmemchr;
	char	*teststrdup;
	int		*buffer;

	printf("'%c' is alphanumeric: %d\n", c, ft_isalnum(c));
	printf("'%c' is alpha: %d\n", c, ft_isalpha(c));
	printf("'%c' is ascii: %d\n", c, ft_isascii(c));
	printf("'%c' is digit: %d\n", c, ft_isdigit(c));
	printf("'%c' is printable: %d\n", c, ft_isprint(c));
	printf("'%c' capitalize: %c\n", c, ft_toupper(c));
	printf("'%c' uncapitalize: %c\n\n", c, ft_tolower(c));

	ft_memset(string3 + 6, '.', 2);
	printf("ft_memset s3: %s\n", string3);
	ft_bzero(string3, 1);
	printf("bzero s3: %s\n", string3);
	printf("before memcpy s2: %s\n", string2);
	ft_memcpy(string2, string1, 6);
	printf("memcpy s1 into s2: %s\n", string2);
	printf("before memmove s4: %s\n", string4);
	ft_memmove(string4, string1, 6);
	printf("memmove s1 into s4: %s\n\n", string4);

	printf("strchr search s1 for first position '%c': %s\n", c, ft_strchr(string1, c));
	printf("strrchr search s1 for last position '%c': %s\n", c, ft_strrchr(string1, c));
	printf("string1 length: %zu\n", ft_strlen(string1));
	printf("s1 and s2 strncmp: %d\n", ft_strncmp(string1, string2, 3));
	ft_strlcpy(string5, string1, 5);
	printf("strlcpy '%ld' characters s1 into s5: %s\n", ft_strlcpy(string5, string1, 5), string5);
	printf("strnstr search '%s' in '%s': %s\n", string7, string6, ft_strnstr(string6, string7, 11));
	testmemchr = ft_memchr(string1, c, 11);
	printf("memchr search '%c' in '%s': %s\n", c, string1, testmemchr);
	printf("memcmp s6'%s' - s7'%s': %d\n", string6, string7, ft_memcmp(string6, string7, 11));
	printf("atoi s8'%s': %d\n", string8, ft_atoi(string8));
	teststrdup = ft_strdup(string1);
	printf("strdup s1'%s' in teststrdup: %s\n", string1, teststrdup);
	buffer = (int *)ft_calloc(20, sizeof(int));
	if (buffer)
		printf("calloc test: allocated 40 int\n");
	else
		printf("calloc failled");
	free(buffer);

	return (0);
}
/* to compile seperately for testing:
gcc main.c -L. -l:libft.a
*/
