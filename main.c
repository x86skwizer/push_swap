/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamrire <yamrire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 04:58:40 by yamrire           #+#    #+#             */
/*   Updated: 2022/08/27 06:53:56 by yamrire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int ac, char **av)
{
	int	*arr;
	int	low;
	int	i;

    if (ac > 1)
    {
		arr = malloc((ac - 1) * sizeof(int));
		i = 1;
		low = 0;
		while (i < ac)
		{
			// check_av_type(ac, av);
			arr[low] = ft_atoi(av[i]);
			ft_printf("arr[%d] = %d\n", low, arr[low]);
			i++;
			low++;
		}
	}
	return (0);
}
