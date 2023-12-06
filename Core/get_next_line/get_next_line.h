/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:58:12 by cgray             #+#    #+#             */
/*   Updated: 2023/11/14 16:31:48 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*string_buffer;
	struct s_list	*next;

}					t_list;

char	*get_next_line(int fd);
t_list	*ft_list_last(t_list *list);
void	ft_list_add_back(t_list **list, char *buf);
void	list_free(t_list **list, t_list *clear_node, char *buf);
void	scoot_line_forward(t_list **list);
void	copy_list_to_string(t_list *list, char *str);
#endif
