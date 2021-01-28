#pragma once

#include <iostream>
#include "List.h"

using namespace std;

template<class T>
class TStackList
{
private:
  TList<T> list;
public:
  TStackList() = default;
  TStackList(const TStackList& st);
  ~TStackList() = default;
  bool isEmpty() const;
  bool isFull() const;
  void push(const T& Val);
  T get();
  T getMax() const;
  T getMin() const;
  int getCount() const;

  TStackList<T>& operator=(const TStackList& st);

  friend ofstream& operator<<(ofstream& fout, const TStackList<T>& st) {
    return fout << st;
  }

  friend istream& operator>>(istream& in, TStackList<T>& st) {
    return in >> st;
  }
};

template<class T>
inline TStackList<T>::TStackList(const TStackList& st)
{
  list = st.list;
}

template<class T>
inline bool TStackList<T>::isEmpty() const
{
  return list.isEmpty();
}

template<class T>
inline bool TStackList<T>::isFull() const
{
  return list.isFull();
}

template<class T>
inline void TStackList<T>::push(const T& val)
{
  list.insLast(val);
}

template<class T>
inline T TStackList<T>::get()
{
  if (list.isEmpty())
    throw new std::exception();
  T res = list.getLast()->getData();
  list.delLast();
  return res;
}

template<class T>
inline T TStackList<T>::getMax() const
{
  TListIterator<T> it = list.cbegin();
  T mx = it.getData();
  while (it.isGoNext()) {
    it.goNext();
    mx = std::max(it.getData(), mx);
  }
  return mx;
}

template<class T>
inline T TStackList<T>::getMin() const
{
  TListIterator<T> it = list.cbegin();
  T mn = it.getData();
  while (it.isGoNext()) {
    it.goNext();
    mn = std::min(it.getData(), mn);
  }
  return mn;
}

template<class T>
inline int TStackList<T>::getCount() const
{
  return list.getCount();
}

template<class T>
inline TStackList<T>& TStackList<T>::operator=(const TStackList& st)
{
  if (this == &st)
    return *this;
  list = st.list;
  return *this;
}
