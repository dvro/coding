#include <stdio.h>
#include <stdlib.h>
#include <array_utils.h>

int main(void)
{
	int *array = (int *)calloc(9, sizeof(int));


	int count = 0;
	while (count < 20) {
		int i;
		for (i = 0; i < 9; i++)
			array[i] = i;

		int status = rotate_array(&array, 9, count);

//		for (i = 0; i < 9; i++)
//			printf("%d ", array[i]);
//		printf("\n");

		count++;
	}

	free(array);

	return 0;
}


