#include "book.hpp"
Book::Book(const std::string &t,const std::string &a,const std::string &s,const std::string &f,const std::string &p,const int &n)
{
	this->title = t;
	this->author = a;
	this->subject = s;
	this->format = f;
	this->publisher = p;
	this->numberAvailable = n;
}
int Book::getNum()
{
	return this->numberAvailable;
}
std::string Book::GetTitle()
{
	return this->title;
}
bool Book::Checkout()
{
	if(this->numberAvailable > 0)
	{
		--this->numberAvailable;
		return true;
	}
	else
		return false;
}
bool Book::Checkin()
{
	++this->numberAvailable;
	return true;
}
bool operator==( Book const &b1, Book const &b2)
{
	return b1.title == b2.title;
}

bool operator<( Book const &b1, Book const &b2)
{
	return b1.title < b2.title;
}

bool operator>( Book const &b1, Book const &b2)
{
	return b1.title > b2.title;
}

std::ostream& operator << (std::ostream& ostr, const Book &b)
{
	ostr << b.title<<", by " << b.author <<"\n\t"<<"Subject: "<< b.subject <<"\n\t"<<"Publisher: "<< b.publisher<<"\n\t"<<b.numberAvailable<<" " <<b.format <<" copies available\n";
	return ostr;
}
