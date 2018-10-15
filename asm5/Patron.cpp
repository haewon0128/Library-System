#include <iostream>
#include "Patron.hpp"
#include <vector>

using namespace std;

Patron::Patron(string idn, string n)
{
	idNum = idn;
	name = n;
}

string Patron::getIdNum()
{
	return idNum;
}

string Patron::getName()
{
	return name;
}

vector<LibraryItem*> Patron::getCheckedOutItems()
{
	return checkedOutItems;
}

void Patron::addLibraryItem(LibraryItem* b)
{
	checkedOutItems.push_back(b);
}

void Patron::removeLibraryItem(LibraryItem* b)
{
	for (vector<LibraryItem*>::iterator it = checkedOutItems.begin(); it != checkedOutItems.end(); it++)
	{
		if (*it == b)
			checkedOutItems.erase(it);
		return;
	}

}

double Patron::getFineAmount()
{
	return fineAmount;
}

void Patron::amendFine(double amount)
{
	fineAmount = fineAmount + amount;
}


