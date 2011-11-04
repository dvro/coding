#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <array_utils.h>


int max_subarray_sum (int array[], int len, int *ini, int *end)
{
	
	int max_sum = -1;
	int max_ini = -1;
	int max_end = -1;
	
	int cur_sum = 0;
	int cur_ini = 0;
	int cur_end = 0;

	max_sum = array[0];

	int i;
	for (i = 0; i < len; i++) {
		cur_sum = cur_sum + array[i];
		if (cur_sum > max_sum) {
			int max_sum = cur_sum;
			int max_ini = cur_ini;
			int max_end = i;
		}
		
		if (cur_sum < 0) {
			cur_ini = i + 1;
			cur_sum = 0;	
		}
	}

	return 1;
}

int binary_search (int array[], int len, int value, int *index)
{
	int i = 0;
	int j = len - 1;

	if (j < i)
		return 0;


	while (i <= j) {
		if (array[i] > array[j])
			return -1;	//ARRAY_NOT_ORDENED

		int m = (i + j) / 2;
		if (array[m] == value) {
			*index = m;
			return 1;
		}
	
		if (array[m] < value) {
			i = m + 1;
		} else {
			j = m - 1;
		}
	}

	return 0;	
}

int quick_sort (int *array, int len)
{

}

int merge_sort (int *array, int len)
{

}


