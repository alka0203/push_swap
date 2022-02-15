/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:07:25 by asanthos          #+#    #+#             */
/*   Updated: 2022/02/02 15:09:26 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rot_a(t_node **l1)
{
	rotate_a(l1);
	ft_putstr("ra\n");
}

void	rot_b(t_node **l2)
{
	rotate_b(l2);
	ft_putstr("rb\n");
}

void	rot_rev_a(t_node **l1)
{
	rotate_rev_a(l1);
	ft_putstr("rra\n");
}

void	rot_rev_b(t_node **l2)
{
	rotate_rev_b(l2);
	ft_putstr("rrb\n");
}
