/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamrire <yamrire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 05:25:47 by yamrire           #+#    #+#             */
/*   Updated: 2022/09/21 05:01:15 by yamrire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(char *str)
{
	ft_printf("%s\n", str);
	exit(-1);
}

void	ft_swap(int	*arr, int i, int j)
{
	int	tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void	scan_integer(char arr, int *sign, int j)
{
	if (j > 10)
		ft_exit("ERROR : I only accept integers !");
	if (arr == '+' || arr == '-')
	{
		if (sign != 0)
			ft_exit("ERROR : I only accept integers !");
		else
			sign += 1;
	}
}

void	integer_check(char *arr)
{
	int	j;
	int	sign;

	j = 0;
	sign = 0;
	if (arr[j] && (arr[j] == '-' || arr[j] == '+') && !arr[j + 1])
		ft_exit("ERROR : I only accept integers !");
	if (!arr[j])
		ft_exit("ERROR : I only accept integers !");
	while (arr[j])
	{
		if (ft_strchr("+-0123456789", arr[j]))
		{
			scan_integer(arr[j], &sign, j);
			j++;
		}
		else
			ft_exit("ERROR : I only accept integers !");
	}
}
