#include "push_swap.h"

void sort_stack_a(t_data data, int *top, int end)
{
    int put_elem;
    int pivot;
    int rot_succ;
    
    if (!(is_sorted(data.arr, (*top) + 1)))
    {
        if ((*top) == end + 1)
        {
            if (!(is_sorted(data.arr, (*top) + 1)))
                sa(data, top);
            return;
        }
        rot_succ = 0; 
        put_elem = ((*top) + 1) / 2;
        pivot = data.sort_arr[(*top) / 2];
        while (put_elem)
        {
            if (data.arr[(*top)] < pivot)
            {
				pb(top);
				put_elem--;
            }
            else
            {
            	ra(data, top);
            	rot_succ++;
			}
		  }
        while (((*top) > 1) && rot_succ)
		{
			rra(data, top);
			rot_succ--;
		}
		sort_stack_a(data, top, end);
		sort_stack_b(data, top, data.size - 1);
    }
}

void sort_stack_b(t_data data, int *top, int end)
{

}