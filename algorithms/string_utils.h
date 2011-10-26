#ifndef STRING_UTILS_H
#define STRING_UTILS_H
#include <stdlib.h>
#include <stdio.h>

int str_to_int (char *str, int *value);

int int_to_str (int value, char **str);

int reverse_words (char *str);

int large_block (char *str, int *index);

int char_most_repeated (char *str, char *output, int *index, int *count);

int first_char_m_times_occurred (char *str, int m, char *output, int *index);

#endif

