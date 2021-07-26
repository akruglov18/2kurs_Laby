#include <gtest.h>
#include "Plex.h"
#include "Line.h"
#include <Square.h>
#include <Canvas.h>


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
		/*TPoint a(1, 1);
		TPoint b(2, 2);
		TLine AB(a, b);

		TPoint c(3, 3);
		TPoint d(4, 4);
		TLine BC(b, c);
		TLine CD(c, d);
		TLine DA(d, a);

		AB.Print();

		TSquare ABCD(AB, BC, CD, DA);
		ABCD.Print();
	  std::cout << "plex AB\n";

		TPlex q(&a, &b);
		q.Print();



		q.AddLine(&a, &c);
		std::cout<<" plex ABC \n";  
		q.Print(); 

		q.AddLine(&c, &b);
		std::cout<<" plex ABCA \n";  
		q.Print(); 

		q.AddLine(&b, &d);
		std::cout<<" plex BCABD \n";  
		q.Print(); */

		/*TCanvas z;
		z.AddObj(&q);
		z.AddObj(&ABCD);
		z.AddObj(&AB);

		z.Print();*/

}