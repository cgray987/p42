/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:58:07 by cgray             #+#    #+#             */
/*   Updated: 2023/11/23 12:40:04 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*Return length to '\n' in list, total length in list if not found
 */
int	newline_len(t_list *list)
{
	int	node_i;
	int	len;

	len = 0;
	while (list)
	{
		node_i = 0;
		while (list->string_buffer[node_i]
			&& node_i < BUFFER_SIZE)
		{
			if (list->string_buffer[node_i] == '\n')
			{
				++len;
				return (len);
			}
			++node_i;
			++len;
		}
		list = list->next;
	}
	return (len);
}

/* Return last line of the node (line with \ n) as a string
*/
char	*return_line(t_list *list)
{
	int		len;
	char	*last_line;

	len = newline_len(list);
	last_line = malloc(len + 1);
	if (!last_line)
		return (NULL);
	copy_list_to_string(list, last_line);
	return (last_line);
}

/* Returns 0 until '\ n' found; used for logic while creating list
Loops thru list, then loops thru string_buffer looking for '\ n'
*/
int	find_newline(t_list *list)
{
	int	i;

	while (list)
	{
		i = 0;
		while (list->string_buffer[i] && i < BUFFER_SIZE)
		{
			if (list->string_buffer[i] == '\n')
			{
				return (1);
			}
			++i;
		}
		list = list->next;
	}
	return (0);
}

/*Create list from fd lines filled with string_buffer as nodes until '\ n'
character is found
*/
void	create_list_to_newline(t_list **list, int fd)
{
	int		read_len;
	char	*buf;

	while (!find_newline(list[fd]))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return ;
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len <= 0)
		{
			free(buf);
			return ;
		}
		buf[read_len] = '\0';
		ft_list_add_back(list, buf, fd);
	}
}

/* Returns a line read from the given file descriptor, NULL if empty/error.
Creates list stopping at the first line it finds '\ n'
Searches thru BUFFER characters in file until it finds '\ n'.
Return that string, and replace remaining BUFFER characters after '\ n' in list.
*/
char	*get_next_line(int fd)
{
	static t_list	*list[4096];
	char			*next_line;

	if (fd < 0 || fd > 4095 || BUFFER_SIZE <= 0)
		return (NULL);
	create_list_to_newline(list, fd);
	if (list[fd] == NULL)
		return (NULL);
	next_line = return_line(list[fd]);
	scoot_line_forward(&list[fd]);
	return (next_line);
}
// /* -----------------MAIN FOR TESTING---------------*/
// #include <stdio.h>
// int	main(void)
// {
// 	int		fd1;
// 	int		fd2;
// 	char	*line1;
// 	char	*line2;
// 	int		lines;

// 	lines = 1;
// 	fd1 = open("text.txt", O_RDONLY);
// 	fd2 = open("text2.txt", O_RDONLY);
// 	while (line1 = get_next_line(fd1))
// 	{
// 		printf("%d -> %s\n", lines++, line1);
// 		free(line1);
// 	}
// 	while (line2 = get_next_line(fd2))
// 	{
// 		printf("%d -> %s\n", lines++, line2);
// 		free(line2);
// 	}
// }
// /*---------------------------------------------------*/
// /* -------------CURRENTLY UNUSED FUNCTIONS----------*/
// /*Returns lastline string when newline character is found in list
// Returns 0 if not found
// */
// char	*return_newline_in_list(t_list *list)
// {
// 	int		node_i;
// 	int		j;
// 	char	*last_line;
//
// 	last_line = malloc(newline_len(list) + 1);
// 	if (!last_line)
// 		return (NULL);
// 	j = 0;
// 	while (list)
// 	{
// 		node_i = 0;
// 		while (list->string_buffer[node_i] && node_i < BUFFER_SIZE)
// 		{
// 			if (list->string_buffer[node_i] == '\n')
// 			{
// 				last_line[j++] = '\n';
// 				last_line[j] = '\0';
// 				return (last_line);
// 			}
// 			last_line[j++] = list->string_buffer[node_i++];
// 		}
// 		list = list->next;
// 	}
// 	return (NULL);
// }
