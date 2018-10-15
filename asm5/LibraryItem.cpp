#include <iostream>
#include "LibraryItem.hpp"

using namespace std;

LibraryItem::LibraryItem(string idc, string t)
{
	idCode = idc;
	title = t;
	checkedOutBy = NULL;
	requestedBy = NULL;

	location = ON_SHELF;

}

string LibraryItem::getIdCode()
{
	return idCode;
}

string LibraryItem::getTitle()
{
	return title;
}

Locale LibraryItem::getLocation()
{
	return location;
}

void LibraryItem::setLocation(Locale l)
{
	location = l;
}

Patron* LibraryItem::getCheckedOutBy()
{
	return checkedOutBy;
}

void LibraryItem::setCheckedOutBy(Patron* p)
{
	checkedOutBy = p;
}

Patron* LibraryItem::getRequestedBy()
{
	return requestedBy;
}

void LibraryItem::setRequestedBy(Patron* p)
{
	requestedBy = p;
}

int LibraryItem::getDateCheckedOut()
{
	return dateCheckedOut;
}

void LibraryItem::setDateCheckedOut(int d)
{
	dateCheckedOut = d;
}