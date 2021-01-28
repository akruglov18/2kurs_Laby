#pragma once
#include<fstream>
#include<exception>
#include<Monom.h>
#include<List.h>

using namespace std;

template<class T>
class TListIterator;

class TPolinomial : public TList<TMonomData>{
private:

public:
  TPolinomial();
  TPolinomial(const TPolinomial& _v);
  ~TPolinomial();

  TPolinomial& operator+= (TMonom& p);
  TPolinomial operator* (TPolinomial& p);
  TPolinomial operator+ (TPolinomial& p);
  TPolinomial operator- (TPolinomial& p);
  /*bool operator==(const TPolinomial& p) const;
  bool operator!=(const TPolinomial& p) const;*/

  friend ofstream& operator<<(ofstream& out, const TPolinomial& p);
};
