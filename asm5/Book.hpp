#ifndef BOOK_HPP
#define BOOK_HPP

#include <iostream>
#include "LibraryItem.hpp"

using namespace std;

class Book : public LibraryItem
{
private:
	string author;
public:
	Book(string idn, string t, string a);
	static const int CHECK_OUT_LENGTH = 21;
	string getAuthor();
	int getCheckOutLength();
};



#endif // !BOOK_HPP




