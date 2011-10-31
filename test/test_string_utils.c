#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include <string_utils.h>

START_TEST (test_str_to_int)
{
	int value = -1;
	int status = str_to_int("1234", &value);
	fail_unless (status == 1);
	fail_unless (value == 1234);
}
END_TEST

START_TEST (test_str_to_int_negative_value)
{
	int value = -1;
	int status = str_to_int("-1234", &value);
	fail_unless (status == 1);
	fail_unless (value == -1234);
}
END_TEST

START_TEST (test_str_to_int_one_string)
{
	int value = -1;
	int status = str_to_int("1", &value);
	fail_unless (status == 1);
	fail_unless (value == 1);
}
END_TEST

START_TEST (test_str_to_int_null_string)
{
	int value = -1;
	int status = str_to_int(NULL, &value);
	fail_unless (status == 0);
	fail_unless (value == -1);
}
END_TEST

START_TEST (test_str_to_int_empty_string)
{
	int value = -1;
	int status = str_to_int("", &value);
	fail_unless (status == 0);
	fail_unless (value == -1);
}
END_TEST

START_TEST (test_str_to_int_invalid_string)
{
	int value = -1;
	int status = str_to_int("-123a4", &value);
	fail_unless (status == 0);
	fail_unless (value == -1);
}
END_TEST

START_TEST (test_int_to_str)
{
	int value = 123;
	char *expected = "123";
	char *actual = calloc(10, sizeof(char));
	int status = int_to_str(value, &actual);
	fail_unless(status == 1, "status = %d", status);
	fail_unless(strcmp(actual, expected) == 0, "%s != %s", actual, expected);
	free(actual);
}
END_TEST

START_TEST (test_int_to_str_negative_value)
{
	int value = -123;
	char *expected = "-123";
	char *actual = calloc(10, sizeof(char));
	int status = int_to_str(value, &actual);
	fail_unless(status == 1, "status = %d", status);
	fail_unless(strcmp(actual, expected) == 0, "%s != %s", actual, expected);
free(actual);
}
END_TEST

START_TEST (test_int_to_str_zero_value)
{
	int value = 0;
	char *expected = "0";
	char *actual = calloc(10, sizeof(char));
	int status = int_to_str(value, &actual);
	fail_unless(status == 1, "status = %d", status);
	fail_unless(strcmp(actual, expected) == 0, "%s != %s", actual, expected);
	free(actual);
}
END_TEST

START_TEST (test_reverse_words)
{
	char *actual = strdup("my name is dayvid");
	char *expected = "dayvid is name my";
	int status = reverse_words(actual);
	fail_unless(status == 1);
	fail_unless(strcmp(actual, expected) == 0, "%s != %s", actual, expected);
	free(actual);
}
END_TEST

START_TEST (test_reverse_words_no_space)
{
	char *actual = strdup("12345");
	char *expected = "12345";
	int status = reverse_words(actual);
	fail_unless(status == 1);
	fail_unless(strcmp(actual, expected) == 0, "%s != %s", actual, expected);
	free(actual);
}
END_TEST

START_TEST (test_reverse_words_one_char_string)
{
	char *actual = strdup("a");
	char *expected = "a";
	int status = reverse_words(actual);
	fail_unless(status == 1);
	fail_unless(strcmp(actual, expected) == 0, "%s != %s", actual, expected);
	free(actual);
}
END_TEST

START_TEST (test_reverse_words_null_string)
{
	char *actual = NULL;
	int status = reverse_words(actual);
	fail_unless(status == 0, "status = %d", status);
}
END_TEST

START_TEST (test_reverse_words_empty_string)
{
	char *actual = strdup("");
	int status = reverse_words(actual);
	fail_unless(status == 1, "status = %d", status);
	free(actual);
}
END_TEST

START_TEST (test_reverse_words_lots_of_spaces)
{
	char *actual = strdup(" 1  2   3    4     ");
	char *expected = "     4    3   2  1 ";
	int status = reverse_words(actual);
	fail_unless(status == 1);
	fail_unless(strcmp(actual, expected) == 0, "%s != %s", actual, expected);
	free(actual);
}
END_TEST

START_TEST(test_large_block_empty_string)
{
	int index = -1;
	int status = large_block("", &index);
	fail_unless(status == 0);
	fail_unless(index == -1);
}
END_TEST

