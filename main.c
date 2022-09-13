/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamrire <yamrire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 04:58:40 by yamrire           #+#    #+#             */
/*   Updated: 2022/09/13 22:23:57 by yamrire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(char *str)
{
	ft_printf("%s\n", str);
	exit(-1);
}

int	is_sorted(char *arr)
{
	int	i;
	
	if (arr)
	{
		i = 1;
		while (arr[i])
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

int	main(int ac, char **av)
{
	t_data data;
	int	i;
	int	j;

    if (ac > 1)
    {
		i = 1;
		//Check if all the args are integers
		while (av[i])
		{
			integer_check(av[i]);
			i++;
		}
		i = 1;
		j = 0;
		data.size = ac - 1;
		data.arr = malloc((ac - 1) * sizeof(int));
		data.sort_arr = malloc((ac - 1) * sizeof(int));
		//Fill the array and the sorted one
		while (i < ac)
		{
			data.arr[j] = ft_atoi(av[i]);
			data.sort_arr[j] = data.arr[j];
			i++;
			j++;
		}
		i = 0;
		quicksort(data.sort_arr, 0, data.size - 1);
		//Check for duplicated integers
		while (i < data.size - 1)
		{
			if (data.sort_arr[i] == data.sort_arr[i + 1])
				ft_exit("ERROR: I don't accept duplicated integers !");
			i++;
		}
	}
	else
		ft_exit("ERROR : You need at least 1 parameter !");
	return (0);
}

		// i = 0;
		// while (i < data.size)
		// {
		// 	ft_printf("arr[%d] = %d\n", i, data.arr[i]);
		// 	i++;
		// }
		// i = 0;
		// while (i < data.size)
		// {
		// 	ft_printf("sort_arr[%d] = %d\n", i, data.sort_arr[i]);
		// 	i++;
		// }