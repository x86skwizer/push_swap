/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_quick_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamrire <yamrire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 05:09:14 by yamrire           #+#    #+#             */
/*   Updated: 2022/09/21 07:23:54 by yamrire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	scan_stack_a(t_data data, t_elements *elem, int *top, int end)
{
	elem->rot_succ = 0;
	elem->put_elem = ((*top) - end + 1) / 2;
	elem->pu_succ = 0;
	elem->pivot = data.sort_arr[((*top - end) / 2) + end];
	while (elem->put_elem)
	{
		if (data.arr[(*top)] < elem->pivot)
		{
			pb(top);
			elem->put_elem--;
			elem->pu_succ++;
		}
		else
		{
			ra(data, top);
			elem->rot_succ++;
		}
	}
}

void	sort_stack_a(t_data data, int *top, int end)
{
	t_elements	elem;

	if (!(is_sorted(data.arr, (*top) + 1)))
	{
		if ((*top) == end)
			return ;
		if ((*top) == end + 1)
		{
			sa(data, top);
			return ;
		}
		scan_stack_a(data, &elem, top, end);
		while (end && elem.rot_succ)
		{
			rra(data, top);
			elem.rot_succ--;
		}
		sort_stack_a(data, top, end);
		sort_stack_b(data, top, (*top + 1) + (elem.pu_succ - 1));
	}
}

void	scan_stack_b(t_data data, t_elements *elem, int *top, int end)
{
	elem->rot_succ = 0;
	elem->put_elem = ((end - (*top + 1)) / 2) + 1;
	elem->pu_succ = 0;
	elem->pivot = data.sort_arr[((end - (*top + 1)) / 2) + (*top + 2)];
	while (elem->put_elem)
	{
		if (data.arr[(*top + 1)] > elem->pivot)
		{
			pa(data, top);
			elem->put_elem--;
			elem->pu_succ++;
		}
		else
		{
			rb(data, top);
			elem->rot_succ++;
		}
	}
	while ((end < data.size - 1) && elem->rot_succ)
	{
		rrb(data, top);
		elem->rot_succ--;
	}
}

void	push_to_a(t_data *data, int *end, int **top, t_elements	*elem)
{
	if (*end == **top + 2)
	{
		sb(*data, *top);
		pa(*data, *top);
		pa(*data, *top);
		return ;
	}
	else if (*end == **top + 1)
	{
		pa(*data, *top);
		return ;
	}
	scan_stack_b(*data, elem, *top, *end);
	sort_stack_a(*data, *top, **top - (elem->pu_succ - 1));
	sort_stack_b(*data, *top, *end);
}

void	sort_stack_b(t_data data, int *top, int end)
{
	t_elements	elem;

	if (!(is_sorted(data.arr + (*top + 1), end - *top)))
		push_to_a (&data, &end, &top, &elem);
	else
	{
		elem.pu_succ = end - *top;
		while (elem.pu_succ)
		{
			pa(data, top);
			elem.pu_succ--;
		}
	}
}
