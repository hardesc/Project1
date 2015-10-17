/*
 ALGORITHM 1 IS COMPLETE
 GROUP 16, SCROLL TO THE BOTTOM TO SEE WHERE THE ALGORITHM DEFINITIONS ARE
 YOU DON'T NEED TO WORRY ABOUT ANY OF THE OTHER CODE, LET ME DEAL WITH IT
 JUST PUT YOUR CODE IN THE DESIGNATED FUNCTION. LET ME KNOW IF YOU NEED WITH IT.
*/

#include "algorithms.h"
#include <stdlib.h>
#include <time.h>

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
        fprintf(file, "\n\nFor n = %d integers using algorithm %d:\n\n\t\tSum\t\tTime (s)\n\n", size, version);
        repetitions = 10;
        index = 1;
        srand((unsigned int) time(NULL));
    }
    
    do{
        if (print_option == 2) {

            fprintf(file, "%d.)\t\t", index);//print numbering for rows
            
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
        fprintf(file, "\n\nAverage Time (s): %f\n", total / 10);
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
    
    
    T2 = clock();//end timer
    time = (double)(T2 - T1) / CLOCKS_PER_SEC;//get total time
    print_results(arr, size, print_option, file, max, beg, end);
    
    return time;
}

double algorithm_4(int *arr, int size, int print_option, FILE *file) {
    
    int max, beg, end;
    
    clock_t T1, T2;
    double time;
    
    T1 = clock();//start timer
    
    /***************************************************
     
     ALGORITHM 4 CODE GOES HERE
     
     *****************************************************/
    
    
    T2 = clock();//end timer
    time = (double)(T2 - T1) / CLOCKS_PER_SEC;//get total time
    print_results(arr, size, print_option, file, max, beg, end);
    
    return time;
}