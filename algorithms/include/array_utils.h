#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H
#include <stdlib.h>
#include <stdio.h>

//TODO test it
int max_subarray_sum (int array[], int len, int *ini, int *end);

/**
 * Selects elements non-sequencial that has the max sum of an
 * array;
 */
int max_notsubsequent_subarray_sum(int array[], int len, int *value);
int binary_search (int array[], int len, int value, int *index);
//TODO
int quick_sort (int *array, int len);
//TODO
int merge_sort (int *array, int len);

/**
 * Find the min and max value in O(3n/2)
 */
int find_max_and_min (int array[], int len, int *min, int *max);
int erase_all_x(int **array, int len, int x);

int rotate_array(int **array, int len, int n);

#endif

