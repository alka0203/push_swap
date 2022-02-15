/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 12:14:28 by asanthos          #+#    #+#             */
/*   Updated: 2022/02/15 14:08:01 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../ft_libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

typedef struct s_linked
{
	t_node	*head_node;
	t_node	*head_node_b;
	t_node	*last_node;
	t_node	**list1;
	t_node	**list2;
}	t_linked;

typedef struct s_all
{
	char	**dest;
	int		i;
	int		a;
	int		j;
	int		k;
	int		x;
	int		l;
	int		z;
	int		rem;
	int		counter;
	int		range;
	int		div_point;
	int		ii;
	int		jj;
	int		kk;
	int		flag;
	int		count;
	int		len;
	int		len_com;
	int		top;
	int		bottom;
	int		divider;
	int		flagaz;
	int		*arr;
	t_node	*head;
	t_node	*head_b;
}	t_all;

void	swap_a(t_node **list);
void	swap_b(t_node **list);
void	swap_ab(t_node **list1, t_node **list2);
void	push_to_a(t_node **list1, t_node **list2);
void	push_to_b(t_node **list1, t_node **list2);
void	rotate_a(t_node **list);
void	rotate_b(t_node **list2);
void	rotate_ab(t_node **list1, t_node **list2);
void	rotate_rev_a(t_node **list);
void	rotate_rev_b(t_node **list2);
void	rotate_rev_ab(t_node **list1, t_node **list2);
int		count_nodes(t_node **list);
t_node	*sort_small(t_node **list);
t_node	*sort_big(t_node **list1, t_node **list2);
t_node	*sort_five(t_node **list1, t_node **list2);
t_node	*get_last_node(t_node **list);
void	fill_arr(t_node **list, t_all boop);
int		get_length(int *arr);
int		compare_top(t_all boop, t_node **list1);
int		compare_bottom(t_all boop, t_node **list1);
int		compare_top_b(t_all boop, t_node **list2);
int		compare_bottom_b(t_all boop, t_node **list2);
void	compare_len(t_all boop, t_node **list1);
void	push(t_node **lst, int new_data);
void	check_dups(t_node **list);
int		count_nodes(t_node **list);
void	sort_last(t_node **list1, t_node **list2);
int		sort_check(t_node **list);
void	check_int(t_node **list);
void	rot_a(t_node **l1);
void	rot_b(t_node **l2);
void	rot_rev_a(t_node **l1);
void	rot_rev_b(t_node **l2);
void	bubblesort(t_all boop, int len);
void	fill(t_node **list, t_all boop);
void	reverse_list(t_node **list);
#endif
