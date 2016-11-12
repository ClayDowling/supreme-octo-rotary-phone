#include "test_stack.h"
#include "../stack.h"

void setup()
{
    stack_init();
}

START_TEST(pushedCharacter_whenPopped_returnsCharacter)
{
  stack_push('A');
  ck_assert_int_eq(stack_pop(), 'A');
}
END_TEST

START_TEST(twoPushedCharacters_whenPopped_willReturnCharactersInReverseOrder)
{
    stack_push('A');
    stack_push('B');
    ck_assert_int_eq(stack_pop(), 'B');
    ck_assert_int_eq(stack_pop(), 'A');
}
END_TEST

TCase *tcase_stack(void) {
  TCase *tc;

  tc = tcase_create("stack");
  tcase_add_checked_fixture(tc, setup, NULL);
  tcase_add_test(tc, pushedCharacter_whenPopped_returnsCharacter);
  tcase_add_test(tc, twoPushedCharacters_whenPopped_willReturnCharactersInReverseOrder);

  return tc;
}

Suite *suite_stack(void)
{
    Suite *s;

    s = suite_create("stack");

	suite_add_tcase(s, tcase_stack());

    return s;
}