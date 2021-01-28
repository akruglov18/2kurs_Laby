#pragma once
#include<fstream>
#include<exception>

using namespace std;

template<class T>
class TArrayListIterator;

template<class T>
class TArrayList {
private:
  T* data;
  int* links;
  int size;
  int count;
  int root;
public:
  TArrayList(int _size = 1);
  TArrayList(const TArrayList<T>& list);
  ~TArrayList();

  TArrayList<T>& operator=(const TArrayList<T>& list);
  TArrayList<T>& operator==(const TArrayList<T>& list);

  void insFirst(T d);
  void insLast(T d);
  void insert(TArrayListIterator<T>& it, T d);

  bool isEmpty() const;
  bool isFull() const;
  T getFirst() const;
  T getLast() const;
  int getSize() const;
  int getCount() const;
  TArrayList<T> get_Kdivisible(T k);

  TArrayListIterator<T> begin();
  TArrayListIterator<T> end();

  void delFirst();
  void delLast();
  void erase(TArrayListIterator<T>& it);

  template<class T1>
  friend ofstream& operator<<(ofstream& out, const TArrayList<T1> list);
  template<class T1>
  friend ifstream& operator>> (ifstream& in, TArrayList<T1>& list);

  template<class T1>
  friend class TArrayListIterator;
};





//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------iterator begin
template<class T>
class TArrayListIterator {
protected:
  TArrayList<T>& list;
  int index;
public:
  TArrayListIterator() = delete;
  TArrayListIterator(TArrayList<T>& list, int _index = -2);
  TArrayListIterator(const TArrayListIterator<T>& it);
  ~TArrayListIterator();

  bool isGoNext();
  void goNext();

  T getData();

  bool operator==(const TArrayListIterator<T>& it);
  TArrayListIterator<T>& operator++();
  TArrayListIterator<T>& operator=(const TArrayListIterator<T>& it);

  friend class TArrayList<T>;
};

template<class T>
inline TArrayListIterator<T>::TArrayListIterator(TArrayList<T>& _list, int _index) : list(_list), index(_index)
{
  index = _index;
}

template<class T>
inline TArrayListIterator<T>::TArrayListIterator(const TArrayListIterator<T>& it) : list(it.list), index(it.index)
{
}

template<class T>
inline TArrayListIterator<T>::~TArrayListIterator()
{
  index = -2;
}

template<class T>
inline bool TArrayListIterator<T>::isGoNext()
{
  return index >= 0;
}

template<class T>
inline void TArrayListIterator<T>::goNext()
{
  if (isGoNext()) {
    index = list.links[index];
    return;
  }
  throw new std::exception();
}

template<class T>
inline T TArrayListIterator<T>::getData()
{
  if (index < 0)
    throw new std::exception();
  return list.data[index];
}

template<class T>
inline bool TArrayListIterator<T>::operator==(const TArrayListIterator<T>& it)
{
  return (index == list.index && *list == *(it.list));
}

template<class T>
inline TArrayListIterator<T>& TArrayListIterator<T>::operator++()
{
  goNext();
  return *this;
}

template<class T>
inline TArrayListIterator<T>& TArrayListIterator<T>::operator=(const TArrayListIterator<T>& it)
{
  list = it.list;
  index = it.list;
}


//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------iterator end






template<class T>
inline TArrayList<T>::TArrayList(int _size)
{
  if (_size <= 0)
    throw new std::exception();
  size = _size;
  data = new T[size];
  links = new int[size];
  count = 0;
  for (int i = 0; i < size; i++) {
    links[i] = -2;
  }
  root = -1;
}

template<class T>
inline TArrayList<T>::TArrayList(const TArrayList<T>& list)
{
  size = list.size;
  count = list.count;

  data = new T[size];
  links = new int[size];

  for (int i = 0; i < size; i++) {
    links[i] = list.links[i];
    data[i] = list.data[i];
  }
  root = list.root;
}

template<class T>
inline TArrayList<T>::~TArrayList()
{
  if (data != NULL)
    delete[] data;
  if (links != NULL)
    delete[] links;
  count = 0;
  size = 0;
  root = -1;
}

template<class T>
inline TArrayList<T>& TArrayList<T>::operator=(const TArrayList<T>& list)
{
  if (this == &list)
    return *this;

  if (size != list.size)
  {
    if (data != NULL)
      delete[] data;
    if (links != NULL)
      delete[] links;
    size = list.size;
    data = new T[size];
    links = new int[size];
  }
  count = list.count;
  root = list.root;
  for (int i = 0; i < size; i++)
  {
    data[i] = list.data[i];
    links[i] = list.links[i];
  }

  return *this;
}

template<class T>
inline TArrayList<T>& TArrayList<T>::operator==(const TArrayList<T>& list)
{
  if (count != list.count || size != list.size)
    return false;
  if (isEmpty())
    return true;
  int i1 = root, i2 = list.root;
  while (links[i1] != -1)
  {
    if (data[i1] != list.data[i2])
      return false;
    i1 = links[i1];
    i2 = list.links[i2];
  }
  return true;
}

