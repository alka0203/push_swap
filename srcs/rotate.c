/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 19:06:14 by asanthos          #+#    #+#             */
/*   Updated: 2022/02/04 21:10:33 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_node **list)
{
	t_node	*head_node;
	t_node	*remain;

	head_node = (*list);
	remain = head_node->next;
	if (!list || remain == NULL)
		return ;
	(*list) = remain;
	while (remain->next != NULL)
		remain = remain->next;
	remain->next = head_node;
	head_node->next = NULL;
}

void	rotate_b(t_node **list2)
{
	t_node	*head_node;
	t_node	*remain;

	head_node = (*list2);
	remain = head_node->next;
	if (!list2 || remain == NULL)
		return ;
	(*list2) = remain;
	while (remain->next != NULL)
		remain = remain->next;
	remain->next = head_node;
	head_node->next = NULL;
}

void	rotate_ab(t_node **list1, t_node **list2)
{
	rotate_a(list1);
	rotate_b(list2);
	ft_putstr("rr\n");
}
