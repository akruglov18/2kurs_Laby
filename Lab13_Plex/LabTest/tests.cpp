#include<gtest.h>
#include"Plex.h"

TEST(TPlex, can_create_0) {
  ASSERT_NO_THROW(TPlex());
}

TEST(TPlex, can_create_1) {
  TPoint a(0,0), b(0,0);
  ASSERT_NO_THROW(TPlex(&a,&b));
}

TEST(TPlex, adding_lines_0) {
	TPoint a(1, 1);
	TPoint b(2, 2);
	TPoint c(3, 3);
	TPoint d(4, 4);
	TLine AB(a, b);
	TLine BC(b, c);
	TLine CD(c, d);
	TLine DA(d, a);

	TPlex q(&a, &b);
	q.AddLine(&a, &c);
	q.AddLine(&c, &b);
	TBase* ri = q.GetRight();
	ASSERT_TRUE(ri == &b);
}

TEST(TPlex, adding_lines_1) {
	TPoint a(1, 1);
	TPoint b(2, 2);
	TPoint c(3, 3);
	TPoint d(4, 4);
	TLine AB(a, b);
	TLine BC(b, c);
	TLine CD(c, d);
	TLine DA(d, a);

	TPlex q(&a, &b);
	q.AddLine(&a, &c);
	q.AddLine(&c, &b);
	TBase* ri = q.GetLeft();
	ri = ri->GetChild(1);
	ASSERT_TRUE(ri == &a);
}

TEST(TPlex, adding_lines_2) {
	TPoint a(1, 1);
	TPoint b(2, 2);
	TPoint c(3, 3);
	TPoint d(4, 4);
	TLine AB(a, b);
	TLine BC(b, c);
	TLine CD(c, d);
	TLine DA(d, a);

	TPlex q(&a, &b);
	q.AddLine(&a, &c);
	q.AddLine(&c, &b);
	TBase* ri = q.GetLeft();
	ri = ri->GetChild(0);
	ri = ri->GetChild(1);
	ASSERT_TRUE(ri == &c);
}

TEST(TPlex, adding_lines_3) {
	TPoint a(1, 1);
	TPoint b(2, 2);
	TPoint c(3, 3);
	TPoint d(4, 4);
	TLine AB(a, b);
	TLine BC(b, c);
	TLine CD(c, d);
	TLine DA(d, a);

	TPlex q(&a, &b);
	q.AddLine(&a, &c);
	q.AddLine(&c, &b);
	TBase* ri = q.GetLeft();
	ri = ri->GetChild(0);
	ri = ri->GetChild(0);
	ASSERT_TRUE(ri == &b);
}

TEST(TPlex, adding_lines_4) {
	TPoint a(1, 1);
	TPoint b(2, 2);
	TPoint c(3, 3);
	TPoint d(4, 4);
	TLine AB(a, b);
	TLine BC(b, c);
	TLine CD(c, d);
	TLine DA(d, a);

	TPlex q(&a, &b);
	q.AddLine(&a, &c);
	q.AddLine(&c, &b);
	q.AddLine(&b, &d);
	TBase* ri = q.GetRight();
	ri = ri->GetChild(1);
	ASSERT_TRUE(ri == &b);
}

TEST(TPlex, adding_lines_5) {
	TPoint a(1, 1);
	TPoint b(2, 2);
	TPoint c(3, 3);
	TPoint d(4, 4);
	TLine AB(a, b);
	TLine BC(b, c);
	TLine CD(c, d);
	TLine DA(d, a);

	TPlex q(&a, &b);
	q.AddLine(&a, &c);
	q.AddLine(&c, &b);
	q.AddLine(&b, &d);
	TBase* ri = q.GetRight();
	ri = ri->GetChild(0);
	ASSERT_TRUE(ri == &d);
}

TEST(TPlex, load_from_file_0) {
	TPoint a(1, 1);
	TPoint b(2, 2);
	TPoint c(3, 3);
	TPoint d(4, 4);
	TLine AB(a, b);
	TLine BC(b, c);
	TLine CD(c, d);
	TLine DA(d, a);

	TPlex q(&a, &b);
	q.AddLine(&a, &c);
	q.AddLine(&c, &b);
	
	q.Save("Test.txt");
	TPlex ad;
	ad.Load("Test.txt");

	TBase* ri = ad.GetRight();
	TPoint new_b = *(dynamic_cast<TPoint*>(ri));
	ASSERT_TRUE(new_b == b);
}

TEST(TPlex, load_from_file_1) {
	TPoint a(1, 1);
	TPoint b(2, 2);
	TPoint c(3, 3);
	TPoint d(4, 4);
	TLine AB(a, b);
	TLine BC(b, c);
	TLine CD(c, d);
	TLine DA(d, a);

	TPlex q(&a, &b);
	q.AddLine(&a, &c);
	q.AddLine(&c, &b);

	q.Save("Test.txt");
	TPlex ad;
	ad.Load("Test.txt");

	TBase* ri = ad.GetLeft();
	ri = ri->GetChild(1);
	TPoint new_p = *(dynamic_cast<TPoint*>(ri));
	ASSERT_TRUE(new_p == a);
}

TEST(TPlex, load_from_file_2) {
	TPoint a(1, 1);
	TPoint b(2, 2);
	TPoint c(3, 3);
	TPoint d(4, 4);
	TLine AB(a, b);
	TLine BC(b, c);
	TLine CD(c, d);
	TLine DA(d, a);

	TPlex q(&a, &b);
	q.AddLine(&a, &c);
	q.AddLine(&c, &b);

	q.Save("Test.txt");
	TPlex ad;
	ad.Load("Test.txt");

	TBase* ri = ad.GetLeft();
	ri = ri->GetChild(0);
	ri = ri->GetChild(0);
	TPoint new_p = *(dynamic_cast<TPoint*>(ri));
	ASSERT_TRUE(new_p == b);
}

TEST(TPlex, load_from_file_4) {
	TPoint a(1, 1);
	TPoint b(2, 2);
	TPoint c(3, 3);
	TPoint d(4, 4);
	TLine AB(a, b);
	TLine BC(b, c);
	TLine CD(c, d);
	TLine DA(d, a);

	TPlex q(&a, &b);
	q.AddLine(&a, &c);
	q.AddLine(&c, &b);
	q.AddLine(&b, &d);

	q.Save("Test.txt");
	TPlex ad;
	ad.Load("Test.txt");

	TBase* ri = ad.GetRight();
	ri = ri->GetChild(0);
	TPoint new_p = *(dynamic_cast<TPoint*>(ri));
	ASSERT_TRUE(new_p == d);
}

TEST(TPlex, load_from_file_5) {
	TPoint a(1, 1);
	TPoint b(2, 2);
	TPoint c(3, 3);
	TPoint d(4, 4);
	TLine AB(a, b);
	TLine BC(b, c);
	TLine CD(c, d);
	TLine DA(d, a);

	TPlex q(&a, &b);
	q.AddLine(&a, &c);
	q.AddLine(&c, &b);
	q.AddLine(&b, &d);

	q.Save("Test.txt");
	TPlex ad;
	ad.Load("Test.txt");

	TBase* ri = ad.GetRight();
	ri = ri->GetChild(1);
	TPoint new_p = *(dynamic_cast<TPoint*>(ri));
	ASSERT_TRUE(new_p == b);
}