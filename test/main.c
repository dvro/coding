#include <stdio.h>
#include <stdlib.h>
#include <array_utils.h>

int main(void)
{
	int *array_a = (int *) calloc(5, sizeof(int));
	int *array_b = (int *) calloc(10, sizeof(int));

	int a[] = {1, 3, 5, 7, 9};
	int b[] = {2, 4, 6, 8, 10};

	int i;
	for (i = 0; i < 5; i++) {
		array_a[i] = a[i];
		array_b[i] = b[i];
	}
	
	int status = merge_n_into_2n(&array_a, &array_b, 5);
	printf("status = %d\n", status);

	for (i = 0; i < 10; i++)
		printf("%d ", array_b[i]);
	printf("\n");

	return 0;
}


