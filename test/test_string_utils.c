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

