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
	case 0:    //Card is diamonds
		if (cd.cardFace == 1)    //Ace of diamonds
		{
			os << "AD[" << cd.cardFace << "]";
		}
		else if (cd.cardFace > 1 && cd.cardFace < 11) //2-10 of diamonds
		{
			os << cd.cardFace << "D[" << cd.cardFace << "]";
		}
		else if (cd.cardFace == 11) //Jack of diamonds
		{
			os << "JD[" << cd.cardFace << "]";
		}
		else if (cd.cardFace == 12) //Queen of diamonds
		{
			os << "QD[" << cd.cardFace << "]";
		}
		else                        //King of diamonds
		{
			os << "KD[" << cd.cardFace << "]";
		}
		break; //break parent case 0

	case 1:    //Card is spades
		if (cd.cardFace == 1)    //Ace of spades
		{
			os << "AS[" << cd.cardFace << "]";
		}
		else if (cd.cardFace > 1 && cd.cardFace < 11) //2-10 of spades
		{
			os << cd.cardFace << "S[" << cd.cardFace << "]";
		}
		else if (cd.cardFace == 11) //Jack of spades
		{
			os << "JS[" << cd.cardFace << "]";
		}
		else if (cd.cardFace == 12) //Queen of spades
		{
			os << "QS[" << cd.cardFace << "]";
		}
		else                        //King of spades
		{
			os << "KS[" << cd.cardFace << "]";
		}
		break; //break parent case 1

	case 2:    //Card is hearts
		if (cd.cardFace == 1)    //Ace of hearts
		{
			os << "AH[" << cd.cardFace << "]";
		}
		else if (cd.cardFace > 1 && cd.cardFace < 11) //2-10 of hearts
		{
			os << cd.cardFace << "H[" << cd.cardFace << "]";
		}
		else if (cd.cardFace == 11) //Jack of hearts
		{
			os << "JH[" << cd.cardFace << "]";
		}
		else if (cd.cardFace == 12) //Queen of hearts
		{
			os << "QH[" << cd.cardFace << "]";
		}
		else                        //King of hearts
		{
			os << "KH[" << cd.cardFace << "]";
		}
		break; //break parent case 2

	case 3:    //Card is clubs
		if (cd.cardFace == 1)    //Ace of clubs
		{
			os << "AC[" << cd.cardFace << "]";
		}
		else if (cd.cardFace > 1 && cd.cardFace < 11) //2-10 of clubs
		{
			os << cd.cardFace << "C[" << cd.cardFace << "]";
		}
		else if (cd.cardFace == 11) //Jack of clubs
		{
			os << "JC[" << cd.cardFace << "]";
		}
		else if (cd.cardFace == 12) //Queen of clubs
		{
			os << "QC[" << cd.cardFace << "]";
		}
		else                        //King of clubs
		{
			os << "KC[" << cd.cardFace << "]";
		}
	}
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