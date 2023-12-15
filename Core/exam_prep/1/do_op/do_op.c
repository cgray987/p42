/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:02:23 by cgray             #+#    #+#             */
/*   Updated: 2023/12/14 18:20:47 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int num1;
	int	num2;
	char *op;
	int	res;

	if (ac == 4)
	{
		num1 = atoi(av[1]);
		num2 = atoi(av[3]);
		op = av[2];
		if (*op == '+')
			printf("%d\n", num1 + num2);
		if (*op == '-')
			printf("%d\n", num1 - num2);
		if (*op == '*')
		{
			res = num1 * num2;
			printf("%d\n", res);
		}
		if (*op == '/')
			printf("%d\n", num1 / num2);
		if (*op == '%')
			printf("%d\n", num1 % num2);
	}
	else
		printf("\n");
}
