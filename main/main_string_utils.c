#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algorithms/string_utils.h"

int main (void)
{
	int value = -1;
	int status = -1;

	printf("\nstr_to_int\n");
	status = str_to_int("", &value);
	printf("status (0,%d); value = (-1, %d)\n", status, value);
	status = str_to_int(NULL, &value);
	printf("status (0,%d); value = (-1, %d)\n", status, value);
	status = str_to_int("-2", &value);
	printf("status (1,%d); value = (-2, %d)\n", status, value);
	status = str_to_int("0", &value);
	printf("status (1,%d); value = (0, %d)\n", status, value);
	status = str_to_int("2", &value);
	printf("status (1,%d); value = (2, %d)\n", status, value);
	status = str_to_int("2", &value);
	printf("status (1,%d); value = (2, %d)\n", status, value);
	status = str_to_int("1234", &value);
	printf("status (1,%d); value = (1234, %d)\n", status, value);
	status = str_to_int("-1234", &value);
	printf("status (1,%d); value = (-1234, %d)\n", status, value);
	value = -1;
	status = str_to_int("-", &value);
	printf("status (0,%d); value = (-1, %d)\n", status, value);
	status = str_to_int("123a", &value);
	printf("status (0,%d); value = (-1, %d)\n", status, value);
	
	printf("\nint_to_str\n");
	char *str = calloc(100,sizeof(char));
	value = -1;
	status = int_to_str(value, &str);
	printf("%d = %s\n", value, str);
	value = 0;
	status = int_to_str(value, &str);
	printf("%d = %s\n", value, str);
	value = 1;
	status = int_to_str(value, &str);
	printf("%d = %s\n", value, str);
	value = -1234;
	status = int_to_str(value, &str);
	printf("%d = %s\n", value, str);
	value = 1234;
	status = int_to_str(value, &str);
	printf("%d = %s\n", value, str);
	value = 32;
	status = int_to_str(value, &str);
	printf("%d = %s\n", value, str);
	status = int_to_str(value, &str);
	printf("%d = %s\n", value, str);
	free(str);

	printf("\nreverse_words\n");
	str = strdup("the sky is blue");
	reverse_words(str);
	printf("'the sky is blue' $ '%s'\n", str);
	free(str);
	str = strdup(" the sky is blue");
	reverse_words(str);
	printf("' the sky is blue' $ '%s'\n", str);
	free(str);
	str = strdup("the sky is blue ");
	reverse_words(str);
	printf("'the sky is blue ' $ '%s'\n", str);
	free(str);
	str = strdup("no_meio_do_caminho    havia_uma_pedra");
	reverse_words(str);
	printf("'no_meio_do_caminho    havia_uma_pedra' $ '%s'\n", str);
	free(str);
	str = strdup("1234");
	reverse_words(str);
	printf("'1234' $ '%s'\n", str);
	free(str);

	printf("\nlarge_block\n");
	int index = -1;
	status = large_block("", &index);
	printf("(0,%d) index = (-1,%d)\n", status, index);
	char *tmp = NULL;
	status = large_block(tmp, &index);
	printf("(0,%d) index = (-1,%d)\n", status, index);
	status = large_block("abcd", &index);
	printf("(1,%d) index = (0,%d)\n", status, index);
	status = large_block("aaabbcc", &index);
	printf("(1,%d) index = (0,%d)\n", status, index);
	status = large_block("aabbbcc", &index);
	printf("(1,%d) index = (2,%d)\n", status, index);
	status = large_block("aabbccc", &index);
	printf("(1,%d) index = (4,%d)\n", status, index);
	status = large_block("abababababcccabababababa", &index);
	printf("(1,%d) index = (10,%d)\n", status, index);

	printf("\nchar_most_repeated\n");
	char output = '\0';
	index = 0;
	int count = 0;
	str = "ababababaccccccababababab";
	status = char_most_repeated(str, &output, &index, &count);
	printf("(1,%d) (a,%c) (0,%d) (10,%d)\n", status, output, index, count);
	str = "ccbaaa";
	status = char_most_repeated(str, &output, &index, &count);
	printf("(1,%d) (a,%c) (3,%d) (3,%d)\n", status, output, index, count);
	str = "ccaaabb";
	status = char_most_repeated(str, &output, &index, &count);
	printf("(1,%d) (a,%c) (2,%d) (3,%d)\n", status, output, index, count);
	str = "aaabbcc";
	status = char_most_repeated(str, &output, &index, &count);
	printf("(1,%d) (a,%c) (0,%d) (3,%d)\n", status, output, index, count);
	str = "";
	status = char_most_repeated(str, &output, &index, &count);
	printf("(0,%d) (a,%c) (0,%d) (3,%d)\n", status, output, index, count);
	str = NULL;
	status = char_most_repeated(str, &output, &index, &count);
	printf("(0,%d) (a,%c) (0,%d) (3,%d)\n", status, output, index, count);
	str = "a";
	status = char_most_repeated(str, &output, &index, &count);
	printf("(1,%d) (a,%c) (0,%d) (1,%d)\n", status, output, index, count);

	printf("\nfirst_char_m_times_occurred\n");
	str = "abcdbcd";
	status = first_char_m_times_occurred(str, 1, &output, &index);
	printf("(1,%d) (a,%c) (0,%d)\n", status, output, index);
	
	str = "abcdbcd";
	status = first_char_m_times_occurred(str, 2, &output, &index);
	printf("(1,%d) (b,%c) (1,%d)\n", status, output, index);

	str = "aabbccc";
	status = first_char_m_times_occurred(str, 3, &output, &index);
	printf("(1,%d) (c,%c) (4,%d)\n", status, output, index);

	str = "";
	status = first_char_m_times_occurred(str, 2, &output, &index);
	printf("(0,%d) (X,%c) (X,%d)\n", status, output, index);

	str = NULL;
	status = first_char_m_times_occurred(str, 2, &output, &index);
	printf("(0,%d) (X,%c) (X,%d)\n", status, output, index);


	printf("\nremove_quotes\n");
	str = strdup("\"where there is a sea, there pirates be\"");
	status = remove_quotes(str);
	printf("%d '%s'\n", status, str);
	free(str);

	str = strdup("\"walk on\" he said.");
	status = remove_quotes(str);
	printf("%d '%s'\n", status, str);
	free(str);

	str = strdup("he said \"walk on\"");
	status = remove_quotes(str);
	printf("%d '%s'\n", status, str);
	free(str);

	str = strdup("no quotes here");
	status = remove_quotes(str);
	printf("%d '%s'\n", status, str);
	free(str);


	return 0;
}
