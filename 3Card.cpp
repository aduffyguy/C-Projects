/***********************************************/
/* File:       3Card.cpp                       */
/* Author:    Alan Duffy-Guy 			       */
/* Selected code provided by Dr. Spiegel       */
/* Creation Date:February 13, 2015             */
/* Extended by:  Alan Duffy-Guy                */
/* Course:       CSC 136                       */
/* Professor:    Dr. Spiegel                   */
/* Purpose: Acquires a card by inputting an    */
/*			integer either by the command line,*/
/*			a text file or from a randomized   */
/*			array. It then outputs the rank and*/
/*			suit as well as what properties the*/
/*			cards in the hand have.            */
/***********************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include "Card.h"

using namespace std;

/**********************************************/
/* class and function provided by Dr. Spiegel */
/* to randomize shuffling of Card arrays      */
/**********************************************/
class MyRandom {
  public:
    ptrdiff_t operator() (ptrdiff_t max) {
        double tmp;
        tmp = static_cast<double>(rand())
                / static_cast<double>(RAND_MAX);
        return static_cast<ptrdiff_t>(tmp * max);
    }
};

void    shuffle(Card *deck) {
        MyRandom rd;
        random_shuffle(deck, deck+52,rd);
}


/************************************************/
/* Function Name:  generateDeck                 */
/*                                              */
/* Description:    generates a deck of cards    */
/*                                              */
/* Parameters:     Card Deck[] - import/export -*/
/*                 array of 52 card objects     */
/*                                              */ 
/* Return Value:   none                         */
/************************************************/
void generateDeck(Card Deck[]);

/************************************************/
/* Function Name:  printHand                    */
/*                                              */
/* Description:    prints the rank and suit of  */
/*                 the cards in the hand        */
/*                                              */
/* Parameters:     Card phHand[]-import- array  */
/*                 of 3 card objects            */
/*                                              */ 
/* Return Value:   none                         */
/************************************************/
void printHand(Card phHand[]);

/************************************************/
/* Function Name:  draw3                        */
/*                                              */
/* Description:    places the first three cards */
/*                 in the deck array into the   */
/*                 first three cards in the     */
/*                 hand array                   */
/*                                              */
/* Parameters:     Card Deck[] - import -       */
/*                 array of 52 card objects     */
/*                 Card Hand[]-export - array   */
/*                 of 3 card objects            */ 
/* Return Value:   none                         */
/************************************************/
void draw3(Card Deck[], Card Hand[]);

/************************************************/
/* Function Name:  isAMatch                     */
/*                                              */
/* Description:    checks to see if the cards in*/
/*                 hand3 are a pair, a 3 of a   */
/*                 kind or nothing              */
/*                                              */
/* Parameters:     Card Hand3[]-import - array  */
/*                 of 3 card objects            */ 
/* Return Value:   int match - export - the     */
/*                 integer representing a pair  */
/*                 3 ofa kind or nothing        */
/************************************************/
int isAMatch(Card Hand3[]);

/************************************************/
/* Function Name:  printDetermineHand           */
/*                                              */
/* Description:    takes all the possible types */
/*                 the hand could be and        */
/*                 narrows them down to what    */
/*                 the had is then print it out */
/*                                              */
/* Parameters:     Card Hand3[]-import - array  */
/*                 of 3 card objects            */ 
/* Return Value:   none                         */
/************************************************/
void printDetermineHand(Card Hand3[]);

/************************************************/
/* Function Name:  isAFlush                     */
/*                                              */
/* Description:    code used to determine if a  */
/*                   hand is a flush            */
/*                                              */
/* Parameters:     Card Hand3[] - import - array*/
/*                 of hand                      */
/* Return Value:   bool - export - true if a    */
/*                 flush otherwise false        */
/************************************************/
bool isAFlush(Card Hand3[]);

/************************************************/
/* Function Name:  isARoyal                     */
/*                                              */
/* Description:    code used to determine if a  */
/*                 hand is a  Royal Flush       */
/*                 straight                     */
/*                                              */
/* Parameters:     Card Hand3[] - import - array*/
/*                 of hand                      */
/* Return Value:   bool - export - true if a    */
/*                 Royal Flush otherwise false  */
/************************************************/
bool isRoyal(Card Hand3[]);

/************************************************/
/* Function Name:  isAStraight                  */
/*                                              */
/* Description:    code provided by Dr. Spiegel */
/*                 to determine if a hand is a  */
/*                 straight                     */
/*                                              */
/* Parameters:     Card Hand3[] - import - array*/
/*                 of hand                      */
/* Return Value:   bool - export - true if a    */
/*                 straight otherwise false     */
/************************************************/
bool isAStraight(Card Hand3[]);

// More prototypes go here.

