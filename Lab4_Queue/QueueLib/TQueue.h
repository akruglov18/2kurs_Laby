#ifndef TQUEUE_H
#define TQUEUE_H

#include <iostream>
#include <fstream>

using namespace std;

template<class T>
class TQueue {
private:
  T* data;
  int size;
  int first;
  int last;
  int count;
public:
  TQueue(int size = 1);
  TQueue(const TQueue<T>& q);
  ~TQueue();

  bool isEmpty() const;
  void push(T d);
  T get();
  T getMax() const;
  T getMin() const;

  TQueue<T>& operator=(const TQueue<T> q);

  friend ofstream& operator<<(ofstream& fout, const TQueue<T>& q) 
  {
    while (!q.isEmpty())
    {
      fout << q.get() << " ";
    }
    return fout;
  }

};

template<class T>
TQueue<T>::TQueue(int _size) {
  if (_size <= 0)
    throw new std::exception();
  first = last = count = 0;
  size = _size;
  data = new T[size];
  for (int i = 0; i < size; i++)
    data[i] = NULL;
}

template<class T>
inline TQueue<T>::TQueue(const TQueue<T>& q)
{
  first = q.first;
  last = q.last;
  count = q.count;
  size = q.size;
  data = new T[size];
  for (int i = 0; i < size; i++)
  {
    if (q.data[i] != NULL)
      data[i] = q.data[i];
    else
      data[i] = NULL;
  }
}

template<class T>
inline TQueue<T>::~TQueue()
{
  first = last = count = size = 0;
  if (data != NULL)
    delete[] data;
  data = NULL;
}

template<class T>
inline bool TQueue<T>::isEmpty() const
{
  if (count == 0)
    return true;
  return false;
}

template<class T>
inline void TQueue<T>::push(T d)
{
  if (count == size)
    first = (first + 1) % size;
  data[last] = d;
  last = (last + 1) % size;
  count = std::min(size, count + 1);
}

template<class T>
inline T TQueue<T>::get()
{
  if (count == 0)
    throw new std::exception();
  count--;
  T tmp = data[first];
  data[first] = NULL;
  first = (first + 1) % size;
  return tmp;
}

template<class T>
inline T TQueue<T>::getMax() const
{
  if (count == 0)
    throw new std::exception();
  T Max = data[first];
  for (int i = 0; i < size; i++) {
    if (data[i] != NULL)
      Max = std::max(data[i], Max);
  }
  return Max;
}

template<class T>
inline T TQueue<T>::getMin() const
{
  if (count == 0)
    throw new std::exception();
  T Min = data[first];
  for (int i = 0; i < size; i++) {
    if (data[i] != NULL)
      Min = std::min(data[i], Min);
  }
  return Min;
}

template<class T>
inline TQueue<T>& TQueue<T>::operator=(const TQueue<T> q)
{
  if (data != NULL)
    delete[] data;
  first = q.first;
  last = q.last;
  count = q.count;
  size = q.size;
  data = new T[size];
  for (int i = 0; i < size; i++)
  {
    if (q.data[i] != NULL)
      data[i] = q.data[i];
    else
      data[i] = NULL;
  }
  return *this;
}

#endif