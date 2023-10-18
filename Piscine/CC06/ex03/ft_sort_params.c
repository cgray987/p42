/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:36:40 by cgray             #+#    #+#             */
/*   Updated: 2023/09/21 21:01:40 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:31:23 by cgray             #+#    #+#             */
/*   Updated: 2023/09/21 17:35:39 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	print(char *str)
{
	while (*str != '\0')
	{
		putchar(*str);
		str++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ascii_sort(int argc, char **argv)
{
	char	*t;
	int		i;
	int		j;

	i = 1;
	t = 0;
	while (i < argc - 1)
	{
		j = 1;
		{
			while (j < argc - 1)
			{
				if (ft_strcmp(argv[j], argv[j + 1]))
				{
					t = argv[j];
					argv[j] = argv[j + 1];
					argv[j + 1] = t;
				}
				j++;
			}
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	ascii_sort(argc, argv);
	while (i < argc)
	{
		print(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
