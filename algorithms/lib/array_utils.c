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

	max_sum = array[0];

	int i;
	for (i = 0; i < len; i++) {
		cur_sum = cur_sum + array[i];
		if (cur_sum > max_sum) {
			max_sum = cur_sum;
			max_ini = cur_ini;
			max_end = i;
		}
		
		if (cur_sum <= 0) {
			cur_ini = i + 1;
			cur_sum = 0;	
		}
	}

	*ini = max_ini;
	*end = max_end;

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

int erase_all_x(int **array, int len, int x)
{
	if (*array == NULL)
		return 0;
	if (len <= 0)
		return 0;

	int *nums = *array;

	int count = 0;

	int i = len - 1;
	while (i >= 0) {
		if (nums[i] == x) {
			int j;
			for (j = i; j < len - 1; j++)
				nums[j] = nums[j+1];
			count++;
		}
		i = i - 1;
	}

	return len - count;
}

int rotate_array(int **array, int len, int n)
{
	if (*array == NULL)
		return 0;
	if (len <= 0)
		return 0;
	if (n < 0)
		return 0;

	int k = n % len;
	if (k == 0)
		return 1;

	int tmp[len];
	
	int i;
	for (i = 0; i < len; i++)
		tmp[(i+k)%len] = (*array)[i];

	for (i = 0; i < len; i++)
		(*array)[i] = tmp[i];

	return 1;
}


void shift(int *array, int i, int j)
{
	int t;
	for (t = j; t >= i; t--)
		array[t+1] = array[t];

}


int merge_n_into_2n(int **a, int **b, int n)
{
	int *array_a = *a;
	int *array_b = *b;

	int i = 0;
	int j = 0;
	
	while (i < n && j < 2*n) {
		if (array_a[i] >= array_b[j]) {
			j++;
		} else {
			shift(array_b, j, 2 * n - 2);
			array_b[j++] = array_a[i++];
		}
	}

	while (i < n) {
		array_b[j++] = array_a[i++];
	}

	return 1;
}




