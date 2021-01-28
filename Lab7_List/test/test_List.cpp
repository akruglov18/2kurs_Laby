#include<gtest.h>
#include"List.h"

TEST(TList, can_set_get_element_0) {
  TList<int> l;
  l.insLast(1);
  l.insLast(2);
  l.insLast(3);
  EXPECT_EQ(l.getFirst()->getData(),1);
}

TEST(TList, can_set_get_element_1) 
{
  TList<int> l;
  l.insLast(1);
  l.insLast(2);
  l.insLast(3);
  EXPECT_EQ(l.getLast()->getData(), 3);
}

TEST(TList, can_set_get_element_2) {
  TList<int> l;
  l.insFirst(1);
  l.insFirst(2);
  l.insFirst(3);
  EXPECT_EQ(l.getFirst()->getData(), 3);
}

TEST(TList, can_set_get_element_3)
{
  TList<int> l;
  l.insFirst(1);
  l.insFirst(2);
  l.insFirst(3);
  EXPECT_EQ(l.getLast()->getData(), 1);
}

TEST(TList, can_get_after_delete_0)
{
  TList<int> l;
  l.insFirst(1);
  l.insFirst(2);
  l.insFirst(3);
  l.insFirst(4);
  l.delLast();
  EXPECT_EQ(l.getLast()->getData(), 2);
}


TEST(TList, can_get_after_delete_1)
{
  TList<int> l;
  l.insFirst(1);
  l.insFirst(2);
  l.insFirst(3);
  l.insFirst(4);
  l.delFirst();
  EXPECT_EQ(l.getFirst()->getData(), 3);
}

TEST(TList, can_get_after_delete_2)
{
  TList<int> l;
  l.insLast(1);
  l.insLast(2);
  l.insLast(3);
  l.insLast(4);
  l.delLast();
  EXPECT_EQ(l.getLast()->getData(), 3);
}


TEST(TList, can_get_after_delete_3)
{
  TList<int> l;
  l.insLast(1);
  l.insLast(2);
  l.insLast(3);
  l.insLast(4);
  l.delFirst();
  EXPECT_EQ(l.getFirst()->getData(), 2);
}

TEST(TList, can_set_get_after_delete_0)
{
  TList<int> l;
  l.insFirst(1);
  l.insFirst(2);
  l.insFirst(3);
  l.delFirst();
  l.insFirst(4);
  EXPECT_EQ(l.getFirst()->getData(), 4);
}

TEST(TList, can_set_get_after_delete_1)
{
  TList<int> l;
  l.insFirst(1);
  l.insFirst(2);
  l.insFirst(3);
  l.delLast();
  l.insLast(4);
  EXPECT_EQ(l.getLast()->getData(), 4);
}

TEST(TList, can_set_get_after_delete_2)
{
  TList<int> l;
  l.insFirst(1);
  l.insFirst(2);
  l.insFirst(3);
  l.delLast();
  l.insFirst(4);
  EXPECT_EQ(l.getLast()->getData(), 2);
}

TEST(TList, can_set_get_after_delete_3)
{
  TList<int> l;
  l.insFirst(1);
  l.insFirst(2);
  l.insFirst(3);
  l.delFirst();
  l.insLast(4);
  EXPECT_EQ(l.getFirst()->getData(), 2);
}

TEST(TList, can_set_get_after_delete_4)
{
  TList<int> l;
  l.insLast(1);
  l.insLast(2);
  l.insLast(3);
  l.delFirst();
  l.insFirst(4);
  EXPECT_EQ(l.getFirst()->getData(), 4);
}

TEST(TList, can_set_get_after_delete_5)
{
  TList<int> l;
  l.insLast(1);
  l.insLast(2);
  l.insLast(3);
  l.delLast();
  l.insLast(4);
  EXPECT_EQ(l.getLast()->getData(), 4);
}

TEST(TList, can_set_get_after_delete_6)
{
  TList<int> l;
  l.insLast(1);
  l.insLast(2);
  l.insLast(3);
  l.delLast();
  l.insFirst(4);
  EXPECT_EQ(l.getLast()->getData(), 2);
}

TEST(TList, can_set_get_after_delete_7)
{
  TList<int> l;
  l.insLast(1);
  l.insLast(2);
  l.insLast(3);
  l.delFirst();
  l.insLast(4);
  EXPECT_EQ(l.getFirst()->getData(), 2);
}

TEST(TList, copied_list_is_equal_to_source_0) {
  TList<int> l1;
  l1.insFirst(1);
  l1.insLast(3);
  l1.insFirst(5);
  TList<int> l2(l1);
  EXPECT_EQ(l2.getLast()->getData(),3);
}

TEST(TList, copied_list_is_equal_to_source_1) {
  TList<int> l1;
  l1.insFirst(1);
  l1.insLast(3);
  l1.insFirst(5);
  TList<int> l2(l1);
  EXPECT_EQ(l2.getFirst()->getData(), 5);
}

TEST(TList, assign_list_is_equal_to_source_0) {
  TList<int> l1;
  l1.insFirst(1);
  l1.insLast(3);
  l1.insFirst(5);
  TList<int> l2;
  l2 = l1;
  EXPECT_EQ(l2.getLast()->getData(), 3);
}

TEST(TList, assign_list_is_equal_to_source_1) {
  TList<int> l1;
  l1.insFirst(1);
  l1.insLast(3);
  l1.insFirst(5);
  TList<int> l2;
  l2 = l1;
  EXPECT_EQ(l2.getFirst()->getData(), 5);
}

TEST(TListIterator, iterator_check_insert) {
  TList<int> l1;
  l1.insLast(1);
  l1.insLast(3);
  l1.insLast(5);
  l1.insLast(7);
  TListIterator<int> it = l1.begin();
  it.goNext();
  it.goNext();
  l1.insert(it, 20);
  l1.delLast();
  l1.delLast();
  EXPECT_EQ(5, l1.getLast()->getData());
}

TEST(TListIterator, iterator_erase_insert) {
  TList<int> l1;
  l1.insLast(1);
  l1.insLast(3);
  l1.insLast(5);
  l1.insLast(7);
  TListIterator<int> it = l1.begin();
  it.goNext();
  it.goNext();
  l1.erase(it);
  l1.delLast();
  EXPECT_EQ(3, l1.getLast()->getData());
}

TEST(TListIterator, get_k_divisible_0) {
  TList<int> l1;
  l1.insLast(3);
  l1.insLast(6);
  l1.insLast(10);
  l1.insLast(11);
  l1.insLast(12);
  TList<int> res;
  res = l1.get_Kdivisible(3);
  EXPECT_EQ(res.getLast()->getData(), 12);
}

TEST(TListIterator, get_k_divisible_1) {
  TList<int> l1;
  l1.insLast(3);
  l1.insLast(6);
  l1.insLast(10);
  l1.insLast(11);
  l1.insLast(12);
  TList<int> res;
  res = l1.get_Kdivisible(3);
  EXPECT_EQ(res.getFirst()->getData(), 3);
}