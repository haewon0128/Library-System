#include <iostream>
#include "Album.hpp"

using namespace std;

Album::Album(string idn, string t, string a) : LibraryItem(idn, t)
{
	artist = a;
}

string Album::getArtist()
{
	return artist;
}

int Album::getCheckOutLength()
{
	return CHECK_OUT_LENGTH;
}