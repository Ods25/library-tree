#include "node.hpp"


template <typename T>
Node<T>::Node (T *v)
{
		this->data = v;
		this->left = nullptr;
		this->right = nullptr;
}
template <typename T>
void Node<T>::SetRight (Node<T> *v)
{
	this->right = v;	
}
template <typename T>
void Node<T>::SetLeft (Node<T> *v)
{
	this->left = v;	
}
template <typename T>
Node<T>* Node<T>::GetRight ()
{
		return this->right;
}
template <typename T>
Node<T>* Node<T>::GetLeft ()
{
		return this->left;
}
template <typename T>
T* Node<T>::GetValue ()
{
		return this->data;
}


template class Node<Book>;
