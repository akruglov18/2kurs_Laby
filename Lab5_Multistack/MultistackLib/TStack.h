#pragma once

#include <iostream>

using namespace std;

template<class T>
class TStack
{
private:
  int MemSize;
  int Top;
  T* Mem;
  bool isOwner;
public:
  TStack(int _size = 1, bool _isOwner = true);
  TStack(TStack& st);
  ~TStack();
  bool isEmpty() const;
  bool isFull() const;
  void push(const T& Val);

  void resize(int _size);
  void setData(T* _data, int size, int _top);
  T get();
  T getMax() const;
  T getMin() const;
  int getSize() const;
  int getCount() const;

  
  TStack<T>& operator=(const TStack& st);

  friend ofstream& operator<<(ofstream& fout, const TStack<T>& st) {
    for (int i = st.Top; i >= 0; i--)
      fout << st.Mem[i] << " ";
    return fout;
  }
  friend istream& operator>>(istream& in, TStack<T>& st) {
    int count;
    in >> count;
    for (int i = 0; i<count; i++)
    {
      T x;
      in >> x;
      st.push(x);
    }
    return in;
  }
};

template<class T>
inline TStack<T>::TStack(int _size, bool _isOwner)
{
  if (_size <= 0)
    throw new std::exception();
  isOwner = _isOwner;
  MemSize = _size;
  Top = -1;
  if (isOwner) 
  {
    Mem = new T[MemSize];
    for (int i = 0; i < MemSize; i++)
      Mem[i] = NULL;
  }
}

template<class T>
inline TStack<T>::TStack(TStack& st)
{
  isOwner = true;
  MemSize = st.MemSize;
  Top = st.Top;
  if (isOwner) {
    Mem = new T[MemSize];
    for (int i = 0; i < MemSize; i++)
      Mem[i] = st.Mem[i];
  }
  else
    Mem = st.Mem;
}

template<class T>
inline TStack<T>::~TStack()
{
  MemSize = 0;
  if (isOwner) {
    if (Mem != NULL) {
      delete[] Mem;
    }
    Mem = NULL;
  }
}

template<class T>
inline bool TStack<T>::isEmpty() const
{
  return Top == -1;
}

template<class T>
inline bool TStack<T>::isFull() const
{
  return Top == MemSize-1;
}

template<class T>
inline void TStack<T>::push(const T& Val)
{
  if (this->isFull())
    throw std::exception();
  Top++;
  Mem[Top] = Val;
}

template<class T>
inline void TStack<T>::setData(T* _data, int size, int _top)
{
  if (isOwner && Mem != NULL)
    delete[] Mem;
  isOwner = false;
  this->Top = _top;
  this->MemSize = size;
  this->Mem = _data;
}

template<class T>
inline T TStack<T>::get(){
  if (this->isEmpty())
    throw std::exception();
  T tmp = Mem[Top];
  Mem[Top] = NULL;
  Top--;
  return tmp;
}

template<class T>
inline T TStack<T>::getMax() const
{
  if (this->isEmpty())
    throw std::exception();
  T Max = Mem[0];
  for (int i = 1; i <= Top; i++)
    Max = std::max(Mem[i], Max);
  return Max;
}

template<class T>
inline T TStack<T>::getMin() const
{
  if (this->isEmpty())
    throw std::exception();
  T Min = Mem[0];
  for (int i = 1; i <= Top; i++)
    Min = std::min(Mem[i], Min);
  return Min;
}

template<class T>
inline int TStack<T>::getSize() const
{
  return this->MemSize;
}

template<class T>
inline int TStack<T>::getCount() const
{
  return Top + 1;
}

template<class T>
inline TStack<T>& TStack<T>::operator=(const TStack& st)
{
  if (this == &st)
    return *this;
  if (isOwner) {
    if (Mem != NULL) {
      delete[] Mem;
    }
    Mem = NULL;
  }
  isOwner = true;
  MemSize = st.MemSize;
  Top = st.Top;
  if (isOwner) {
    Mem = new T[MemSize];
    for (int i = 0; i < Top + 1; i++)
      Mem[i] = st.Mem[i];
  }
  else
    Mem = st.Mem;
  return *this;
}
