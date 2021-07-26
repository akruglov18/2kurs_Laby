#ifndef _SORT_MAP_H
#define _SORT_MAP_H

#include "Map.h"
#include "Sorts.h"
#include <iostream>

enum class MapSorts
{
  bubble_sort = 0, quick_sort, insertion_sort, counting_sort, radix_sort
};

template <class TK, class TV>
class TIterSortMap;

template<class TK, class TV>
class TSortMap : public TMap<TK, TV>
{
private:
  int binary_search(const TNode<TK, TV>& node);
public:
  TSortMap(int size_ = 1000);
  TSortMap(int size_, TNode<TK, TV>* m, MapSorts _sort);
  TSortMap(const TSortMap<TK, TV>& p);

  virtual TV& operator[](TK i);

  virtual TV Find(TK k);
  virtual void Delete(TK k);
  virtual void Add(TK k, TV v);

  bool operator==(const TSortMap<TK, TV>& other) const;

  friend class TNode<TK, TV>;
  friend class TIterSortMap <TK, TV>;

  TIterSortMap<TK, TV> begin();
  TIterSortMap<TK, TV> end();

};

template<class TK, class TV>
inline int TSortMap<TK, TV>::binary_search(const TNode<TK, TV>& node)
{
  int ind = -1;
  int l = 0, r = this->count - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (node <= this->mas[mid]) {
      r = mid - 1; 
      ind = mid;
    }
    else {
      l = mid + 1;
    }
  }
  return ind;
}

template<class TK, class TV>
inline TSortMap<TK, TV>::TSortMap(int size_) : TMap<TK, TV>::TMap(size_)
{
}

template <class TK, class TV>
inline TSortMap<TK, TV>::TSortMap(int size_, TNode<TK, TV>* m, MapSorts _sort)
{
  size = size_;
  count = size_;
  mas = new TNode<TK, TV>[size_];
  for (int i = 0; i < size_; i++)
    mas[i] = m[i];
  switch (_sort)
  {
  case MapSorts::bubble_sort:
    BubbleSort(mas, size_);
    break;
  case MapSorts::counting_sort: 
    CountingSort(mas, size_);
    break;
  case MapSorts::quick_sort: 
    QuickSort(mas, size_);
    break;
  case MapSorts::insertion_sort: 
    InsertionSort(mas, size_);
    break;
  case MapSorts::radix_sort: 
    RadixSort(mas, size_);
    break;
  default:
    throw std::exception();
  }
}

template <class TK, class TV> 
inline TSortMap<TK, TV>::TSortMap(const TSortMap& p) : TMap<TK, TV>::TMap(p)
{

}

template <class TK, class TV>
inline TV& TSortMap<TK, TV>::operator[](TK k)
{
  int ind = binary_search(TNode<TK, TV>(k, TV{}));
  if (ind == -1) {
    if (count == size)
      this->Resize(2 * size);
    this->mas[count].key = k;
    this->mas[count].val = TV{};
    this->count++;
    return mas[count - 1].val;
  }
  else {
    if (mas[ind].key == k)
      return mas[ind].val;

    this->count++;
    if (this->count >= this->size)
      Resize(2 * this->size);

    for (int i = this->count; i > ind; i--)
      this->mas[i] = this->mas[i - 1];

    this->mas[ind] = TNode<TK, TV>(k, TV{});
      return mas[ind].val;
  }
}

template <class TK, class TV>
inline TV TSortMap<TK, TV>::Find(TK k)
{
  int ind = binary_search(TNode<TK, TV> (k, TV{}));
  if (ind != -1)
    return mas[ind].val;
  throw std::exception();
}

template <class TK, class TV>
inline void TSortMap<TK, TV>::Delete(TK k)
{
  int ind = binary_search(TNode<TK, TV>(k, TV{}));

  if (ind != -1)
  {
    for (int i = ind; i < this->count - 1; i++)
      this->mas[i] = this->mas[i + 1];

    this->mas[this->count - 1].key = TK{};
    this->mas[this->count - 1].val = TV{}; 
    count--;
  }
}

template <class TK, class TV>
inline void TSortMap<TK, TV>::Add(TK k, TV v){

  int ind = binary_search(TNode<TK, TV>(k, TV{}));

  if (ind == -1)
    ind = this->count;

  this->count++;

  if (this->count >= this->size)
    Resize(2 * this->size);

  for (int i = this->count; i > ind; i--)
    this->mas[i] = this->mas[i - 1];
  
  this->mas[ind] = TNode<TK, TV>(k, v);
}

template<class TK, class TV>
bool TSortMap<TK, TV>::operator==(const TSortMap<TK, TV>& other) const{
  if (count != other.count)
    return false;
  for (size_t j = 0; j < count; j++) {
    if (mas[j] != other.mas[j]) {
      return false;
    }
  }
  return true;
}

template<class TK, class TV>
inline TIterSortMap<TK, TV> TSortMap<TK, TV>::begin()
{
  return TIterSortMap<TK, TV>(*this, 0);
}

template<class TK, class TV>
inline TIterSortMap<TK, TV> TSortMap<TK, TV>::end()
{
  return TIterSortMap<TK, TV>(*this, count);
}

template <class TK, class TV>
class TIterSortMap
{
protected:
  TSortMap<TK, TV>& map;
  int index;
public:
  TIterSortMap(const TIterSortMap<TK, TV>& p);
  TIterSortMap(TSortMap<TK, TV>& p, int index = 0);
  TIterSortMap<TK, TV>& operator++();
  TIterSortMap<TK, TV>& operator--();
  TIterSortMap<TK, TV>& operator=(const TIterSortMap<TK, TV>& it);
  TV& operator*();
  bool operator==(const TIterSortMap<TK, TV>& it) const;
  bool operator!=(const TIterSortMap<TK, TV>& it) const;
};

template<class TK, class TV>
inline TIterSortMap<TK, TV>::TIterSortMap(const TIterSortMap<TK, TV>& p) : map(p.map), index(p.index)
{
}

template<class TK, class TV>
inline TIterSortMap<TK, TV>::TIterSortMap(TSortMap<TK, TV>& p, int _index) : map(p), index(_index)
{

}

template<class TK, class TV>
inline TIterSortMap<TK, TV>& TIterSortMap<TK, TV>::operator++()
{
  index++;
  return *this;
}

template<class TK, class TV>
inline TIterSortMap<TK, TV>& TIterSortMap<TK, TV>::operator--()
{
  index--;
  return *this;
}

template<class TK, class TV>
inline TIterSortMap<TK, TV>& TIterSortMap<TK, TV>::operator=(const TIterSortMap<TK, TV>& it)
{
  map = it.map;
  index = it.index;
}

template<class TK, class TV>
inline TV& TIterSortMap<TK, TV>::operator*()
{
  return map.mas[index].val;
}

template<class TK, class TV>
inline bool TIterSortMap<TK, TV>::operator==(const TIterSortMap<TK, TV>& it) const{
  return index == it.index && map == it.map;
}

template<class TK, class TV>
inline bool TIterSortMap<TK, TV>::operator!=(const TIterSortMap<TK, TV>& it) const {
  return !(*this == it);
}

#endif