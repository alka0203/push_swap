/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 19:41:45 by asanthos          #+#    #+#             */
/*   Updated: 2022/02/15 14:41:44 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	fill(t_node **list, t_all boop)
{
	fill_arr(list, boop);
	bubblesort(boop, count_nodes(list) - 1);
}

static void	push_reset(t_all *boop, t_node **l1)
{
	boop->arr = (int *)malloc(count_nodes(l1) * sizeof(int));
	fill(l1, *boop);
	boop->ii = 0;
	boop->kk = 0;
	if (count_nodes(l1) < (boop->divider * 2))
	{
		boop->range = count_nodes(l1) / 2;
		boop->div_point = count_nodes(l1) / 2;
	}
	else
	{
		boop->range = count_nodes(l1) / boop->divider;
		boop->div_point = count_nodes(l1) / boop->divider;
	}
}

static void	check_main_loop(t_linked link, t_all boop, t_node **l1, t_node **l2)
{
	while (link.head_node != NULL || boop.ii <= boop.range)
	{
		if (boop.ii == boop.range)
		{
			free (boop.arr);
			if (count_nodes(l1) <= 3)
				break ;
			push_reset(&boop, l1);
		}
		boop.flag = 0;
		boop.kk = 0;
		if (link.head_node->data < boop.arr[boop.div_point])
		{
			boop.flag = 1;
			push_to_b(l1, l2);
			boop.kk++;
		}
		compare_len(boop, l1);
		boop.ii += boop.kk;
		link.head_node = (*l1);
	}
}

t_node	*sort_big(t_node **list1, t_node **list2)
{
	t_linked	link;
	t_all		boop;

	link.head_node = (*list1);
	if (count_nodes(list1) <= 100)
		boop.divider = 4;
	else
		boop.divider = 8;
	push_reset(&boop, list1);
	if (sort_check(list1) == 0)
		return (*list1);
	check_main_loop(link, boop, list1, list2);
	if (count_nodes(list1) <= 3)
		sort_small(list1);
	sort_last(list1, list2);
	return (*list1);
}
