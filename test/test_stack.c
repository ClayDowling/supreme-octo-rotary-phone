#include "test_stack.h"
#include "../stack.h"

static void setup() { stack_init(); }

START_TEST(pushedCharacter_whenPopped_returnsCharacter) {
  stack_push('A');
  ck_assert_int_eq(stack_pop(), 'A');
}
END_TEST

START_TEST(twoPushedCharacters_whenPopped_willReturnCharactersInReverseOrder) {
  stack_push('A');
  stack_push('B');
  ck_assert_int_eq(stack_pop(), 'B');
  ck_assert_int_eq(stack_pop(), 'A');
}
END_TEST

START_TEST(onePushedCharacter_withTwoPops_willReturnStackUnderflow) {
  stack_push('Z');
  ck_assert_int_eq(stack_pop(), 'Z');
  ck_assert_int_eq(stack_pop(), STACK_UNDERFLOW);
}
END_TEST

START_TEST(
    fiftyOnePushedCharacters_whenPoppedFiftyOneTimes_willReturnStackUnderflowOnTheFiftyFirstPop) {
  int i;
  stack_push('X');
  for (i = 0; i < 50; ++i) {
    stack_push('A');
  }
  for (i = 0; i < 50; ++i) {
    stack_pop();
  }
  ck_assert_int_eq(stack_pop(), STACK_UNDERFLOW);
}
END_TEST

START_TEST(stackPeek_withTwoCharactersPushed_returnsMostRecentCharacterPushed) {
  stack_push('A');
  stack_push('B');
  ck_assert_int_eq(stack_peek(), 'B');
}
END_TEST

START_TEST(
    stackPeekCalledTwice_withTwoCharactersPushed_returnsMostRecentCharacterPushed) {
  stack_push('A');
  stack_push('B');
  ck_assert_int_eq(stack_peek(), 'B');
  ck_assert_int_eq(stack_peek(), 'B');
}
END_TEST

START_TEST(stackPeek_withEmptyStack_returnsStackUnderflow) {
  ck_assert_int_eq(stack_peek(), STACK_UNDERFLOW);
}
END_TEST

TCase *tcase_stack(void) {
  TCase *tc;

  tc = tcase_create("stack");
  tcase_add_checked_fixture(tc, setup, NULL);
  tcase_add_test(tc, pushedCharacter_whenPopped_returnsCharacter);
  tcase_add_test(
      tc, twoPushedCharacters_whenPopped_willReturnCharactersInReverseOrder);
  tcase_add_test(tc, onePushedCharacter_withTwoPops_willReturnStackUnderflow);
  tcase_add_test(
      tc,
      fiftyOnePushedCharacters_whenPoppedFiftyOneTimes_willReturnStackUnderflowOnTheFiftyFirstPop);
  tcase_add_test(
      tc, stackPeek_withTwoCharactersPushed_returnsMostRecentCharacterPushed);
  tcase_add_test(
      tc,
      stackPeekCalledTwice_withTwoCharactersPushed_returnsMostRecentCharacterPushed);
  tcase_add_test(tc, stackPeek_withEmptyStack_returnsStackUnderflow);

  return tc;
}

Suite *suite_stack(void) {
  Suite *s;

  s = suite_create("stack");

  suite_add_tcase(s, tcase_stack());

  return s;
}
