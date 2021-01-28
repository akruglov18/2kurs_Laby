#include <gtest.h>
#include<Polish.h>

TEST(Polish, 1)
{
  char* s = "2+2";
  int n= TPolish::Calculation(s);
  ASSERT_EQ(4, n);
}

TEST(Polish, 2)
{
  char* s = "2*3";
  int n = TPolish::Calculation(s);
  ASSERT_EQ(6, n);
}

TEST(Polish, 3)
{
  char* s = "2+2*2";
  int n = TPolish::Calculation(s);
  ASSERT_EQ(6, n);
}

TEST(Polish, 4)
{
  char* s = "(2+2)*2";
  int n = TPolish::Calculation(s);
  ASSERT_EQ(8, n);
}

TEST(Polish, 5)
{
  char* s = "(2+3)*4";
  int n = TPolish::Calculation(s);
  ASSERT_EQ(20, n);
}

TEST(Polish, 6)
{
  char* s = "(3+8)*3-6/2";
  int n = TPolish::Calculation(s);
  ASSERT_EQ(30, n);
}

TEST(Polish, 7)
{
  char* s = "(((((((((((((2+2)*2)*2)*2)*2)*2)/2)/2)/2)/2)/2)/2)/2)";
  int n = TPolish::Calculation(s);
  ASSERT_EQ(1, n);
}

TEST(Polish, 8)
{
  char* s = "(100+100)/2*100";
  int n = TPolish::Calculation(s);
  ASSERT_EQ(10000, n);
}

TEST(Polish, 9)
{
  char* s = "(100+100)/(2*100)";
  int n = TPolish::Calculation(s);
  ASSERT_EQ(1, n);
}
