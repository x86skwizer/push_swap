/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamrire <yamrire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 04:58:40 by yamrire           #+#    #+#             */
/*   Updated: 2022/09/08 20:17:41 by yamrire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(char *str)
{
	ft_printf("%s\n", str);
	exit(-1);
}

int	main(int ac, char **av)
{
	int	*arr;
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
