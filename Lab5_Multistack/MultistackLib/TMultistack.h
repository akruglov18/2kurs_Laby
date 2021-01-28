#pragma once

#include "TStack.h"
#include <math.h>

template<class T>
class TMultiStack {
protected:
  int size;
  int stackCount;
  TStack<T>* stacks;
  T* data;
  T** oldData;
  void stackRelocation(int i);
public:
  TMultiStack(int _size = 1, int _stackCount = 1);
  TMultiStack(TMultiStack& st);
  ~TMultiStack();
  bool isEmpty(int i) const;
  bool isFull(int i) const;
  void push(const T& Val, int i);

  T get(int i);
  int getMinSize();
  int getSize() const;

  TMultiStack<T>& operator=(const TMultiStack& st);

  friend ofstream& operator<<(ofstream& fout, const TMultiStack<T>& st) 
  {
    for (int i = st.Top; i >= 0; i--)
      fout << st.stacks[i] << endl;
    return fout;
  }
  friend istream& operator>>(istream& in, TMultiStack<T>& st) {
    int stCount, size;
    in >> stCount >> size;
    st.resize(size, stCount);
    for (int i = 0; i < stCount; i++)
    {
      in >> st.stacks[i];
    }
    return in;
  }
};

template<class T>
inline TMultiStack<T>::TMultiStack(int _size, int _stackCount)
{
  if (_size <= 0 || _stackCount<=0)
    throw new std::exception();
  this->size = _size;
  this->stackCount = _stackCount;

  this->data = new T[size];
  for (int i = 0; i < size; i++)
    data[i] = 0;

  int count = int(floor(double(size) / stackCount));
  int* sizes = new int[this->stackCount];
  for (int i = 0; i < stackCount - 1; i++) {
    sizes[i] = count;
  }
  sizes[stackCount - 1] = size - (count * (stackCount - 1));

  stacks = new TStack<T>[this->stackCount];
  oldData = new T * [this->stackCount];

  int k = 0;
  for (int i = 0; i < stackCount; i++) {
    this->stacks[i].setData(&(data[k]), sizes[i], -1);
    this->oldData[i] = &(data[k]);
    k += sizes[i];
  }

  delete[] sizes;
}

template<class T>
inline TMultiStack<T>::TMultiStack(TMultiStack& ms)
{
  size = ms.size;
  stackCount = ms.stackCount;

  data = new T[size];
  for (int i = 0; i < size; i++)
  {
    data[i] = ms.data[i];
  }

  stacks = new TStack<T>[stackCount];
  for (int i = 0; i < stackCount; i++)
  {
    stacks[i] = ms.stacks[i];
  }
  oldData = ms.oldData;
}

template<class T>
inline TMultiStack<T>::~TMultiStack()
{
  size = stackCount = 0;
  if (data == NULL)
  {
    delete[] data;
  }

  if (stacks == NULL)
  {
    delete[] stacks;
  }

}

template<class T>
inline bool TMultiStack<T>::isEmpty(int i) const
{
  if (i<0 || i>=stackCount)
    throw std::exception();
  return stacks[i].isEmpty();
}

template<class T>
inline bool TMultiStack<T>::isFull(int i) const
{
  if (i<0 || i>=stackCount)
    throw std::exception();
  return stacks[i].isFull();
}

template<class T>
inline void TMultiStack<T>::push(const T& d, int i)
{
  if (i<0 || i>=stackCount)
    throw new std::exception();
  
  if (stacks[i].isFull()) {
    stackRelocation(i);
  }
  if (stacks[i].isFull())
    throw new std::exception();
  
  stacks[i].push(d);
}

template<class T>
inline void TMultiStack<T>::stackRelocation(int index)
{
  int freeSize = 0;
  for (int i = 0; i < stackCount; i++)
  {
    freeSize += (stacks[i].getSize() - stacks[i].getCount());
  }
  if (freeSize == 0)
    throw new std::exception();

  int count = int(floor(double(freeSize) / stackCount));
  int* sizes = new int[this->stackCount];
  for (int i = 0; i < stackCount - 1; i++) {
    sizes[i] = stacks[i].getCount() + count;
  }

  sizes[stackCount - 1] = stacks[stackCount-1].getCount() + freeSize - (count * (this->stackCount - 1));

  T** newData = new T * [stackCount];

  int k = 0;
  for (int i = 0; i < stackCount; i++) {
    newData[i] = &(data[k]);
    k += sizes[i];
  }

  for (int i = 0; i < stackCount; i++) {
    if (newData[i] == this->oldData[i])
    {
      stacks[i].setData(newData[i], sizes[i], stacks[i].getCount()-1);
    }
    else if (newData[i] < oldData[i])
    {
      for (int j = 0; j < stacks[i].getCount(); j++) {
        newData[i][j] = oldData[i][j];
      }
      stacks[i].setData(newData[i], sizes[i], stacks[i].getCount() - 1);
    }
    else if(newData[i]>oldData[i])
    {
      int k = i;
      for (; k < stackCount; k++)
      {
        if (newData[k] > oldData[k])
          continue;
        else
          break;
      }
      k--;
      for (int s = k; s >= i; s--)
      {
        for (int j = stacks[s].getCount(); j >=0; j--) {
          newData[s][j] = oldData[s][j];
        }
        stacks[s].setData(newData[s], sizes[s], stacks[s].getCount() - 1);
      }
    }
  }
  T** buf = oldData;
  oldData = newData;
  delete[] buf;
  delete[] sizes;
}

template<class T>
inline T TMultiStack<T>::get(int i) {
  if (i<0 || i>stackCount)
    throw std::exception();

  if (stacks[i].isEmpty())
    throw std::exception();
  T d = stacks[i].get();
  return d;
}

template<class T>
inline int TMultiStack<T>::getMinSize()
{
  int Min = this->size+1;
  for (int i = 0; i < stackCount; i++)
    Min = std::min(stacks[i].getSize(), Min);
  return Min;
}

template<class T>
inline int TMultiStack<T>::getSize() const
{
  return this->size;
}

template<class T>
inline TMultiStack<T>& TMultiStack<T>::operator=(const TMultiStack& ms)
{
  if (this == &ms)
    return *this;

  size = ms.size;
  stackCount = ms.stackCount;
  if (data != NULL)
    delete[] data;

  if (stacks != NULL)
    delete[] stacks;

  data = new T[size];
  for (int i = 0; i < size; i++)
    data[i] = ms.data[i];

  stacks = new TStack<T>[stackCount];
  for (int i = 0; i < stackCount; i++)
    stacks[i] = ms.stacks[i];

  return *this;
}