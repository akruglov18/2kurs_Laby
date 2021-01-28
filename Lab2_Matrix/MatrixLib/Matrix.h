#pragma once

#include "MyVector.h"

template<class T>
class TMatrix : public Vector<Vector<T> >
{
  int size;
public:
  TMatrix(int _size = 0);
  TMatrix(const TMatrix& A);
  TMatrix(const Vector<Vector<T> >& A);
  ~TMatrix();

  T& operator()(int row, int col) const;
  TMatrix& operator=(const TMatrix<T>& mt);
  TMatrix operator+(const TMatrix& mt) const;
  TMatrix operator-(const TMatrix& mt) const;
  TMatrix operator*(const TMatrix& mt) const;
  bool operator==(const TMatrix& mt) const;
  bool operator!=(const TMatrix& mt) const;

  friend ostream& operator<<(ostream& out,const TMatrix& mt) {
    for (int i = 0; i < mt.length; i++) {
      out << mt.x[i] << "\n";
    }
    return out;
  }

  friend istream& operator>>(istream& in, TMatrix& mt) {
    for (int i = 0; i < mt.Lenngth(); i++)
      in >> mt.pVector[i];
    return in;
  }
};

template<class T>
inline TMatrix<T>::TMatrix(int _size) : Vector<Vector<T> >(_size)
{
  if (_size < 0)
    throw new std::exception();
  this->size = _size;
  for (int i = 0; i < _size; i++)
    this->x[i] = Vector<T>(_size - i);
}


template<class T>
inline TMatrix<T>::TMatrix(const TMatrix& A) : Vector<Vector<T> >(A) 
{
  this->size = A.size;
}

template<class T>
inline TMatrix<T>::TMatrix(const Vector<Vector<T> >& A) : Vector<Vector<T> >(A)
{
}

template<class T>
inline TMatrix<T>::~TMatrix()
{
}

template<class T>
inline T& TMatrix<T>::operator()(int row, int col) const
{
  if (row < 0 || row >= this->size)
    throw new std::exception();
  if (col < 0 || col >= this->size)
    throw new std::exception();
  return this->x[row][col - row];
}

template<class T>
 TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T>& mt)
{
   if (this == &mt)
     return *this;
   if (this->x != NULL) 
     delete[] this->x;
   Vector<Vector<T> >:: operator=(mt);
   return *this;
}

template<class T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& mt) const
{
   TMatrix<T> tmp(*this);
   if (this->length != mt.length)
     throw new exception();
   for (int i = 0; i < tmp.length; i++)
     tmp.x[i] = tmp.x[i] + mt.x[i];

   return tmp;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator-(const TMatrix& mt) const
{
  TMatrix<T> tmp(*this);
  if (this->length != mt.length)
    throw new exception();
  for (int i = 0; i < tmp.length; i++)
    tmp.x[i] = tmp.x[i] - mt.x[i];
  return tmp;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator*(const TMatrix& mt) const
{
  if (this->size != mt.size)
  {
    throw new std::exception();
  }

  TMatrix<T> m(*this);
  TMatrix<T> res(this->size);

  for (int i = 0; i < this->size; i++)
  {
    for (int j = 0; j < this->size - i; j++)
    {
      res.x[i][j] = 0;
      for (int k = 0; k < this->size; k++)
        res.x[i][j] += (m.x[i][k] * mt.x[k][j]);
    }
  }
  return res;
}

 template<class T>
inline bool TMatrix<T>::operator==(const TMatrix& mt) const
{
  if (this->size != mt.size)
    return false;
  for (int i = 0; i < this->size; i++)
    if (this->x[i] != mt.x[i])
      return false;
  return true;
}

template<class T>
inline bool TMatrix<T>::operator!=(const TMatrix& mt) const
{
  return !(*this == mt);
}
