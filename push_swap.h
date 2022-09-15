/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamrire <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 05:05:31 by yamrire           #+#    #+#             */
/*   Updated: 2022/09/15 03:27:31 by yamrire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./includes/libftprintf.h"
# include <stdlib.h>

typedef struct s_data
{
	int	*arr;
	int	*sort_arr;
	int	size;
	int	iatop;
}	t_data;

int		len_arr(int *arr, int start, int end);
void	sa(t_data data, int *top);
void	sb(t_data data, int *top);
void	ss(t_data data, int *top);
void	pa(t_data data, int *top);
void	pb(int *top);
void	ra(t_data data, int *top);
void	rb(t_data data, int *top);
void	rra(t_data data, int *top);
void	rrb(t_data data, int *top);
void	rrr(t_data data, int *top);

#endif