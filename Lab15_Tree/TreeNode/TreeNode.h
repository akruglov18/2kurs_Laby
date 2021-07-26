#ifndef _TREE_NODE_H
#define _TREE_NODE_H

#include "Node.h"

template <class TK, class TV>
class Tree;

template<typename TK, typename TV>
class TreeNode : public TNode<TK, TV> {
public:
  TreeNode* left;
  TreeNode* right;
  int height;
public:
  TreeNode();
  TreeNode(TK k = 0, TV v = 0);
  TreeNode(const TreeNode<TK, TV>& p);
  void autoSetHeight();
  int balance_factor();
  
  friend class Tree<TK, TV>;
};



template<typename TK, typename TV>
inline TreeNode<TK, TV>::TreeNode() : left(nullptr), right(nullptr)
{
}

template<typename TK, typename TV>
inline TreeNode<TK, TV>::TreeNode(TK k, TV v) : TNode<TK, TV>::TNode(k, v), left(nullptr), right(nullptr), height(1)
{
}


template<typename TK, typename TV>
inline TreeNode<TK, TV>::TreeNode(const TreeNode<TK, TV>& p) : TNode<TK, TV>::TNode(p), left(p.left)
, right(p.right), height(p.height)
{
}

template<typename TK, typename TV>
inline void TreeNode<TK, TV>::autoSetHeight()
{
  int hl = 0;
  if (left != nullptr)
    hl = left->height;
  int hr = 0;
  if (right != nullptr)
    hr = right->height;
  height = std::max(hl, hr) + 1;
}

template<typename TK, typename TV>
inline int TreeNode<TK, TV>::balance_factor()
{
  if (this == nullptr)
    return 0;
  int lh = 0, rh = 0;
  if (left != nullptr) lh = left->height;
  if (right != nullptr) rh = right->height;
  return rh - lh;
}

#endif