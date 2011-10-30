#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string_utils.h>

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
		s[index++] = (((value % (m * 10)) / m) + '0');
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

int char_most_repeated (char *str, char *output, int *index, int *count)
{
	if (str == NULL || strlen(str) == 0)
		return 0;

	int *hashtable = calloc(256, sizeof(int));
	if (!hashtable)
		return 0;

	int i = 0;
	int max_count = 0;
	char most_repeated = '\0';

	while (str[i] != '\0') {
		hashtable[str[i]] = hashtable[str[i]] + 1;
		if (hashtable[str[i]] > max_count) {
			max_count = hashtable[str[i]];
			most_repeated = str[i];
		}
		i++;
	}

	i = 0;
	while (str[i] != most_repeated)
		i++;

	*index = i;
	*output = most_repeated;
	*count = max_count;
	
	free(hashtable);
	return 1;
}

int first_char_m_times_occurred (char *str, int m, char *output, int *index)
{
	if (!str || strlen(str) == 0)
		return 0;

	if (m <= 0)
		return 0;

	int *hashtable = calloc(256, sizeof(int));
	if (!hashtable)
		return 0;

	int i = 0;
	while (str[i] != '\0') {
		hashtable[str[i]] = hashtable[str[i]] + 1;
		i++;
	}

	i = 0;
	while (str[i] != '\0' && hashtable[str[i]] != m)
		i++;

	if (str[i] != '\0') {
		if (index != NULL)	*index = i;
		if (output != NULL)	*output = str[i];
	}

	free(hashtable);
	return 1;
}

void move (char *str, int i, int j) {
	int len = strlen(str);
	if (j > len)
		return;
	if (i == j)
		return;

	while (j <= len) {
		str[i] = str[j];
		i++;
		j++;
	}
}

int remove_quotes (char *str)
{
	char quote = '\"';
	int flag = 0;
	
	if (str == NULL || strlen(str) == 0)
		return 0;

	int start = 0;

	while (str[start] != '\0') {
		int i = start;
		while (str[i] != '\0' && str[i] != quote)
			i++;

		if (str[i] == '\0')
			return flag;

		int j = i + 1;
		while (str[j] != '\0' && str[j] != quote)
			j++;
		
		if (str[j] == '\0')
			return flag;

		move (str, i, j+1);
		start = i;
		flag = 1;
	}
	
	return flag;
}

int remove_substring (char *str, char *substring)
{
	if (!str || !substring)
		return 0;

	int str_len = strlen(str);
	int sub_len = strlen(substring);

	if (str_len == 0 || sub_len == 0 || str_len < sub_len)
		return 0;
	
	int i = 0;
	int flag = 0;
	while (i <= (str_len - sub_len)) {
		if (strncmp(str+i, substring, sub_len) == 0) {
			move(str, i, i+sub_len);
			str_len = str_len - sub_len;
			if(flag == 0)
				flag = 1;
		}
		i++;
	}

	return flag;
}

int remove_chars (char *str, char *chars)
{
	if (!str)
		return 0;
	if (!chars)
		return 0;

	int *hashtable = calloc(256, sizeof(int));
	if (!hashtable)
		return 0;

	int i;
	for (i = 0; i < strlen(chars); i++) {
		hashtable[chars[i]] = 1;
	}

	i = 0;
	int len = strlen(str);
	while (i < len) {
		if (hashtable[str[i]] == 1) {
			move(str, i, i+1);
		} else {
			i++;
		}
	}

	free(hashtable);
	return 1;
}

int string_distance (char *str_a, char *str_b)
{
	int len_a = strlen(str_a);
	int len_b = strlen(str_b);

	int matrix[len_a + 1][len_b + 1];

	int i, j;

	for (i = 0; i < len_a; i++)
		matrix[i][0] = i;
	
	for (i = 0; i < len_b; i++)
		matrix[0][i] = i;


	for (i = 1; i <= len_a; i++) {
		for (j = 1; j <= len_b; j++) {
			if (str_a[i-1] == str_b[j-1]) {
				matrix[i][j] = matrix[i-1][j-1];
			} else {
				int cost = matrix[i-1][j-1];

				if (cost > matrix[i-1][j])
					cost = matrix[i-1][j];
				if (cost > matrix[i][j-1])
					cost = matrix[i][j-1];

				matrix[i][j] = cost + 1;
			}
		}
	}

	return matrix[len_a][len_b];
}


