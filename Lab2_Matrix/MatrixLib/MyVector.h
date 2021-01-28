#ifndef _MY_VECTOR_
#define _MY_VECTOR_

#include <iostream>

using namespace std;

template <class T>
class Vector
{
protected:
  int length;
  T* x;
public:
  Vector<T>* vec;
  Vector();
  Vector(int _size);
  Vector(int rowsCount, T* _v);
  Vector(int rowsCount, T _v);
  Vector(const Vector<T>& _v);
  virtual ~Vector();

  bool operator==(const Vector<T>& _v);
  bool operator!=(const Vector<T>& _v);
  Vector<T> operator +(const Vector<T>& _v);
  Vector<T> operator -(Vector<T>& _v);
  Vector<T> operator *(Vector<T>& _v);
  Vector<T> operator /(Vector<T>& _v);
  Vector<T>& operator =(const Vector<T>& _v);
  T& operator[] (const int index);

  Vector<T>& operator ++();
  Vector<T>& operator --();
  Vector<T>& operator +=(Vector<T>& _v);
  Vector<T>& operator -=(Vector<T>& _v);

  template <class T1>
  friend ostream& operator<< (ostream& ostr, const Vector<T1> &A);
  template <class T1>
  friend istream& operator >> (istream& istr, Vector<T1> &A);

  int Length();
};

template <class T1>
ostream& operator<< (ostream& ostr, const Vector<T1> &A) {
  for (int i = 0; i < A.length; i++) {
    ostr << A.x[i] << " ";
  }
  return ostr;
}

template <class T1>
istream& operator >> (istream& istr, Vector<T1> &A) {
  for (int i = 0; i < A.length; i++) {
    istr >> A.x[i];
  }
  return istr;
}

#define MIN(a,b)(a>b?b:a)
#define MAX(a,b)(a>b?a:b)

template <class T>
Vector<T>::Vector()
{
  length = 0;
  x = 0;
}
template <class T>
Vector<T>::Vector(int _size)
{
  if (_size < 0)
    throw new exception();
  length = _size;
  x = new T[length];
}

template <class T>
Vector<T>::Vector(int rowsCount, T* _v)
{
  length = rowsCount;

  ///x = _v;

  x = new T [length];
  for (int i = 0; i < length; i++)
    x[i] = _v[i];
}
template <class T>
Vector<T>::Vector(int rowsCount, T _v)
{
  length = rowsCount;
  x = new T [length];
  for (int i = 0; i < length; i++)
    x[i] = _v;
}
template <class T>
Vector<T>::Vector(const Vector<T>& _v)
{
  length = _v.length;
  x = new T [length];
  for (int i = 0; i < length;i = i + 1)
    x[i] = _v.x[i];
}
template <class T>
Vector<T>::~Vector()
{
  length = 0;
  if (x != 0)
    delete[] x;
  x = 0;
}

template<class T>
inline bool Vector<T>::operator==(const Vector<T>& _v)
{
  if (this->length != _v.length)
    return false;
  for (int i = 0; i < length; i++)
    if (x[i] != _v.x[i])
      return false;
  return true;
}

template<class T>
inline bool Vector<T>::operator!=(const Vector<T>& _v)
{
  return !(*this==_v);
}

template <class T>
Vector<T> Vector<T>::operator +(const Vector<T>& _v)
{
  Vector<T> res;
  res.length = MIN(length, _v.length);
  res.x = new T [res.length];
  for (int i = 0; i < res.length; i++)
  {
    res.x[i] = x[i] + _v.x[i];
  }
  return res;
}
template <class T>
Vector<T> Vector<T>::operator -(Vector<T>& _v)
{
  Vector<T> res;
  res.length = MIN(length, _v.length);
  res.x = new T [res.length];
  for (int i = 0; i < res.length; i++)
  {
    res.x[i] = x[i] - _v.x[i];
  }
  return res;
}
template <class T>
Vector<T> Vector<T>::operator *(Vector<T>& _v)
{
  Vector<T> res;
  res.length = MIN(length, _v.length);
  res.x = new T [res.length];
  for (int i = 0; i < res.length; i++)
  {
    res.x[i] = x[i] * _v.x[i];
  }
  return res;
}
template <class T>
Vector<T> Vector<T>::operator /(Vector<T>& _v)
{
  Vector<T> res;
  res.length = MIN(length, _v.length);
  res.x = new T [res.length];
  for (int i = 0; i < res.length; i++)
  {
    res.x[i] = x[i] / _v.x[i];
  }
  return res;
}
template <class T>
Vector<T>& Vector<T>::operator =(const Vector<T>& _v)
{
  if (this == &_v)
    return *this;

  length = _v.length;
  x = new T [length];
  for (int i = 0; i < length; i++)
    x[i] = _v.x[i];
  return *this;
}
template <class T>
T& Vector<T>::operator[] (const int index)
{
  if ((index >= 0) && (index < length))
    return x[index];
  return x[0];
}

template <class T>
Vector<T>& Vector<T>::operator ++()
{
  for (int i = 0; i < length; i++)
    x[i]++;
  return *this;
}
template <class T>
Vector<T>& Vector<T>::operator --()
{
  for (int i = 0; i < length; i++)
    x[i]--;
  return *this;
}
template <class T>
Vector<T>& Vector<T>::operator +=(Vector<T>& _v)
{
  length = MIN(length, _v.length);
  for (int i = 0; i < length; i++)
  {
    x[i] += _v.x[i];
  }
  return *this;
}
template <class T>
Vector<T>& Vector<T>::operator -=(Vector<T>& _v)
{
  length = MIN(length, _v.length);
  for (int i = 0; i < length; i++)
  {
    x[i] -= _v.x[i];
  }
  return *this;
}
template <class T>
int Vector<T>::Length()
{
  return length;
}


#endif