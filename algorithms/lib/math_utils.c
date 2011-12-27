#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <array_utils.h>

#define MAX(a,b) a>b?a:b
#define ABS(x) x<0?-x:x

float square(float value, float precision)
{
	float x = 1.0;
	while (ABS(x*x - value) >= precision) {
		x = x - (x*x - value)/(2*x);
	}
	return x;
}



