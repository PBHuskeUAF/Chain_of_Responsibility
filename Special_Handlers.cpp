#include "Special_Handlers.h"
#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::endl;

/**************************************************************Parents***********************************************************************/

Parents::Parents(string greetings, int cash) {
	_Warm_Greetings = greetings;
	_Money = cash;
}

// Handles incoming request
void Parents::request(bool Top_Secret, bool Rowdy) {
	if (!Top_Secret && !Rowdy)
	{
		cout << _Warm_Greetings << " I transferred " << _Money << " into your account" << endl;
	}
	else if (next != nullptr) { // Passes it on to the next in the chain
	next->request(Top_Secret, Rowdy);
	}
	else
	{
		cout << "Can't handle this Message";
	}
}

/*************************************************************Friends*************************************************************************/
Friends::Friends(string joke, string date, string location) {
	_Rowdy_Joke = joke;
	_Meetup_Date = date;
	_Meetup_Place = location;
}

// Handles incoming request
void Friends::request(bool Top_Secret, bool Rowdy) {

 if (Rowdy && !Top_Secret)//friends
	{
		cout << _Rowdy_Joke << " Hey everyone lets get together at " << _Meetup_Place << " on the " << _Meetup_Date << endl;
	}
	else if (next != nullptr) { // Passes it on to the next in the chain
		next->request( Top_Secret, Rowdy);
	}
	else
	{
		cout << "Can't handle this Message";
	}
}

/************************************************************Mistress*************************************************************************/

Mistress::Mistress(string location, string time) {
	_Hotel = location;
	_Time = time;
}

// Handles incoming request
void Mistress::request(bool Top_Secret, bool Rowdy) {

	 if (Top_Secret && !Rowdy)//mistress
	{
		cout << "Meet me at " << _Hotel << " at " << _Time << endl;
	}
	 else if (next != nullptr) { // Passes it on to the next in the chain
		 next->request( Top_Secret, Rowdy);
	 }
	else
	{
		cout << "Can't handle this Message" << endl;
	}
}