#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "string_utils.h"

int str_to_int (char *str, int *value)
{
	if (!str)
		return 0;

	if (strlen(str) == 0)
		return 0;

	int negative = (str[0] == '-');
	if (negative) {
		str++;
		if (*str == '\0')
			return 0;
	}
	
	int num = 0;
	while (*str != '\0') {
		if (*str < '0' || *str > '9')
			return 0;

		num = (*str - '0') + (10 * num);
		str++;
	}
	
	if (negative)
		num = -1 * num;

	*value = num;
	return 1;
}

int int_to_str (int value, char **str)
{
	char s[100];
	int index = 0;

	if (value < 0) {
		s[index] = '-';
		value = value * (-1);
		index++;
	}

	int m = 1;
	while ((value / m) > 0)
		m = m * 10;

	if (m != 1)
		m = m / 10;

	while (m > 0) {
		s[index] = (((value % (m * 10)) / m) + '0');
		index++;
		m = m/10;
	}
	s[index] = '\0';	
	strcpy(*str, s);
	
	return 1;
}

int reverse_words (char **str)
{

}

int large_block (char *str, int *index)
{

}



