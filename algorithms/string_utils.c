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


int reverse_letters (char *str, int i, int j)
{
	if (str == NULL)
		return 0;

	if (i > j)
		return 0;

	if (i < 0 || j > strlen(str) - 1)
		return 0;

	while (i < j) {
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}

	return 1;
}

int reverse_words (char *str)
{
	if (str == NULL)
		return 0;
	if (strlen(str) < 2)
		return 1;

	int i = 0;
	int j = 1;

	while (str[i] != '\0') {
		while (str[i] == ' ' && str[i] != '\0')
			i++;

		j = i;
		while (str[j] != ' ' && str[j] != '\0')
			j++;

		if (i != j) {
			reverse_letters(str, i, --j);
			i = ++j;
		}
	}

	reverse_letters(str, 0, strlen(str) - 1);
	return 1;
}

int large_block (char *str, int *index)
{
	if (str == NULL)
		return 0;

	int len = strlen(str);
	if (len == 0)
		return 0;
	

	int max_count_index = 0;
	int max_count = 0;
	
	int current_count = 0;
	int current_count_index = 0;

	int i = 0;

	while (i <= len) {
		if (str[i] == str[current_count_index]) {
			current_count++;
		} else {
			if (current_count > max_count) {
				max_count = current_count;
				max_count_index = current_count_index;
			}
			current_count_index = i;
			current_count = 1;
		}
		i++;
	}

	*index = max_count_index;

	return 1;
}



