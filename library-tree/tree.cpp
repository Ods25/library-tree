#include "tree.hpp"
template <typename T>
Tree<T>::Tree ()
{
    this->root = nullptr;
}

template <typename T>
Tree<T>::~Tree ()
{
	this->DeleteSubTree(this->root);
}
template <typename T>
void Tree<T>::DeleteSubTree (Node<T>* subtreeRoot)
{
	if (subtreeRoot == nullptr)
	{
		return;
	}

	this->DeleteSubTree(subtreeRoot->GetLeft());
	this->DeleteSubTree(subtreeRoot->GetRight());

	delete subtreeRoot;
}
template <typename T>
void Tree<T>::Insert (T* value)
{
	Node<T>* newNode = new Node<T>(value);

	if (this->root == nullptr)
	{
		this->root = newNode;
		return;
	}

	Node<T>* currentNode = this->root;
	while (currentNode != nullptr)
	{
        
		if (*currentNode->GetValue() > *value) 
		{
			if (currentNode->GetLeft() == nullptr) // about to fall off the tree
			{
				currentNode->SetLeft(newNode);
				break;
			}

			currentNode = currentNode->GetLeft();
		}
		else
		{

			if (currentNode->GetRight() == nullptr) // about to fall off the tree
			{
				currentNode->SetRight(newNode);
				break;
			}

			currentNode = currentNode->GetRight();
		}
	}
}
template <typename T>
Node<T>* Tree<T>::GetRoot ()
{
	return this->root;
}

template <typename T>
std::string Tree<T>::Traverse (bool showFullDetails)
{
	this->sFD = showFullDetails;
	return this->RecursivePrintTree(this->root);
}
template <typename T>
std::string Tree<T>::RecursivePrintTree (Node<T>* subtreeRoot)
{
	if (subtreeRoot == nullptr)
	{
		return "";
	}

	std::ostringstream printedTree;

    
	printedTree << this->RecursivePrintTree(subtreeRoot->GetLeft());
   	if(this->sFD) 
		printedTree << *subtreeRoot->GetValue(); 
	else 
		printedTree << subtreeRoot->GetValue()->GetTitle() << "\n";
	printedTree << this->RecursivePrintTree(subtreeRoot->GetRight());

	return printedTree.str();
}


template <typename T>
Node<T>* Tree<T>::Search(std::string S)
{
	return this->RecursiveSearch(S, this->root);
}

template <typename T>
Node<T>* Tree<T>::RecursiveSearch(std::string S, Node<T>* currentRoot)
{

	if(currentRoot == nullptr)
	{
		return nullptr;
	}

	Node<T>* result = nullptr;
	if(S == currentRoot->GetValue()->GetTitle())
		result = currentRoot;
	if(result == nullptr)
	{
	result = this->RecursiveSearch(S, currentRoot->GetLeft());	
	if(result == nullptr)
		result = this->RecursiveSearch(S, currentRoot->GetRight());
	}
	return result;
}

template class Tree<Book>;
