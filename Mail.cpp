#include "Mail.h"

Mail::Mail() { next = nullptr; }

// Sets next handler in the chain
void Mail::setNextHandler(Mail *nextInLine) {
	next = nextInLine;
}