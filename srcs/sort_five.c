/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 22:39:08 by asanthos          #+#    #+#             */
/*   Updated: 2022/02/10 17:18:21 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	check(t_node *head_node, t_all boop, t_node **list1, t_node **list2)
{
	while (head_node != NULL || boop.i <= boop.range)
	{
		if (boop.i == boop.range)
			break ;
		boop.flag = 0;
		boop.div_point = 3;
		boop.k = 0;
		if (head_node->data >= boop.arr[boop.div_point])
		{
			boop.flag = 1;
			push_to_b(list1, list2);
			boop.k++;
		}
		if (boop.flag == 0)
			rot_a(list1);
		boop.i += boop.k;
		head_node = (*list1);
	}
}

static void	end_check(t_all boop, t_node **list1, t_node **list2)
{
	if (boop.len == 5)
	{
		if ((*list2)->data > ((*list2)->next)->data)
			swap_b(list2);
	}
	while (boop.rem-- > 0)
	{
		push_to_a(list1, list2);
		rot_a(list1);
	}
}

t_node	*sort_five(t_node **list1, t_node **list2)
{
	t_node	*head_node;
	t_all	boop;

	boop.i = 0;
	boop.k = 0;
	boop.flag = 0;
	boop.len = 0;
	head_node = (*list1);
	boop.len = count_nodes(list1);
	boop.arr = (int *)malloc(count_nodes(list1) * (sizeof(int)));
	fill(list1, boop);
	boop.div_point = 3;
	boop.range = count_nodes(list1) - 3;
	boop.rem = boop.range;
	if (sort_check(list1) == 0)
		return (*list1);
	check(head_node, boop, list1, list2);
	sort_small(list1);
	end_check(boop, list1, list2);
	free (boop.arr);
	return (*list1);
}
