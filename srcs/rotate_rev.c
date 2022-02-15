/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 19:07:27 by asanthos          #+#    #+#             */
/*   Updated: 2022/02/04 21:10:44 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_rev_a(t_node **list)
{
	t_node	*head_node;
	t_node	*remain;

	head_node = (*list);
	if (!list || head_node->next == NULL)
		return ;
	while (head_node->next->next != NULL)
		head_node = head_node->next;
	remain = head_node->next;
	remain->next = (*list);
	head_node->next = NULL;
	(*list) = remain;
}

void	rotate_rev_b(t_node **list2)
{
	t_node	*head_node;
	t_node	*remain;

	head_node = (*list2);
	if (!list2 || head_node->next == NULL)
		return ;
	while (head_node->next->next != NULL)
		head_node = head_node->next;
	remain = head_node->next;
	remain->next = (*list2);
	head_node->next = NULL;
	(*list2) = remain;
}

void	rotate_rev_ab(t_node **list1, t_node **list2)
{
	rotate_rev_a(list1);
	rotate_rev_b(list2);
	ft_putstr("rrr\n");
}