START_TEST(test_large_block_null_string)
{
	int index = -1;
	char *tmp = NULL;
	int status = large_block(tmp, &index);
	fail_unless(status == 0);
	fail_unless(index == -1);
}
END_TEST

START_TEST(test_large_block_non_block)
{
	int index = -1;
	char *tmp = "abcd";
	int status = large_block(tmp, &index);
	fail_unless(status == 1);
	fail_unless(index == 0);
}
END_TEST

START_TEST(test_large_block_init)
{
	int index = -1;
	char *tmp = "aaabbcc";
	int status = large_block(tmp, &index);
	fail_unless(status == 1);
	fail_unless(index == 0);
}
END_TEST

START_TEST(test_large_block_middle)
{
	int index = -1;
	char *tmp = "aabbbcc";
	int status = large_block(tmp, &index);
	fail_unless(status == 1);
	fail_unless(index == 2);
}
END_TEST

START_TEST(test_large_block_end)
{
	int index = -1;
	char *tmp = "aabbccc";
	int status = large_block(tmp, &index);
	fail_unless(status == 1);
	fail_unless(index == 4);
}
END_TEST

START_TEST(test_large_block_concept)
{
	int index = -1;
	int status = large_block("abababababcccabababababa", &index);
	fail_unless(status == 1);
	fail_unless(index == 10);
}
END_TEST

START_TEST(test_large_block_one_char)
{
	int index = -1;
	int status = large_block("a", &index);
	fail_unless(status == 1);
	fail_unless(index == 0);
}
END_TEST

START_TEST(test_char_most_repeated)
{
	char output = '\0';
	int index = -1;
	int count = -1;
	char *str = "ababababaccccccababababab";
	int status = char_most_repeated(str, &output, &index, &count);

	fail_unless(status == 1);
	fail_unless(output == 'a');
	fail_unless(index == 0);
	fail_unless(count == 10);
}
END_TEST

START_TEST(test_char_most_repeated_end)
{
	char output = '\0';
	int index = -1;
	int count = -1;
	char *str = "ccbaaa";
	int status = char_most_repeated(str, &output, &index, &count);

	fail_unless(status == 1);
	fail_unless(output == 'a');
	fail_unless(index == 3);
	fail_unless(count == 3);
}
END_TEST

START_TEST(test_char_most_repeated_middle)
{
	char output = '\0';
	int index = -1;
	int count = -1;
	char *str = "ccbbbaa";
	int status = char_most_repeated(str, &output, &index, &count);

	fail_unless(status == 1);
	fail_unless(output == 'b');
	fail_unless(index == 2);
	fail_unless(count == 3);
}
END_TEST

START_TEST(test_char_most_repeated_init)
{
	char output = '\0';
	int index = -1;
	int count = -1;
	char *str = "abcbcbcadadadadadadadada";
	int status = char_most_repeated(str, &output, &index, &count);

	fail_unless(status == 1);
	fail_unless(output == 'a');
	fail_unless(index == 0);
	fail_unless(count == 10);
}
END_TEST

START_TEST(test_char_most_repeated_empty_string)
{
	char output = '\0';
	int index = -1;
	int count = -1;
	char *str = "";
	int status = char_most_repeated(str, &output, &index, &count);

	fail_unless(status == 0);
	fail_unless(output == '\0');
	fail_unless(index == -1);
	fail_unless(count == -1);
}
END_TEST

START_TEST(test_char_most_repeated_null_string)
{
	char output = '\0';
	int index = -1;
	int count = -1;
	char *str = NULL;
	int status = char_most_repeated(str, &output, &index, &count);

	fail_unless(status == 0);
	fail_unless(output == '\0');
	fail_unless(index == -1);
	fail_unless(count == -1);
}
END_TEST

START_TEST(test_char_most_repeated_one_char)
{
	char output = '\0';
	int index = -1;
	int count = -1;
	char *str = "a";
	int status = char_most_repeated(str, &output, &index, &count);
	
	fail_unless(status == 1);
	fail_unless(output == 'a');
	fail_unless(index == 0);
	fail_unless(count == 1);
}
END_TEST

START_TEST (test_first_char_m_times_ocurred_1)
{
	int index = -1;
	char output = '\0';
	char *str = "abcdbcd";
	int status = first_char_m_times_occurred(str, 1, &output, &index);

	fail_unless(status == 1);
	fail_unless(output == 'a');
	fail_unless(index == 0);	
}
END_TEST

