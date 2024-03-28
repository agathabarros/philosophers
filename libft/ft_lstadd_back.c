/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:59:50 by agpereir          #+#    #+#             */
/*   Updated: 2023/05/04 15:08:13 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*lst: The address of a pointer to the first link of
a list.
new: The address of a pointer to the node to be
added to the list.
Adds the node ’new’ at the end of the list*/
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			temp = ft_lstlast(*(lst));
			temp->next = new;
		}
	}
}
