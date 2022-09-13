/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamrire <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 04:58:40 by yamrire           #+#    #+#             */
/*   Updated: 2022/09/13 07:21:42 by yamrire          ###   ########.fr       */
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

// int	*quicksort(char *arr, int start, int end)
// {
// 	if (start < end)
// 	{
// 		if (!(is_sorted(arr)))
// 		{
			
// 		}
// 	}
// }

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
		data.sort_arr = quicksort(data.arr, 0, data.size - 1);
	}
	return (0);
}