START_TEST (test_first_char_m_times_ocurred_2_at_the_end)
{
	int index = -1;
	char output = '\0';
	char *str = "abbbccca";
	int status = first_char_m_times_occurred(str, 2, &output, &index);

	fail_unless(status == 1);
	fail_unless(output == 'a');
	fail_unless(index == 0);	
}
END_TEST

START_TEST (test_first_char_m_times_ocurred_non_existent)
{
	int index = -1;
	char output = '\0';
	char *str = "abcdbcd";
	int status = first_char_m_times_occurred(str, 3, &output, &index);

	fail_unless(status == 0);
	fail_unless(output == '\0');
	fail_unless(index == -1);	
}
END_TEST

START_TEST (test_first_char_m_times_ocurred_null)
{
	int index = -1;
	char output = '\0';
	char *str = NULL;
	int status = first_char_m_times_occurred(str, 1, &output, &index);

	fail_unless(status == 0);
	fail_unless(output == '\0');
	fail_unless(index == -1);	
}
END_TEST

START_TEST (test_first_char_m_times_ocurred_empty_string)
{
	int index = -1;
	char output = '\0';
	char *str = "";
	int status = first_char_m_times_occurred(str, 1, &output, &index);

	fail_unless(status == 0);
	fail_unless(output == '\0');
	fail_unless(index == -1);	
}
END_TEST

START_TEST (test_first_char_m_times_ocurred_0)
{
	int index = -1;
	char output = '\0';
	char *str = "";
	int status = first_char_m_times_occurred(str, 0, &output, &index);

	fail_unless(status == 0);
	fail_unless(output == '\0');
	fail_unless(index == -1);	
}
END_TEST

START_TEST (test_first_char_m_times_ocurred_negative_m)
{
	int index = -1;
	char output = '\0';
	char *str = "";
	int status = first_char_m_times_occurred(str, -1, &output, &index);

	fail_unless(status == 0);
	fail_unless(output == '\0');
	fail_unless(index == -1);	
}
END_TEST

START_TEST (test_remove_quotes)
{
	char *str = strdup("\"where there is a sea, there pirates be\"");
	char *exp = "";
	int status = remove_quotes(str);
	fail_unless(status == 1);
	fail_unless(strcmp(str, exp) == 0);
	free(str);
}
END_TEST

START_TEST (test_remove_quotes_begining_1)
{
	char *str = strdup("\"walk ok\" he said");
	char *exp = " he said";
	int status = remove_quotes(str);
	fail_unless(status == 1);
	fail_unless(strcmp(str, exp) == 0);
	free(str);
}
END_TEST

START_TEST (test_remove_quotes_begining_2)
{
	char *str = strdup("t\"walk ok\" he said");
	char *exp = "t he said";
	int status = remove_quotes(str);
	fail_unless(status == 1);
	fail_unless(strcmp(str, exp) == 0);
	free(str);
}
END_TEST

START_TEST (test_remove_quotes_middle)
{
	char *str = strdup("he said \"walk on\" to me.");
	char *exp = "he said  to me.";
	int status = remove_quotes(str);
	fail_unless(status == 1);
	fail_unless(strcmp(str, exp) == 0);
	free(str);
}
END_TEST

START_TEST (test_remove_quotes_end_1)
{
	char *str = strdup("he said \"walk on\"");
	char *exp = "he said ";
	int status = remove_quotes(str);
	fail_unless(status == 1);
	fail_unless(strcmp(str, exp) == 0);
	free(str);
}
END_TEST

START_TEST (test_remove_quotes_end_2)
{
	char *str = strdup("he said \"walk on\".");
	char *exp = "he said .";
	int status = remove_quotes(str);
	fail_unless(status == 1);
	fail_unless(strcmp(str, exp) == 0);
	free(str);
}
END_TEST

START_TEST (test_remove_quotes_many_quotes)
{
	char *str = strdup("1\"2\"3\"4\"5\"6\"7");
	char *exp = "1357";
	int status = remove_quotes(str);
	fail_unless(status == 1);
	fail_unless(strcmp(str, exp) == 0);
	free(str);
}
END_TEST

