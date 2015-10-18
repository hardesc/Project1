/*
 ALGORITHM 1 IS COMPLETE
 GROUP 16, SCROLL TO THE BOTTOM TO SEE WHERE THE ALGORITHM DEFINITIONS ARE
 YOU DON'T NEED TO WORRY ABOUT ANY OF THE OTHER CODE, LET ME DEAL WITH IT
 JUST PUT YOUR CODE IN THE DESIGNATED FUNCTION. LET ME KNOW IF YOU NEED WITH IT.
*/

int *left_max_index, left_max_size, *right_max_index, right_max_size, *max_index, max_size, max_sum, *low, *high;

#include "algorithms.h"
#include <stdlib.h>
#include <time.h>
#include <limits.h>

/*
 This function handles which function is going to be called and passes the array, size, print_option, and version on to the appropriate functions. 
 If print_option is 2, this means that this input array will be randomly generated and computed by the appropriate algorithm 10 times. The total time to compute is returned on each calculation, averaged, and printed.
 */
void algorithm(int *arr, int size, int print_option, int version, FILE *file) {
    
    int repetitions, index;
    int i, temp;
    double total, t;
    
    t = 0;
    total = 0;
    repetitions = 0;
    index = 0;

    if (print_option == 2) {
        fprintf(file, "For n = %d integers using algorithm %d:\n\n\t\tSum\t\tTime (s)\n\n", size, version);
        repetitions = 10;
        index = 1;
        srand((unsigned int) time(NULL));
    }
    
    do{
        if (print_option == 2) {
            if (repetitions == 1) {
                fprintf(file, "%d.)\t", index);//print numbering for last row
            }
            else {
                fprintf(file, "%d.)\t\t", index);//print numbering for rows
            }

            arr = (int *)malloc(sizeof(int) * size);
            
            
            for (i = 0; i < size; i++) {
                temp = rand() % 200 - 100;
                arr[i] = temp;
            }

        }
        //Call the appropriate algorithm on the array
        switch (version) {
            case 1 :
                t = algorithm_1(arr, size, print_option, file);
                total += t;
                break;
            case 2 :
                t = algorithm_2(arr, size, print_option, file);
                total += t;
                break;
            case 3 :
                t = algorithm_3(arr, size, print_option, file);
                total += t;
                break;
            case 4 :
                t = algorithm_4(arr, size, print_option, file);
                total += t;
                break;
        }
        repetitions--;
        if (print_option == 2) {
            free(arr);
            index++;
            fprintf(file, "%f\n", t);
        }
    }while (repetitions > 0);
    
    if (print_option == 2) {
        fprintf(file, "\nAverage Time (s): %f\n", total / 10);
    }

}

/*
 Prints the results to the file specified in MSS.c (MSS_Results.txt)
- Will print different formats depending on print_option, which is derived from whether the input array
 comes from a file or is randomly generated
    - if print_option 1: prints the entire input array, followed by the max sub-array, then the sum
    - if print_option 2: prints two columns consisting of the sum and time to compute.
*/
void print_results(int *arr, int size, int print_option, FILE *file, int max, int beg, int end) {
    
    int i;
    
    //if input from file
    if (print_option == 1) {
        
        //print original array
        fprintf(file, "[");
        for (i = 0; i < size - 1; i++) {
            fprintf(file, "%d, ", arr[i]);
        }
        fprintf(file, "%d]\n", arr[size - 1]);//print last element with closing bracket
        
        //print sub-array
        fprintf(file, "[");
        for (i = beg; i < end; i++) {
            fprintf(file, "%d, ", arr[i]);
        }
        fprintf(file, "%d]\n", arr[end]);//print last element with closing bracket
        
        fprintf(file, "%d\n\n", max);//print sum
    }
    
    //if randomly generated arrays
    else if (print_option == 2) {
        fprintf(file, "%d\t\t", max);
    }
}

/******************************************************************************************


*****************************   CODE FOR ALL ALGORITHMS BELOW  ******************************/

                               //|||||||||||||||||||||||||||||\\
/********************************VVVVVVVVVVVVVVVVVVVVVVVVVVVVV*****************************/

double algorithm_1(int *arr, int size, int print_option, FILE *file) {
    
    int i, j, k, s, temp, max, end, beg;
    
    max = -32767;
    beg = 0;
    end = size - 1;
    clock_t T1, T2;
    double time;
    
    T1 = clock();//start timer
    
    
    //beginning point incrementer
    for (i = 0; i < size; i++) {
        //end point incrementer
        for (j = i; j < size; j++) {
            s = 0;
            //summation loop
            for (k = i; k <= j; k++) {
                temp = arr[k];//for debugging
                s += arr[k];
                if (s > max) {
                    max = s;
                    end = j;
                    beg = i;
                }
            }
        }
    }
    
    T2 = clock();//end timer
    time = (double)(T2 - T1) / CLOCKS_PER_SEC;//get total time
    print_results(arr, size, print_option, file, max, beg, end);
    
    return time;
}

double algorithm_2(int *arr, int size, int print_option, FILE *file) {
    
    int i, j, s, temp, max, beg, end;
    clock_t T1, T2;
    double time;
    
    max = -32767;
    beg = 0;
    end = size - 1;
    
    T1 = clock();//start timer
    
    //beginning point incrementer
    for (i = 0; i < size; i++) {
        s = 0;
        //end point incrementer
        for (j = i; j < size; j++) {
            temp = arr[j];//for debugging
            s += arr[j];
            if (s > max) {
                max = s;
                end = j;
                beg = i;
            }
        }
    }
    
    
    T2 = clock();//end timer
    time = (double)(T2 - T1) / CLOCKS_PER_SEC;//get total time
    print_results(arr, size, print_option, file, max, beg, end);
    
    return time;
}

double algorithm_3(int *arr, int size, int print_option, FILE *file) {
    
    int max, beg, end;
    
    clock_t T1, T2;
    double time;
    
    T1 = clock();//start timer
    
    /***************************************************
     
     ALGORITHM 3 CODE GOES HERE
     
     *****************************************************/
    max = alg3(arr, size, 0);
    
    
    
    T2 = clock();//end timer
    time = (double)(T2 - T1) / CLOCKS_PER_SEC;//get total time
    
    beg = (int)(max_index - &arr[0]);
   
    end = beg + max_size - 1;
    
    print_results(arr, size, print_option, file, max, beg, end);
    

    
    return time;
}

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
    return 0;
}//end function alg3

double algorithm_4(int *arr, int size, int print_option, FILE *file) {
    
    int max, beg, end;
    
    clock_t T1, T2;
    double time;
    
    T1 = clock();//start timer
    
    /***************************************************
     
     ALGORITHM 4 CODE GOES HERE
     
     *****************************************************/
    
    max = alg4(arr, &size);
    
    T2 = clock();//end timer
    time = (double)(T2 - T1) / CLOCKS_PER_SEC;//get total time
    
    beg = *low;
    end = *high;
    
    print_results(arr, size, print_option, file, max, beg, end);
    
    return time;
}

int alg4(int * array, int * array_size)
{
    int max_sum, ending_here_sum, j, *ending_here_low, *ending_here_high;
    
    ending_here_low = &array[0];
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

