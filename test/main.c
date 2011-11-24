#include <stdio.h>
#include <stdlib.h>
#include <array_utils.h>

int main(void)
{
	int value = 4;
	int array[11] = {0,1,2,3,4,5,6,7,8,9,10};
	int index = -1;
	int status = binary_search(array, 11, value, &index);

//	printf("status = %d\n", status);
//	printf("index = %d\n", index);

	return 0;
}


