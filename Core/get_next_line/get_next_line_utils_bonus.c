/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:58:10 by cgray             #+#    #+#             */
/*   Updated: 2023/11/14 16:45:19 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
/*-------------------------------------------*/
/*Returns last node of the list 'list'
*/
t_list	*ft_list_last(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

/*Adds the node 'buf' at the end of the list 'list'
*/
void	ft_list_add_back(t_list **list, char *buf, int fd)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = ft_list_last(list[fd]);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	if (!last_node)
	{
		list[fd] = new_node;
	}
	else
		last_node->next = new_node;
	new_node->string_buffer = buf;
	new_node->next = NULL;
}

/* frees memory for buf and 'clear node' used in fn 'scoot line forward'
*/
void	list_free(t_list **list, t_list *clear_node, char *buf)
{
	t_list	*tmp;

	if (*list == NULL)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->string_buffer);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clear_node && clear_node->string_buffer[0])
		*list = clear_node;
	else
	{
		free(buf);
		free(clear_node);
	}
}

/* Function moves pointer to last line past the '\n' char found previously
in list and frees memory
*/
void	scoot_line_forward(t_list **list)
{
	t_list	*last_node;
	t_list	*clear_node;
	char	*buf;
	int		node_i;
	int		buf_i;

	buf = malloc(BUFFER_SIZE + 1);
	clear_node = malloc(sizeof(t_list));
	if (buf == NULL || clear_node == NULL)
		return ;
	last_node = (ft_list_last(*list));
	node_i = 0;
	buf_i = 0;
	while (last_node->string_buffer[node_i]
		&& last_node->string_buffer[node_i] != '\n')
		++node_i;
	while (last_node->string_buffer[node_i]
		&& last_node->string_buffer[++node_i])
	{
		buf[buf_i++] = last_node->string_buffer[node_i];
	}
	buf[buf_i] = '\0';
	clear_node->string_buffer = buf;
	clear_node->next = NULL;
	list_free(list, clear_node, buf);
}

/* Follow '\n' list logic and copy last line of list to string 'str'
*/
void	copy_list_to_string(t_list *list, char *str)
{
	int	node_i;
	int	j;

	j = 0;
	while (list)
	{
		node_i = 0;
		while (list->string_buffer[node_i])
		{
			if (list->string_buffer[node_i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j++] = list->string_buffer[node_i++];
		}
		list = list->next;
	}
	str[j] = '\0';
}
/*------------------------------------------------------------------*/
