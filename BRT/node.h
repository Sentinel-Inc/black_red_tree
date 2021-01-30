#ifndef NODE_H
#define NODE_H

#include <assert.h>

template<class T>
class node {
public:

	// consider removing this outside the class 
	// fixes warning and does not change anything
	static const enum Color {
		red = 0,
		black = 1
	};

	node();
	node(T);
	node(node<T>*, Color, T);
	node<T>& operator=(const node<T>&);
	node(const node<T>&);
	node<T>* search(const T&);
	node<T>* acces_or_asign(const T&);
	node<T>* end();
	node<T>* next(const T& previous_value);
	node<T>* in_order(unsigned&);
	size_t size();

	void append(const T& value);
	void append_or_replace(const T& value);

	T& get_value();
	~node();

protected:

	T value;
	Color color;
	node<T>* father;
	node<T>* left;
	node<T>* right;

};

template<class T>
inline node<T>::node()

	:father(nullptr),
	left(nullptr),
	right(nullptr),
	color(node<T>::black),
	value(NULL)
{} // and waht's the diffrence? 


template<class T>
inline node<T>::node(T value)
{
	father = nullptr;
	left = nullptr;
	right = nullptr;
	color = node<T>::black;
	this->value = value;

}

template<class T>
inline node<T>::node(node<T>* father, Color color, T value)
{
	this->father = father;
	left = nullptr;
	right = nullptr;
	this->color = color;
	this->value = value;

}

template<class T>
inline node<T>& node<T>::operator=(const node<T>& other)
{

	if (this == &other) return *this;
	father = nullptr;

	color = other.color;
	value = other.value;

	if (!other.left)left = new node<T>(other.left);   // todo this shiet is crazy
	if (!other.right)right = node<T>(other.right);
	return *this;
}


template<class T>
inline node<T>::node(const node<T>& other)
{
	father = nullptr;

	color = other.color;
	value = other.value;

	if (other.left) {
		left = new node<T>(*other.left);
		left->father = this;
	}
	else left = nullptr;
	if (other.right) {
		right = new  node<T>(*other.right);
		right->father = this;
	}
	else right = nullptr;

}

template<class T>
inline node<T>* node<T>::search(const T& value)
{
	if (this->value == value) return this;

	node<T>* ptr_to_return = nullptr;

	if (value < this->value && left) ptr_to_return = left->search(value);

	if (value > this->value && right) ptr_to_return = right->search(value);

	return ptr_to_return;
}

template<class T>
inline node<T>* node<T>::acces_or_asign(const T& value)
{
	if (value == this->value) return this;

	if (value < this->value) {
		if (left) return left->acces_or_asign(value);
		else left = new node<T>(this, node<T>::black, value);
		return left;
	}

	if (value > this->value) {
		if (right) return right->acces_or_asign(value);
		else right = new node<T>(this, node<T>::black, value);
		return right;

	}

	// this should never happen :
	assert(false);
	return nullptr;
}

template<class T>
inline node<T>* node<T>::end()
{

	if (right) return right->end();
	if (left) return left->end();

	return this;

	//if (!right) return this;
	//else return right->end();



}

template<class T>
inline node<T>* node<T>::next(const T& previous_value)
{

	if (previous_value == this->value && left) return left;
	if (previous_value == this->value && right) return right;

	if (previous_value < value) {
		if (right) return right;
		else if (father)return father->next(value);
		else return nullptr;

	}
	if (father)return father->next(value);
	else return nullptr;

}

template<class T>
inline node<T>* node<T>::in_order(unsigned& counter)
{

	if (counter == 0) return this;
	counter--;
	node<T>* ptr_to_return = nullptr;

	if (left) ptr_to_return = left->in_order(counter);
	if (ptr_to_return) return ptr_to_return;
	if (right) ptr_to_return = right->in_order(counter);
	if (ptr_to_return) return ptr_to_return;

	return nullptr;

}

template<class T>
inline size_t node<T>::size()
{
	size_t partial_sum = 1;
	if (left)partial_sum += left->size();
	if (right)partial_sum += right->size();
	return partial_sum;

}

template<class T>
inline void node<T>::append(const T& value)
{


	if (value < this->value && left) left->append(value);
	if (value < this->value && !left) left = new node<T>(this, node<T>::black, value);

	if (value > this->value && right) right->append(value);
	if (value > this->value && !right) right = new node<T>(this, node<T>::black, value);


}

template<class T>
inline void node<T>::append_or_replace(const T& value)
{

	if (value < this->value && left) left->append(value);
	else if(!left) this->left = new node<T>(this, node<T>::black, value);

	if (value > this->value && right) right->append(value);
	else if(!right) this->right = new node<T>(this, node<T>::black, value);


	this->value = value;

}

template<class T>
inline T& node<T>::get_value()
{
	return value;
}

template<class T>
inline node<T>::~node()
{
	if (!left)delete left;
	if (!right)delete right;
	// if (!father)delete father // almost made dodo
}


#endif // !NODE_H
