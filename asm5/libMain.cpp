#include <iostream>
#include <stdlib.h>
#include <cmath>

#include "Library.hpp"


using namespace std;

int main()
{

	Book b1("123", "War and Peace", "Tolstoy");
	Book b2("234", "Moby Dick", "Melville");
	Book b3("345", "Phantom Tollbooth", "Juster");
	Album a1("456", "haha", "hoho");
	Album a2("567", "hoho", "haha");
	Album a3("678", "hihi", "popo");
	Movie m1("789", "harry", "potter");
	Movie m2("890", "lord", "rings");
	Movie m3("901", "sally", "molly");

	Patron p1("abc", "haewon");
	Patron p2("bcd", "martin");
	Patron p3("cde", "joe");
	Patron p4("def", "anders");
	Patron p5("efg", "asa");

	Library lib;
	lib.addLibraryItem(&b1);
	lib.addLibraryItem(&b2);
	lib.addLibraryItem(&b3);
	lib.addLibraryItem(&a1);
	lib.addLibraryItem(&a2);
	lib.addLibraryItem(&a3);
	lib.addLibraryItem(&m1);
	lib.addLibraryItem(&m2);
	lib.addLibraryItem(&m3);

	lib.addPatron(&p1);
	lib.addPatron(&p2);
	lib.addPatron(&p3);
	lib.addPatron(&p4);
	lib.addPatron(&p5);
	

	cout << "haewon " << lib.checkOutLibraryItem("abc", "789") << endl;
	cout << "haewon " << lib.checkOutLibraryItem("abc", "123") << endl;
	cout << "haewon " << lib.checkOutLibraryItem("abc", "456") << endl;
	for (int i = 0; i < 12; i++)
		lib.incrementCurrentDate();
	cout << "After 12days from checking out day, haewon's fine amount is " << p1.getFineAmount() << endl;

	cout << "martin " << lib.checkOutLibraryItem("bcd", "123") << endl;
	cout << "martin " << lib.requestLibraryItem("bcd", "123") << endl;

	for (int i = 0; i < 7; i++)
		lib.incrementCurrentDate();
	cout << "After 19days from chekcing out day, haewon's fine amount is " << p1.getFineAmount() << endl;

	cout <<"haewon "<< lib.returnLibraryItem("789") << endl;
	cout <<"haewon "<< lib.returnLibraryItem("123") << endl;
	cout <<"haewon "<< lib.returnLibraryItem("456") << endl;

	cout << "haewon paid fine " << lib.payFine("abc", 2.0) <<endl;
	cout << "After paying, haewon's fine amount is " << p1.getFineAmount() << endl;


	cout << "joe " << lib.checkOutLibraryItem("cde", "123") << endl;
	cout << "joe " << lib.requestLibraryItem("cde", "123") << endl;


	cout << "martin " << lib.checkOutLibraryItem("bcd", "123") << endl; 
	cout << lib.checkOutLibraryItem("bc", "901") << endl;
	cout << lib.checkOutLibraryItem("bcd", "91") << endl;
	cout << "martin " << lib.checkOutLibraryItem("bcd", "901") << endl;

	cout << "haewon " << lib.checkOutLibraryItem("abc", "567") << endl;

	for (int i = 0; i < 18; i++)
		lib.incrementCurrentDate();

	cout << "After 18days from checking out day, haewon's fine amount is " << p1.getFineAmount() << endl;
	cout << "haewon paid fine " << lib.payFine("abc", 0.1) << endl;
	double p1fine = p1.getFineAmount();
	cout << "After paying, haewon's fine amount is " << roundf(p1fine) << endl;
	cout << lib.returnLibraryItem("46") << endl;
	cout << lib.returnLibraryItem("456") << endl;
	cout << "haewon " << lib.returnLibraryItem("567") << endl;

	cout << lib.payFine("ef", 0.5) << endl;


	cout << "After 18days from checking out day, martin's fine amount is " << p2.getFineAmount() << endl;
	cout << "martin paid fine " << lib.payFine("bcd", 1.0) << endl;
	cout << "After paying, martin's fine amount is " << p2.getFineAmount() << endl;
	cout << "martin " << lib.returnLibraryItem("123") << endl;
	cout << "item 123's location = " << b1.getLocation() << endl;


	cout << lib.requestLibraryItem("de", "123") << endl;
	cout << lib.requestLibraryItem("de", "12") << endl;
	cout <<"anders "<<lib.requestLibraryItem("def", "123") << endl;
	cout << "item 123's location = " << b1.getLocation() << endl;


	cout << lib.checkOutLibraryItem("def", "123") << endl;
	cout << "item 123's location = " << b1.getLocation() << endl;


	return 0;
}