/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:37:25 by agpereir          #+#    #+#             */
/*   Updated: 2023/05/04 15:08:39 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Adds a new node to the beginning of the list.
If there is a node at the beginning, add it as next to the new
lst: The address of a pointer to the first link of
a list.
new: The address of a pointer to the node to be
added to the list.*/
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
