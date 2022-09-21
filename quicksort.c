/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamrire <yamrire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 02:50:43 by yamrire           #+#    #+#             */
/*   Updated: 2022/09/21 03:40:41 by yamrire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition(int *arr, int start, int end)
{
	int	x;
	int	i;
	int	j;

	x = arr[end];
	i = start - 1;
	j = start;
	while (j < end)
	{
		if (arr[j] >= x)
		{
			i++;
			ft_swap(arr, i, j);
		}
		j++;
	}
	ft_swap(arr, i + 1, end);
	return (i + 1);
}

void	quicksort(int *arr, int start, int end)
{
	int	p;

	if (start < end)
	{
		p = partition(arr, start, end);
		quicksort(arr, start, p - 1);
		quicksort(arr, p + 1, end);
	}
}
