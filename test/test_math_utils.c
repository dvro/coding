#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include <math_utils.h>

#define ABS(x) x<0?-x:x

START_TEST (test_square_root)
{
	int s = square(9.0,0.001);
	fail_unless(ABS(s - 3) < 0.001);
}
END_TEST

Suite *get_math_utils_suite(void)
{
	Suite *s = suite_create("math utils suite");

	TCase *tc_square = tcase_create("tc_square");
	tcase_add_test(tc_square, test_square_root);
	suite_add_tcase(s, tc_square);

	return s;
}

int main(void)
{
	Suite *s = get_math_utils_suite();
	SRunner *sr = 	srunner_create(s);
	srunner_run_all(sr, CK_NORMAL);
	
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? 0 : 1;
}





