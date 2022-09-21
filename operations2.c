/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamrire <yamrire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 05:05:22 by yamrire           #+#    #+#             */
/*   Updated: 2022/09/21 05:06:28 by yamrire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data data, int *top)
{
	int	tmp;
	int	i;

	if (*top > 1)
	{
		tmp = data.arr[*top];
		i = *top;
		while (i > 0)
		{
			data.arr[i] = data.arr[i - 1];
			i--;
		}
		data.arr[i] = tmp;
		ft_printf("ra\n");
	}
	else
		sa(data, top);
}

void	rb(t_data data, int *top)
{
	int	tmp;
	int	i;

	if (*top + 1 < data.size - 2)
	{
		tmp = data.arr[*top + 1];
		i = *top + 1;
		while (i < data.size - 1)
		{
			data.arr[i] = data.arr[i + 1];
			i++;
		}
		data.arr[data.size - 1] = tmp;
		ft_printf("rb\n");
	}
	else
		sb(data, top);
}

void	rr(t_data data, int *top)
{
	ra(data, top);
	rb(data, top);
}

void	rra(t_data data, int *top)
{
	int	tmp;
	int	i;

	if (*top > 1)
	{
		tmp = data.arr[0];
		i = 0;
		while (i < *top)
		{
			data.arr[i] = data.arr[i + 1];
			i++;
		}
		data.arr[*top] = tmp;
		ft_printf("rra\n");
	}
	else
		sa(data, top);
}

void	rrb(t_data data, int *top)
{
	int	tmp;
	int	i;

	if (*top + 1 < data.size - 2)
	{
		tmp = data.arr[data.size - 1];
		i = data.size - 1;
		while (i > *top + 1)
		{
			data.arr[i] = data.arr[i - 1];
			i--;
		}
		data.arr[*top + 1] = tmp;
		ft_printf("rrb\n");
	}
	else
		sb(data, top);
}
