/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamrire <yamrire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 05:25:47 by yamrire           #+#    #+#             */
/*   Updated: 2022/09/20 06:34:55 by yamrire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(char *str)
{
	ft_printf("%s\n", str);
	exit(-1);
}

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
		ft_exit("ERROR : Empty array !");
	return (1);
}

void	ft_swap(int	*arr, int i, int j)
{
	int	tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void    sort_three_elements(t_data data, int *top)
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