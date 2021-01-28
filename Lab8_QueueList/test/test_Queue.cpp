#include <gtest.h>
#include<QueueList.h>

TEST(QueueList, can_create_queue_of_size_10)
{
  EXPECT_NO_THROW(QueueList<int> q);
}

TEST(QueueList, can_create_copy_of_queue)
{
  QueueList<int> q;
  EXPECT_NO_THROW(QueueList<int> queue(q));
}

TEST(QueueList, can_create_copy_of_stack_and_stacks_are_equal)
{
  QueueList<int> queue;
  queue.push(2);
  QueueList<int> q(queue);
  EXPECT_EQ(queue.get(), q.get());
}

TEST(QueueList, can_push_if_full)
{
  QueueList<int> q;
  q.push(1);
  EXPECT_NO_THROW(q.push(2));
}

TEST(QueueList, can_push_if_is_not_full)
{
  QueueList<int> q;
  EXPECT_NO_THROW(q.push(2));
}

TEST(QueueList, can_get_element_if_empty)
{
  QueueList<int> q;
  q.push(1);
  q.get();
  EXPECT_ANY_THROW(q.get());
}

TEST(QueueList, can_get_element_if_is_not_empty)
{
  QueueList<int> s;
  s.push(1);
  EXPECT_NO_THROW(s.get());
}

TEST(QueueList, can_get_existing_element)
{
  QueueList<int> q;
  q.push(1);
  q.push(5);
  q.push(2);
  q.get();
  EXPECT_EQ(5, q.get());
}

TEST(QueueList, can_get_max_element)
{
  QueueList<int> q;
  for (int i = 0; i < 10; i++)
    q.push(i);
  q.get();
  EXPECT_EQ(9, q.getMax());
}

TEST(QueueList, can_get_min_element)
{
  QueueList<int> q;
  for (int i = 0; i < 10; i++)
    q.push(10 - i);
  q.get();
  EXPECT_EQ(1, q.getMin());
}

TEST(QueueList, return_empty_if_queue_is_empty)
{
  QueueList<int> s;
  s.push(2);
  s.push(2);
  s.get();
  s.get();

  EXPECT_EQ(true, s.isEmpty());
}

TEST(QueueList, return_empty_if_queue_is_not_empty)
{
  QueueList<int> s;
  s.push(2);
  s.push(2);
  s.get();

  EXPECT_EQ(false, s.isEmpty());
}

TEST(QueueList, can_assign_with_no_exc)
{
  QueueList<int> queue;
  queue.push(2);
  QueueList<int> q;
  EXPECT_NO_THROW(q = queue);
}

TEST(QueueList, can_assign_with_equal_element_0)
{
  QueueList<int> queue;
  queue.push(2);
  QueueList<int> q = queue;
  EXPECT_EQ(q.get(), queue.get());
}

TEST(QueueList, can_assign_with_equal_element_1)
{
  QueueList<int> queue;
  queue.push(2);
  queue.push(3);
  queue.push(4);
  QueueList<int> q = queue;
  EXPECT_EQ(q.get(), queue.get());
}

TEST(QueueList, can_assign_with_equal_element_2)
{
  QueueList<int> queue;
  queue.push(2);
  queue.push(3);
  queue.push(4);
  queue.push(5);
  queue.get();
  QueueList<int> q = queue;
  EXPECT_EQ(q.get(), queue.get());
}
