#include "book.hpp"
#include <string>
#include <fstream>
class BookLoader
{
	private:
		std::string fn;
		std::ifstream infile;
	public:
		bool SetFileName(std::string f);

		Book* GetNextBook();		
};
