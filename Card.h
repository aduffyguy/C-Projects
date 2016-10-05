/*************************************************************/
/* File:        Card.h                                       */ 
/*Author:       Alan Duffy-Guy	 					         */
/*Creation Date:February 13, 2015                            */
/*Extended by:  Alan Duffy-Guy                               */
/*Course:       CSC 136                                      */
/*Professor:    Dr. Spiegel                                  */
/*File Name:    p1.cpp		 					             */
/* Purpose:     The Declarations of the functions and the    */
/*			    deceleration of the card object.             */
/*************************************************************/

#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>

using namespace std;

class Card {

  enum Rank {two, three, four, five, 
			six, seven, eight, nine,ten, jack, queen, king, ace};
  enum Suit {spade, heart, club, diamond};

 public:
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
  Card(int value = 0);
  
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
  void setRank(int value);

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
  void setSuit(int value);

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
  void setCard(int value);
  
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
  string getRankString() const;

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
  char getSuitString() const;

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
  int getRank() const;

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
  int getSuit() const;

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
  bool compareSuit(const Card &right) const;

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
  bool operator<(const Card &right) const;

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
  bool operator==(const Card &right) const;

 private:
  Rank rank;     
  Suit suit;

  static const string rankStr[];
  static const char suitChar[];

};

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
  ostream &operator<<(ostream &out,const Card &right);

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
  ifstream &operator>>(ifstream &inf,Card &right);

#endif