START_TEST (test_remove_quotes_not_well_formed_quotes)
{
	char *str = strdup("1\"2");
	char *exp = "1\"2";
	int status = remove_quotes(str);
	fail_unless(status == 0);
	fail_unless(strcmp(str, exp) == 0);
	free(str);
}
END_TEST

START_TEST (test_remove_quotes_no_quotes)
{
	char *str = strdup("Hello Hello, I'm at a place called vertigo");
	char *exp = "Hello Hello, I'm at a place called vertigo";
	int status = remove_quotes(str);
	fail_unless(status == 0);
	fail_unless(strcmp(str, exp) == 0);
	free(str);
}
END_TEST

START_TEST (test_remove_quotes_empty_string)
{
	char *str = strdup("");
	char *exp = "";
	int status = remove_quotes(str);
	fail_unless(status == 0);
	fail_unless(strcmp(str, exp) == 0);
	free(str);
}
END_TEST

START_TEST (test_remove_quotes_null_string)
{
	char *str = NULL;
	int status = remove_quotes(str);
	fail_unless(status == 0);
}
END_TEST

START_TEST (test_remove_quotes_one_char)
{
	char *str = strdup("a");
	int status = remove_quotes(str);
	fail_unless(status == 0);
	fail_unless(strcmp(str, "a") == 0);
	free(str);
}
END_TEST

START_TEST (test_remove_quotes_only_quotes)
{
	char *str = strdup("\"\"");
	int status = remove_quotes(str);
	fail_unless(status == 1);
	fail_unless(strcmp(str, "") == 0);
	free(str);
}
END_TEST

START_TEST (test_remove_substring_many_times)
{
	char *str = strdup("a1a2a3a4a5a6a7a8a9a");
	char *exp = "123456789";
	int status = remove_substring(str, "a");
	fail_unless(status == 1);
	fail_unless(strcmp(str, exp) == 0);
	free(str);
}
END_TEST

START_TEST (test_remove_substring_regular_case)
{
	char *str = strdup("i used to rule the world");
	char *exp = "i  to rule the world";
	int status = remove_substring(str, "used");
	fail_unless(status == 1);
	fail_unless(strcmp(str, exp) == 0);
	free(str);
}
END_TEST

START_TEST (test_remove_substring_no_occurrence)
{
	char *str = strdup("hello hello");
	char *exp = "hello hello";
	int status = remove_substring(str, "a");
	fail_unless(status == 0);
	fail_unless(strcmp(str, exp) == 0);
	free(str);
}
END_TEST

START_TEST (test_remove_substring_init)
{
	char *str = strdup("oi fulano");
	char *exp = " fulano";
	int status = remove_substring(str, "oi");
	fail_unless(status == 1);
	fail_unless(strcmp(str, exp) == 0);
	free(str);
}
END_TEST

START_TEST (test_remove_substring_end)
{
	char *str = strdup("oi fulano");
	char *exp = "oi ";
	int status = remove_substring(str, "fulano");
	fail_unless(status == 1);
	fail_unless(strcmp(str, exp) == 0);
	free(str);
}
END_TEST

START_TEST (test_remove_substring_null_string)
{
	char *str = NULL;
	int status = remove_substring(str, "fulano");
	fail_unless(status == 0);
}
END_TEST

START_TEST (test_remove_substring_empty_string)
{
	char *str = strdup("");
	int status = remove_substring(str, "a");
	fail_unless(status == 0);
	free(str);
}
END_TEST

START_TEST (test_remove_substring_null_substring)
{
	char *str = strdup("casa");
	char *sub = NULL;
	int status = remove_substring(str, sub);
	fail_unless(status == 0);
	free(str);
}
END_TEST

START_TEST (test_remove_substring_empty_substring)
{
	char *str = strdup("casa");
	int status = remove_substring(str, "");
	fail_unless(status == 0);
	free(str);
}
END_TEST

START_TEST (test_remove_chars)
{
	char *str = strdup("eu sou dayvid");
	char *exp = " s dyvd";
	int status = remove_chars(str, "aeiou");
	fail_unless (status == 1);
	fail_unless (strcmp(str,exp) == 0);
	free(str);
}
END_TEST

START_TEST (test_remove_chars_all_chars)
{
	char *str = strdup("aaaeeeiiiooouuuaeiou");
	char *exp = "";
	int status = remove_chars(str, "aeiou");
	fail_unless (status == 1);
	fail_unless (strcmp(str,exp) == 0);
	free(str);
}
END_TEST

