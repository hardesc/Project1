// Daniel McMillan
// Project1 CS325

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int *low, *high;

int alg4(int * array, int * array_size)
{
    int max_sum, ending_here_sum, j, *ending_here_low, *ending_here_high;

    max_sum = INT_MIN;
    ending_here_sum = INT_MIN;
    for(j=0;j<*array_size;j++)
    {
        ending_here_high = &array[j];
        if(ending_here_sum > 0)
            ending_here_sum = ending_here_sum + array[j];
        else
        {
            ending_here_low = &array[j];
            ending_here_sum = array[j];
        }
        if(ending_here_sum > max_sum)
        {
            max_sum = ending_here_sum;
            low = ending_here_low;
            high = ending_here_high;
        }
    }
    return max_sum;
} //end alg4()


int main()
{
    int array[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4}, array_size=9, sum, i;
    int *array_size_pointer=&array_size;
    sum = alg4(array, array_size_pointer);
    printf("sum: %d\n",sum);
    array_size = (&high[0] - &low[0] + 1);
    for (i=0;i<array_size;i++)
    {
        printf("%d", low[i]);
        if(i==array_size-1)
            printf("\n");
        else
            printf(": ");
    }
    return 0;
} //end main()
