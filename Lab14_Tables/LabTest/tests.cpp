#include <gtest.h>
#include "SortMap.h"
#include "Map.h"
#include "Sorts.h"

TEST(TMap, Add_0) {
  TMap<int, char> m;
  ASSERT_NO_THROW(m.Add(3, 'c'));
}

TEST(TMap, Add_1) {
  TMap<int, char> m;
  m.Add(3, 'c');
  ASSERT_NO_THROW(m.Add(5, 'e'));
}

TEST(TMap, Add_2) {
  TMap<int, char> m;
  m.Add(3, 'c');
  m.Add(5, 'e');
  ASSERT_NO_THROW(m.Add(1, 'a'));
}

TEST(TMap, Find_0) {
  TMap<int, char> m;
  m.Add(3, 'c');
  m.Add(5, 'e');
  m.Add(1, 'a');
  ASSERT_EQ(m.Find(5), 'e');
}

TEST(TMap, Find_1) {
  TMap<int, char> m;
  m.Add(3, 'c');
  m.Add(5, 'e');
  m.Add(1, 'a');
  ASSERT_EQ(m.Find(3), 'c');
}

TEST(TMap, Find_2) {
  TMap<int, char> m;
  m.Add(3, 'c');
  m.Add(5, 'e');
  m.Add(1, 'a');
  ASSERT_ANY_THROW(m.Find(6));
}


TEST(TMap, Indexation_0) {
  TMap<int, char> m;
  m.Add(3, 'c');
  m.Add(5, 'e');
  m.Add(1, 'a');
  ASSERT_EQ(m[5], 'e');
}

TEST(TMap, Indexation_1) {
  TMap<int, char> m;
  m.Add(3, 'c');
  m.Add(5, 'e');
  m.Add(1, 'a');
  ASSERT_EQ(m[3], 'c');
}

TEST(TMap, Indexation_2) {
  TMap<int, char> m;
  m.Add(3, 'c');
  m.Add(5, 'e');
  m.Add(1, 'a');
  ASSERT_NO_THROW(m[6] = 'f');
}

TEST(TMap, Indexation_3) {
  TMap<int, char> m;
  m[3] = 'c';
  m[5] = 'e';
  m[1] = 'a';
  ASSERT_EQ(m[5], 'e');
}

TEST(TMap, Indexation_4) {
  TMap<int, char> m;
  m[3] = 'c';
  m[5] = 'e';
  m[1] = 'a';
  ASSERT_EQ(m[3], 'c');
}

TEST(TMap, Indexation_5) {
  TMap<int, char> m;
  m[3] = 'c';
  m[5] = 'e';
  m[1] = 'a';
  ASSERT_NO_THROW(m[6] = 'f');
}

TEST(TMap, Delete_0) {
  TMap<int, char> m;
  m[3] = 'c';
  m[5] = 'e';
  m.Delete(5);
  m[1] = 'a';
  ASSERT_ANY_THROW(m.Find(5));
}

TEST(TMap, Delete_1) {
  TMap<int, char> m;
  m[3] = 'c';
  m[5] = 'e';
  m[1] = 'a';
  m.Delete(3);
  ASSERT_EQ(m[5], 'e');
}

TEST(TMap, Delete_2) {
  TMap<int, char> m;
  m[3] = 'c';
  m[5] = 'e';
  m[1] = 'a';
  m.Delete(1);
  ASSERT_EQ(m[5], 'e');
}

TEST(TMap, Delete_3) {
  TMap<int, char> m;
  m[3] = 'c';
  m[5] = 'e';
  m[1] = 'a';
  m.Delete(1);
  m.Delete(3);
  ASSERT_EQ(m[5], 'e');
}

//----------------------------TESTING SORT MAP--------------------------------------

TEST(TSortMap, Add_0) {
  TSortMap<int, char> m;
  ASSERT_NO_THROW(m.Add(3, 'c'));
}

TEST(TSortMap, Add_1) {
  TSortMap<int, char> m;
  m.Add(3, 'c');
  ASSERT_NO_THROW(m.Add(5, 'e'));
}

TEST(TSortMap, Add_2) {
  TSortMap<int, char> m;
  m.Add(3, 'c');
  m.Add(5, 'e');
  ASSERT_NO_THROW(m.Add(1, 'a'));
}

