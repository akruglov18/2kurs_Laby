#include <gtest.h>
#include "Map.h"
#include "HashListMap.h"
#include "HashMap.h"


TEST(HashListMap, Add_0) {
  THashListMap<int, char> m;
  ASSERT_NO_THROW(m.Add(3, 'c'));
}

TEST(HashListMap, Add_1) {
  THashListMap<int, char> m;
  m.Add(3, 'c');
  ASSERT_NO_THROW(m.Add(5, 'e'));
}

TEST(HashListMap, Add_2) {
  THashListMap<int, char> m;
  m.Add(3, 'c');
  m.Add(5, 'e');
  ASSERT_NO_THROW(m.Add(1, 'a'));
}

TEST(HashListMap, Find_0) {
  THashListMap<int, char> m;
  m.Add(3, 'c');
  m.Add(5, 'e');
  m.Add(1, 'a');
  ASSERT_EQ(m.Find(5), 'e');
}

TEST(HashListMap, Find_1) {
  THashListMap<int, char> m;
  m.Add(3, 'c');
  m.Add(5, 'e');
  m.Add(1, 'a');
  ASSERT_EQ(m.Find(3), 'c');
}

TEST(HashListMap, Find_2) {
  THashListMap<int, char> m;
  m.Add(3, 'c');
  m.Add(5, 'e');
  m.Add(1, 'a');
  ASSERT_ANY_THROW(m.Find(6));
}


TEST(HashListMap, Indexation_0) {
  THashListMap<int, char> m;
  m.Add(3, 'c');
  m.Add(5, 'e');
  m.Add(1, 'a');
  ASSERT_EQ(m[5], 'e');
}

TEST(HashListMap, Indexation_1) {
  THashListMap<int, char> m;
  m.Add(3, 'c');
  m.Add(5, 'e');
  m.Add(1, 'a');
  ASSERT_EQ(m[3], 'c');
}

TEST(HashListMap, Indexation_2) {
  THashListMap<int, char> m;
  m.Add(3, 'c');
  m.Add(5, 'e');
  m.Add(1, 'a');
  ASSERT_NO_THROW(m[6] = 'f');
}

TEST(HashListMap, Indexation_3) {
  THashListMap<int, char> m;
  m[3] = 'c';
  m[5] = 'e';
  m[1] = 'a';
  ASSERT_EQ(m[5], 'e');
}

TEST(HashListMap, Indexation_4) {
  THashListMap<int, char> m;
  m[3] = 'c';
  m[5] = 'e';
  m[1] = 'a';
  ASSERT_EQ(m[3], 'c');
}

TEST(HashListMap, Indexation_5) {
  THashListMap<int, char> m;
  m[3] = 'c';
  m[5] = 'e';
  m[1] = 'a';
  ASSERT_NO_THROW(m[6] = 'f');
}

TEST(HashListMap, Delete_0) {
  THashListMap<int, char> m;
  m[3] = 'c';
  m[5] = 'e';
  m.Delete(5);
  m[1] = 'a';
  ASSERT_ANY_THROW(m.Find(5));
}

TEST(HashListMap, Delete_1) {
  THashListMap<int, char> m;
  m[3] = 'c';
  m[5] = 'e';
  m[1] = 'a';
  m.Delete(3);
  ASSERT_EQ(m[5], 'e');
}

TEST(HashListMap, Delete_2) {
  THashListMap<int, char> m;
  m[3] = 'c';
  m[5] = 'e';
  m[1] = 'a';
  m.Delete(1);
  ASSERT_EQ(m[5], 'e');
}

TEST(HashListMap, Delete_3) {
  THashListMap<int, char> m;
  m[3] = 'c';
  m[5] = 'e';
  m[1] = 'a';
  m.Delete(1);
  m.Delete(3);
  ASSERT_EQ(m[5], 'e');
}

TEST(HashMap, Add_0) {
  THashMap<int, char> m;
  ASSERT_NO_THROW(m.Add(3, 'c'));
}

TEST(HashMap, Add_1) {
  THashMap<int, char> m;
  m.Add(3, 'c');
  ASSERT_NO_THROW(m.Add(5, 'e'));
}

TEST(HashMap, Add_2) {
  THashMap<int, char> m;
  m.Add(3, 'c');
  m.Add(5, 'e');
  ASSERT_NO_THROW(m.Add(1, 'a'));
}

TEST(HashMap, Find_0) {
  THashMap<int, char> m;
  m.Add(3, 'c');
  m.Add(5, 'e');
  m.Add(1, 'a');
  ASSERT_EQ(m.Find(5), 'e');
}

TEST(HashMap, Find_1) {
  THashMap<int, char> m;
  m.Add(3, 'c');
  m.Add(5, 'e');
  m.Add(1, 'a');
  ASSERT_EQ(m.Find(3), 'c');
}

TEST(HashMap, Find_2) {
  THashMap<int, char> m;
  m.Add(3, 'c');
  m.Add(5, 'e');
  m.Add(1, 'a');
  ASSERT_ANY_THROW(m.Find(6));
}


TEST(HashMap, Indexation_0) {
  THashMap<int, char> m;
  m.Add(3, 'c');
  m.Add(5, 'e');
  m.Add(1, 'a');
  ASSERT_EQ(m[5], 'e');
}

TEST(HashMap, Indexation_1) {
  THashMap<int, char> m;
  m.Add(3, 'c');
  m.Add(5, 'e');
  m.Add(1, 'a');
  ASSERT_EQ(m[3], 'c');
}

TEST(HashMap, Indexation_2) {
  THashMap<int, char> m;
  m.Add(3, 'c');
  m.Add(5, 'e');
  m.Add(1, 'a');
  ASSERT_NO_THROW(m[6] = 'f');
}

TEST(HashMap, Indexation_3) {
  THashMap<int, char> m;
  m[3] = 'c';
  m[5] = 'e';
  m[1] = 'a';
  ASSERT_EQ(m[5], 'e');
}

TEST(HashMap, Indexation_4) {
  THashMap<int, char> m;
  m[3] = 'c';
  m[5] = 'e';
  m[1] = 'a';
  ASSERT_EQ(m[3], 'c');
}

TEST(HashMap, Indexation_5) {
  THashMap<int, char> m;
  m[3] = 'c';
  m[5] = 'e';
  m[1] = 'a';
  ASSERT_NO_THROW(m[6] = 'f');
}

TEST(HashMap, Delete_0) {
  THashMap<int, char> m;
  m[3] = 'c';
  m[5] = 'e';
  m.Delete(5);
  m[1] = 'a';
  ASSERT_ANY_THROW(m.Find(5));
}

TEST(HashMap, Delete_1) {
  THashMap<int, char> m;
  m[3] = 'c';
  m[5] = 'e';
  m[1] = 'a';
  m.Delete(3);
  ASSERT_EQ(m[5], 'e');
}

TEST(HashMap, Delete_2) {
  THashMap<int, char> m;
  m[3] = 'c';
  m[5] = 'e';
  m[1] = 'a';
  m.Delete(1);
  ASSERT_EQ(m[5], 'e');
}

TEST(HashMap, Delete_3) {
  THashMap<int, char> m;
  m[3] = 'c';
  m[5] = 'e';
  m[1] = 'a';
  m.Delete(1);
  m.Delete(3);
  ASSERT_EQ(m[5], 'e');
}