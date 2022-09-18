/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamrire <yamrire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 05:05:31 by yamrire           #+#    #+#             */
/*   Updated: 2022/09/18 01:35:28 by yamrire          ###   ########.fr       */
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
void    sort_three_elements(t_data data);
void	swap_stack_a(t_data data);
void	ft_swap(int	*arr, int i, int j);
int		is_sorted(int *arr, int size);
void	ft_exit(char *str);
void	sort_stack_a(t_data data, int *top, int end);
void	sort_stack_b(t_data data, int *top, int end);

#endif