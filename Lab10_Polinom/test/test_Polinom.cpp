#include "Polinom.h"
#include <gtest.h>

TEST(TPolinomial, can_add_monom_to_polinom)
{
  TMonom a(new double[3]{ 2, 4, 7 }, 3, 1);
  TPolinomial p1;
  ASSERT_NO_THROW(p1 += a);
}


TEST(TPolinomial, can_multiplicate)
{
  TMonom a(new double[3]{ 2, 4, 7 }, 3, 1);
  TMonom b(new double[3]{ 1,4,6 }, 3, 1);
  TPolinomial p1, p2;
  p1 += a;
  p2 += b;

  ASSERT_NO_THROW(p1 * p2);
}

TEST(TPolinomial, multiplicate)
{
  TMonom a(new double[3]{ 1, 2, 3 }, 3, 1);
  TMonom b(new double[3]{ 2, 4, 6 }, 3, 1);
  TPolinomial p1, p2, p3;
  p1 += a;
  p2 += a;
  p1 = p1 * p2;
  p3 += b;
  ASSERT_NO_THROW(p1*p3);
}

TEST(TPolinomial, can_subtraction)
{
  TMonom a(new double[3]{ 2, 4, 7 }, 3, 1);
  TMonom b(new double[3]{ 1,4,6 }, 3, 1);
  TPolinomial p1, p2;
  p1 += a;
  p2 += b;

  ASSERT_NO_THROW(p2 - p1);
}

TEST(TPolinomial, can_addition)
{
  TMonom a(new double[3]{ 2, 4, 7 }, 3, 1);
  TMonom b(new double[3]{ 1,4,6 }, 3, 1);
  TPolinomial p1, p2;
  p1 += a;
  p2 += b;
  ASSERT_NO_THROW(p2 + p1);
}

TEST(TPolinomial, double_pow)
{
  TMonom a(new double[3]{ 2.1, 4.2, 7.7 }, 3, 1);
  TPolinomial p;
  ASSERT_NO_THROW(p += a);
}

TEST(TPolinomial, unlimited_size_of_the_polynomial)
{
  TMonom a(new double[8]{ 4, 6, 2, 1, 5, 1, 2, 3 }, 8, 1);
  TMonom b(new double[6]{ 1, 2, 3, 4, 5, 6 }, 6, 1);
  TPolinomial p;
  p += a;
  ASSERT_NO_THROW(p += b);
}