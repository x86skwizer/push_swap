/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamrire <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 04:58:40 by yamrire           #+#    #+#             */
/*   Updated: 2022/11/20 21:06:25 by yamrire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_kick_duplicate(t_data data)
{
	int	i;

	i = 0;
	quicksort(data.sort_arr, 0, data.size - 1);
	while (i < data.size - 1)
	{
		if (data.sort_arr[i] == data.sort_arr[i + 1])
			ft_exit();
		i++;
	}
}

void	fill_array(t_data data, int ac, char **av)
{
	int	i;
	int	j;

	j = 0;
	i = ac - 1;
	while (i > 0)
	{
		data.arr[j] = ft_atoi(av[i]);
		data.sort_arr[j] = data.arr[j];
		i--;
		j++;
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	if (ac > 2)
	{
		i = 1;
		while (av[i])
		{
			integer_check(av[i]);
			i++;
		}
		data.size = ac - 1;
		data.iatop = data.size - 1;
		data.arr = malloc((ac - 1) * sizeof(int));
		data.sort_arr = malloc((ac - 1) * sizeof(int));
		fill_array(data, ac, av);
		sort_array(data);
		free(data.arr);
		free(data.sort_arr);
	}
	return (0);
}
