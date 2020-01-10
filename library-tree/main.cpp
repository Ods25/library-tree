#include "book.hpp"
#include "node.hpp"
#include "tree.hpp"
#include "book_loader.hpp"
#include <string>


/*
#include <cstdlib>
void clear_screen()
{
#ifdef WINDOWS
	    std::system("cls");
#else
	    // Assume POSIX
	    std::system ("clear");
#endif
}
*/


int main()
{
	BookLoader parser;
	std::string fn;
	do{
		std::cout << "Please enter a valid filename : ";
		
			std::getline(std::cin,fn);
	}while(!parser.SetFileName(fn));

	Tree<Book> library;



	Book* b = nullptr;	
	do{
		b = parser.GetNextBook();
		if(b !=nullptr)
		{
			library.Insert(b);
			//std::cout << "Inserting..." << std::endl;
		}
	}while(b!= nullptr);
	std::string uinp;
	std::string uglyLine = "\n_________________________________________________________________\n";
	do{
		do{
		std::cout << uglyLine;
		std::cout << "Welcome to the Library,\n\t(F)ind a book, \n\t(L)ist all books and their details, list only the \n\t(T)itles of books, \n\t(G)et availability of a book, \n\t(B)orrow a book, \n\t(D)eposit a borrowed book,or \n\t(Q) to Quit: ";	

		std::getline(std::cin,uinp);
		std::cout << uglyLine;
		}while(/*uinp != "C" and*/ uinp != "F" and uinp != "L" and uinp != "T" and uinp != "G" and uinp != "R" and uinp != "B" and uinp != "D" and uinp != "Q");	
		
		/*
		if(uinp == "C")
			clear_screen();
		*/
		if(uinp == "L")
			std::cout << library.Traverse() <<std::endl;
		if(uinp == "T")
			std::cout << library.Traverse(false) << std::endl;
		if(uinp == "F")
		{
			std::cout << "Please type the name of the book: ";
			std::getline(std::cin,uinp);
			std::cout << "You have searched for: " << uinp << std::endl;
			Node<Book>* fB = library.Search(uinp);
			if(fB == nullptr)
				std::cout << "\n That book could not be found";
			else
			{
				std::cout << "Here are the details on that book: \n";
				std::ostringstream ostr;
				ostr << *fB->GetValue();
				std::cout << ostr.str();
			}
		}
		if(uinp == "G")
		{
			std::cout << "Please type the name of the book: ";
			std::getline(std::cin,uinp);
			std::cout << "You have searched for: " << uinp << std::endl;
			Node<Book>* fB = library.Search(uinp);

			if(fB == nullptr)
				std::cout << "\n That book could not be found";
			else
			{
				
				std::cout << "There are currently " << fB->GetValue()->getNum() << " copies of that book available.\n";
			}
		}
		if(uinp == "B")
		{

			std::cout << "Please type the name of the book: ";
			std::getline(std::cin,uinp);
			std::cout << "You have searched for: " << uinp << std::endl;
			Node<Book>* fB = library.Search(uinp);

			if(fB == nullptr)
				std::cout << "\n That book could not be found";
			else
			{
				if(fB->GetValue()->getNum() < 1)
					std::cout<< "Sorry, there aren't any more of that book left."<<std::endl;
				else
				{
					std::cout << "It's all yours!" << std::endl;
					fB->GetValue()->Checkout();
				}
			}
		}

		if(uinp == "D")
		{

			std::cout << "Please type the name of the book: ";
			std::getline(std::cin,uinp);
			Node<Book>* fB = library.Search(uinp);

			if(fB == nullptr)
				std::cout << "\n That's not our book.";
			else
			{
					std::cout << "Thank you, it looks pristine!" << std::endl;
					fB->GetValue()->Checkin();
			}
		}

	}while(uinp != "Q");


	return 0;
}
