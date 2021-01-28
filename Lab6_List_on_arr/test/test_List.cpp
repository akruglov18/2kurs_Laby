#include<gtest.h>
#include<ArrayList.h>

TEST(TArrayList, can_create_list) 
{
  ASSERT_NO_THROW(TArrayList<int>(3));
}

TEST(TArrayList, can_create_list_with_negative_size)
{
  ASSERT_ANY_THROW(TArrayList<int>(-3));
}

TEST(TArrayList, can_set_get_element_0) {
  TArrayList<int> l(5);
  l.insLast(1);
  l.insLast(2);
  l.insLast(3);
  EXPECT_EQ(l.getFirst(),1);
}

TEST(TArrayList, can_set_get_element_1) 
{
  TArrayList<int> l(5);
  l.insLast(1);
  l.insLast(2);
  l.insLast(3);
  EXPECT_EQ(l.getLast(), 3);
}

TEST(TArrayList, can_set_get_element_2) {
  TArrayList<int> l(5);
  l.insFirst(1);
  l.insFirst(2);
  l.insFirst(3);
  EXPECT_EQ(l.getFirst(), 3);
}

TEST(TArrayList, can_set_get_element_3)
{
  TArrayList<int> l(5);
  l.insFirst(1);
  l.insFirst(2);
  l.insFirst(3);
  EXPECT_EQ(l.getLast(), 1);
}

TEST(TArrayList, can_get_after_delete_0)
{
  TArrayList<int> l(5);
  l.insFirst(1);
  l.insFirst(2);
  l.insFirst(3);
  l.insFirst(4);
  l.delLast();
  EXPECT_EQ(l.getLast(), 2);
}


TEST(TArrayList, can_get_after_delete_1)
{
  TArrayList<int> l(5);
  l.insFirst(1);
  l.insFirst(2);
  l.insFirst(3);
  l.insFirst(4);
  l.delFirst();
  EXPECT_EQ(l.getFirst(), 3);
}

TEST(TArrayList, can_get_after_delete_2)
{
  TArrayList<int> l(5);
  l.insLast(1);
  l.insLast(2);
  l.insLast(3);
  l.insLast(4);
  l.delLast();
  EXPECT_EQ(l.getLast(), 3);
}


TEST(TArrayList, can_get_after_delete_3)
{
  TArrayList<int> l(5);
  l.insLast(1);
  l.insLast(2);
  l.insLast(3);
  l.insLast(4);
  l.delFirst();
  EXPECT_EQ(l.getFirst(), 2);
}

TEST(TArrayList, can_set_get_after_delete_0)
{
  TArrayList<int> l(5);
  l.insFirst(1);
  l.insFirst(2);
  l.insFirst(3);
  l.delFirst();
  l.insFirst(4);
  EXPECT_EQ(l.getFirst(), 4);
}

TEST(TArrayList, can_set_get_after_delete_1)
{
  TArrayList<int> l(5);
  l.insFirst(1);
  l.insFirst(2);
  l.insFirst(3);
  l.delLast();
  l.insLast(4);
  EXPECT_EQ(l.getLast(), 4);
}

TEST(TArrayList, can_set_get_after_delete_2)
{
  TArrayList<int> l(5);
  l.insFirst(1);
  l.insFirst(2);
  l.insFirst(3);
  l.delLast();
  l.insFirst(4);
  EXPECT_EQ(l.getLast(), 2);
}

TEST(TArrayList, can_set_get_after_delete_3)
{
  TArrayList<int> l(5);
  l.insFirst(1);
  l.insFirst(2);
  l.insFirst(3);
  l.delFirst();
  l.insLast(4);
  EXPECT_EQ(l.getFirst(), 2);
}

TEST(TArrayList, can_set_get_after_delete_4)
{
  TArrayList<int> l(5);
  l.insLast(1);
  l.insLast(2);
  l.insLast(3);
  l.delFirst();
  l.insFirst(4);
  EXPECT_EQ(l.getFirst(), 4);
}

