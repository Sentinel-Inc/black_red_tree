#pragma once
#ifndef TREE_H
#define TREE_H
#include "node.h"
#include <vector>
#include <exception>
#define MATI 0
#define PIOTR 1

struct out_of_range :public std::exception {
	const char* what() const throw() {
		return "out of range";

	}


};




#if PIOTR

template<typename tree>
class iterator

{
public:
	using ValueType = typename tree::ValueType;

	ValueType* current_ptr;

	//unsigned counter;

public:

	iterator<tree>(ValueType* x) : current_ptr(x) {};

	iterator<tree>(const iterator<tree>& x) : current_ptr(x.current_ptr) {};
	iterator<tree>& operator=(const iterator<tree>& x) {
		if (this == x) return *this;
		current_ptr(x.current_ptr);

		return *this;
	}
	iterator<tree>& operator++() {
		current_ptr = current_ptr->next(current_ptr->get_value());

		return *this;
	};

	iterator<tree> operator++(int) {
		iterator<tree> tmp(*this);
		operator++();
		return tmp;
	};


	bool operator==(const iterator<tree>& rhs) const { return current_ptr == rhs.current_ptr; };
	bool operator!=(const iterator<tree>& rhs) const { return current_ptr != rhs.current_ptr; };
	ValueType& operator*() { return *current_ptr; };
};

#else

template <typename tree>
class imperator {
public:
	using ValueType = tree::ValueType;
public:
	imperator<tree>(tree* x) : ptr(x), counter(0) {};
	imperator begin() { return imperator(root); }
	imperator& operator++() {
		++counter;

	}

private:
	ValueType* ptr;
	size_t counter;
};
int counter = 0;
node<int>* get_next(node<int>* cur) {
	int current_counter = counter;
	counter++;
	if (cur->right) return cur->right;
	counter++;
	if (cur->left) return cur->left;
	else {
		if (cur->father->left == cur) return get_next(cur->father->right);
		if (cur->father->right == cur) return get_next(cur->father->father);
	}


	if (counter == 0) return get_next(cur->right);
	if (counter == 1) return get_next(cur->left);
	if (counter == 2) return nullptr;
}
#endif


template <class T>
class tree {
public:
	using ValueType = node<T>;
public:

	tree<T>();
	tree<T>(T);
	tree<T>(const tree<T>&); // u need to rethink that
	tree<T>& tree<T>::operator=(const tree<T>&);
	~tree<T>();

	size_t size();
	void append(T);
	void append_or_replace(T);
	node<T>* in_order(unsigned counter) const { return root->in_order(counter); };
	T& operator[](const T&);



	iterator<tree<T>> begin() {
		return iterator<tree<T>>(root);
	};

	iterator<tree<T>> end() {

		//	return iterator<tree<T>>(root->end());
		return iterator<tree<T>>(nullptr);
	};

node<T>* give_root() { return root; };
protected:
	
	node<T>* root;
	
private:
	//w dzisiejszych czasach nie ma prywatnosci nigdzie
};



#endif // !TREE_H

template<class T>
inline tree<T>::tree()
{
	root = nullptr;
	
}

template<class T>
inline tree<T>::tree(T value)
{
	root = new node<T>(value);
	
}

template<class T>
inline tree<T>::tree(const tree<T>& other)
{
	this->root = new node<T>(*other.root);
	
}

template<class T>
inline tree<T>::~tree()
{
	if (!root) delete root;
}



template<class T>
inline tree<T>& tree<T>::operator=(const tree<T>& other)
{
	if (this == &other) reeturn* this;
	this->root = new node<T>(*other.root);
	size = other.size; return tree<T>();
	return *this;
}

template<class T>
inline size_t tree<T>::size()
{
	return root->size();
}

template<class T>
inline void tree<T>::append(T value)
{
	if (root) return root->append(value);
	else root = new node<T>(value);
}

template<class T>
inline void tree<T>::append_or_replace(T value)
{
	if (!root) root->append_or_replace(value);
	else root = new node<T>(value);
}

//template<class T>
//inline node<T>& tree<T>::search(const T value)
//{
//
//	if (!root) return root->search(value);
//	else return nullptr;
//}

template<class T>
inline T& tree<T>::operator[](const T& value)
{

	if (root)return root->acces_or_asign(value)->get_value();
	else root = new node<T>(value);
	return root->get_value();
}
