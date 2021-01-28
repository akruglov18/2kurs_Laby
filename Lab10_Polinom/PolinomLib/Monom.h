#pragma once
#include "List.h"

class TMonomData
{
public:
  double* data;
  double K;
  int dim;

  TMonomData(int t);
  TMonomData(double* _data = 0, int _dim = 0, double _K = 0);
  TMonomData(const TMonomData& _v);
  ~TMonomData();
};

class TMonom : public TListElem<TMonomData>
{
protected:

public:
  TMonom(TMonomData _data);
  TMonom(double* _data = 0, int _dim = 0, double _K = 0);
  TMonom(TMonom& m);
  ~TMonom();

  bool operator == (const TMonom& m);
  bool operator != (const TMonom& m);

  TMonomData& operator *();
  TMonomData& operator *(int);

  double getK();
  void setK(double _K);

  int getDim();
  void setDim(int _dim);

  virtual TMonom* clone();

  double& operator[] (int i);
  TMonom& operator= (const TMonom& m);
  TMonom  operator* (const TMonom& m);
  TMonom  operator/ (const TMonom& m);
  TMonom* operator+ (const TMonom& m);
  TMonom* operator- (const TMonom& m);

  bool operator> (const TMonom& m);
  bool operator< (const TMonom& m);

  friend ofstream& operator<< (ofstream& out, const TMonom& m);
  friend ifstream& operator>> (ifstream& in, TMonom& m);
};
