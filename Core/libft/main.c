/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:28:38 by cgray             #+#    #+#             */
/*   Updated: 2023/10/18 13:50:01 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
/*
main function to test each lib function
*/
int	main(void)
{
	char	c = 'l';
	char	string1[] = "Hello World";
	char	string2[] = "qwerty";
	char	string3[] = "ft_memset test";
	char	string4[] = "abcdef";
	char	string5[] = "1234";

	printf("%c is alphanumeric: %d\n", c, ft_isalnum(c));
	printf("%c is alpha: %d\n", c, ft_isalpha(c));
	printf("%c is ascii: %d\n", c, ft_isascii(c));
	printf("%c is digit: %d\n", c, ft_isdigit(c));
	printf("%c is printable: %d\n", c, ft_isprint(c));
	printf("%c capitalize: %c\n", c, ft_toupper(c));
	printf("%c uncapitalize: %c\n\n", c, ft_tolower(c));

	ft_memset(string3 + 6, '.', 2);
	printf("ft_memset: %s\n", string3);
	ft_bzero(string3, 1);
	printf("bzero: %s\n", string3);
	printf("before memcpy s2: %s\n", string2);
	ft_memcpy(string2, string1, 6);
	printf("memcpy s1 into s2: %s\n", string2);
	printf("before memmove s4: %s\n", string4);
	ft_memmove(string4, string1, 6);
	printf("memmove s1 into s4: %s\n\n", string4);

	printf("search s1 for first position %c: %s\n", c, ft_strchr(string1, c));
	printf("search s1 for last position %c: %s\n", c, ft_strrchr(string1, c));
	printf("string1 length: %zu\n", ft_strlen(string1));
	printf("s1 and s2 cmp: %d\n", ft_strncmp(string1, string2, 3));
	ft_strlcpy(string5, string1, 5);
	printf("strlcpy %ld characters s1 into s5: %s\n", ft_strlcpy(string5, string1, 5), string5);

	return (0);
}
/* to compile seperately for testing:
gcc main.c -L. -l:libft.a
*/
