/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:46:17 by cgray             #+#    #+#             */
/*   Updated: 2023/09/08 10:49:14 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// def and init ch; ASCII 'a' = 97; 'z' = 122
void	ft_print_alphabet(void)
{
	char	ch;

	ch = 97;

	while (ch >= 97 && ch <= 122)
	{
		write(1, &ch, 1);
		ch = ch + 1;
	}
}
/*/ to be commented out to submit
int main(void)
{
    ft_print_alphabet();
    return 0;
}
*/
