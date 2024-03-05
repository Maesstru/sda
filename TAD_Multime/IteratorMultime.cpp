#include "IteratorMultime.h"
#include "Multime.h"


IteratorMultime::IteratorMultime(const Multime& m): mult(m) {
	/* de adaugat */
	this->currentElement = m.elemente;
	this->currentIt = 0;
}

TElem IteratorMultime::element() const {
	/* de adaugat */
	return *this->currentElement;
}

bool IteratorMultime::valid() const {
	/* de adaugat */
	return this->currentIt < mult.lungime;
}

void IteratorMultime::urmator() {
	/* de adaugat */
	this->currentElement++;
	this->currentIt++;
}

void IteratorMultime::prim() {
	/* de adaugat */
	this->currentElement = mult.elemente;
	this->currentIt = 0;
}

