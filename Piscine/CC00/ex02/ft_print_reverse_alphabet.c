/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:47:47 by cgray             #+#    #+#             */
/*   Updated: 2023/09/08 10:53:11 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//ASCII 'a' == 97 : 'z' == 122
//declare ch as type char
//init ch == 122 ('z')
//run while 122>=ch>=97 ('z:a')
// display ch and iterate -1
void	ft_print_reverse_alphabet(void)
{
	char	ch;

	ch = 122;

	while (ch <= 122 && ch >= 97)
	{
		write(1, &ch, 1);
		ch = ch - 1;
	}
}

/*/main function to be commentted out to submit
int main(void)
{
    ft_print_reverse_alphabet();
}
*/
