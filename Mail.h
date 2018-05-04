#ifndef Mail_H_Included
#define Mail_H_Included
#pragma once
//Paul Huske
//CS 372 Chain of Responsibility

// Abstract class called Mail
// This Specialized mail handlers inherit this class and pass mail to where it is needed
class Mail {
protected:
	Mail * next;
public:
	Mail();

	// Each Special Mail handler will implement request
	virtual void request(bool secret, bool rowdy) = 0;

	// Sets next handler in the chain
	void setNextHandler(Mail *nextInLine);

};
#endif // !Mail_H_Included