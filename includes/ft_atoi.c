/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamrire <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:53:01 by yamrire           #+#    #+#             */
/*   Updated: 2022/08/24 02:20:04 by yamrire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	initiate_atoi(char **src, int *sign)
{
	while (ft_strchr(" \n\f\r\t\v", **src))
		(*src)++;
	*sign = 1;
	if (**src == '-')
	{
		*sign = -1;
		(*src)++;
	}
	else if (**src == '+')
		(*src)++;
}

int	ft_atoi(const char *str)
{
	char	*src;
	long	num;
	int		sign;

	if (!ft_strlen(str))
		return (0);
	src = (char *) str;
	num = 0;
	initiate_atoi (&src, &sign);
	while (*src >= '0' && *src <= '9')
	{
		if (num * 10 + (*src - 48) >= num)
			num = num * 10 + (*src - 48);
		else
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		src++;
	}
	return (num * sign);
}
