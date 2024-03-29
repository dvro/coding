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

int remove_quotes (char *str);

int remove_substring (char *str, char *substring);

int remove_chars (char *str, char *chars);

int remove_repeated_chars(char *str);
//TODO
int match_re(char *str, char *re);

int string_distance (char *str_a, char *str_b);

#endif