TEST(TArrayList, can_set_get_after_delete_5)
{
  TArrayList<int> l(5);
  l.insLast(1);
  l.insLast(2);
  l.insLast(3);
  l.delLast();
  l.insLast(4);
  EXPECT_EQ(l.getLast(), 4);
}

TEST(TArrayList, can_set_get_after_delete_6)
{
  TArrayList<int> l(5);
  l.insLast(1);
  l.insLast(2);
  l.insLast(3);
  l.delLast();
  l.insFirst(4);
  EXPECT_EQ(l.getLast(), 2);
}

TEST(TArrayList, can_set_get_after_delete_7)
{
  TArrayList<int> l(5);
  l.insLast(1);
  l.insLast(2);
  l.insLast(3);
  l.delFirst();
  l.insLast(4);
  EXPECT_EQ(l.getFirst(), 2);
}

TEST(TArrayList, can_ins_element_out_of_range) {
  TArrayList<int> l(2);
  l.insFirst(1);
  l.insFirst(2);
  EXPECT_ANY_THROW(l.insFirst(2));
}

TEST(TArrayList, can_get_when_empty_0) {
  TArrayList<int> l(2);
  EXPECT_ANY_THROW(l.getFirst());
}

TEST(TArrayList, can_get_when_empty_1) {
  TArrayList<int> l(2);
  EXPECT_ANY_THROW(l.getLast());
}

TEST(TArrayList, copied_list_is_equal_to_source_0) {
  TArrayList<int> l1(4);
  l1.insFirst(1);
  l1.insLast(3);
  l1.insFirst(5);
  TArrayList<int> l2(l1);
  EXPECT_EQ(l2.getLast(),3);
}

TEST(TArrayList, copied_list_is_equal_to_source_1) {
  TArrayList<int> l1(4);
  l1.insFirst(1);
  l1.insLast(3);
  l1.insFirst(5);
  TArrayList<int> l2(l1);
  EXPECT_EQ(l2.getFirst(), 5);
}

TEST(TArrayList, assign_list_is_equal_to_source_0) {
  TArrayList<int> l1(4);
  l1.insFirst(1);
  l1.insLast(3);
  l1.insFirst(5);
  TArrayList<int> l2;
  l2 = l1;
  EXPECT_EQ(l2.getLast(), 3);
}

TEST(TArrayList, assign_list_is_equal_to_source_1) {
  TArrayList<int> l1(4);
  l1.insFirst(1);
  l1.insLast(3);
  l1.insFirst(5);
  TArrayList<int> l2;
  l2 = l1;
  EXPECT_EQ(l2.getFirst(), 5);
}

TEST(TArrayListIterator, iterator_check_insert) {
  TArrayList<int> l1(10);
  l1.insLast(1);
  l1.insLast(3);
  l1.insLast(5);
  l1.insLast(7);
  TArrayListIterator<int> it = l1.begin();
  it.goNext();
  it.goNext();
  l1.insert(it, 20);
  l1.delLast();
  l1.delLast();
  EXPECT_EQ(20, l1.getLast());
}

TEST(TArrayListIterator, iterator_erase_insert) {
  TArrayList<int> l1(10);
  l1.insLast(1);
  l1.insLast(3);
  l1.insLast(5);
  l1.insLast(7);
  TArrayListIterator<int> it = l1.begin();
  it.goNext();
  it.goNext();
  l1.erase(it);
  l1.delLast();
  EXPECT_EQ(3, l1.getLast());
}

TEST(TArrayListIterator, get_k_divisible_0) {
  TArrayList<int> l1(10);
  l1.insLast(3);
  l1.insLast(6);
  l1.insLast(10);
  l1.insLast(11);
  l1.insLast(12);
  TArrayList<int> res;
  res = l1.get_Kdivisible(3);
  EXPECT_EQ(res.getLast(), 12);
}

TEST(TArrayListIterator, get_k_divisible_1) {
  TArrayList<int> l1(10);
  l1.insLast(3);
  l1.insLast(6);
  l1.insLast(10);
  l1.insLast(11);
  l1.insLast(12);
  TArrayList<int> res;
  res = l1.get_Kdivisible(3);
  EXPECT_EQ(res.getFirst(), 3);
}