template<class T>
inline void TArrayList<T>::insFirst(T d)
{
  if (isFull())
    throw new std::exception();
  int i;
  for (i = 0; i < size; i++)
  {
    if (links[i] == -2)
      break;
  }

  data[i] = d;
  links[i] = root;
  root = i;

  count++;
}

template<class T>
inline void TArrayList<T>::insLast(T d)
{
  if (isFull())
    throw new std::exception();
  if (isEmpty()) {
    root = 0;
    data[0] = d;
    links[0] = -1;
    count++;
    return;
  }
  int i;
  for (i = 0; i < size; i++)
  {
    if (links[i] == -2)
      break;
  }
  int j = root;
  while (links[j] != -1) {
    j = links[j];
  }
  links[i] = -1;
  links[j] = i;
  data[i] = d;
  count++;
}

template<class T>
inline void TArrayList<T>::insert(TArrayListIterator<T>& it, T d)
{
  if (isFull())
  {
    throw new std::exception();
  }
  if (isEmpty())
  {
    root = 0;
    data[0] = d;
    links[0] = -1;
    it.index = 0;
  }
  else
  {
    int i;
    for (i = 0; i < size; i++)
    {
      if (links[i] == -2)
        break;
    }

    int j = root;
    while (links[j] != it.index) {
      j = links[j];
    }
    data[i] = d;
    links[j] = i;
    links[i] = it.index;
    it.index = i;
  }
  count++;
}

template<class T>
inline bool TArrayList<T>::isEmpty() const
{
  return count == 0;
}

template<class T>
inline bool TArrayList<T>::isFull() const
{
  return count >= size;
}

template<class T>
inline T TArrayList<T>::getFirst() const
{
  if (isEmpty())
    throw new std::exception();
  return data[root];
}

template<class T>
inline T TArrayList<T>::getLast() const
{
  if (isEmpty())
    throw new std::exception();
  int i = root;
  while (links[i] != -1)
  {
    i = links[i];
  }
  return data[i];
}

template<class T>
inline int TArrayList<T>::getSize() const
{
  return size;
}

template<class T>
inline int TArrayList<T>::getCount() const
{
  return count;
}

template<class T>
inline TArrayList<T> TArrayList<T>::get_Kdivisible(T k)
{
  if (isEmpty())
    return NULL;
  int i = root, count = 0;
  while (links[i] != -1)
  {
    if (data[i] % k == 0)
      count++;
    i = links[i];
  }
  if (data[i] % k == 0)
    count++;

  TArrayList<T> res(count);
  i = root;
  while (links[i] != -1)
  {
    if (data[i] % k == 0)
      res.insLast(data[i]);
    i = links[i];
  }
  if (data[i] % k == 0)
    res.insLast(data[i]);
  return res;
}

template<class T>
inline TArrayListIterator<T> TArrayList<T>::begin()
{
  return TArrayListIterator<T>(*this, root);
}

template<class T>
inline TArrayListIterator<T> TArrayList<T>::end()
{
  return TArrayListIterator<T>(*this, -1);
}

template<class T>
inline void TArrayList<T>::delFirst()
{
  if (isEmpty())
    throw new std::exception();
  int i = root;
  root = links[root];
  links[i] = -2;
  data[i] = NULL;
  count--;
}

template<class T>
inline void TArrayList<T>::delLast()
{
  if (isEmpty())
    throw new std::exception();
  if (links[root] == -1) {
    links[root] = -2;
    data[root] = NULL;
    root = -1;
    count--;
    return;
  }
  int pEnd = root;
  int end = links[root];
  while (links[end] != -1) {
    pEnd = end;
    end = links[end];
  }
  links[pEnd] = -1;
  links[end] = -2;
  data[end] = NULL;
  count--;
}

template<class T>
inline void TArrayList<T>::erase(TArrayListIterator<T>& it)
{
  if (isEmpty())
  {
    throw new std::exception();
  }
  else
  {
    int j = root;
    while (links[j] != it.index) {
      j = links[j];
    }
    data[it.index] = NULL;
    links[j] = links[it.index];
    links[it.index] = -2;
    it.index = links[j];
  }
  count--;
}

template<class T1>
inline ofstream& operator<<(ofstream& out, const TArrayList<T1> list)
{
  if (list.isEmpty())
    return out;
  int i = list.root;
  while (list.links[i] != -1)
  {
    out << list.data[i] << " ";
    i = list.links[i];
  }
  out << list.data[i] << " ";
  return out;
}

template<class T1>
inline ifstream& operator>>(ifstream& in, TArrayList<T1>& list)
{
  int count;
  in >> count;
  TArrayList<T1> res(count);
  for (int i = 0; i < count; i++) {
    T1 d;
    in >> d;
    res.insLast(d);
  }
  list = res;
  return in;
}

