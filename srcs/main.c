/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:22:20 by asanthos          #+#    #+#             */
/*   Updated: 2022/03/20 17:52:48 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_node	*check_input(t_all boop, t_node *head, t_node *head_b)
{
	free(boop.dest);
	check_dups(&head);
	reverse_list(&head);
	if (count_nodes(&head) <= 3)
		return (sort_small(&head));
	else if (count_nodes(&head) <= 5)
		return (sort_five(&head, &head_b));
	else
		return (sort_big(&head, &head_b));
}

static void	del_list(t_node *head)
{
	t_node	*temp_node;

	while (head != NULL)
	{
		temp_node = (head)->next;
		free(head);
		head = temp_node;
	}
}

static void	push_init(t_all *boop)
{
	boop->i = 1;
	boop->j = 0;
	boop->l = 0;
	boop->x = 0;
	boop->head = NULL;
	boop->head_b = NULL;
	boop->dest = 0;
	boop->flagaz = 0;
}

static void	loop_split(t_all *boop)
{
	while (boop->dest[boop->z])
	{
		boop->l = 0;
		boop->x = ft_atoi(boop->dest[boop->z]);
		free(boop->dest[boop->z++]);
		push(&boop->head, boop->x);
	}
}

#include <stdio.h>

void	print_list(t_node *head)
{
	while(head != NULL)
	{
		printf("%d\n", head->data);
		head = head->next;
	}
}

int	main(int argc, char **argv)
{
	t_all	boop;
	t_node	*ret_node;

	push_init(&boop);
	if (argc > 1)
	{
		while (boop.i < argc)
		{
			if (boop.dest && boop.flagaz == 1)
				free(boop.dest);
			boop.dest = ft_split(argv[boop.i], ' ');
			boop.z = 0;
			loop_split(&boop);
			boop.flagaz = 1;
			boop.i++;
		}
		ret_node = check_input(boop, boop.head, boop.head_b);
		boop.head = ret_node;
		print_list(boop.head);
		del_list(boop.head);
	}
}
