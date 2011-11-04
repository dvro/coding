#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H
#include <stdlib.h>
#include <stdio.h>

int max_subarray_sum (int array[], int len, int *ini, int *end);
int binary_search (int array[], int len, int value, int *index);
int quick_sort (int *array, int len);
int merge_sort (int *array, int len);

#endif