int main(int argc,char **argv)
{ Card Deck[52];
  Card Hand3[3];

  // Seed random number generator
  srand(time(NULL));

  if (argc>2)   { // Hand is set from command line
    for (int i=0;i<3;i++)
      Hand3[i].setCard(atoi(argv[i+1]));
	
    printHand(Hand3);
	printDetermineHand(Hand3);
  }    
  else if (argc==2) {  // Cards are in file
    ifstream inf;
    inf.open(argv[1]);
    if (inf) {
		while (inf >> Hand3[0] >> Hand3[1] >> Hand3[2]) {
		printHand(Hand3);
		printDetermineHand(Hand3);
		}
	}
	
  }
  else {	  // Generate deck to deal random hand
    generateDeck(Deck);
    shuffle(Deck);
    
	//CODE GOES HERE
	draw3(Deck, Hand3);
	printHand(Hand3);
	printDetermineHand(Hand3);
  }
  //copareCards(Hand3);

  
  return 0;
}


// fill deck array with one of each card
void generateDeck(Card Deck[])
{
	for (int i = 0; i < 52; i++)
	Deck[i].setCard(i);
}
//prints the hand out
void printHand(Card phHand[])
{
	for (int i = 0; i < 3; i++)
	{
	cout << phHand[i] <<" "; 
	}
cout << endl;
}
//"draws" a card from he deck
void draw3(Card Deck[], Card Hand[])
{
	for (int i=0; i < 3;i++)
	{
    Hand[i] = Deck[i];
	}   
	
}
// Functions go here

// determine if the hand is a straight
bool isAStraight(Card Hand3[])
  // Suppose the cards are A B C.
  // Then we must check for ABC, ACB, BAC, BCA, CAB, and CBA
  // We must also check for ace low
 {if (((Hand3[2].getRank()+2)%13)==((Hand3[0].getRank()+1))&&		//CAB
   ((Hand3[0].getRank()+1)%13)==(Hand3[1].getRank()) &&
                              (Hand3[1].getRank()==0 || Hand3[1].getRank()>1))
  return(true);
 if (((Hand3[2].getRank()+2)%13)==((Hand3[1].getRank()+1))&&		//CBA
   ((Hand3[1].getRank()+1)%13)==(Hand3[0].getRank()) &&
                              (Hand3[0].getRank()==0 || Hand3[0].getRank()>1))
  return(true);
 if (((Hand3[0].getRank()+2)%13)==((Hand3[2].getRank()+1))&&		//ACB
   ((Hand3[2].getRank()+1)%13)==(Hand3[1].getRank()) &&
                              (Hand3[1].getRank()==0 || Hand3[1].getRank()>1))
  return(true);
 if (((Hand3[0].getRank()+2)%13)==((Hand3[1].getRank()+1))&&		//ABC
   ((Hand3[1].getRank()+1)%13)==(Hand3[2].getRank()) &&
                              (Hand3[2].getRank()==0 || Hand3[2].getRank()>1))
  return(true);
 if (((Hand3[1].getRank()+2)%13)==((Hand3[2].getRank()+1))&&		//BCA
   ((Hand3[2].getRank()+1)%13)==(Hand3[0].getRank()) &&
                              (Hand3[0].getRank()==0 || Hand3[0].getRank()>1))
  return(true);
 if (((Hand3[1].getRank()+2)%13)==((Hand3[0].getRank()+1))&&		//BAC
   ((Hand3[0].getRank()+1)%13)==(Hand3[2].getRank()) &&
                              (Hand3[2].getRank()==0 || Hand3[2].getRank()>1))
  return(true);
 return(false);
}

// More functions go here
//checks if there are any matching ranks
//returns int showing how many cards match by rank
int isAMatch(Card Hand3[])
{
     int match;
	
	// check for a = c, a = b, b = c 
	if (Hand3[0] ==(Hand3[1]) ||
	    Hand3[0] ==(Hand3[2]) ||
        Hand3[1] ==(Hand3[2]))
	{
		if (Hand3[0] ==(Hand3[1]) &&
	    Hand3[0] ==(Hand3[2]))
		{
		match = 3;
		return match;
		}
		else
		{
		match = 2;
		return match;
		}
	}
	else
	{
	match = 0;
	return match;
	}
}

void printDetermineHand(Card Hand3[])
{       
int match;
bool straight;
bool flush;
bool royal;
royal = isRoyal(Hand3);
straight = isAStraight(Hand3);
flush = isAFlush(Hand3);
match = isAMatch(Hand3);
	if (match == 2)
	{
	cout << "one pair"<< endl;
	}
	else if (match == 3)
	cout << "three of a kind" << endl;
	else if(straight == true && flush == true && royal == true)
	{
	cout<< "royal flush" << endl;
	}
	else if(straight == true && flush == true)
	{
	cout<< "straight flush" << endl;
	}
	else if (flush == true)
	{
	cout << "is a flush" << endl;
	}
	else if (straight == true)
	{
	cout << "is a straight"<< endl;
	}
	else
	{
	cout << "nothing"<< endl;
	}
	
}

bool isAFlush(Card Hand3[])
{
	if (Hand3[0].compareSuit(Hand3[1]) && Hand3[0].compareSuit(Hand3[2]))
	{
	return true;
	}
	else
	{
	return false;
	}
}

bool isRoyal(Card Hand3[])
{
	if(Hand3[0].getRank() + Hand3[0].getRank() + Hand3[0].getRank() == 33)
	{
	return true;
	}
	else
	{
	return false;
	}
}


