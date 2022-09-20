/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamrire <yamrire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 04:58:40 by yamrire           #+#    #+#             */
/*   Updated: 2022/09/20 06:51:58 by yamrire          ###   ########.fr       */
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

void	integer_check(char *arr)
{
	int	j;
	int	sign;
	
	j = 0;
	sign = 0;
	if(arr[j] && (arr[j] == '-' || arr[j] == '+') && !arr[j + 1])
			ft_exit("ERROR : I only accept integers !");
	if (!arr[j])
		ft_exit("ERROR : I only accept integers !");
	while (arr[j]) 
	{ 
		if (ft_strchr("+-0123456789", arr[j]))
		{
			if (j > 10)
				ft_exit("ERROR : I only accept integers !");
			if (arr[j] == '+' || arr[j] == '-')
			{
				if (sign != 0)
					ft_exit("ERROR : I only accept integers !");
				else
					sign += 1;
			}
			j++;
		}
		else
			ft_exit("ERROR : I only accept integers !");
	}
}
// #include <stdio.h>

// void sort_5(t_data data)
// {
// 	int i = 0;
// 	while(!is_sorted(data.arr,data.size) || i != 0)
// 	{
// 		if(data.arr[data.iatop] < data.arr[0] && data.arr[data.iatop - 1] < data.arr[0])
// 			ra(data,&data.iatop);
// 		else if(data.arr[data.iatop] > data.arr[data.iatop - 1])
// 			sa(data, &data.iatop); 
// 		else if ()
// 			rra(data,&data.iatop);
// 		else if (is_sorted(data.arr,data.size - i) && i > 0)
// 		{
// 			i--;
// 			pa(data, &data.iatop);
// 		}
// 		else 
// 		{
// 			i++;
// 			pb(&data.iatop);
// 		}	
// 	}
// }




int	main(int ac, char **av)
{
	t_data data;
	int	i;
	int	j;
	int	tmp;
	int	size;

    if (ac > 1)
    {
		i = 1;
		while (av[i])
		{
			integer_check(av[i]);
			i++;
		}
		i = ac - 1;
		j = 0;
		data.size = ac - 1;
		data.arr = malloc((ac - 1) * sizeof(int));
		data.sort_arr = malloc((ac - 1) * sizeof(int));
		while (i > 0)
		{
			data.arr[j] = ft_atoi(av[i]);
			data.sort_arr[j] = data.arr[j];
			i--;
			j++;
		}
		if (!(is_sorted(data.arr, data.size)))
		{
			i = 0;
			quicksort(data.sort_arr, 0, data.size - 1);
			while (i < data.size - 1)
			{
				if (data.sort_arr[i] == data.sort_arr[i + 1])
					ft_exit("ERROR: I don't accept duplicated integers !");
				i++;
			}
			data.iatop = data.size - 1;
			if (data.size < 6)
			{
				if (data.size == 2)
					sa(data, &data.iatop);
				else if (data.size == 3)
					sort_three_elements(data, &data.iatop);
				else if (data.size > 3 && data.size <= 5)
				{
					// sort_5(data);
					// for(int i = 0; i < data.size; i++)
					// 	printf("%d ",data.arr[i]);
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
						if (!(is_sorted(data.arr, data.size)))
							sort_three_elements(data, &data.iatop);
						size = data.size - tmp - 1;
						while (data.iatop != data.size - 1)
							pa(data, &data.iatop);
					}
				}
			}
			else
			{
				sort_stack_a(data, &data.iatop, 0);
			}
		}
	}
	else
		ft_exit("ERROR : You need at least 1 parameter !");
	return (0);
}