TEST(TSortMap, Find_0) {
  TSortMap<int, char> m;
  m.Add(3, 'c');
  m.Add(5, 'e');
  m.Add(1, 'a');
  ASSERT_EQ(m.Find(5), 'e');
}

TEST(TSortMap, Find_1) {
  TSortMap<int, char> m;
  m.Add(3, 'c');
  m.Add(5, 'e');
  m.Add(1, 'a');
  ASSERT_EQ(m.Find(3), 'c');
}

TEST(TSortMap, Find_2) {
  TSortMap<int, char> m;
  m.Add(3, 'c');
  m.Add(5, 'e');
  m.Add(1, 'a');
  ASSERT_ANY_THROW(m.Find(6));
}


TEST(TSortMap, Indexation_0) {
  TSortMap<int, char> m;
  m.Add(3, 'c');
  m.Add(5, 'e');
  m.Add(1, 'a');
  ASSERT_EQ(m[5], 'e');
}

TEST(TSortMap, Indexation_1) {
  TSortMap<int, char> m;
  m.Add(3, 'c');
  m.Add(5, 'e');
  m.Add(1, 'a');
  ASSERT_EQ(m[3], 'c');
}

TEST(TSortMap, Indexation_2) {
  TSortMap<int, char> m;
  m.Add(3, 'c');
  m.Add(5, 'e');
  m.Add(1, 'a');
  ASSERT_NO_THROW(m[6] = 'f');
}

TEST(TSortMap, Indexation_3) {
  TSortMap<int, char> m;
  m[3] = 'c';
  m[5] = 'e';
  m[1] = 'a';
  ASSERT_EQ(m[5], 'e');
}

TEST(TSortMap, Indexation_4) {
  TSortMap<int, char> m;
  m[3] = 'c';
  m[5] = 'e';
  m[1] = 'a';
  ASSERT_EQ(m[3], 'c');
}

TEST(TSortMap, Indexation_5) {
  TSortMap<int, char> m;
  m[3] = 'c';
  m[5] = 'e';
  m[1] = 'a';
  ASSERT_NO_THROW(m[6] = 'f');
}

TEST(TSortMap, Delete_0) {
  TSortMap<int, char> m;
  m[3] = 'c';
  m[5] = 'e';
  m.Delete(5);
  m[1] = 'a';
  ASSERT_ANY_THROW(m.Find(5));
}

TEST(TSortMap, Delete_1) {
  TSortMap<int, char> m;
  m[3] = 'c';
  m[5] = 'e';
  m[1] = 'a';
  m.Delete(3);
  ASSERT_EQ(m[5], 'e');
}

TEST(TSortMap, Delete_2) {
  TSortMap<int, char> m;
  m[3] = 'c';
  m[5] = 'e';
  m[1] = 'a';
  m.Delete(1);
  ASSERT_EQ(m[5], 'e');
}

TEST(TSortMap, Delete_3) {
  TSortMap<int, char> m;
  m[3] = 'c';
  m[5] = 'e';
  m[1] = 'a';
  m.Delete(1);
  m.Delete(3);
  ASSERT_EQ(m[5], 'e');
}

TEST(TSortMap, Is_Sorted_0) {
  TSortMap<int, char> m;
  m.Add(3, 'c');
  m.Add(5, 'e');
  m.Add(1, 'a');
  m.Add(10, 'g');
  m.Add(7, 'r');
  char a[5] = { 'a','c','e','r','g' };
  bool ok = true;
  int i = 0;
  TIterSortMap<int, char> it = m.begin();
  for (it; it != m.end(); ++it, i++) {
    if (*it != a[i]) {
      ok = false;
    }
  }
  ASSERT_TRUE(ok);
}

TEST(TSortMap, Is_Sorted_1) {
  TSortMap<int, char> m;
  m.Add(3, 'c');
  m.Add(5, 'e');
  m.Add(1, 'a');
  m.Add(10, 'g');
  m.Add(7, 'r');
  m.Add(11, 'f');
  m.Add(12, 'h');
  char a[7] = { 'a','c','e','r','g', 'f', 'h' };
  bool ok = true;
  int i = 0;
  TIterSortMap<int, char> it = m.begin();
  for (it; it != m.end(); ++it, i++) {
    if (*it != a[i]) {
      ok = false;
    }
  }
  ASSERT_TRUE(ok);
}

