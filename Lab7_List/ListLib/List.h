#pragma once
#include<fstream>
#include<exception>
#include<TListElem.h>

using namespace std;

template<class T>
class TListIterator;

template<class T>
class TList {
private:
  TListElem<T>* _root;
  TListElem<T>* _end;
  int count;

public:
  TList();
  TList(const TList<T>& list);
  ~TList();

  TList<T>& operator=(const TList<T>& list);

  void insFirst(T d);
  void insLast(T d);
  void insert(TListIterator<T>& it, T d);
  void delFirst();
  void delLast();
  void erase(TListIterator<T>& it);

  TListIterator<T> begin();
  TListIterator<T> end();
  TListIterator<T> cbegin() const;
  TListIterator<T> cend() const;

  bool isEmpty() const;
  bool isFull() const;

  TListElem<T>* getFirst() const;
  TListElem<T>* getLast() const;
  int getCount() const;
  TList<T> get_Kdivisible(T k);

  template<class T1>
  friend ofstream& operator<<(ofstream& out, const TList<T1> list);
  template<class T1>
  friend ifstream& operator>> (ifstream& in, TList<T1>& list);

  friend class TListIterator<T>;
};





//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------iterator begin


template<class T>
class TListIterator {
protected:
  TListElem<T>* elem;
public:
  TListIterator() = delete;
  explicit TListIterator(TListElem<T>* _elem);
  TListIterator(const TListIterator<T>& it);
  ~TListIterator();

  bool isGoNext();
  void goNext();

  T getData();

  bool operator==(const TListIterator<T>& it);
  TListIterator<T>& operator++();
  TListIterator<T>& operator=(const TListIterator<T>& it);

  friend class TList<T>;
};

template<class T>
inline TListIterator<T>::TListIterator(TListElem<T>* _elem) : elem(_elem)
{
}

template<class T>
inline TListIterator<T>::TListIterator(const TListIterator<T>& it) : elem(it.elem)
{
}

template<class T>
inline TListIterator<T>::~TListIterator()
{
  elem = 0;
}

template<class T>
inline bool TListIterator<T>::isGoNext()
{
  return elem->getNext() != 0;
}

template<class T>
inline void TListIterator<T>::goNext()
{
  if (isGoNext()) {
    elem = elem->getNext();
    return;
  }
  throw new std::exception();
}

template<class T>
inline T TListIterator<T>::getData()
{
  if (elem == 0)
    throw new std::exception();
  return elem->getData();
}

template<class T>
inline bool TListIterator<T>::operator==(const TListIterator<T>& it)
{
  return this == &it;
}

template<class T>
inline TListIterator<T>& TListIterator<T>::operator++()
{
  goNext();
  return *this;
}

template<class T>
inline TListIterator<T>& TListIterator<T>::operator=(const TListIterator<T>& it)
{
  elem = it.elem;
}


//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------iterator end

template<class T>
inline TList<T>::TList()
{
  _root = 0;
  _end = 0;
  count = 0;
}

template<class T>
inline TList<T>::TList(const TList<T>& list)
{
  _root = 0;
  _end = 0;
  count = 0;
  TListElem<T>* i = list._root;
  while (i != 0) {
    this->insLast(i->getData());
    i = i->getNext();
  }
  count = list.count;
}

template<class T>
inline TList<T>::~TList()
{
  if (_root != 0) {
    TListElem<T>* i = _root;
    TListElem<T>* p = 0;
    while (i != 0 && count) {
      p = i;
      i = i->getNext();
      delete p;
      p = 0;
      count--;
    }
  }
  _root = _end = 0;
}

template<class T>
inline TList<T>& TList<T>::operator=(const TList<T>& list)
{
  if (this == &list)
    return *this;

  if (this->_root != 0) {
    TListElem<T>* i = _root;
    TListElem<T>* p = 0;
    while (i != 0 && count) {
      p = i;
      i = i->getNext();
      delete p;
      count--;
    }
    _root = _end = 0;
  }


  TListElem<T>* i = list._root;
  TListElem<T>* j;
  count = 0;
  while (i != 0) {
    j = new TListElem<T>(*i);
    this->insLast(j->getData());
    i = i->getNext();
  }
  count = list.count;
  return *this;
}

