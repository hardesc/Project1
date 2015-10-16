//
//  algorithms.h
//  MMS
//
//  Created by Charles Hardes on 10/14/15.
//  Copyright (c) 2015 Charles Hardes. All rights reserved.
//

#ifndef __MMS__algorithms__
#define __MMS__algorithms__

#include <stdio.h>

void algorithm(int *arr, int size, int option, int version, FILE *file);


double algorithm_1(int *arr, int size, int print_option, FILE *file);

double algorithm_2(int *arr, int size, int print_option, FILE *file);

double algorithm_3(int *arr, int size, int print_option, FILE *file);

double algorithm_4(int *arr, int size, int print_option, FILE *file);

void print_results(int *arr, int size, int print_option, FILE *file, int max, int beg, int end);

#endif /* defined(__MMS__algorithms__) */
