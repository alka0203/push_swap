/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:16:59 by asanthos          #+#    #+#             */
/*   Updated: 2022/02/07 12:53:02 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_int(double r)
{
	if (r > 2147483647 || r < -2147483648)
	{
		ft_putstr("Error\n");
		exit(EXIT_FAILURE);
	}
}

static void	check_num(const char *str, int i)
{
	if (str[i] < 48 || str[i] > 57)
	{
		ft_putstr("Error\n");
		exit(EXIT_FAILURE);
	}
}

int	ft_atoi(const char *str)
{
	int		i;
	int		s;
	double	r;

	i = 0;
	s = 1;
	r = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	check_num(str, i);
	while (str[i] <= '9' && str[i] >= '0')
	{
		 r *= 10;
		 r = r + (str[i] - '0');
		 i++;
	}
	r *= s;
	check_int(r);
	return (r);
}
