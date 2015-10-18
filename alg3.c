//Algorithm 3
//CS325 Project 1

int *left_max_index, left_max_size, *right_max_index, right_max_size, *max_index, max_size, max_sum;

#include <stdio.h>
#include <stdlib.h>

int alg3(int * array, int array_size, int left_or_right)
{
   int i, x, prefix_sum, max_prefix_sum, prefix_index, prefix_size, suffix_sum, max_suffix_sum, suffix_index, suffix_size, cross_index, cross_size, cross_sum, left_sum, right_sum, *left_index, *right_index;

if(array_size==1 && left_or_right==1)
    return array[0];
else if(array_size==1 && left_or_right==2)
    return array[0];
else
{
    prefix_index=array_size/2;
    prefix_size=1;
    prefix_sum=0;
    max_prefix_sum=array[prefix_index];
    x=0;
    for(i=prefix_index;i<array_size;i++)
    {
        prefix_sum = prefix_sum + array[i];
        x++;
        if(prefix_sum > max_prefix_sum)
        {
            prefix_size=x;
            max_prefix_sum=prefix_sum;
        }
    }

    suffix_index = (array_size/2)-1;
    suffix_size = 1;
    suffix_sum = 0;
    max_suffix_sum = array[suffix_index];
    x=0;
    for(i=suffix_index;i>=0;i--)
    {
        suffix_sum = suffix_sum + array[i];
        x++;
        if(suffix_sum > max_suffix_sum)
        {
            suffix_index=i;
            suffix_size=x;
            max_suffix_sum=suffix_sum;
        }
    }
    cross_index = suffix_index;
    cross_size = suffix_size+prefix_size;
    cross_sum = max_suffix_sum+max_prefix_sum;

    left_index = array;
    right_index = &array[array_size/2];
    left_sum = alg3(left_index, array_size/2, 1);
    right_sum = alg3(right_index, array_size/2, 2);

    if(left_or_right == 1 && left_sum >= right_sum && left_sum >= cross_sum)
    {
        if(left_sum > max_sum)
        {
            max_index = left_max_index;
            max_sum = left_sum;
            max_size = left_max_size;
        }
        return left_sum;
    }
    else if(left_or_right == 1 && right_sum >= left_sum && right_sum >= cross_sum)
    {
        if(right_sum > max_sum)
        {
            max_index = right_max_index;
            max_sum = right_sum;
            max_size = right_max_size;
        }
        left_max_index = right_max_index;
        left_max_size = right_max_size;
        return right_sum;
    }
    else if(left_or_right == 1 && cross_sum >= left_sum && cross_sum >= right_sum)
    {
        if(cross_sum > max_sum)
        {
            max_index = &array[cross_index];
            max_sum = cross_sum;
            max_size = cross_size;
        }
        left_max_index = &array[cross_index];
        left_max_size = cross_size;
        return cross_sum;
    }
    else if(left_or_right == 2 && left_sum >= right_sum && left_sum >= cross_sum)
    {
        if(left_sum > max_sum)
        {
            max_index = left_max_index;
            max_sum = left_sum;
            max_size = left_max_size;
        }
        right_max_index = left_max_index;
        right_max_size = left_max_size;
        return left_sum;
    }
    else if(left_or_right == 2 && right_sum >= left_sum && right_sum >= cross_sum)
    {
        if(right_sum > max_sum)
        {
            max_index = right_max_index;
            max_sum = right_sum;
            max_size = right_max_size;
        }
        return right_sum;
    }
    else if(left_or_right == 2 && cross_sum >= left_sum && cross_sum >= right_sum)
    {
        if(cross_sum > max_sum)
        {
            max_index = &array[cross_index];
            max_sum = cross_sum;
            max_size = cross_size;
        }
        right_max_index = &array[cross_index];
        right_max_size = cross_size;
        return cross_sum;
    }
    else if(left_or_right == 0 && left_sum >= right_sum && left_sum >= cross_sum)
    {
        if(left_sum > max_sum)
        {
            max_index = left_max_index;
            max_sum = left_sum;
            max_size = left_max_size;
        }
        return left_sum;
    }
    else if(left_or_right == 0 && right_sum >= left_sum && right_sum >= cross_sum)
    {
        if(right_sum > max_sum)
        {
            max_index = right_max_index;
            max_sum = right_sum;
            max_size = right_max_size;
        }
        return right_sum;
    }
    else if(left_or_right == 0 && cross_sum >= left_sum && cross_sum >= right_sum)
    {
        if(cross_sum > max_sum)
        {
            max_index = &array[cross_index];
            max_sum = cross_sum;
            max_size = cross_size;
        }
        return cross_sum;
    }


}//end else

}//end function alg3

int main ()
{
    int array[12] = {10, -11, -1, -9, 33, -45, 23, 24, -1, -7, -8, 19}, array_size=12;
    int i, sum, left_or_right=0;
    left_max_index = &array[0];
    right_max_index = &array[1];
    left_max_size = 1;
    right_max_size = 1;
    max_index = &array[0];
    max_sum = 0;
    sum = alg3(array, array_size, left_or_right);
    printf("sum of the max array: %d\n", sum);
    for (i=0;i<max_size;i++)
    {
        printf("%d", max_index[i]);
        if(i==max_size-1)
            printf("\n");
        else
            printf(": ");
    }

    return 0;
}
