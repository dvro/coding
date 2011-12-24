#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int overlap(char *needle, int table[])
{
	table[0] = -1;
	int i;
	for (i = 0; needle[i] != '\0'; i++) {
		table[i + 1] = table[i] + 1;
		while (table[i + 1] > 0 && needle[i] != needle[table[i + 1] - 1]) {
			table[i + 1] = table[table[i + 1] - 1] + 1;
		}
	}

	return 1;
}

int kmp (char *haystack, char *needle, int *index)
{
							//TODO validate inputs and handle special cases
	
	int haystack_len = strlen(haystack);
	int needle_len = strlen(needle);

	int table[needle_len];				//auxiliar overlap table
	overlap(needle, table);				//compute overlap

	int m = 0;					//haystack index
	int i = 0;					//needle index
	
	while (m + i < haystack_len) {
		if (needle[i] == haystack[m + i]) {	//if matched so far
			if (i == needle_len - 1) {	//if matched all needle
				*index = m;
				return 1;
			}
			i++;
		} else {				//if didn't match
			m = m + i - table[i];		//compute from where to begin
			if (table[i] > -1)
				i = table[i];		//set from where to start now
			else
				i = 0;
		}
	}

	return 0;
}

/*
int main(void)
{
	int index = -1;
	kmp("banananobano", "nano", &index);
	printf("index = %d\n", index);
	return 0;
}
*/

