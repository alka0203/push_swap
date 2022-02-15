/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 22:37:57 by asanthos          #+#    #+#             */
/*   Updated: 2022/02/05 13:23:20 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*get_last_node(t_node **list)
{
	t_node	*last_node;

	last_node = (*list);
	while (last_node->next != NULL)
		last_node = last_node->next;
	return (last_node);
}

int	compare_top(t_all boop, t_node **list1)
{
	int		len;
	int		i;
	t_node	*head_node;

	len = 0;
	i = 0;
	head_node = (*list1);
	while (head_node != NULL)
	{
		if (head_node->data < boop.arr[boop.div_point])
		{
			len = i;
			while (i--)
				rotate_rev_a(list1);
			return (len);
		}
		i++;
		rotate_a(list1);
		head_node = (*list1);
	}
	return (0);
}

int	compare_bottom(t_all boop, t_node **list1)
{
	int		len;
	int		i;
	t_node	*head_node;
	t_node	*last_node;

	len = 0;
	i = 0;
	head_node = (*list1);
	while (head_node != NULL)
	{
		last_node = get_last_node(list1);
		if (last_node->data < boop.arr[boop.div_point])
		{
			len = i;
			while (i--)
				rotate_a(list1);
			return (len);
		}
		i++;
		rotate_rev_a(list1);
		head_node = (*list1);
	}
	return (0);
}
