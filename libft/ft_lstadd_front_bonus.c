/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:47:49 by adihaj            #+#    #+#             */
/*   Updated: 2022/10/31 14:34:26 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//add node in the beginning of the list

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL || lst == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

// int main()
// {
// 	t_list	*node1;
// 	t_list	*node2;

// 	node1 = ft_lstnew("levi");
// 	node2 = ft_lstnew("eren");

// 	ft_lstadd_front(&node1, node2);
// 	while(node1)
// 	{
// 		printf("%s\n", node1->content);
// 		node1 = node1->next;
// 	}

// }