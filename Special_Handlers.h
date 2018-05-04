#ifndef Special_Handler_H_INCLUDED
#define Special_Handler_H_INCLUDED
#pragma once
#include "Mail.h"
#include <string>
using std::string;

// Parents is a mail handler for the parents
// It also determines if it can handle the request or needs to send it on
// If it is the last in the chain and can't handle it, it lets the user know.
class Parents : public Mail {
private:
	string _Warm_Greetings;
	int _Money;
public:
	Parents(string greetings, int cash);
	~Parents() = default;
	// Handles incoming request
	void request(bool Top_Secret, bool Rowdy);
};

//Handles Mail for Friends
//Takes Rowdy Messages only 
class Friends : public Mail {
private:
	string _Rowdy_Joke;
	string _Meetup_Date;
	string _Meetup_Place;

public:
	Friends(string joke, string date, string location);
	~Friends() = default;
	// Handles incoming request
	void request(bool Top_Secret, bool Rowdy);
};

//Handles Mail to the Mistress
//Only Takes _topSecret Messages
class Mistress : public Mail {
private:
	string _Hotel;
	string _Time;
public:
	Mistress(string location, string time);
	~Mistress() = default;
	// Handles incoming request
	void request(bool Top_Secret, bool Rowdy);
};
#endif