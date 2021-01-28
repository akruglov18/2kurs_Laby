#include <gtest.h>
#include "TMultistack.h"



TEST(TMultiStack, can_create_multistack_of_size_10)
{
  EXPECT_NO_THROW(TMultiStack<int> ms(10, 5));
}

TEST(TMultiStack, can_create_multistack_of_size_0)
{
  EXPECT_ANY_THROW(TMultiStack<int> ms(0, 1));
}

TEST(TMultiStack, can_create_multistack_of_stacks_size_0)
{
  EXPECT_ANY_THROW(TMultiStack<int> ms(1, 0));
}

TEST(TMultiStack, can_create_copy_of_stack)
{
  TMultiStack<int> mstack(1);
  EXPECT_NO_THROW(TMultiStack<int> s(mstack));
}

TEST(TMultiStack, can_create_copy_of_mstack_and_mstacks_is_equal)
{
  TMultiStack<int> ms(9,3);
  ms.push(11,0);
  ms.push(12, 1);
  ms.push(13, 1);
  ms.push(14, 1);
  TMultiStack<int> ms1(ms);
  ms.get(1);
  ms.get(1);
  ms1.get(1);
  EXPECT_EQ(13,ms1.get(1));
}

TEST(TMultiStack, can_get_element_if_empty)
{
  TMultiStack<int> ms(9, 3);
  ms.push(11, 0);
  ms.push(12, 1);
  ms.push(13, 1);
  ms.push(14, 1);
  ms.get(0);
  EXPECT_ANY_THROW(ms.get(0));
}

TEST(TMultiStack, can_get_element_if_is_not_empty)
{
  TMultiStack<int> ms(9, 3);
  ms.push(11, 0);
  ms.push(12, 1);
  ms.push(13, 1);
  ms.push(14, 1);
  EXPECT_NO_THROW(ms.get(0));
}

TEST(TMultiStack, can_get_existing_element)
{
  TMultiStack<int> ms(9, 3);
  ms.push(11, 0);
  ms.push(12, 1);
  ms.push(13, 1);
  ms.push(14, 1);
  EXPECT_EQ(14,ms.get(1));
}

TEST(TMultiStack, can_push_if_pushing_stack_is_full_but_freeSize_is_still)
{
  TMultiStack<int> ms(4,2);
  ms.push(10,1);
  ms.push(11, 1);
  EXPECT_NO_THROW(ms.push(12,1));
}

TEST(TMultiStack, can_push_if_free_size_of_ms_is_empty)
{
  TMultiStack<int> ms(2, 2);
  ms.push(10, 1);
  ms.push(11, 1);
  EXPECT_ANY_THROW(ms.push(10,0));
}


TEST(TMultiStack, true_push_if_pushing_stack_is_full_but_freeSize_is_still)
{
  TMultiStack<int> ms(4, 2);
  ms.push(10, 1);
  ms.push(11, 1);
  ms.push(12, 1);
  ms.push(1, 0);
  EXPECT_EQ(ms.get(1), 12);
}

TEST(TMultiStack, can_get_ms_size)
{
  TMultiStack<int> ms(10,3);
  EXPECT_NO_THROW(ms.getSize());
}

TEST(TMultiStack, true_get_ms_size)
{
  TMultiStack<int> ms(10, 3);
  EXPECT_EQ(10, ms.getSize());
}

TEST(TMultiStack, can_get_min_size_of_stacks)
{
  TMultiStack<int> ms(10, 3);
  EXPECT_NO_THROW(ms.getMinSize());
}

TEST(TMultiStack, true_get_ms_min_size_of_stacks)
{
  TMultiStack<int> ms(10, 3);
  EXPECT_EQ(3, ms.getMinSize());
}

TEST(TMultiStack, true_get_ms_min_size_of_stacks_1)
{
  TMultiStack<int> ms(10, 5);
  ms.push(1, 3);
  ms.push(2, 3);
  ms.push(2, 3);
  ms.push(2, 3);
  EXPECT_EQ(1, ms.getMinSize());
}


TEST(TMultiStack, return_empty_if_stack_is_empty)
{
  TMultiStack<int> ms(4,2);
  ms.push(2,1);
  ms.get(1);
  EXPECT_EQ(true, ms.isEmpty(1));
}

TEST(TMultiStack, return_Full_if_stack_is_full)
{
  TMultiStack<int> ms(4, 2);
  ms.push(2, 1);
  ms.push(2, 1);
  EXPECT_EQ(true, ms.isFull(1));
}

TEST(TMultiStack, true_assign_with_no_exc_and_mstacks_is_equal)
{
  TMultiStack<int> ms(9, 3);
  ms.push(11, 0);
  ms.push(12, 1);
  ms.push(13, 1);
  ms.push(14, 1);
  TMultiStack<int> ms1(1, 1);
  ms1 = ms;
  ms.get(1);
  ms.get(1);
  ms1.get(1);
  EXPECT_EQ(ms1.get(1), 13);
}