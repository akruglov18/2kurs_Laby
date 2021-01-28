#include <iostream>

#include "MyVector.h"
#include "Matrix.h"

int main()
{
  TMatrix<int> a(5), b(5);
  cout << "TEST" << endl;
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
    {
      a[i][j] = i * 10 + j;
      b[i][j] = (i * 10 + j) * 100;
    }
  TMatrix<int> c = a;
  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;
  cout << "Matrix a + b " << endl << a + b << endl;
  cout << "Matrix a - b " << endl << a - b << endl;
  cout << c;
}
