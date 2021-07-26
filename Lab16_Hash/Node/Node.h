#ifndef _NODE_H
#define _NODE_H

template <class TK, class TV> class TMap;
template <class TK, class TV> class THashMap;
template <class TK, class TV> class TSortMap;
template <class TK, class TV> class TIterSortMap;

template <class TK, class TV>
class TNode {
protected:
	TK key;
	TV val;

public:
	TNode(TK k = 0, TV v = 0);
	TNode(const TNode& p);

	TK GetKey();
	TV GetVal();

	void SetKey(TK k);
	void SetVal(TV v);

	TNode& operator=(const TNode<TK, TV>& p);

	bool operator==(const TNode<TK, TV>& p) const;
	bool operator!=(const TNode<TK, TV>& p) const;
	bool operator>(const TNode<TK, TV>& p) const;
	bool operator<(const TNode<TK, TV>& p) const;
	bool operator>=(const TNode<TK, TV>& p) const;
	bool operator<=(const TNode<TK, TV>& p) const;

	friend class TMap<TK, TV>;
	friend class TSortMap<TK, TV>;
	friend class TIterSortMap<TK, TV>;
	friend class THashMap<TK, TV>;
};

template <class TK, class TV> 
inline TNode<TK, TV>::TNode(TK k, TV v) {
	key = k;
	val = v;
}

template <class TK, class TV> 
inline TNode<TK, TV>::TNode(const TNode& p) {
	key = p.key;
	val = p.val;
}

template <class TK, class TV> 
inline TK TNode<TK, TV>::GetKey() {
	return key;
}

template <class TK, class TV> 
inline TV TNode<TK, TV>::GetVal() {
	return val;
}

template <class TK, class TV> 
inline void TNode<TK, TV>::SetKey(TK k) {
	key = k;
}

template <class TK, class TV> 
inline void TNode<TK, TV>::SetVal(TV v) {
	val = v;
}

template <class TK, class TV> 
inline bool TNode<TK, TV>::operator==(const TNode<TK, TV>& p) const {
	bool res = false;

	if (p.key == this->key)
		res = true;

	return res;
}

template<class TK, class TV>
inline bool TNode<TK, TV>::operator!=(const TNode<TK, TV>& p) const
{
	return !(*this == p);
}

template <class TK, class TV> 
inline bool TNode<TK, TV>::operator>(const TNode<TK, TV>& p) const {
	bool res = false;

	if (this->key > p.key)
		res = true;

	return res;
}

template <class TK, class TV> 
inline bool TNode<TK, TV>::operator<(const TNode<TK, TV>& p) const{
	bool res = false;

	if (key < p.key)
		res = true;

	return res;
}

template<class TK, class TV>
inline bool TNode<TK, TV>::operator>=(const TNode<TK, TV>& p) const
{
	return *this == p || *this > p;
}

template<class TK, class TV>
inline bool TNode<TK, TV>::operator<=(const TNode<TK, TV>& p) const
{
	return *this == p || *this < p;
}

template <class TK, class TV>
inline TNode<TK, TV>& TNode<TK, TV>::operator=(const TNode<TK, TV>& p) {
	this->key = p.key;
	this->val = p.val;
	return *this;
}

#endif // !_NODE_H