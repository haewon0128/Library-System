#include <iostream>
#include "Library.hpp"
#include "LibraryItem.hpp"
#include <vector>
#include "Patron.hpp"
#include "Book.hpp"

using namespace std;

Library::Library()
{
	currentDate = 0;
}

void Library::addLibraryItem(LibraryItem* b)
{
	holdings.push_back(b);

}

void Library::addPatron(Patron* p)
{
	members.push_back(p);
	
	
}


LibraryItem* Library::getLibraryItem(string ItemID)
{
	for (int i = 0; i < holdings.size(); i++)
	{
		if (ItemID == holdings.at(i)->getIdCode())
			return holdings.at(i);

		
	}

	return NULL;
}


Patron* Library::getPatron(string patronID)
{
	for (int i = 0; i < members.size(); i++)
	{
		if (patronID == members.at(i)->getIdNum())
			return members.at(i);

	}

	return NULL;
}


string Library::checkOutLibraryItem(string patronID, string ItemID)
{

	if (getLibraryItem(ItemID) == NULL)
		return "item not found";

	if (getPatron(patronID) == NULL) 
		return "patron not found";

	

	else if (getLibraryItem(ItemID) != NULL && getLibraryItem(ItemID)->getLocation() == CHECKED_OUT)
		return "item already checked out";
	else if (getLibraryItem(ItemID)->getRequestedBy() != getPatron(patronID)&&getLibraryItem(ItemID)->getLocation() == ON_HOLD_SHELF)
		return "item on hold by other patron";
	
	else if(getLibraryItem(ItemID) != NULL && getLibraryItem(ItemID)->getLocation() != CHECKED_OUT)
		{
		
			getLibraryItem(ItemID)->setCheckedOutBy(getPatron(patronID));
			getLibraryItem(ItemID)->setDateCheckedOut(currentDate);


			getLibraryItem(ItemID)->setLocation(CHECKED_OUT);

			
			
			if (getLibraryItem(ItemID)->getRequestedBy() == getPatron(patronID))
				getLibraryItem(ItemID)->setRequestedBy(NULL);

			getPatron(patronID)->addLibraryItem(getLibraryItem(ItemID));

			
			return "check out successful";

		}

}
	

string Library::returnLibraryItem(string ItemID)
{
	if (getLibraryItem(ItemID) == NULL)
		return "item not found";

	else if (getLibraryItem(ItemID) != NULL && getLibraryItem(ItemID)->getLocation() != CHECKED_OUT)
		return "item already in library";

	else if (getLibraryItem(ItemID) != NULL && getLibraryItem(ItemID)->getLocation() == CHECKED_OUT)
	{
		getLibraryItem(ItemID)->getCheckedOutBy()->removeLibraryItem(getLibraryItem(ItemID));
		
		if (getLibraryItem(ItemID)->getRequestedBy() == NULL)
			getLibraryItem(ItemID)->setLocation(ON_SHELF);
		else if(getLibraryItem(ItemID)->getRequestedBy() != NULL)
			getLibraryItem(ItemID)->setLocation(ON_HOLD_SHELF);

		getLibraryItem(ItemID)->setCheckedOutBy(NULL);

		return "return successful";

	}
	
}

string Library::requestLibraryItem(string patronID, string ItemID)
{
	if (getPatron(patronID) == NULL)
	{
		return "patron not found";
	}

	if (getLibraryItem(ItemID) == NULL)
		return "item not found";

	if (getLibraryItem(ItemID)->getRequestedBy() != NULL)
		return "item already on hold";

	else if (getLibraryItem(ItemID)->getLocation() != ON_HOLD_SHELF )
	{
		getLibraryItem(ItemID)->setRequestedBy(getPatron(patronID));

		if (getLibraryItem(ItemID)->getLocation() == ON_SHELF)
			getLibraryItem(ItemID)->setLocation(ON_HOLD_SHELF);


		return "request successful";
	}

}

string Library::payFine(string patronID, double payment)
{
	if (getPatron(patronID) == NULL)
	{
		return "patron not found";
	}

	getPatron(patronID)->amendFine(-payment);

	return "payment successful";
	
}

void Library::incrementCurrentDate()
{

	currentDate++;

	for (int i = 0; i < members.size(); i++)
	{
		Patron *p = members[i];
		vector<LibraryItem*> items = p->getCheckedOutItems();

		for (int j = 0; j < items.size(); j++)
		{
			LibraryItem* l = items[j];
			if (currentDate - l->getDateCheckedOut() > l->getCheckOutLength())
			{
				p->amendFine(0.1);
			}
		}
	}

	
}



	