#ifndef MOVIE_HPP
#define MOVIE_HPP

#include <iostream>
#include "LibraryItem.hpp"

using namespace std;

class Movie : public LibraryItem
{
private:
	string director;

public:
	Movie(string idn, string t, string d);
	static const int CHECK_OUT_LENGTH = 7;
	string getDirector();
	int getCheckOutLength();

};



#endif // !MOVIE_HPP



