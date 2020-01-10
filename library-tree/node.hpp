#pragma once
#include "book.hpp"
template <typename T>
class Node
{
		private:
			T* data;
			Node<T>* left = nullptr;
			Node<T>* right = nullptr;
		public:
			Node (T *v);
			T* GetValue ();
			void SetRight(Node<T> *v);
			void SetLeft(Node<T> *v);
			Node<T>* GetRight();
			Node<T>* GetLeft();

};
