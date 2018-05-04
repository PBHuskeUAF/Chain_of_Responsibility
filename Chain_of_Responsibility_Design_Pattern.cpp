﻿// Chain_Of_Responsibility.cpp : Defines the entry point for the console application.
//Paul Huske
//CS 372 Spring 2018
//Take Home Final

#include"Mail.h"
#include"Special_Handlers.h"
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
		int main()
		{
			string nice = "Hoper you are well";
			string bad_Taste = "What is the Square Root of 69? Ate Something\n";
			string buddyNight = "8/23";
			string buddyMeet = "bar";
			string Afternoon_Delight = "1:00pm";
			string rendevous = "8/21";
			int cash = 100;
			

			//create three types of messages.
			Mail *h1 = new Parents(nice, cash);
			Mail *h2 = new Friends(bad_Taste, buddyNight, buddyMeet);
			Mail *h3 = new Mistress(rendevous, Afternoon_Delight);
		
			// Form the message chain
			h1->setNextHandler(h2);
			h2->setNextHandler(h3);
	
			//sends parents a message
			h1->request(false, false);
			// sends friends a message
			h1->request(false, true);
			// sends Mistress a message
			h1->request(true, false);
			// Fails because no handler for this case
			h1->request(true, true);
		
			delete h1;
			delete h2;
			delete h3;
			
			return 0;
	}

