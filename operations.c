/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamrire <yamrire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 01:10:28 by yamrire           #+#    #+#             */
/*   Updated: 2022/09/21 05:05:46 by yamrire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data data, int *top)
{
	int	tmp;

	if (*top > 0)
	{
		tmp = data.arr[*top];
		data.arr[*top] = data.arr[*top - 1];
		data.arr[*top - 1] = tmp;
		ft_printf("sa\n");
	}
}

void	sb(t_data data, int *top)
{
	int	tmp;

	if ((data.size - (*top + 1)) > 1)
	{
		tmp = data.arr[*top + 1];
		data.arr[*top + 1] = data.arr[*top + 2];
		data.arr[*top + 2] = tmp;
		ft_printf("sb\n");
	}
}

void	ss(t_data data, int *top)
{
	sa(data, top);
	sb(data, top);
}

void	pa(t_data data, int *top)
{
	if (*top < data.size - 1)
	{
		*top += 1;
		ft_printf("pa\n");
	}
}

void	pb(int *top)
{
	if (*top + 1 > 0)
	{
		*top -= 1;
		ft_printf("pb\n");
	}
}
