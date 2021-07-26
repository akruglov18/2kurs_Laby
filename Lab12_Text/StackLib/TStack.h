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
public:
  TStack(int _size = 1000);
  TStack(TStack& st);
  ~TStack();
  bool isEmpty() const;
  bool isFull() const;
  void push(const T& Val);
  T get();
  T getMax() const;
  T getMin() const;
  
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
inline TStack<T>::TStack(int _size)
{
  if (_size <= 0)
    throw new std::exception();
  MemSize = _size;
  Top = -1;
  Mem = new T[MemSize];
}

template<class T>
inline TStack<T>::TStack(TStack& st)
{
  MemSize = st.MemSize;
  Top = st.Top;
  Mem = new T[MemSize];
  for (int i = 0; i < MemSize; i++)
    Mem[i] = st.Mem[i];
}

template<class T>
inline TStack<T>::~TStack()
{
  if (Mem != NULL) {
    delete[] Mem;
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
inline TStack<T>& TStack<T>::operator=(const TStack& st)
{
  if (Mem != NULL)
    delete[] Mem;

  MemSize = st.MemSize;
  Top = st.Top;
  Mem = new T[MemSize];
  for (int i = 0; i <= Top; i++)
    Mem[i] = st.Mem[i];
  return *this;
}
