#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include <array_utils.h>

START_TEST (test_binary_search_even)
{
	int value = 5;
	int array[10] = {0,1,2,3,4,5,6,7,8,9};
	int index = -1;
	int status = binary_search(array, 10, value, &index);
	fail_unless(status == 1, "status = %d", status);
	fail_unless(index == 5);
}
END_TEST

START_TEST (test_binary_search_odd_size)
{
	int value = 4;
	int array[11] = {0,1,2,3,4,5,6,7,8,9,10};
	int index = -1;
	int status = binary_search(array, 11, value, &index);
	fail_unless(status == 1, "status = %d", status);
	fail_unless(index == 4);
}
END_TEST

START_TEST (test_binary_search_left)
{
	int value = 0;
	int array[11] = {0,1,2,3,4,5,6,7,8,9,10};
	int index = -1;
	int status = binary_search(array, 11, value, &index);
	fail_unless(status == 1, "status = %d", status);
	fail_unless(index == 0);
}
END_TEST

START_TEST (test_binary_search_left_2)
{
	int value = 1;
	int array[11] = {0,1,2,3,4,5,6,7,8,9,10};
	int index = -1;
	int status = binary_search(array, 11, value, &index);
	fail_unless(status == 1);
	fail_unless(index == 1);
}
END_TEST


START_TEST (test_binary_search_right)
{
	int value = 10;
	int array[11] = {0,1,2,3,4,5,6,7,8,9,10};
	int index = -1;
	int status = binary_search(array, 11, value, &index);
	fail_unless(status == 1);
	fail_unless(index == 10);
}
END_TEST

START_TEST (test_binary_search_right_2)
{
	int value = 9;
	int array[11] = {0,1,2,3,4,5,6,7,8,9,10};
	int index = -1;
	int status = binary_search(array, 11, value, &index);
	fail_unless(status == 1);
	fail_unless(index == 9);
}
END_TEST

START_TEST (test_binary_search_value_not_found)
{
	int value = 5;
	int array[5] = {0,2,4,6,8};
	int index = -1;
	int status = binary_search(array, 5, value, &index);
	fail_unless(status == 0);
	fail_unless(index == -1);
}
END_TEST

START_TEST (test_binary_search_value_not_found_left)
{
	int value = -1;
	int array[5] = {0,2,4,6,8};
	int index = -1;
	int status = binary_search(array, 5, value, &index);
	fail_unless(status == 0);
	fail_unless(index == -1);
}
END_TEST

START_TEST (test_binary_search_value_not_found_left_2)
{
	int value = 1;
	int array[5] = {0,2,4,6,8};
	int index = -1;
	int status = binary_search(array, 5, value, &index);
	fail_unless(status == 0);
	fail_unless(index == -1);
}
END_TEST

START_TEST (test_binary_search_value_not_found_right)
{
	int value = 11;
	int array[5] = {0,2,4,6,8};
	int index = -1;
	int status = binary_search(array, 5, value, &index);
	fail_unless(status == 0);
	fail_unless(index == -1);
}
END_TEST

START_TEST (test_binary_search_value_not_found_right_2)
{
	int value = 9;
	int array[5] = {0,2,4,6,8};
	int index = -1;
	int status = binary_search(array, 5, value, &index);
	fail_unless(status == 0);
	fail_unless(index == -1);
}
END_TEST

START_TEST (test_binary_search_array_unordened)
{
	int value = 6;
	int array[5] = {0,10,2,8,6};
	int index = -1;
	int status = binary_search(array, 5, value, &index);
	fail_unless(status == -1);				//NOT_ORDENED
	fail_unless(index == -1);
}
END_TEST





Suite *get_array_utils_suite(void)
{
	Suite *s = suite_create("array utils suite");

	TCase *tc_binary_search = tcase_create("tc_binary_search");
	tcase_add_test(tc_binary_search, test_binary_search_even);
	tcase_add_test(tc_binary_search, test_binary_search_odd_size);
	tcase_add_test(tc_binary_search, test_binary_search_left);
	tcase_add_test(tc_binary_search, test_binary_search_left_2);
	tcase_add_test(tc_binary_search, test_binary_search_right);
	tcase_add_test(tc_binary_search, test_binary_search_right_2);
	tcase_add_test(tc_binary_search, test_binary_search_value_not_found);
	tcase_add_test(tc_binary_search, test_binary_search_value_not_found_left);
	tcase_add_test(tc_binary_search, test_binary_search_value_not_found_left_2);
	tcase_add_test(tc_binary_search, test_binary_search_value_not_found_right);
	tcase_add_test(tc_binary_search, test_binary_search_value_not_found_right_2);
	tcase_add_test(tc_binary_search, test_binary_search_array_unordened);
	suite_add_tcase(s, tc_binary_search);
	
	return s;
}

int main(void)
{
	Suite *s = get_array_utils_suite();
	SRunner *sr = 	srunner_create(s);
	srunner_run_all(sr, CK_NORMAL);
	
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? 0 : 1;
}










