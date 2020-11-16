/*------------------------------------------------------------------------*
 *Author: Jared Frazier   | 
 *Course: CSCI 3110-003   | 
 *Instructor: Dr. Barbosa | File Name: card.cpp
 *Purpose: Implementation of Card class
 *------------------------------------------------------------------------*/

#include "card.h"
//Default constructor
Card::Card() {};

//Parametrized constructor
Card::Card(int face, suit st)
{
	cardFace = face;
	cardSuit = st;
}

//Overload ostream
std::ostream& operator<<(std::ostream& os, const Card& cd)
{
	//Switch cardSuit (i.e diamonds=0,spades=1,hearts=2,clubs=3)
	switch (cd.cardSuit)
	{
	case 0:    //Card is spades
		if (cd.cardFace == 1)    //Ace of spades
		{
			os << "AS[" << cd.cardFace << "]   ";
		}
		else if (cd.cardFace > 1 && cd.cardFace < 10) //2-10 of spades
		{
			os << cd.cardFace << "S[" << cd.cardFace << "]   ";
		}
		else if (cd.cardFace == 10) {
			os << cd.cardFace << "S[" << cd.cardFace << "] ";
		}
		else if (cd.cardFace == 11) //Jack of spades
		{
			os << "JS[" << cd.cardFace << "]  ";
		}
		else if (cd.cardFace == 12) //Queen of spades
		{
			os << "QS[" << cd.cardFace << "]  ";
		}
		else                        //King of spades
		{
			os << "KS[" << cd.cardFace << "]  ";
		}
		break; //break parent case 1

	case 1:    //Card is hearts
		if (cd.cardFace == 1)    //Ace of hearts
		{
			os << "AH[" << cd.cardFace << "]   ";
		}
		else if (cd.cardFace > 1 && cd.cardFace < 10) //2-10 of hearts
		{
			os << cd.cardFace << "H[" << cd.cardFace << "]   ";
		}
		else if (cd.cardFace == 10) {
			os << cd.cardFace << "H[" << cd.cardFace << "] ";
		}
		else if (cd.cardFace == 11) //Jack of hearts
		{
			os << "JH[" << cd.cardFace << "]  ";
		}
		else if (cd.cardFace == 12) //Queen of hearts
		{
			os << "QH[" << cd.cardFace << "]  ";
		}
		else                        //King of hearts
		{
			os << "KH[" << cd.cardFace << "]  ";
		}
	};
	return os;
}

// LESS THAN OR EQUAL TO OPERATOR
bool Card::operator <= (const Card& cd) const{
	return this->cardFace <= cd.cardFace;
}

// GREATER THAN OR EQUAL TO OPERATOR
bool Card::operator >= (const Card& cd) const {
	return this->cardFace >= cd.cardFace;
}

//Overload less than
bool Card::operator < (const Card& cd) const
{
	return this->cardFace < cd.cardFace;
}

//Overload greater than
bool Card::operator > (const Card& cd) const
{
	return this->cardFace > cd.cardFace;
}

//Overload equal to
bool Card::operator== (const Card& cd) const
{
	return this->cardFace == cd.cardFace;
}

//Get face face value (1-13)
int Card::getFaceValue() const
{
	return cardFace;
}

//Get suit (0-3)
suit Card::getSuit() const
{
	return cardSuit;
}
