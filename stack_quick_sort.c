#include "push_swap.h"
#include <stdio.h>
void sort_stack_a(t_data data, int *top, int end)
{
    int put_elem;
    int pivot;
    int rot_succ;
    int pu_succ;
    
    if (!(is_sorted(data.arr, (*top) + 1)))
    {
        if ((*top) == end + 1)
        {
            if (!(is_sorted(data.arr, (*top) + 1)))
                sa(data, top);
            return;
        }
        rot_succ = 0; 
        put_elem = ((*top) - end + 1) / 2;
        // mak(" put : %d\n",put_elem);
        pu_succ = 0;
        // for(int i = 0; i < 4 ;i++)
        //     printf(" %d ",data.sort_arr[i]);
        // printf("\nsort\n");
        // for(int i = 0; i < 4 ;i++)
        //     printf(" %d ",data.arr[i]);
        // printf("\nsort\n");

        pivot = data.sort_arr[((*top - end) / 2) + end];
        // printf("re %d\n",((*top - end) / 2) + end);
        // printf("e :  %d\n",end);
        // printf("t :  %d\n",*top);
        // printf("p :  %d\n",pivot);
        while (put_elem)
        {

            if (data.arr[(*top)] < pivot)
            {
				pb(top);
				put_elem--;
                pu_succ++;
            }
            else
            {
            	ra(data, top);
            	rot_succ++;
			}
		}
        while (rot_succ)
		{
			rra(data, top);
			rot_succ--;
		}
		sort_stack_a(data, top, 0);
		sort_stack_b(data, top, (*top + 1) + (pu_succ - 1) );
    }
	
}

void sort_stack_b(t_data data, int *top, int end)
{

    int put_elem;
    int pivot;
    int rot_succ;
    int pu_succ;
    
    if (!(is_sorted(data.arr + (*top + 1), end - *top)))
    {
        if (end == *top + 2)
        {
            sb(data, top);
            pa(data, top);
            pa(data, top);
            return;
        }
        else if (end == *top + 1)
        {
            pa(data, top);
            return;
        }
        rot_succ = 0; 
        put_elem = (end - (*top)) / 2;
        pu_succ = 0;
        pivot = data.sort_arr[((end - (*top + 1)) /2 ) + *top + 2];
        while (put_elem)
        {
            if (data.arr[(*top + 1)] > pivot)
            {
				pa(data, top);
				put_elem--;
                pu_succ++;
            }
            else
            {
            	rb(data, top);
            	rot_succ++;
			}
		  }
        while (rot_succ)
		{
			rrb(data, top);
			rot_succ--;
		}
		sort_stack_a(data, top, *top - (pu_succ - 1) );
		sort_stack_b(data, top, end );
    }
    else
    {
		pu_succ = end - *top;
    	while (pu_succ)
    	{
    	    pa(data, top);
			pu_succ--;
    	}
	}
}