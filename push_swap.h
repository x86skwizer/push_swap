/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamrire <yamrire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 05:05:31 by yamrire           #+#    #+#             */
/*   Updated: 2022/09/21 11:25:41 by yamrire          ###   ########.fr       */
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

typedef struct s_elemts
{
	int	put_elem;
	int	pivot;
	int	rot_succ;
	int	pu_succ;
}	t_elements;

int		partition(int *arr, int start, int end);
void	quicksort(int *arr, int start, int end);
void	integer_check(char *arr);
void	sa(t_data data, int *top);
void	sb(t_data data, int *top);
void	ss(t_data data, int *top);
void	pa(t_data data, int *top);
void	pb(int *top);
void	ra(t_data data, int *top);
void	rb(t_data data, int *top);
void	rra(t_data data, int *top);
void	rrb(t_data data, int *top);
void	sort_three_elements(t_data data, int *top);
void	swap_stack_a(t_data data);
void	ft_swap(int	*arr, int i, int j);
int		is_sorted(int *arr, int size);
void	ft_exit(void);
void	sort_stack_a(t_data data, int *top, int end);
void	sort_stack_b(t_data data, int *top, int end);
void	three_five(t_data data, int tmp);
void	sort_five_elements(t_data data);
void	sort_array(t_data data);
void	sort_kick_duplicate(t_data data);

#endif