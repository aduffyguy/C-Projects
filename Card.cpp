/*************************************************************/
/* File:        Card.cpp                                     */ 
/*Author:       Alan Duffy-Guy	 					         */
/*Creation Date:February 13, 2015                            */
/*Extended by:  Alan Duffy-Guy                               */
/*Course:       CSC 136                                      */
/*Professor:    Dr. Spiegel                                  */
/*File Name:    p1.cpp		 					             */
/* Purpose:     The Definitions of the functions and the     */
/*			    deceleration of the card object.             */
/*************************************************************/


#include "Card.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


  enum Rank {two, three, four, five, 
			six, seven, eight, nine,ten, jack, queen, king, ace};
  enum Suit {spade, heart, club, diamond};
  
 

  /********************************************************/
  /*  Function Name: Card                                 */
  /*                                                      */
  /*  Description:   The Card constructor.		          */
  /*                                                      */
  /*  Parmeters:     int value = 0 - default value        */
  /*                                                      */
  /*  Return Value:  card - export -                      */
  /*                 the return value of setCard          */
  /********************************************************/
  Card::Card(int value)
   {
   setCard(value);
   
   }
  // Sets
  /********************************************************/
  /* Function Name:  setRank                              */
  /*                                                      */
  /* Description:    sets the card's rank based on the    */
  /*                 integer recieved                     */
  /*                                                      */
  /* Parameters:     int value - import - the int value   */
  /*                 passed in                            */
  /*                                                      */
  /* Return Value:   none                                 */
  /********************************************************/
// Set card rank
  void Card::setRank(int value)
    { rank = (Rank)(value % 13);
    }
  /********************************************************/
  /* Function Name:  setSuit                              */
  /*                                                      */
  /* Description:    sets teh suit of the card based on   */
  /*                 the integer received                 */
  /*                                                      */
  /* Parameters:     int value - import -  the int        */
  /*                 value passed in                      */
  /*                                                      */
  /* Return Value:   none                                 */
  /********************************************************/
  void Card::setSuit(int value)
    { suit = (Suit)(value / 13);
    }
  /********************************************************/
  /* Function Name:  setCard                              */
  /*                                                      */
  /* Description:    calls setSuit and setRank based on   */
  /*                 the integer value received           */
  /*                                                      */
  /* Parameters:     int value - import - the int value to*/
  /*                 pass                                 */
  /*                                                      */
  /* Return Value:   none                                 */
  /********************************************************/
  void Card::setCard(int value)
	{
	setSuit(value);
	setRank(value);
	}
  //Gets
  /********************************************************/
  /* Function Name:  getRankString                        */
  /*                                                      */
  /* Description:   gets the string from the rankStr array*/
  /*                                                      */
  /* Parameters:     none                                 */
  /*                                                      */
  /* Return Value:  string -Import/Export- rankStr[rank]  */
  /*			        - the string value of the rank    */
  /********************************************************/
  string Card::getRankString() const
	{
	return rankStr[rank];
	}
  /********************************************************/
  /* Function Name:  getSuitString                        */
  /*                                                      */
  /* Description:    gets the character from the          */
  /*                 suitChar array                       */
  /*                                                      */
  /* Parameters:     none                                 */
  /*                                                      */
  /* Return Value:   char - import/export -the char value */
  /*                 of the suit                          */
  /********************************************************/
  char Card::getSuitString() const
	{
	return suitChar[suit];
	}

   /*******************************************************/
  /* Function Name:  getRank                              */
  /*                                                      */
  /* Description:    gets the integer value of the        */
  /*                 rank enumeration                     */
  /*                                                      */
  /* Parameters:     none                                 */
  /*                                                      */
  /* Return Value:   int - import/export - the Rank value */
  /********************************************************/
  int Card::getRank() const
	{
	return (rank);
	}

  /********************************************************/
  /* Function Name:  getSuit                              */
  /*                                                      */
  /* Description:    gets the integer value of the suit   */
  /*                 enumeration                          */
  /*                                                      */
  /* Parameters:     none                                 */
  /*                                                      */
  /* Return Value:   int - import/export - the Suit value */
  /********************************************************/
  int Card::getSuit() const
	{
	return (suit);	
	}
  /********************************************************/
  /* Function Name:  compareSuit                          */
  /*                                                      */
  /* Description:    compares the object being called on  */
  /*                 to the object in the parameter to see*/
  /*				 if there suits are the same          */
  /*                                                      */
  /* Parameters:     const Card &c - import-              */
  /*                   the other card                     */
  /*                                                      */
  /* Return Value:   bool - export - true if the          */
  /*                 suits are the same, otherwise false  */
  /********************************************************/
  bool Card::compareSuit(const Card &right) const
	{
		if (getSuit() == right.getSuit())
			return true;
		else 
			return false;
	}
  /********************************************************/
  /* Function Name:  operator <                           */
  /*                                                      */
  /* Description:    compares the object being called on  */
  /*                 to see if its rank is less than the  */
  /*                 object in the paramer's rank         */
  /*                                                      */
  /* Parameters:     const Card &right - import -         */
  /*			     the other card                       */
  /*                                                      */
  /* Return Value:   bool - export -true if *this's rank  */
  /*                 is less than                         */
  /*		     	 right's rank			              */
  /********************************************************/
  bool Card::operator<(const Card &right) const
  {
	  if (getRank() < right.getRank())
		  return true;
	  else
		  return false;
  }

  /********************************************************/
  /* Function Name:  operator ==                          */
  /*                                                      */
  /* Description:    compare 2 object's ranks to see if   */
  /*                 the ranks have the same rank         */
  /*                                                      */
  /* Parameters:     const Card &right - import - the     */
  /*                 other card                           */
  /*                                                      */
  /* Return Value:   bool - export - true if *this's rank */
  /*                   is equal to right's rank			  */
  /********************************************************/
  bool Card::operator==(const Card &right) const
  {
	  if (getRank() == right.getRank())
		  return true;
	  else
		  return false;
  }
 
       
  

  const string Card::rankStr[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10",
         "J", "Q", "K", "A"};
  const char Card::suitChar[] = {'S', 'H', 'C', 'D'};



 /*********************************************************/
  /* Function Name:  operator <<                          */
  /*                                                      */
  /* Description:    overloades the stream extraction to  */
  /*                 let the output output the rank and   */
  /*                 suit of the card                     */
  /* Parameters:     ostream &out - import/export - the   */
  /*                  ostream being passed in             */
  /*		         const Card &right - import- the card */
  /*                 object on the right                  */
  /*                                                      */
  /*                                                      */
  /* Return Value:   ostream - out - import/export -      */
  /*			     The ostream passed in	the card      */
  /********************************************************/
  ostream &operator<<(ostream &out,const Card &right)
  { 
	out << right.getRankString() << right.getSuitString() << " ";
  
  return(out);
  }
 /*********************************************************/
  /* Function Name:  operator >>                          */
  /*                                                      */
  /* Description:    overloades the stream extraction to  */
  /*                 let the output output the rank and   */
  /*                 suit of the card                     */
  /*                                                      */
  /* Parameters:     ifstream &inf - import/export - the  */
  /*                 ifstream being passed in             */
  /*		         Card &right - import- the card       */
  /*                 object on the right                  */
  /*		                                			  */
  /*                                                      */
  /* Return Value:   ifstream &inf -import/export -       */
  /*                 The ifstream passed in	              */
  /********************************************************/
  ifstream &operator>>(ifstream &inf, Card &right)
  { 
  int i;
  inf >> i;
  right.setRank(i);
  right.setSuit(i);
  return(inf);  
  }


