#include <gtest.h>
#include "TQueue.h"

TEST(TQueue, can_create_queue_of_size_10)
{
  EXPECT_NO_THROW(TQueue<int> q(10));
}

TEST(TQueue, can_create_queue_of_size_0)
{
  EXPECT_ANY_THROW(TQueue<int> q(0));
}

TEST(TQueue, can_create_copy_of_queue)
{
  TQueue<int> q(1);
  EXPECT_NO_THROW(TQueue<int> queue(q));
}

TEST(TQueue, can_create_copy_of_stack_and_stacks_are_equal)
{
  TQueue<int> queue(1);
  queue.push(2);
  TQueue<int> q(queue);
  EXPECT_EQ(queue.get(), q.get());
}

TEST(TQueue, can_push_if_full)
{
  TQueue<int> q(1);
  q.push(1);
  EXPECT_NO_THROW(q.push(2));
}

TEST(TQueue, can_push_if_is_not_full)
{
  TQueue<int> q(1);
  EXPECT_NO_THROW(q.push(2));
}

TEST(TQueue, can_get_element_if_empty)
{
  TQueue<int> q(1);
  q.push(1);
  q.get();
  EXPECT_ANY_THROW(q.get());
}

TEST(TQueue, can_get_element_if_is_not_empty)
{
  TQueue<int> s(1);
  s.push(1);
  EXPECT_NO_THROW(s.get());
}

TEST(TQueue, can_get_existing_element)
{
  TQueue<int> q(3);
  q.push(1);
  q.push(5);
  q.push(2);
  q.get();
  EXPECT_EQ(5, q.get());
}

TEST(TQueue, can_get_max_element)
{
  TQueue<int> q(10);
  for (int i = 0; i < 10; i++)
    q.push(i);
  q.get();
  EXPECT_EQ(9, q.getMax());
}

TEST(TQueue, can_get_min_element)
{
  TQueue<int> q(10);
  for (int i = 0; i < 10; i++)
    q.push(10 - i);
  q.get();
  EXPECT_EQ(1, q.getMin());
}

TEST(TQueue, return_empty_if_queue_is_empty)
{
  TQueue<int> s(2);
  s.push(2);
  s.push(2);
  s.get();
  s.get();

  EXPECT_EQ(true, s.isEmpty());
}

TEST(TQueue, return_right_elem_if_queue_is_full)
{
  TQueue<int> q(10);
  for (int i = 0; i < 15; i++)
    q.push(i);
  EXPECT_EQ(5, q.get());
}

TEST(TQueue, return_empty_if_queue_is_not_empty)
{
  TQueue<int> s(2);
  s.push(2);
  s.push(2);
  s.get();

  EXPECT_EQ(false, s.isEmpty());
}

TEST(TQueue, can_assign_with_no_exc)
{
  TQueue<int> queue(1);
  queue.push(2);
  TQueue<int> q(2);
  EXPECT_NO_THROW(q = queue);
}

TEST(TQueue, can_assign_with_equal_element)
{
  TQueue<int> queue(1);
  queue.push(2);
  TQueue<int> q = queue;
  EXPECT_EQ(q.get(), queue.get());
}