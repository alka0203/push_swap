/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:18:37 by asanthos          #+#    #+#             */
/*   Updated: 2022/02/10 18:08:26 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	fill_arr(t_node **list, t_all boop)
{
	t_node	*head_node;
	int		i;

	i = 0;
	head_node = (*list);
	while (head_node != NULL)
	{
		boop.arr[i] = head_node->data;
		head_node = head_node->next;
		i++;
	}
}

int	get_length(int *arr)
{
	int		i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	compare_len(t_all boop, t_node **list1)
{
	if (boop.flag == 0)
	{
		boop.top = compare_top(boop, list1);
		boop.bottom = compare_bottom(boop, list1);
		if (boop.top <= boop.bottom)
			rot_a(list1);
		else if (boop.top > boop.bottom)
			rot_rev_a(list1);
	}
}
