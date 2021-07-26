#include <gtest.h>
#include "Tree.h"

TEST(Tree, can_insert_0){
  Tree<int, int> s;
  ASSERT_NO_THROW(s.insert(1, 1));
}

TEST(Tree, can_insert_1) {
  Tree<int, int> s;
  s.insert(1, 1);
  ASSERT_NO_THROW(s.insert(6, 6));
}

TEST(Tree, can_find_0) {
  Tree<int, int> s;
  s.insert(1, 1);
  s.insert(6, 6);
  s.insert(3, 3);
  ASSERT_EQ(s.find(3), 3);
}

TEST(Tree, can_find_1) {
  Tree<int, int> s;
  s.insert(1, 1);
  s.insert(6, 6);
  s.insert(3, 3);
  ASSERT_EQ(s.find(1), 1);
}

TEST(Tree, can_find_2) {
  Tree<int, int> s;
  s.insert(1, 1);
  ASSERT_ANY_THROW(s.find(6));
}

TEST(Tree, Indexation_0) {
  Tree<int, int> s;
  s.insert(1, 1);
  s.insert(6, 6);
  s.insert(3, 3);
  ASSERT_EQ(s[3], 4);
}

TEST(Tree, Indexation_1) {
  Tree<int, int> s;
  s.insert(1, 1);
  s.insert(6, 6);
  s.insert(3, 3);
  ASSERT_EQ(s[6], 6);
}

TEST(Tree, Indexation_2) {
  Tree<int, int> s;
  s.insert(1, 1);
  s.insert(6, 6);
  s.insert(3, 3);
  ASSERT_NO_THROW(s[2]);
}

TEST(Tree, Indexation_3) {
  Tree<int, int> s;
  s[1] = 1;
  s[3] = 3;
  s[6] = 6;
  ASSERT_EQ(s[3], 3);
}

TEST(Tree, Indexation_4) {
  Tree<int, int> s;
  s[1] = 1;
  s[3] = 3;
  s[6] = 6;
  ASSERT_EQ(s[6], 6);
}

TEST(Tree, Indexation_5) {
  Tree<int, int> s;
  s[1] = 1;
  s[3] = 3;
  s[6] = 6;
  ASSERT_EQ(s[1], 1);
}

TEST(Tree, Erase_0) {
  Tree<int, int> s;
  s[1] = 1;
  s[3] = 3;
  s.erase(3);
  s[6] = 6;
  ASSERT_ANY_THROW(s.find(3));
}

TEST(Tree, Erase_1) {
  Tree<int, int> s;
  s[1] = 1;
  s[3] = 3;
  s.erase(3);
  s[6] = 6;
  ASSERT_EQ(s[6], 6);
}

TEST(Tree, Erase_2) {
  Tree<int, int> s;
  s[1] = 1;
  s[3] = 3;
  s.erase(3);
  s[6] = 6;
  ASSERT_EQ(s[1], 1);
}

TEST(Tree, Erase_3) {
  Tree<int, int> s;
  s[5] = 5;
  s[3] = 3;
  s[1] = 1;
  s[6] = 6;
  s[10] = 10;
  s[7] = 7;
  s[8] = 8;
  s.erase(3);
  ASSERT_EQ(s[1], 1);
}

TEST(Tree, Erase_4) {
  Tree<int, int> s;
  s[5] = 5;
  s[3] = 3;
  s[1] = 1;
  s[6] = 6;
  s[10] = 10;
  s[7] = 7;
  s[8] = 8;
  s.erase(3);
  ASSERT_EQ(s[5], 5);
}

TEST(Tree, Erase_5) {
  Tree<int, int> s;
  s[5] = 5;
  s[3] = 3;
  s[1] = 1;
  s[6] = 6;
  s[10] = 10;
  s[7] = 7;
  s[8] = 8;
  s.erase(3);
  ASSERT_EQ(s[10], 10);
}

TEST(Tree, Erase_6) {
  Tree<int, int> s;
  s[5] = 5;
  s[3] = 3;
  s[1] = 1;
  s[6] = 6;
  s[10] = 10;
  s[7] = 7;
  s[8] = 8;
  s.erase(3);
  ASSERT_EQ(s[8], 8);
}


TEST(Tree, Erase_7) {
  Tree<int, int> s;
  s[5] = 5;
  s[3] = 3;
  s[1] = 1;
  s[6] = 6;
  s[10] = 10;
  s[7] = 7;
  s[8] = 8;
  s.erase(6);
  ASSERT_EQ(s[1], 1);
}

TEST(Tree, Erase_8) {
  Tree<int, int> s;
  s[5] = 5;
  s[3] = 3;
  s[1] = 1;
  s[6] = 6;
  s[10] = 10;
  s[7] = 7;
  s[8] = 8;
  std::cout << s;
  s.erase(6);
  ASSERT_EQ(s[10], 10);
}

TEST(Tree, Erase_9) {
  Tree<int, int> s;
  s[5] = 5;
  s[3] = 3;
  s[1] = 1;
  s[6] = 6;
  s[10] = 10;
  s[7] = 7;
  s[8] = 8;
  s.erase(6);
  ASSERT_EQ(s[8], 8);
}

TEST(Tree, Erase_10) {
  Tree<int, int> s;
  s[5] = 5;
  std::cout << s << '\n';
  s[3] = 3;
  std::cout << s << '\n';
  s[1] = 1;
  std::cout << s << '\n';
  s[6] = 6;
  std::cout << s << '\n';
  s[10] = 10;
  std::cout << s << '\n';
  s[7] = 7;
  std::cout << s << '\n';
  s[8] = 8;
  s.erase(6);
  std::cout << s << '\n';
  s.erase(3);
  std::cout << s << '\n';
  s.erase(5);
  std::cout << s << '\n';
  s.erase(10);
  std::cout << s << '\n';
  s.erase(7);
  std::cout << s << '\n';
  s.erase(1);
  ASSERT_EQ(s[8], 8);
}