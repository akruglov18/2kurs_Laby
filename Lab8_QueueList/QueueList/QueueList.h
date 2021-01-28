#pragma once
#include <iostream>
#include "List.h"
#include <fstream>

using namespace std;

template<class T>
class QueueList {
private:
  TList<T> list;
public:
  QueueList() = default;
  QueueList(const QueueList<T>& q);
  ~QueueList();

  bool isEmpty() const;
  void push(T d);
  T get();
  T getMax() const;
  T getMin() const;

  int getCount();

  QueueList<T>& operator=(const QueueList<T> q);

  friend ofstream& operator<<(ofstream& fout, const QueueList<T>& q)
  {
    return fout << q.list;
  }

  friend ofstream& operator>>(ofstream& fin, QueueList<T>& q)
  {
    return fin >> q.list;
  }

};

template<class T>
inline QueueList<T>::QueueList(const QueueList<T>& q)
{
  list = q.list;
}

template<class T>
inline QueueList<T>::~QueueList()
{
}

template<class T>
inline bool QueueList<T>::isEmpty() const
{
  if (list.isEmpty())
    return true;
  return false;
}

template<class T>
inline void QueueList<T>::push(T d)
{
  if (list.isFull())
    throw new std::exception();
  list.insFirst(d);
}

template<class T>
inline T QueueList<T>::get()
{
  if (list.isEmpty())
    throw new std::exception();
  T res= list.getLast()->getData();
  list.delLast();
  return res;
}

template<class T>
inline T QueueList<T>::getMax() const
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
inline T QueueList<T>::getMin() const
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
inline int QueueList<T>::getCount()
{
  return list.getCount();
}

template<class T>
inline QueueList<T>& QueueList<T>::operator=(const QueueList<T> q)
{
  if (this == &q)
    throw new std::exception();
  list = q.list;
  return *this;
}
