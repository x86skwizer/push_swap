/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamrire <yamrire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 04:58:40 by yamrire           #+#    #+#             */
/*   Updated: 2022/09/13 08:01:52 by yamrire          ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_data data;
	int	low;
	int	i;
	int	j;
	int	sign;

    if (ac > 1)
    {
		i = 1;
		sign = 0;
		while (av[i])
		{
			j = 0;
			if (!av[i][j])
				ft_exit("ERROR : I only accept integers !");
			while (av[i][j]) 
			{ 
				if (ft_strchr("+-0123456789", av[i][j]))
				{
					if (av[i][j] == '+' || av[i][j] == '-')
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
			i++;
		}
		data.arr = malloc((ac - 1) * sizeof(int));
		i = 1;
		low = 0;
		while (i < ac)
		{
			data.arr[low] = ft_atoi(av[i]);
			i++;
			low++;
		}
		data.size = ac;
		quicksort(data.arr, 0, data.size - 1);	
	}
	return (0);
}
