#ifndef _HASH_LIST_MAP_H_
#define _HASH_LIST_MAP_H_

#include "Node.h"
#include <iostream>
#include <fstream>
#include <stack>

template <class TK, class TV>
class THashListMap;

template <class TK, class TV>
class THashListNode
{
public:
  THashListNode(TK k = 0, TV v = 0);
  THashListNode(const THashListNode& p);

  THashListNode& operator=(const THashListNode& p);
protected:
  TK key;
  TV val;
  THashListNode* next;
  friend class THashListMap<TK, TV>;
};

template <class TK, class TV>
THashListNode<TK, TV>::THashListNode(TK k, TV v) : key(k), val(v), next(nullptr)
{
}

template <class TK, class TV>
THashListNode<TK, TV> ::THashListNode(const THashListNode& p) : key(p.k), val(p.v), next(nullptr)
{
}

template <class TK, class TV>
THashListNode<TK, TV>& THashListNode<TK, TV> :: operator=(const THashListNode& p)
{
  if (this != &p) {
    key = p.key;
    val = p.val;
    next = nullptr;
  }
  return *this;
}

template <class TK, class TV>
class THashListMap {
protected:
  THashListNode<TK, TV>** mas;
  int size;
  int count;

  void Resize(int newSize);
  virtual int Hash(TK k);
public:
  THashListMap(int size_ = 1000);
  THashListMap(const THashListMap& p);
  virtual ~THashListMap();

  virtual TV& operator[](TK i);

  virtual TV Find(TK k);
  virtual void Delete(TK k);
  virtual void Add(TK k, TV v);
};

template <class TK, class TV>
void THashListMap<TK, TV>::Resize(int newSize) {
  THashListNode<TK, TV>** oldMas = mas;
  int oldSize = size;
  size = newSize;
  count = 0;
  mas = new THashListNode<TK, TV>*[size];
  for (int i = 0; i < size; i++)
    mas[i] = nullptr;
  for (int i = 0; i < oldSize; i++) {
    THashListNode<TK, TV>* cur = oldMas[i];
    THashListNode<TK, TV>* del;
    while (cur != nullptr) {
      Add(cur->key, cur->val);
      del = cur;
      cur = cur->next;
      delete del;
    }
  }
  delete[] oldMas;
}

template <class TK, class TV>
int THashListMap<TK, TV>::Hash(TK k)
{
  return abs(k);
}

template <class TK, class TV>
THashListMap<TK, TV>::THashListMap(int size_)
{
  size = size_;
  if (size_ <= 0)
    throw - 1;
  else
    mas = new THashListNode<TK, TV>*[size];
  for (int i = 0; i < size; i++)
    mas[i] = nullptr;
  count = 0;
}

template <class TK, class TV>
THashListMap<TK, TV>::THashListMap(const THashListMap& p) {
  size = p->size;
  count = p->count;
  mas = new THashListNode<TK, TV>*[size];
  for (int i = 0; i < size; i++) {
    if (p->mas[i] == 0)
      mas[i] = 0;
    else {
      mas[i] = new THashListNode<TK, TV>(*(p->mas[i]));
      THashListNode<TK, TV>* iter = p->mas[i];
      while (iter) {
        THashListNode<TK, TV>* tmp = new THashListNode<TK, TV>(&iter);
        tmp->next = mas[i];
        mas[i] = tmp;
        iter = iter->next;
      }
    }
  }
}

template <class TK, class TV>
THashListMap<TK, TV>::~THashListMap() {
  std::stack<THashListNode<TK, TV>*> st;
  for (int i = 0; i < size; i++) {
    THashListNode<TK, TV>* cur = mas[i];
    while (cur != nullptr) {
      st.push(cur);
      cur = cur->next;
    }
  }
  while (!st.empty()) {
    delete st.top();
    st.pop();
  }
}

template <class TK, class TV>
TV& THashListMap<TK, TV>::operator[](TK i)
{
  int index = Hash(i) % size;
  THashListNode<TK, TV>* cur = mas[index];
  if (cur == nullptr)
  {
    cur = new THashListNode<TK, TV>(i, TV{});
    mas[index] = cur;
    return mas[index]->val;
  }
  else
  {
    while (cur->key != i)
    {
      cur = cur->next;
      if (cur == 0)
      {
        break;
      }
    }
    if (cur != nullptr)
    {
      return cur->val;
    }
    else
    {
      cur = new THashListNode<TK, TV>();
      cur->key = i;
      if (mas[index] == nullptr) {
        mas[index] = cur;
      }
      else {
        cur->next = mas[index];
        mas[index] = cur;
      }
      return cur->val;
    }
  }
}

template <class TK, class TV>
TV THashListMap<TK, TV>::Find(TK k)
{
  int ind = Hash(k) % size;
  if (mas[ind] != 0)
  {
    THashListNode<TK, TV>* cur = mas[ind];
    while (cur->key != k)
    {
      cur = cur->next;
      if (cur == 0)
      {
        throw - 1;
      }
    }
    return cur->val;
  }
  else
  {
    throw - 1;
  }

}

template <class TK, class TV>
void THashListMap<TK, TV>::Delete(TK k)
{
  int ind = Hash(k) % size;
  if (mas[ind] != 0)
  {
    THashListNode<TK, TV>* cur = mas[ind];
    THashListNode<TK, TV>* prev = nullptr;
    while (cur->key != k)
    {
      prev = cur;
      cur = cur->next;
      if (cur == 0)
        return;
    }
    if (prev == nullptr) {
      mas[ind] = cur->next;
    }
    else {
      prev->next = cur->next;
    }
    delete cur;
  }
}

template <class TK, class TV>
void THashListMap<TK, TV>::Add(TK k, TV v)
{
  int ind = Hash(k) % size;
  if (mas[ind] == 0)
  {
    mas[ind] = new THashListNode<TK, TV>(k, v);
  }
  else
  {
    THashListNode<TK, TV>* cur = mas[ind];
    mas[ind] = new THashListNode<TK, TV>(k, v);
    mas[ind]->next = cur;
  }
  count++;
  if (count >= size)
    Resize(size * 2);
}
#endif