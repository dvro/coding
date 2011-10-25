#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algorithms/string_utils.h"

int main (void)
{
	int value = -1;
	int status = -1;
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
	


	printf("\nint to string\n\n");
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


	str = strdup("the sky is blue");
	reverse_words(&str);
	printf("'the sky is blue' $ '%s'\n", str);
	free(str);
	str = strdup(" the sky is blue");
	reverse_words(&str);
	printf("' the sky is blue' $ '%s'\n", str);
	free(str);
	str = strdup("the sky is blue ");
	reverse_words(&str);
	printf("'the sky is blue ' $ '%s'\n", str);
	free(str);
	str = strdup("no_meio_do_caminho    havia_uma_pedra");
	reverse_words(&str);
	printf("'no_meio_do_caminho    havia_uma_pedra' $ '%s'\n", str);
	free(str);

	return 0;
}
