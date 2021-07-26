#ifndef _TREE_H_
#define _TREE_H_

#include "TreeNode.h"
#include <iostream>
#include <fstream>
#include <stack>

template <class TK, class TV> 
class Tree {
protected:
	TreeNode<TK,TV>* root;

public:
	Tree();
	~Tree();
	//Tree(const Tree& p);

	TV& operator[](TK k);
	TV find(TK k);
	void erase(TK k);
	void insert(TK k, TV v);

	friend std::ostream& operator<<(std::ostream& o, Tree<TK,TV>& t) {
		print(o, t.root, 0);
		return o;
	}

	friend void print(std::ostream& o, TreeNode<TK, TV>* root, int level) {
		for (int i = 0; i < level; i++)
			o << "  ";
		o << root->GetVal() << "(" << root->height << ")" << std::endl;
		if (root->right != nullptr) {

			print(o, root->right, level + 1);
		}
		if (root->left != nullptr) {
			print(o, root->left, level + 1);
		}
	}

private:
	TreeNode<TK,TV>* find(TK k, std::stack<TreeNode<TK, TV>*>& path);
	TreeNode<TK, TV>* rotate_left(TreeNode<TK,TV>* node);
	TreeNode<TK, TV>* rotate_right(TreeNode<TK, TV>* node);
	TreeNode<TK, TV>* balance_node(TreeNode<TK, TV>* node);
	void balance_path(std::stack<TreeNode<TK,TV>*>& path);
};

template<class TK, class TV>
inline TreeNode<TK, TV>* Tree<TK, TV>::rotate_right(TreeNode<TK, TV>* node)
{
	TreeNode<TK, TV>* q = node->left;
	node->left = q->right;
	q->right = node;
	q->autoSetHeight();
	node->autoSetHeight();
	return q;
}

template<class TK, class TV>
inline TreeNode<TK, TV>* Tree<TK, TV>::rotate_left(TreeNode<TK, TV>* node)
{
	TreeNode<TK, TV>* q = node->right;
	node->right = q->left;
	q->left = node;
	node->autoSetHeight();
	q->autoSetHeight();
	return q;
}

template<class TK, class TV>
inline TreeNode<TK,TV>* Tree<TK, TV>::balance_node(TreeNode<TK, TV>* node)
{
	node->autoSetHeight();
	if (node->balance_factor() == 2) {
		if (node->right->balance_factor() < 0)
			node->right = rotate_right(node->right);
		return node = rotate_left(node);
	}
	if (node->balance_factor() == -2) {
		if (node->right->balance_factor() > 0)
			node->left = rotate_left(node->left);
		return node = rotate_right(node);
	}
	return node;
}

template<class TK, class TV>
inline void Tree<TK, TV>::balance_path(std::stack<TreeNode<TK, TV>*>& path)
{
	while (!path.empty())
	{
		path.top()->autoSetHeight();
		TreeNode<TK,TV>* cur = path.top();
		path.pop();
		cur = balance_node(cur);
		if (!path.empty()) {
			if (cur->key > path.top()->key) 
				path.top()->right = cur;
			else 
				path.top()->left = cur;
		}
		else root = cur;
	}
}

template<class TK, class TV>
inline Tree<TK, TV>::Tree() : root(nullptr)
{
}

template<class TK, class TV>
inline Tree<TK, TV>::~Tree()
{
	std::stack<TreeNode<TK,TV>*> path;
	path.push(root);
	while (!path.empty()) {
		TreeNode<TK,TV>* tmp = path.top();
		path.pop();
		if (tmp->right != nullptr) 
			path.push(tmp->right);
		if (tmp->left != nullptr) 
			path.push(tmp->left);
		delete tmp;
	}
	root = nullptr;
}

template<class TK, class TV>
inline TreeNode<TK, TV>* Tree<TK, TV>::find(TK k, std::stack<TreeNode<TK, TV>*>& path)
{
	if (root == nullptr)
		return nullptr;

	TreeNode<TK, TV>* cur = root;
	while (cur != nullptr) {
		if (k == cur->key) 
			return cur;
		TreeNode<TK, TV>* tmp = nullptr;
		if (k < cur->key) {
			tmp = cur->left;
		}
		else {
			tmp = cur->right;
		}
		path.push(cur);
		cur = tmp;
	}
	return nullptr;
}

template<class TK, class TV>
inline TV& Tree<TK, TV>::operator[](TK k)
{
	std::stack<TreeNode<TK, TV>*> path;
	TreeNode<TK, TV>* new_node = find(k, path);
	if (new_node != nullptr)
		return new_node->val;
	new_node = new TreeNode<TK, TV>(k, TV());
	if (path.empty())
		root = new_node;
	else {
		if (k > path.top()->key)
			path.top()->right = new_node;
		else
			path.top()->left = new_node;
	}
	balance_path(path);
	return new_node->val;
}

template<class TK, class TV>
inline TV Tree<TK, TV>::find(TK k)
{
	if (root == nullptr)
		throw std::exception();

	TreeNode<TK, TV>* cur = root;
	while (cur != nullptr) {
		if (k == cur->key)
			return cur->GetVal();
		TreeNode<TK, TV>* tmp = nullptr;
		if (k < cur->key) {
			tmp = cur->left;
		}
		else {
			tmp = cur->right;
		}
		cur = tmp;
	}
	throw std::exception();
}

template<class TK, class TV>
inline void Tree<TK, TV>::erase(TK k)
{
	std::stack<TreeNode<TK,TV>*> path;
	TreeNode<TK, TV>* delNode = find(k, path);
	if (delNode == nullptr) 
		return;
	if (delNode->left == nullptr && delNode->right == nullptr) {
		if (delNode == root) {
			delete delNode;
			root = delNode = root;
		}
		else {
			delete delNode;
			delNode = nullptr;
			if (k > path.top()->GetKey())
				path.top()->right = nullptr;
			else
				path.top()->left = nullptr;
		}
		balance_path(path);
		return;
	}
	if (delNode->left == nullptr || delNode->right == nullptr) {
		if (delNode == root) {
			if (delNode->left == nullptr) 
				root = delNode->right;
			else root = 
				delNode->left;
			delete delNode;
		}
		else {
			TreeNode<TK,TV>* cur = nullptr;
			if (delNode->left == nullptr) 
				cur = delNode->right;
			else 
				cur = delNode->left;
			delete delNode;

			if (k > path.top()->GetKey()) 
				path.top()->right = cur;
			else  
				path.top()->left = cur;
		}
		balance_path(path);
		return;
	}
	TreeNode<TK,TV>* swapNode = delNode->right;
	TreeNode<TK, TV>* prev = delNode;
	while (true) {
		if (swapNode->left != nullptr) {
			path.push(prev);
			prev = swapNode;
			swapNode = swapNode->left;
		}
		else break;
	}
	if (prev->left == swapNode)
		prev->left = swapNode->right;
	else {
		prev->right = swapNode->right;
	}
	delNode->SetKey(swapNode->GetKey());
	delNode->SetVal(swapNode->GetVal());
	balance_path(path);
	return;
}

template<class TK, class TV>
inline void Tree<TK, TV>::insert(TK k, TV v)
{
	std::stack<TreeNode<TK, TV>*> path;
	TreeNode<TK, TV>* new_node = find(k, path);
	if (new_node != nullptr)
		return;
	new_node = new TreeNode<TK, TV>(k, v);
	if (path.empty())
		root = new_node;
	else {
		if (k > path.top()->key)
			path.top()->right = new_node;
		else
			path.top()->left = new_node;
	}
	balance_path(path);
}

#endif