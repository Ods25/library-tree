#include "book_loader.hpp"

bool BookLoader::SetFileName(std::string f)
{
	this->infile.open(f);
	if(this->infile.is_open())
		return true;
	else 
		return false;
}


Book* BookLoader::GetNextBook()
{
	std::string args[6];
	for(int i=0; i<6; ++i)
	{
		//std::cout << "this is i: "<< i << std::endl;
		std::getline(this->infile, args[i]);
	
		if(this->infile.eof())	
			return nullptr;	
	}
/*
	for(int i=0; i<6; ++i)
		std::cout << args[i] << std::endl;
	*/
	return new Book(args[0],args[1],args[2],args[3],args[4],std::stoi(args[5]));
}
