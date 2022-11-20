/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamrire <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 03:35:58 by yamrire           #+#    #+#             */
/*   Updated: 2022/11/20 21:04:36 by yamrire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int *arr, int size)
{
	int	i;

	if (arr)
	{
		i = 1;
		while (i < size)
		{
			if (arr[i] < arr[i - 1])
				i++;
			else
				return (0);
		}
	}
	else
		ft_exit();
	return (1);
}

void	three_five(t_data data)
{
	if (!(is_sorted(data.arr, data.size)))
		sort_three_elements(data, &data.iatop);
	while (data.iatop != data.size - 1)
		pa(data, &data.iatop);
}

void	sort_three_elements(t_data data, int *top)
{
	if (data.arr[2] > data.arr[1])
	{
		if (data.arr[1] > data.arr[0])
		{
			sa(data, top);
			rra(data, top);
		}
		else if (data.arr[1] < data.arr[0])
		{
			if (data.arr[2] > data.arr[0])
				ra(data, top);
			else if (data.arr[2] < data.arr[0])
				sa(data, top);
		}
	}
	else if (data.arr[2] < data.arr[1])
	{
		if (data.arr[2] < data.arr[0])
		{
			sa(data, top);
			ra(data, top);
		}
		else if (data.arr[2] > data.arr[0])
			rra(data, top);
	}
}

void	sort_five_elements(t_data data)
{
	int	tmp;

	while (!(is_sorted(data.arr, data.size)))
	{
		tmp = data.size - 1;
		while (tmp > 2)
		{
			if (data.arr[0] == data.sort_arr[tmp])
			{
				rra(data, &data.iatop);
				pb(&data.iatop);
				tmp--;
			}
			else if (data.arr[data.iatop] == data.sort_arr[tmp])
			{
				pb(&data.iatop);
				tmp--;
			}
			else
				ra(data, &data.iatop);
		}
		three_five(data);
	}
}

void	sort_array(t_data data)
{
	if (!(is_sorted(data.arr, data.size)))
	{
		sort_kick_duplicate(data);
		if (data.size < 6)
		{
			if (data.size == 2)
				sa(data, &data.iatop);
			else if (data.size == 3)
				sort_three_elements(data, &data.iatop);
			else if (data.size > 3 && data.size <= 5)
				sort_five_elements(data);
		}
		else
			sort_stack_a(data, &data.iatop, 0);
	}
}