template<class T>
inline void TList<T>::insFirst(T d)
{
  if (isFull())
    throw new std::exception();
  if (_root == 0) {
    _root = new TListElem<T>(d);
    _end = _root;
  }
  else {
    TListElem<T>* tmp = new TListElem<T>(d);
    tmp->setNext(_root);
    tmp->setPrev(0);
    _root->setPrev(tmp);
    _root = tmp;
  }
  count++;
}

template<class T>
inline void TList<T>::insLast(T d)
{
  if (isFull())
    throw new std::exception();
  if (_root == 0) {
    insFirst(d);
  }
  else {
    TListElem<T>* tmp = new TListElem<T>(d);
    _end->setNext(tmp);
    tmp->setPrev(_end);
    tmp->setNext(0);
    _end = tmp;
    count++;
  }
}

template<class T>
inline void TList<T>::insert(TListIterator<T>& it, T d)
{
  if (isFull() || it.elem == 0)
    throw new std::exception();
  TListElem<T>* tmp = new TListElem<T>(d);
  tmp->setNext(it.elem->getNext());
  tmp->setPrev(it.elem);
  if (it.elem->getNext() != 0) {
    it.elem->getNext()->setPrev(tmp);
  }
  it.elem->setNext(tmp);
  count++;
}

template<class T>
inline bool TList<T>::isEmpty() const
{
  return count == 0;
}

template<class T>
inline bool TList<T>::isFull() const
{
  try {
    TListElem<T>* e = new TListElem<T>();
    delete e;
    return false;
  }
  catch (...) {
    return true;
  }
}

template<class T>
inline TListElem<T>* TList<T>::getFirst() const
{
  if (isEmpty())
    throw new std::exception();
  return _root;
}

template<class T>
inline TListElem<T>* TList<T>::getLast() const
{
  if (isEmpty())
    throw new std::exception();
  return _end;
}

template<class T>
inline int TList<T>::getCount() const
{
  return count;
}

template<class T>
inline TList<T> TList<T>::get_Kdivisible(T k)
{
  TListElem<T>* i = _root;
  TList<T> res;
  while (i != 0) {
    if (i->getData() % k == 0)
      res.insLast(i->getData());
    i = i->getNext();
  }
  return res;
}

template<class T>
inline void TList<T>::delFirst()
{
  if (isEmpty())
    throw new std::exception();
  TListElem<T>* tmp = _root;
  _root = _root->getNext();
  if (_root != 0)
    _root->setPrev(0);
  delete tmp;
  tmp = 0;
  count--;
}

template<class T>
inline void TList<T>::delLast()
{
  if (isEmpty())
    throw new std::exception();
  TListElem<T>* tmp = _end;
  _end = _end->getPrev();
  if (_end != 0)
    _end->setNext(0);
  delete tmp;
  tmp = 0;
  count--;
}

template<class T>
inline void TList<T>::erase(TListIterator<T>& it)
{
  if (it.elem == 0) {
    throw new std::exception();
  }
  it.elem->getPrev()->setNext(it.elem->getNext());
  it.elem->getNext()->setPrev(it.elem->getPrev());
  count--;
  delete it.elem;
}

template<class T>
TListIterator<T> TList<T>::begin() {
  return TListIterator<T>(_root);
}

template<class T>
TListIterator<T> TList<T>::end() {
  return TListIterator<T>(_end);
}

template<class T>
inline TListIterator<T> TList<T>::cbegin() const
{
  return TListIterator<T>(_root);
}

template<class T>
inline TListIterator<T> TList<T>::cend() const
{
  return TListIterator<T>(_end);
}

template<class T1>
inline ofstream& operator<<(ofstream& out, const TList<T1>& list)
{
  TListElem<T1>* i = list._root;
  while (i != 0) {
    out << *i << " ";
    i = i->getNext();
  }
  return out;
}

template<class T1>
inline ifstream& operator>>(ifstream& in, TList<T1>& list)
{
  int cnt;
  in >> cnt;
  list.count = cnt;
  for (int i = 0; i < cnt; i++)
  {
    T1 d;
    in >> d;
    list.insLast(d);
  }
  return in;
}
