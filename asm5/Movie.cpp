#include <iostream>
#include "Movie.hpp"

using namespace std;

Movie::Movie(string idn, string t, string d) : LibraryItem(idn, t)
{
	director = d;
}

string Movie::getDirector()
{
	return director;
}

int Movie::getCheckOutLength()
{
	return CHECK_OUT_LENGTH;
}