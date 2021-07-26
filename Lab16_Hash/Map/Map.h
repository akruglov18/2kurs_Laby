#ifndef _MAP_H_
#define _MAP_H_

#include "Node.h"
#include <iostream>
#include <fstream>

template <class TK, class TV> 
class TMap {
protected:
	TNode<TK, TV>* mas;
	int size;
	int count;

	void Resize(int newSize);

public:
	TMap(int size_ = 1000);
	TMap(const TMap& p);
	virtual ~TMap();

	virtual TV& operator[](TK i);

	virtual TV Find(TK k);
	virtual void Delete(TK k);
	virtual void Add(TK k, TV v);

	virtual bool Save(std::string fileName);
	virtual bool Load(std::string fileName);

	friend class TNode<TK, TV>;
};

template <class TK, class TV> 
inline void TMap<TK, TV>::Resize(int newSize) {
	TNode<TK, TV>* tmp;
	tmp = new TNode<TK, TV>[newSize];
	for (int i = 0; i < std::min(this->size, newSize); i++)
		tmp[i] = mas[i];
	delete[] mas;
	mas = tmp;
	this->size = newSize;
}


template <class TK, class TV> 
inline TMap<TK, TV>::TMap(int size_) {
	size = size_;
	count = 0;
	if (size_ <= 0)
		throw - 1;
	else
		mas = new TNode<TK, TV>[size];
}


template <class TK, class TV> 
inline TMap<TK, TV>::TMap(const TMap<TK, TV>& p) {
	this->size = p.size;
	this->count = p.count;
	this->mas = new TNode<TK, TV>[p.size];
	for (int i = 0; i < p.count; i++)
		this->mas[i] = p.mas[i];
}

template <class TK, class TV>
inline TMap<TK, TV>::~TMap() {
	if (mas != nullptr)
		delete[] mas;
	mas = nullptr;
	size = 0;
	count = 0;
}

template <class TK, class TV>
inline TV& TMap<TK, TV>::operator[](TK i) {
	for (size_t j = 0; j < count; j++) {
		if (mas[j].key == i) {
			return mas[j].val;
		}
	}
	if (count == size)
		Resize(size * 2);
	mas[count].key = i;
	mas[count].val = TV{};
	count++;
	return mas[count - 1].val;
}

template <class TK, class TV>
inline TV TMap<TK, TV>::Find(TK k) {
	for (int i = 0; i < this->count; i++) {
		if (mas[i].key == k)
			return this->mas[i].val;
	}
	throw - 1;
}

template <class TK, class TV> 
inline void TMap<TK, TV>::Delete(TK k) {
	for (int i = 0; i < count; i++) {
		if (mas[i].key == k) {
			for (int j = i; j < count - 1; j++) {
				mas[j] = mas[j + 1];
			}
			count--;
			return;
		}
	}
}

template <class TK, class TV> 
inline void TMap<TK, TV>::Add(TK k, TV v) {
	if (count == size)
		Resize(size * 2);
	mas[count].key = k;
	mas[count].val = v;
	count++;
}

template<class TK, class TV>
inline bool TMap<TK, TV>::Save(std::string fileName)
{
	std::ofstream fout(fileName);
	if (fout.is_open()) {
		fout << size << ' ' << count <<'\n';
		for (int i = 0; i < count; i++) {
			fout << mas[i].key << " " << mas[i].val << "\n";
		}
		fout.close();
		return true;
	}
	return false;
}

template<class TK, class TV>
inline bool TMap<TK, TV>::Load(std::string fileName)
{
	std::ifstream fin(fileName);
	if (fin.is_open()) {
		if (mas != nullptr) {
			delete[] mas;
			mas = nullptr;
		}
		fin >> size >> count;
		mas = new TNode<TK, TV>[size];
		for (int i = 0; i < count; i++) {
			TK k;
			TV v;
			fin >> k >> v;
			mas[i] = TNode<TK, TV>(k, v);
		}
		fin.close();
		return true;
	}
	return false;
}

#endif