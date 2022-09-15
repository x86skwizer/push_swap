/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamrire <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 01:10:28 by yamrire           #+#    #+#             */
/*   Updated: 2022/09/15 03:27:05 by yamrire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_arr(int *arr, int start, int end)
{
	int	len;

	len = 0;
	if (arr)
	{
		while (start > end)
		{
			len++;
			start++;
		}
	}
	return (len);
	
}

void	sa(t_data data, int *top)
{
	int	tmp;
	
	if (len_arr(data.arr, 0, *top) > 1)
	{
		tmp = data.arr[*top];
		data.arr[*top] = data.arr[*top - 1];
		data.arr[*top - 1] = tmp;
	}
}

void	sb(t_data data, int *top)
{
	int	tmp;
	
	if (len_arr(data.arr, *top + 1, data.size - 1) > 1)
	{
		tmp = data.arr[*top + 1];
		data.arr[*top + 1] = data.arr[*top + 2];
		data.arr[*top + 2] = tmp;
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
		*top -= 1;
}

void	pb(int *top)
{
	if (*top + 1 > 0)
		*top += 1;
}

void	ra(t_data data, int *top)
{
	int	tmp;
	int	i;

	if (*top > 2)
	{
		tmp = data.arr[*top];
		i = *top;
		while (i > 0)
		{
			data.arr[i] = data.arr[i - 1];
			i--;
		}
		data.arr[i] = tmp;
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

	if (*top > 2)
	{
		tmp = data.arr[0];
		i = 0;
		while (i < *top)
		{
			data.arr[i] = data.arr[i + 1];
			i++;
		}
		data.arr[*top] = tmp;
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
	}
	else
		sb(data, top);
}

void	rrr(t_data data, int *top)
{
	rra(data, top);
	rrb(data, top);
}