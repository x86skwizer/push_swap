/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamrire <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 04:58:40 by yamrire           #+#    #+#             */
/*   Updated: 2022/08/24 04:19:07 by yamrire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int	*arr;
	int high;
	int	low;
	int	mid;
	int	guess;
	int	item;
	int	i;

    if (ac > 1)
    {
		arr = malloc(ac * sizeof(int));
		i = 1;
		low = 0;
		while (i < ac)
		{
			arr[low] = ft_atoi(av[i]);
			ft_printf("arr[%d] = %d\n", low, arr[low]);
			i++;
			low++;
		}
		item = 740;
		low = 0;
		high = ac - 1;
		while (low <= high)
		{
			mid = (low + high) / 2;
			guess = arr[mid];
			ft_printf("guess = %d\n", guess);
			if (guess == item)
			{
				ft_printf("Found it !\n");
				return (0);
			}
			else if (guess < item)
				low = mid + 1;
			else
				high = mid - 1;
		}
			ft_printf("Playing with me ? :(\n");
	}
	return (0);
}
