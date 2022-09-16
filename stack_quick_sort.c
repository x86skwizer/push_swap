#include "push_swap.h"

void sort_stack_a(t_data data, int *top, int end)
{
    int put_elem;
    int pivot;
    int push_succ;
    
    if (!(is_sorted(data.arr, (*top) + 1)))
    {
        if ((*top) == end + 1)
        {
            if (!(is_sorted(data.arr, (*top) + 1)))
                sa(data, top);
            return;
        }
        push_succ = 0;
        put_elem = ((*top) + 1) / 2;
        pivot = data.sort_arr[(*top) / 2];
        while (put_elem)
        {
            if (data.arr[(*top)] < pivot)
            {
                pb(top);
                put_elem--;
                push_succ++;
            }
            else
                ra(data, top);
        }
        //rra
    }
    sort_stack_a(data, top, end);
    sort_stack_b(data, top, );
}

void sort_stack_b(t_data data, int *top, int end)
{
   while ((*top) + 1 < data.size - 2)
   {

   }
}