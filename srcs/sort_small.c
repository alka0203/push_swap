/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 22:39:27 by asanthos          #+#    #+#             */
/*   Updated: 2022/02/10 17:55:37 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	check_if_greater(t_node *head_node, t_node **list)
{
	if ((head_node->next)->data > (head_node->next->next)->data)
	{
		rot_rev_a(list);
		head_node = (*list);
		if (head_node->data > (head_node->next)->data)
			swap_a(list);
	}
}

static void	check_if_smaller(t_node **list, t_node *head_node)
{
	if ((head_node->next)->data < (head_node->next->next)->data)
	{
		swap_a(list);
		head_node = (*list);
		if ((head_node->next)->data > (head_node->next->next)->data)
		{
			rot_rev_a(list);
			swap_a(list);
		}
	}
	else if ((head_node->next)->data > (head_node->next->next)->data)
	{
		swap_a(list);
		rot_rev_a(list);
	}
}

int	sort_check(t_node **list)
{
	int		i;
	t_node	*head_node;
	t_all	boop;

	head_node = (*list);
	boop.arr = (int *)malloc(count_nodes(list) * sizeof(int));
	fill(list, boop);
	i = 0;
	while (head_node != NULL && (i < count_nodes(list)))
	{
		if (head_node->data != boop.arr[i])
		{
			free(boop.arr);
			return (1);
		}
		i++;
		head_node = head_node->next;
	}
	free(boop.arr);
	return (0);
}

t_node	*sort_small(t_node **list)
{
	t_node	*head_node;

	head_node = (*list);
	if (head_node->next == NULL)
		head_node->next = NULL;
	else if (head_node->next->next == NULL)
		swap_a(list);
	else if (head_node->data < (head_node->next)->data)
	{
		if (sort_check(list) == 0)
			return (*list);
		check_if_greater(head_node, list);
	}
	else if (head_node->data > (head_node->next)->data)
	{
		if (sort_check(list) == 0)
			return (*list);
		check_if_smaller(list, head_node);
		return (*list);
	}
	return (*list);
}
