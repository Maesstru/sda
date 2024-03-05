#include "Multime.h"
#include "IteratorMultime.h"
#include <iostream>
#include <exception>
#include <stdio.h>

using namespace std;

//o posibila relatie
bool rel(TElem e1, TElem e2)
{
    if (e1 <= e2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Multime::Multime()
{
    /* de adaugat */
    this->elemente = new TElem[4];
    this->capacitate = 4;
    this->lungime = 0;
}


bool Multime::adauga(TElem elem)
{
    /* de adaugat */
    if(this->capacitate == this->lungime)
    {
        this->capacitate *= 2;
        TElem* new_elem = new TElem[this->capacitate];
        for (int i = 0; i < this->lungime; i++)
            new_elem[i] = this->elemente[i];
        delete[] this->elemente;
        this->elemente = new_elem;
    }

    for (int i = 0; i < this->lungime; i++)
    {
        if(elem == this->elemente[i])
        {
            return false;
        }
    }

    int poz = 0;

    while(rel(this->elemente[poz], elem) && poz < this->lungime)
    {
        poz++;
    }

    for(int i=this->lungime; i>poz; i--)
    {
        this->elemente[i] = this->elemente[i-1];
    }

    this->elemente[poz] = elem;
    this->lungime++;


    return true;
}


bool Multime::sterge(TElem elem)
{
    /* de adaugat */
    int poz = -1;

    for(int i = 0; i<this->lungime; i++)
    {
        if(elem == this->elemente[i])
        {
            poz = i;
        }

    }

    if(poz == -1)
    {
        return false;
    }

    this->lungime--;

    for(int i = poz; i< this->lungime; i++)
    {
        this->elemente[i] = this->elemente[i+1];
    }


    return true;
}


bool Multime::cauta(TElem elem) const
{
    /* de adaugat */
    for(int i = 0; i<this->lungime; i++)
    {
        if(elem == this->elemente[i])
        {
            return true;
        }
    }

    return false;
}


int Multime::dim() const
{
    /* de adaugat */

    return this->lungime;
}



bool Multime::vida() const
{
    /* de adaugat */
    if(this->lungime == 0)
        return true;
    return false;
}

IteratorMultime Multime::iterator() const
{
    return IteratorMultime(*this);
}


Multime::~Multime()
{
    /* de adaugat */
    delete[] this->elemente;
}






