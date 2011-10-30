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

