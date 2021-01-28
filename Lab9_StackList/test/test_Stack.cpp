#include <gtest.h>
#include "StackList.h"

TEST(TStackList, can_create_stack_of_size_0)
{
  EXPECT_NO_THROW(TStackList<int> set);
}

TEST(TStackList, can_create_copy_of_stack)
{
  TStackList<int> stack;
  EXPECT_NO_THROW(TStackList<int> s(stack));
}

TEST(TStackList, can_create_copy_of_stack_and_stacks_is_equal)
{
  TStackList<int> stack;
  stack.push(2);
  TStackList<int> st(stack);
  EXPECT_EQ(stack.get(), st.get());
}

TEST(TStackList, can_push_if_is_not_full)
{
  TStackList<int> s;
  EXPECT_NO_THROW(s.push(2));
}

TEST(TStackList, can_get_element_if_empty)
{
  TStackList<int> s;
  s.push(1);
  s.get();
  EXPECT_ANY_THROW(s.get());
}

TEST(TStackList, can_get_element_if_is_not_empty)
{
  TStackList<int> s;
  s.push(1);
  EXPECT_NO_THROW(s.get());
}

TEST(TStackList, can_get_existing_element)
{
  TStackList<int> s;
  s.push(1);
  s.push(5);
  s.push(2);
  s.get();
  EXPECT_EQ(5, s.get());
}

TEST(TStackList, can_get_max_element)
{
  TStackList<int> s;
  for (int i = 0; i < 10; i++)
    s.push(i);
  s.get();
  EXPECT_EQ(8, s.getMax());
}

TEST(TStackList, can_get_min_element)
{
  TStackList<int> s;
  for (int i = 0; i < 10; i++)
    s.push(10 - i);
  s.get();
  EXPECT_EQ(2, s.getMin());
}

TEST(TStackList, return_empty_if_stack_is_empty)
{
  TStackList<int> s;
  s.push(2);
  s.push(2);
  s.get();
  s.get();

  EXPECT_EQ(true, s.isEmpty());
}

TEST(TStackList, return_empty_if_stack_is_not_empty)
{
  TStackList<int> s;
  s.push(2);
  s.push(2);
  s.get();

  EXPECT_EQ(false, s.isEmpty());
}

TEST(TStackList, return_Full_if_stack_is_not_full)
{
  TStackList<int> s;
  for (int i = 0; i < 9; i++)
    s.push(10 - i);
  EXPECT_EQ(false, s.isFull());
}

TEST(TStackList, can_assign_with_no_exc)
{
  TStackList<int> stack;
  stack.push(2);
  TStackList<int> st;
  EXPECT_NO_THROW(st = stack);
}

TEST(TStackList, can_assign_with_equal_element)
{
  TStackList<int> stack;
  stack.push(2);
  TStackList<int> st = stack;
  EXPECT_EQ(st.get(), stack.get());
}