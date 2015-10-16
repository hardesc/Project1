#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include "algorithms.h"

int main(int argv, char **argc) {
    
    char line[200], *token;
    int numberArray[10][100], *newArr, temp, version, size, i, j,k, n, m;
    const char s[3] = ", ";
    FILE *ifp, *ofp;
    
    if (argv != 3) {
        printf("ERROR: wrong number of arguments\n");
        exit(1);
    }//improper parameters entered on command line
    version = atoi(argc[2]);//                               FOR COMMAND LINE
    //version = 1;//                                             FOR XCODE

    ofp = fopen("MSS_Results.txt", "w");//                   FOR COMMAND LINE
    //ofp = fopen("/Users/charleshardes/Documents/XCode Workspace/MMS/MMS/MSS_Results.txt", "w");//FOR XCODE
    
    if (ofp == NULL) {
        fprintf(stderr, "Can't open output file!\n");
        exit(1);
    }
    
    size = 0;
    //get value of first argument, if it's an int, then no file input, random generate
    size = atoi(argc[1]);//                                   FOR COMMAND LINE
    //size = 20;//                                                 FOR XCODE
    if (size != 0) {
        algorithm(newArr, size, 2, version, ofp);
        return 0;
    }
    
    ifp = fopen(argc[1], "r");//                             FOR COMMAND LINE
    //ifp = fopen("/Users/charleshardes/Documents/XCode Workspace/MMS/MMS/MSS_Problems.txt", "r");//FOR XCODE
    if (ifp == NULL) {
        fprintf(stderr, "Can't open input file!\n");
        exit(1);
    }
    
    j = 0;
    while (1) {
        i = 0;
        if (fgets(line, 200, ifp) == NULL){break;}
        //printf("%s", line);
       // numberArray[j] = (int *)malloc(strlen(line) * sizeof(int));
        memmove(line, line + 1, strlen(line));//strip leading '['
        line[strlen(line) - 2] = ' ';//strip trailing ']'
        token = strtok(line, s);//break up string into tokens
        while (token != NULL) {
            printf("%s ", token);
            numberArray[j][i] = atoi(token);//convert token to int
            token = strtok(NULL, s);
            i++;
        }
        numberArray[j][i - 1] = 1111111111;//marks end of input
        j++;
        printf("\nj=%d\n", j);
    }
    n = j;
    
    //loop through arrays to print outputs
    printf("\nPrinting Arrays:\n");
    for (j = 0; j < n; j++){
        k = 0;
        printf("Array %d:\n", j);
        
        //loop through array elements
        while (numberArray[j][k] != 1111111111) {
            printf("%d ", numberArray[j][k]);//TESTING
            k++;
        }

        newArr = (int *) malloc(sizeof(int) * (k));
        
        //copy to new array to be passed to computing function
        for (m = 0; m < k; m++) {
            temp = numberArray[j][m];//for debugging
            newArr[m] = numberArray[j][m];
        }
        
        algorithm(newArr, k, 1, version, ofp);
        
        free(newArr);
        printf("\n\n");
    }
    
    fclose(ifp);
    fclose(ofp);
    
    return 0;
}
