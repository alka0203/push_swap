/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:31:13 by asanthos          #+#    #+#             */
/*   Updated: 2022/02/05 13:20:34 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	compare_top_b(t_all boop, t_node **list2)
{
	int		len;
	int		i;
	t_node	*head_node;

	len = 0;
	i = 0;
	head_node = (*list2);
	while (head_node != NULL)
	{
		boop.jj = count_nodes(list2) - 1;
		if (head_node->data == boop.arr[boop.jj])
		{
			len = i;
			while (i)
			{
				rotate_rev_b(list2);
				i--;
			}
			return (len);
		}
		i++;
		rotate_b(list2);
		head_node = (*list2);
	}
	return (0);
}

int	compare_bottom_b(t_all boop, t_node **list2)
{
	t_node	*head_node;
	t_node	*last_node;

	boop.len_com = 0;
	boop.a = 0;
	head_node = (*list2);
	while (head_node != NULL)
	{
		boop.jj = count_nodes(list2) - 1;
		last_node = get_last_node(list2);
		if (last_node->data == boop.arr[boop.jj])
		{
			boop.len_com = boop.a;
			while (boop.a)
			{
				rotate_b(list2);
				boop.a--;
			}
			return (boop.len_com);
		}
		boop.a++;
		rotate_rev_b(list2);
		head_node = (*list2);
	}
	return (0);
}
