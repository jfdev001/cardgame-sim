/*------------------------------------------------------------------------*
 *Author: Jared Frazier   | 
 *Course: CSCI 3110-003   | 
 *Instructor: Dr. Barbosa | File Name: card.h
 *Purpose: Specification of Card class
 *------------------------------------------------------------------------*/

#ifndef CARD_H
#define CARD_H

#include <iostream>

 // Enumerated type that represents the card suits
enum suit { diamonds, spades, hearts, clubs }; //Default 0,1,2,3

class Card
{
public:
	//default constructor - required
	Card();

	//constructor that takes a card's face value (an integer) and its suit
	//card face example: Ace=0, 2=1, 3=2, ... Q=11, K=12
	Card(int face, suit st);

	// overload the << operator to display the card
	friend std::ostream& operator << (std::ostream& os, const Card& cd);

	// LESS THAN OR EQUAL TO OPERATOR
	bool operator <= (const Card& cd) const;

	// GREATER THAN OR EQUAL TO OPERATOR
	bool operator >= (const Card& cd) const;

	// compare and return true if *this has a lesser point value than cd, false otherwise
	bool operator < (const Card& cd) const;

	// compare and return true if *this has a larger point value than cd, false otherwise
	bool operator > (const Card& cd) const;

	// compare and return true if *this has the same point value as cd, false otherwise
	bool operator== (const Card& cd) const;

	// return the face value of the card: Ace: 0, 2: 1, 3:2, .... Queen:11, King:12
	int getFaceValue() const;

	// return the card's suit: clubs, hearts, spades, diamonds
	suit getSuit() const;

private:
	suit	cardSuit;		// card's suit
	int     cardFace;		// card's face value
	//int     pointValue;		// card's point value (from its face)
};
#endif

