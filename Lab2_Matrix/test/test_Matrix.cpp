#include "MyVector.h"

#include <gtest.h>
#include "Matrix.h"

TEST(TMatrix, can_create_matrix) {
  ASSERT_NO_THROW(TMatrix<int>(3));
}

TEST(TMatrix, can_set_get_element) {
  TMatrix<int> m1(2);
  m1(1, 1) = 6;
  EXPECT_EQ(m1(1, 1), 6);
}

TEST(TMatrix, can_set_get_element_out_of_range) {
  TMatrix<int> m1(3);
  m1(1, 1) = 5;
  EXPECT_ANY_THROW(m1(3,0) = 5);
}

TEST(TMatrix, error_with_negative_index) {
  TMatrix<int> m1(4);
  EXPECT_ANY_THROW(m1(-1, -1));
}

TEST(TMatrix, can_compare_two_matrix) {
  TMatrix<int> m1(4), m2(m1);
  EXPECT_NO_THROW(m1 == m2);
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one) {
  TMatrix<int> m1(4), m2(m1);
  EXPECT_EQ(m1, m2);
}

TEST(TMatrix, error_with_exceed_index) {
  TMatrix<int> m1(4);
  ASSERT_ANY_THROW(m1(5, 5));
}

TEST(TMatrix, can_copy_matrix) {
  TMatrix<int> m1(2);
  m1(0, 0) = 1;
  m1(0, 1) = 2;
  m1(1, 0) = 3;
  m1(1, 1) = 4;
  TMatrix<int>m2(m1);
  EXPECT_EQ(m1, m2);
}

TEST(TMatrix, assign_changes_size) {
  TMatrix<int> m1(2), m2(3);
  m1 = m2;
  EXPECT_EQ(m1.Length(), 3);
}
TEST(TMatrix, assign_changes_size_and_elements_are_equal) {
  TMatrix<int> m1(2), m2(3);
  m2(1, 1) = 6;
  m1 = m2;
  EXPECT_EQ(m1(1,1), 6);
}
TEST(TMatrix, can_multiplicate_with_equal_size) {
  TMatrix<int> m1(3), m2(3);
  EXPECT_NO_THROW(m1 *m2);
}

TEST(TMatrix, multiplicate) {
  TMatrix<int> m1(2), m2(2);
  m1(0, 0) = m2(0, 0) = 1;
  m1(0, 1) = m2(0, 1) = 2;
  m1(1, 1) = m2(1, 1) = 3;
  TMatrix<int> mr = m1 * m2;
  EXPECT_EQ(mr(0, 1), 8);
}



