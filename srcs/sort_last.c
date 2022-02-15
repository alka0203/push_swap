/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_last.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:38:10 by asanthos          #+#    #+#             */
/*   Updated: 2022/02/10 17:41:49 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void	loop(t_node *head_node, t_node **l1, t_node **list2, t_all boop)
{
	int	count;

	while (head_node != NULL)
	{
		boop.jj = 0;
		count = count_nodes(list2) - 1;
		if (head_node->data == boop.arr[count])
			push_to_a(l1, list2);
		else
		{
			boop.top = compare_top_b(boop, list2);
			boop.bottom = compare_bottom_b(boop, list2);
			if (boop.top <= boop.bottom)
			{
				rotate_b(list2);
				ft_putstr("rb\n");
			}
			else if (boop.top > boop.bottom)
			{
				rotate_rev_b(list2);
				ft_putstr("rrb\n");
			}
		}
		head_node = (*list2);
	}
}

void	sort_last(t_node **list1, t_node **list2)
	{
	t_node	*head_node;
	t_all	boop;

	head_node = (*list2);
	boop.arr = (int *)malloc(count_nodes(list2) * sizeof(int));
	fill(list2, boop);
	boop.jj = 0;
	loop(head_node, list1, list2, boop);
	free (boop.arr);
}
