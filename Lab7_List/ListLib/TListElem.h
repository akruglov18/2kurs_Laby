#pragma once

#include<fstream>
#include<iostream>

using namespace std;

template<class T>
class TListElem {
private:
  T data;
  TListElem<T>* next;
  TListElem<T>* prev;
public:
  TListElem() = default;
  TListElem(T _data);
  ~TListElem();

  T getData() const;
  TListElem<T>* getNext() const;
  TListElem<T>* getPrev() const;

  void setData(T _data);
  void setNext(TListElem<T>* next);
  void setPrev(TListElem<T>* prev);

  template<class T1>
  friend ofstream& operator<<(ofstream& out, const TListElem<T1>& elem);

  template<class T1>
  friend ifstream& operator>>(ifstream& in, TListElem<T1>& elem);
};

template<class T>
inline TListElem<T>::TListElem(T _data)
{
  data = _data;
  next = 0;
  prev = 0;
}

template<class T>
inline TListElem<T>::~TListElem()
{
  next = 0;
  prev = 0;
}

template<class T>
inline T TListElem<T>::getData() const
{
  return data;
}

template<class T>
inline TListElem<T>* TListElem<T>::getNext() const
{
  return next;
}

template<class T>
inline TListElem<T>* TListElem<T>::getPrev() const
{
  return prev;
}

template<class T>
inline void TListElem<T>::setData(T _data)
{
  data = _data;
}

template<class T>
inline void TListElem<T>::setNext(TListElem* _next)
{
  next = _next;
}

template<class T>
inline void TListElem<T>::setPrev(TListElem* _prev)
{
  prev = _prev;
}

template<class T1>
inline ofstream& operator<<(ofstream& out, const TListElem<T1>& elem)
{
  out << elem.data;
  return out;
}

template<class T1>
inline ifstream& operator>>(ifstream& in, TListElem<T1>& elem)
{
  in >> elem.data;
  return in;
}
