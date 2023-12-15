/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:22:15 by cgray             #+#    #+#             */
/*   Updated: 2023/12/14 18:27:25 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

int	ft_list_size(t_list *list)
{
	int i = 0;

	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}