START_TEST (test_remove_chars_no_occurrence)
{
	char *str = strdup("Jesus blood never failed me yet");
	char *exp = "Jesus blood never failed me yet";
	int status = remove_chars(str, "xzk");
	fail_unless (status == 0);
	fail_unless (strcmp(str,exp) == 0);
	free(str);
}
END_TEST

START_TEST (test_remove_chars_null_string)
{
	char *str = NULL;
	int status = remove_chars(str, "xzk");
	fail_unless (status == 0);
}
END_TEST

START_TEST (test_remove_chars_empty_string)
{
	char *str = strdup("");
	int status = remove_chars(str, "xzk");
	fail_unless (status == 0);
	free(str);
}
END_TEST

START_TEST (test_remove_chars_null_chars)
{
	char *str = strdup("abcd");
	char *chars = NULL;
	int status = remove_chars(str, chars);
	fail_unless (status == 0);
	free(str);
}
END_TEST

START_TEST (test_remove_chars_empty_chars)
{
	char *str = strdup("abcd");
	char *chars = "";
	int status = remove_chars(str, chars);
	fail_unless (status == 0);
	fail_unless (strcmp(str, "abcd") == 0);
	free(str);
}
END_TEST

START_TEST (test_string_distance)
{
	char *str_a = "kitten";
	char *str_b = "sitting";
	int distance = string_distance(str_a, str_b);
	fail_unless(distance == 3, "distance == %d", distance);
}
END_TEST

START_TEST (test_string_distance_same_strings)
{
	char *str1 = "sitting";
	char *str2 = "sitting";
	int distance = string_distance(str1, str2);
	fail_unless(distance == 0);
}
END_TEST

START_TEST (test_string_distance_empty_string)
{
	char *str1 = "";
	char *str2 = "sitting";
	int distance = string_distance(str1, str2);
	fail_unless(distance == 7);
}
END_TEST

START_TEST (test_string_distance_null_string)
{
	char *str1 = NULL;
	char *str2 = "sitting";
	int distance = string_distance(str1, str2);
	fail_unless(distance == -1);
	distance = string_distance(str2, str1);
	fail_unless(distance == -1);
}
END_TEST

