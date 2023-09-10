/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:20:40 by cgray             #+#    #+#             */
/*   Updated: 2023/09/10 17:58:28 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

//A == if i&j = 1 or i=a & j=1
//C == if i=1 & j=b or i=a & j=b
//B == if i=1 or j=1 or i=a or j =b
//" " == else
void	rush(int a, int b)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (j <= b)
	{
		while (i <= a)
		{
			if ((i == 1 && j == 1) || (i == a && j == 1))
				ft_putchar('A');
			else if ((i == 1 && j == b) || (i == a && j == b))
				ft_putchar('C');
			else if (i == 1 || j == 1 || i == a || j == b)
				ft_putchar('B');
			else
				ft_putchar (32);
			i++;
		}
		j++;
		i = 1;
		ft_putchar ('\n');
	}

}

