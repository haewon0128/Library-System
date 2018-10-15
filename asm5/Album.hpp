#ifndef ALBUM_HPP
#define ALBUM_HPP

#include <iostream>
#include "LibraryItem.hpp"

using namespace std;

class Album : public LibraryItem
{
private:
	string artist;

public:
	Album(string idn, string t, string a);
	static const int CHECK_OUT_LENGTH = 14;
	string getArtist();
	int getCheckOutLength();

};



#endif // !ALBUM_HPP