Suite *get_suite(void)
{
	Suite *s = suite_create("string utils suite");

	TCase *tc_str_to_int = tcase_create("tcase_str_to_int");
	tcase_add_test(tc_str_to_int, test_str_to_int);
	tcase_add_test(tc_str_to_int, test_str_to_int_negative_value);
	tcase_add_test(tc_str_to_int, test_str_to_int_one_string);
	tcase_add_test(tc_str_to_int, test_str_to_int_null_string);
	tcase_add_test(tc_str_to_int, test_str_to_int_empty_string);
	tcase_add_test(tc_str_to_int, test_str_to_int_invalid_string);
	suite_add_tcase(s, tc_str_to_int);
	
	TCase *tc_int_to_str = tcase_create("tcase_int_to_str");
	tcase_add_test(tc_int_to_str, test_int_to_str);
	tcase_add_test(tc_int_to_str, test_int_to_str_negative_value);
	tcase_add_test(tc_int_to_str, test_int_to_str_zero_value);
	suite_add_tcase(s, tc_int_to_str);

	TCase *tc_reverse_words = tcase_create("tcase_reverse_words");
	tcase_add_test(tc_reverse_words, test_reverse_words);
	tcase_add_test(tc_reverse_words, test_reverse_words_no_space);
	tcase_add_test(tc_reverse_words, test_reverse_words_one_char_string);
	tcase_add_test(tc_reverse_words, test_reverse_words_null_string);
	tcase_add_test(tc_reverse_words, test_reverse_words_empty_string);
	tcase_add_test(tc_reverse_words, test_reverse_words_lots_of_spaces);
	suite_add_tcase(s, tc_reverse_words);

	TCase *tc_large_block = tcase_create("tcase_large_block");
	tcase_add_test(tc_large_block, test_large_block_empty_string);
	tcase_add_test(tc_large_block, test_large_block_null_string);
	tcase_add_test(tc_large_block, test_large_block_non_block);
	tcase_add_test(tc_large_block, test_large_block_init);
	tcase_add_test(tc_large_block, test_large_block_middle);
	tcase_add_test(tc_large_block, test_large_block_end);
	tcase_add_test(tc_large_block, test_large_block_concept);
	tcase_add_test(tc_large_block, test_large_block_one_char);
	suite_add_tcase(s, tc_large_block);

	TCase *tc_char_most_repeated = tcase_create("tcase_char_most_repeated");
	tcase_add_test(tc_char_most_repeated, test_char_most_repeated);
	tcase_add_test(tc_char_most_repeated, test_char_most_repeated_end);
	tcase_add_test(tc_char_most_repeated, test_char_most_repeated_middle);
	tcase_add_test(tc_char_most_repeated, test_char_most_repeated_init);
	tcase_add_test(tc_char_most_repeated, test_char_most_repeated_empty_string);
	tcase_add_test(tc_char_most_repeated, test_char_most_repeated_null_string);
	tcase_add_test(tc_char_most_repeated, test_char_most_repeated_one_char);
	suite_add_tcase(s, tc_char_most_repeated);
	
	TCase *tc_remove_quotes = tcase_create("tcase_remove_quotes");
	tcase_add_test(tc_remove_quotes, test_remove_quotes);
	tcase_add_test(tc_remove_quotes, test_remove_quotes_begining_1);
	tcase_add_test(tc_remove_quotes, test_remove_quotes_begining_2);
	tcase_add_test(tc_remove_quotes, test_remove_quotes_middle);
	tcase_add_test(tc_remove_quotes, test_remove_quotes_end_1);
	tcase_add_test(tc_remove_quotes, test_remove_quotes_end_2);
	tcase_add_test(tc_remove_quotes, test_remove_quotes_many_quotes);
	tcase_add_test(tc_remove_quotes, test_remove_quotes_not_well_formed_quotes);
	tcase_add_test(tc_remove_quotes, test_remove_quotes_no_quotes);
	tcase_add_test(tc_remove_quotes, test_remove_quotes_empty_string);
	tcase_add_test(tc_remove_quotes, test_remove_quotes_null_string);
	tcase_add_test(tc_remove_quotes, test_remove_quotes_one_char);
	tcase_add_test(tc_remove_quotes, test_remove_quotes_only_quotes);
	suite_add_tcase(s, tc_remove_quotes);

	TCase *tc_remove_substring = tcase_create("tcase_remove_substring");
	tcase_add_test(tc_remove_substring, test_remove_substring_many_times);
	tcase_add_test(tc_remove_substring, test_remove_substring_empty_substring);
	tcase_add_test(tc_remove_substring, test_remove_substring_null_substring);
	tcase_add_test(tc_remove_substring, test_remove_substring_empty_string);
	tcase_add_test(tc_remove_substring, test_remove_substring_null_string);
	tcase_add_test(tc_remove_substring, test_remove_substring_end);
	tcase_add_test(tc_remove_substring, test_remove_substring_init);
	tcase_add_test(tc_remove_substring, test_remove_substring_no_occurrence);
	tcase_add_test(tc_remove_substring, test_remove_substring_regular_case);
	suite_add_tcase(s, tc_remove_substring);

	TCase *tc_remove_chars = tcase_create("tc_remove_chars");
	tcase_add_test(tc_remove_chars, test_remove_chars);
	tcase_add_test(tc_remove_chars, test_remove_chars_all_chars);
	tcase_add_test(tc_remove_chars, test_remove_chars_no_occurrence);
	tcase_add_test(tc_remove_chars, test_remove_chars_null_string);
	tcase_add_test(tc_remove_chars, test_remove_chars_empty_string);
	tcase_add_test(tc_remove_chars, test_remove_chars_null_chars);
	tcase_add_test(tc_remove_chars, test_remove_chars_empty_chars);
	suite_add_tcase(s, tc_remove_chars);
	
	TCase *tc_string_distance = tcase_create("tc_string_distance");
	tcase_add_test(tc_string_distance, test_string_distance);
	//tcase_add_test(tc_string_distance, test_string_distance_same_strings);
	//tcase_add_test(tc_string_distance, test_string_distance_empty_string);
	//tcase_add_test(tc_string_distance, test_string_distance_null_string);
	suite_add_tcase(s, tc_string_distance);

	return s;
}

int main(void)
{
	Suite *s = get_suite();
	SRunner *sr = 	srunner_create(s);
	srunner_run_all(sr, CK_NORMAL);
	
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? 0 : 1;
}

