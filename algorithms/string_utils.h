#ifndef STRING_UTILS_H
#define STRING_UTILS_H
#include <stdlib.h>
#include <stdio.h>

int str_to_int (char *str, int *value);

int int_to_str (int value, char **str);

int reverse_words (char **str);

int large_block (char *str, int *index);

#endif

