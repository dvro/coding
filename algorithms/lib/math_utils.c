#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <array_utils.h>

#define MAX(a,b) a>b?a:b
#define ABS(x) x<0?-x:x

int square(float value, float precision)
{
	int x = 1.0;
	while (ABS(x**2 - value) >= precision) {
		x = x - (x**2 - value)/(2*x);
	}
	return x;
}



