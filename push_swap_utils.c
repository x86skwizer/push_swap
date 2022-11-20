/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamrire <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 05:25:47 by yamrire           #+#    #+#             */
/*   Updated: 2022/11/20 20:44:23 by yamrire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(void)
{
	write(2, "Error\n", 6);
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
	if (j > 11)
		ft_exit();
	if (arr == '+' || arr == '-')
	{
		if (*sign != 0)
			ft_exit();
		else
			*sign += 1;
	}
}

void	integer_check(char *arr)
{
	int	j;
	int	sign;

	j = 0;
	sign = 0;
	if (arr[j] && (arr[j] == '-' || arr[j] == '+') && !arr[j + 1])
		ft_exit();
	if (!arr[j])
		ft_exit();
	while (arr[j])
	{
		if (ft_strchr("+-0123456789", arr[j]))
		{
			scan_integer(arr[j], &sign, j);
			j++;
		}
		else
			ft_exit();
	}
}
