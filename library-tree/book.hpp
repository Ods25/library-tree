#ifndef BOOK_HPP
#define BOOK_HPP
#include <string>
#include <iostream>
class Book
{
	private:
		int numberAvailable;
		std::string title,author,subject,format,publisher;		
	public:
		Book(const std::string &t,const std::string &a,const std::string &s,const std::string &f,const std::string &p,const int &n);
		std::string GetTitle();
		bool Checkout();
		bool Checkin();
		int getNum();
		friend bool operator==(Book const &b1,Book const &b2);

		friend bool operator<(Book const &b1,Book const &b2);
		friend bool operator>(Book const &b1,Book const &b2);
		friend std::ostream& operator << (std::ostream& ostr, const Book &b);

};
#endif
