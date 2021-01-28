#include <gtest.h>
#include "TStack.h"



TEST(TStack, can_create_stack_of_size_10)
{
  EXPECT_NO_THROW(TStack<int> set(10));
}

TEST(TStack, can_create_stack_of_size_0)
{
  EXPECT_ANY_THROW(TStack<int> set(0));
}

TEST(TStack, can_create_copy_of_stack)
{
  TStack<int> stack(1);
  EXPECT_NO_THROW(TStack<int> s(stack));
}

TEST(TStack, can_create_copy_of_stack_and_stacks_is_equal)
{
  TStack<int> stack(1);
  stack.push(2);
  TStack<int> st(stack);
  EXPECT_EQ(stack.get(), st.get());
}

TEST(TStack, can_push_if_full)
{
  TStack<int> s(1);
  s.push(1);
  EXPECT_ANY_THROW(s.push(2));
}

TEST(TStack, can_push_if_is_not_full)
{
  TStack<int> s(1);
  EXPECT_NO_THROW(s.push(2));
}

TEST(TStack, can_get_element_if_empty)
{
  TStack<int> s(1);
  s.push(1);
  s.get();
  EXPECT_ANY_THROW(s.get());
}

TEST(TStack, can_get_element_if_is_not_empty)
{
  TStack<int> s(1);
  s.push(1);
  EXPECT_NO_THROW(s.get());
}

TEST(TStack, can_get_existing_element)
{
  TStack<int> s(3);
  s.push(1);
  s.push(5);
  s.push(2);
  s.get();
  EXPECT_EQ(5,s.get());
}

TEST(TStack, can_get_max_element)
{
  TStack<int> s(10);
  for (int i = 0; i < 10; i++)
    s.push(i);
  s.get();
  EXPECT_EQ(8, s.getMax());
}

TEST(TStack, can_get_min_element)
{
  TStack<int> s(10);
  for (int i = 0; i < 10; i++)
    s.push(10-i);
  s.get();
  EXPECT_EQ(2, s.getMin());
}

TEST(TStack, return_empty_if_stack_is_empty)
{
  TStack<int> s(2);
  s.push(2);
  s.push(2);
  s.get();
  s.get();

  EXPECT_EQ(true, s.isEmpty());
}

TEST(TStack, return_Full_if_stack_is_full)
{
  TStack<int> s(10);
  for (int i = 0; i < 10; i++)
    s.push(10 - i);
  EXPECT_EQ(true, s.isFull());
}

TEST(TStack, return_empty_if_stack_is_not_empty)
{
  TStack<int> s(2);
  s.push(2);
  s.push(2);
  s.get();

  EXPECT_EQ(false, s.isEmpty());
}

TEST(TStack, return_Full_if_stack_is_not_full)
{
  TStack<int> s(10);
  for (int i = 0; i < 9; i++)
    s.push(10 - i);
  EXPECT_EQ(false, s.isFull());
}

TEST(TStack, can_assign_with_no_exc)
{
  TStack<int> stack(1);
  stack.push(2);
  TStack<int> st(2);
  EXPECT_NO_THROW(st = stack);
}

TEST(TStack, can_assign_with_equal_element)
{
  TStack<int> stack(1);
  stack.push(2);
  TStack<int> st = stack;
  EXPECT_EQ(st.get(),stack.get());
}