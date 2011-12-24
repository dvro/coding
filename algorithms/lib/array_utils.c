#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <array_utils.h>

#define MAX(a,b) a>b?a:b

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
		
		if (cur_sum <= 0) {
			cur_ini = i + 1;
			cur_sum = 0;	
		}
	}

	return 1;
}

int max_notsubsequent_subarray_sum(int array[], int len, int *value)
{
	if (len <= 0)
		return 0;

	int prev = 0;
	int curr = 0;

	int i;	
	for (i = 0; i < len; i++) {
		int tmp = curr;
		curr = MAX(array[i] + prev, curr);
		prev = tmp;
	}

	*value = curr;
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

int find_max_and_min (int array[], int len, int *min, int *max)
{
	int i = 0;
	int j = len - 1;
	while (i < j) {
		if (array[i] > array[j]) {
			int tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
		i++;
		j--;
	}
	
	*min = array[0];
	for (i = 0; i <= len/2; i++) {
		if (array[i] < *min)
			*min = array[i];
	}

	*max = array[len/2];
	for (i = len/2; i < len; i++) {
		if (array[i] > *max)
			*max = array[i];
	}

	return 1;
}




