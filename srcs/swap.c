/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 20:26:48 by asanthos          #+#    #+#             */
/*   Updated: 2022/02/04 21:09:02 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_node **list)
{
	t_node	*head_node;
	t_node	*second_node;

	head_node = (*list);
	second_node = head_node->next;
	if (!list)
		return ;
	else if (head_node->data > second_node->data)
	{
		head_node->next = second_node->next;
		second_node->next = head_node;
		(*list) = second_node;
		ft_putstr_fd("sa\n", 1);
	}
}

void	swap_b(t_node **list)
{
	t_node	*head_node;
	t_node	*second_node;

	head_node = (*list);
	second_node = head_node->next;
	if (second_node == NULL || !list)
		return ;
	else if (head_node->data > second_node->data)
	{
		head_node->next = second_node->next;
		second_node->next = head_node;
		(*list) = second_node;
		ft_putstr("sb\n");
	}
}

void	swap_ab(t_node **list1, t_node **list2)
{
	swap_a(list1);
	swap_b(list2);
	ft_putstr("ss\n");
}

void	push_to_a(t_node **list1, t_node **list2)
{
	t_node	*head_node1;
	t_node	*head_node2;

	if (!list2)
		return ;
	else
	{
		head_node1 = (*list1);
		head_node2 = (*list2);
		if (head_node2->next != NULL)
			(*list2) = head_node2->next;
		else
			(*list2) = NULL;
		head_node2->next = head_node1;
		(*list1) = head_node2;
	}
	ft_putstr("pa\n");
}

void	push_to_b(t_node **list1, t_node **list2)
{
	t_node	*head_node1;
	t_node	*head_node2;

	head_node1 = (*list1);
	head_node2 = (*list2);
	(*list1) = head_node1->next;
	head_node1->next = head_node2;
	(*list2) = head_node1;
	ft_putstr("pb\n");
}
