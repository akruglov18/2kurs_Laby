#ifndef _HASH_MAP_H_
#define _HASH_MAP_H_

#include "Map.h"
#include "Node.h"
#include <vector>


template <class TK, class TV>
class THashMap
{
private:

public:
  THashMap(int size_ = 1);
  THashMap(const THashMap& p);


  TV& operator[](TK i);

   TV Find(TK k);
   void Delete(TK k);
   void Add(TK k, TV v);

protected:
  int Hash(TK k);
  std::vector<std::vector<TNode<TK,TV>>> data;
};

template <class TK, class TV>
int THashMap<TK, TV>::Hash(TK k)
{
  return abs(k);
}

template <class TK, class TV>
THashMap<TK, TV>::THashMap(int size_) : data(size_)
{
  
}

template <class TK, class TV>
THashMap<TK, TV>::THashMap(const THashMap& p) : data(p.data)
{
}

template <class TK, class TV>
TV& THashMap<TK, TV>::operator[](TK key)
{
  int ind = Hash(key) % data.size();

  for (int i = 0; i < data[ind].size(); i++)
  {
    if (data[ind][i].key == key) {
      return data[ind][i].val;
    }
  }
  data[ind].push_back(TNode<TK, TV>(key, TV{}));
  return data[ind].back().val;
}

template <class TK, class TV>
TV THashMap<TK, TV>::Find(TK key)
{
  int ind = Hash(key) % data.size();

  for (int i = 0; i < data[ind].size(); i++)
  {
    if (data[ind][i].key == key) {
      return data[ind][i].val;
    }
  }
  throw - 1;
}

template <class TK, class TV>
void THashMap<TK, TV>::Delete(TK key)
{
  int ind = Hash(key) % data.size();

  for (int i = 0; i < data[ind].size(); i++)
  {
    if (data[ind][i].key == key) {
      data[ind].erase(data[ind].begin() + i);
      return;
    }
  }
}

template <class TK, class TV>
void THashMap<TK, TV>::Add(TK k, TV v)
{
  int ind = Hash(k) % data.size();
  data[ind].push_back(TNode<TK, TV>(k, v));
}
#endif