TEST(TSortMap, Is_Sorted_with_sort_function_0) {
  char a[7] = { 'c','e','a','g','r','f','h' };
  int b[7] = { 3,5,1,10,7,11,12 };
  TNode<int,char> n[7];
  for (int i = 0; i < 7; i++) {
    n[i] = TNode<int,char>(b[i], a[i]);
  }
  TSortMap<int, char> m(7, n, MapSorts::bubble_sort);
  char c[7] = { 'a','c','e','r','g', 'f', 'h' };
  bool ok = true;
  int i = 0;
  TIterSortMap<int, char> it = m.begin();
  for (it; it != m.end(); ++it, i++) {
    if (*it != c[i]) {
      ok = false;
    }
  }
  ASSERT_TRUE(ok);
}

TEST(TSortMap, Is_Sorted_with_sort_function_1) {
  char a[7] = { 'c','e','a','g','r','f','h' };
  int b[7] = { 3,5,1,10,7,11,12 };
  TNode<int, char> n[7];
  for (int i = 0; i < 7; i++) {
    n[i] = TNode<int, char>(b[i], a[i]);
  }
  TSortMap<int, char> m(7, n, MapSorts::counting_sort);
  char c[7] = { 'a','c','e','r','g', 'f', 'h' };
  bool ok = true;
  int i = 0;
  TIterSortMap<int, char> it = m.begin();
  for (it; it != m.end(); ++it, i++) {
    if (*it != c[i]) {
      ok = false;
    }
  }
  ASSERT_TRUE(ok);
}

TEST(TSortMap, Is_Sorted_with_sort_function_2) {
  char a[7] = { 'c','e','a','g','r','f','h' };
  int b[7] = { 3,5,1,10,7,11,12 };
  TNode<int, char> n[7];
  for (int i = 0; i < 7; i++) {
    n[i] = TNode<int, char>(b[i], a[i]);
  }
  TSortMap<int, char> m(7, n, MapSorts::insertion_sort);
  char c[7] = { 'a','c','e','r','g', 'f', 'h' };
  bool ok = true;
  int i = 0;
  TIterSortMap<int, char> it = m.begin();
  for (it; it != m.end(); ++it, i++) {
    if (*it != c[i]) {
      ok = false;
    }
  }
  ASSERT_TRUE(ok);
}

TEST(TSortMap, Is_Sorted_with_sort_function_3) {
  char a[7] = { 'c','e','a','g','r','f','h' };
  int b[7] = { 3,5,1,10,7,11,12 };
  TNode<int, char> n[7];
  for (int i = 0; i < 7; i++) {
    n[i] = TNode<int, char>(b[i], a[i]);
  }
  TSortMap<int, char> m(7, n, MapSorts::quick_sort);
  char c[7] = { 'a','c','e','r','g', 'f', 'h' };
  bool ok = true;
  int i = 0;
  TIterSortMap<int, char> it = m.begin();
  for (it; it != m.end(); ++it, i++) {
    if (*it != c[i]) {
      ok = false;
    }
  }
  ASSERT_TRUE(ok);
}

TEST(TSortMap, Is_Sorted_with_sort_function_4) {
  char a[7] = { 'c','e','a','g','r','f','h' };
  int b[7] = { 3,5,1,10,7,11,12 };
  TNode<int, char> n[7];
  for (int i = 0; i < 7; i++) {
    n[i] = TNode<int, char>(b[i], a[i]);
  }
  TSortMap<int, char> m(7, n, MapSorts::radix_sort);
  char c[7] = { 'a','c','e','r','g', 'f', 'h' };
  bool ok = true;
  int i = 0;
  TIterSortMap<int, char> it = m.begin();
  for (it; it != m.end(); ++it, i++) {
    if (*it != c[i]) {
      ok = false;
    }
  }
  ASSERT_TRUE(ok);
}

TEST(TSortMap, save_and_load) {
  TSortMap<int, char> m;
  m.Add(3, 'c');
  m.Add(5, 'e');
  m.Add(1, 'a');
  m.Add(10, 'g');
  m.Add(7, 'r');
  m.Add(11, 'f');
  m.Add(12, 'h');
  char a[7] = { 'a','c','e','r','g', 'f', 'h' };
  std::string file= "Test.txt";
  bool ok = m.Save(file);
  TSortMap<int, char> m2;
  ok &= (m2.Load(file));
  ok &= (m == m2);
  ASSERT_TRUE(ok);
}