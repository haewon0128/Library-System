#include <iostream>
#include "Book.hpp"
#include "LibraryItem.hpp"

using namespace std;

Book::Book(string idn, string t, string a) : LibraryItem(idn, t)
{
	author = a;
}

string Book::getAuthor()
{
	return author;
}

int Book::getCheckOutLength()
{
	return CHECK_OUT_LENGTH;
}