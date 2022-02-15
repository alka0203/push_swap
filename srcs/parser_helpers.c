/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 00:27:22 by asanthos          #+#    #+#             */
/*   Updated: 2022/02/10 17:56:00 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_node **lst, int new_data)
{
	t_node	*new_node;
	t_node	*temp_node;

	if (!lst)
		return ;
	temp_node = (*lst);
	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = new_data;
	(*lst) = new_node;
	new_node->next = temp_node;
}

void	check_dups(t_node **list)
{
	t_node	*head_node;
	t_node	*dup_node;
	int		check;

	head_node = (*list);
	while (head_node != NULL)
	{
		check = 0;
		dup_node = (*list);
		while (dup_node != NULL)
		{
			if (head_node->data == dup_node->data)
				check++;
			dup_node = dup_node->next;
		}
		if (check > 1)
		{
			ft_putstr("Error\n");
			exit(EXIT_FAILURE);
		}
		head_node = head_node->next;
	}
}

int	count_nodes(t_node **list)
{
	t_node	*head_node;
	int		i;

	i = 0;
	head_node = (*list);
	if (!list)
		return (0);
	while (head_node != NULL)
	{
		i++;
		head_node = head_node->next;
	}
	return (i);
}

void	reverse_list(t_node **list)
{
	t_node	*prev;
	t_node	*curr;

	if (list != NULL)
	{
		prev = (*list);
		curr = (*list)->next;
		(*list) = (*list)->next;
		prev->next = NULL;
		while ((*list) != NULL)
		{
			(*list) = (*list)->next;
			curr->next = prev;
			prev = curr;
			curr = (*list);
		}
		(*list) = prev;
	}
}

void	bubblesort(t_all boop, int len)
{
	int		i;
	int		j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < (len - i))
		{
			if (boop.arr[j] > boop.arr[j + 1])
				ft_swap(&(boop.arr[j]), &(boop.arr[j + 1]));
			j++;
		}
		i++;
	}
}
