#pragma once

#include "node.hpp"
#include <string>
#include <sstream>
template <typename T>
class Tree
{

		private:
			Node<T>* root;
			void DeleteSubTree (Node<T>* subtreeRoot);
			bool sFD = true;
		public:
			Tree ();
			~Tree ();
			void Insert (T* value);
			Node<T>* GetRoot ();
			std::string Traverse (bool showFullDetails = true);
			std::string RecursivePrintTree (Node<T>* subtreeRoot);
			Node<T>* Search(std::string S);
			Node<T>* RecursiveSearch(std::string S, Node<T>* currentRoot);


};
