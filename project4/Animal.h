/*
    Author:         Julia Moran
    Major:          Computer Science
    Creation Date:  April 7, 2022
    Due Date:       April 24. 2022
    Course:         CSC136 030
    Professor Name: Dr. Frye
    Assignment:     #4
    Filename:       Animal.h
    Purpose:        Header file for the Animal class. Provides the prototypes
                    for the member functions within that class.
*/
//Source Cited:
/*****************************************************************************/
/*                                                                           */
// Author: Lisa Frye
// Date Created: January 14, 2022
// Date Retrieved: March 3, 2022
// Title: Animal.h
// Purpose: Definition for Animal class for the aquarium
// Retrieved from Dr. Frye's public directory under csc136/aquariumS22
/*                                                                           */
/*****************************************************************************/

/* Citation source: This header file was retrieved from the Kutztown CSIT
   public directory on March 3, 2022 and authored by Dr. Lisa Frye. All content except
   for the operator overloading was authored by Dr. Frye. */

#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

using namespace std;

class Animal
{
 public:
  // CONSTRUCTORS

  // Name: Animal
  // Description: Default Constructor
  // Parameters: None
  // Return Value: None
  Animal();   // default constructor

  // Name: Animal
  // Description: Constructor
  // Parameters: a_name - animal's name - input
  //             a_type - animal's type (D or T) - input
  //             a_gender - animal's gender - input
  // Return Value: None
  Animal(string a_name, char a_type, char a_gender);

  // Name: Animal
  // Description: Copy Constructor
  // Parameters: animal - Animal object
  // Return Value: None
  Animal(const Animal& animal);

  //DESTRUCTOR

  // Name: Animal
  // Description: Destructor
  // Parameters: None
  // Return Value: None
  ~Animal();

  //OVERLOADED OPERATORS

  // Name: operator<<
  // Description: Overloaded extraction operator
  // Parameters: in - input stream object
  //             animal - Animal object
  // Return Value: in - input stream object
  friend istream& operator>>(istream& in, Animal& animal);

  // Name: operator<<
  // Description: Overloaded insertion operator
  // Parameters: out - output stream object
  //             animal - Animal object
  // Return Value: out - output stream object
  friend ostream& operator<<(ostream& out, const Animal& animal);

  // Name: operator=
  // Description: Overloaded assignment operator
  // Parameters: animal - Animal object
  // Return Value: None
  Animal& operator=(const Animal& animal);

  // Name: operator==
  // Description: Overloaded == operator to determine equivalance
  // Parameters: animal - Animal object
  // Return Value: true or false
  bool operator==(const Animal& animal);

  // Name: operator!=
  // Description: Overloaded != operator to determine if the Animal objects are not equal to each other
  // Parameters: animal - Animal object
  // Return Value: true or false
  bool operator!=(const Animal& animal);

  // Name: operator<
  // Description: Overloaded < operator to compare two Animal objects by name
  // Parameters: animal - Animal object
  // Return Value: true or false
  bool operator<(const Animal& animal);

  // SET FUNCTIONS

  // Name: setName
  // Description: Set the animal's name
  // Parameters: sn_name - animal's name - input
  // Return Value: None
  void setName(string sn_name);

  // Name: setType
  // Description: Set the animal's type (D or T)
  // Parameters: st_type - the animal's type - input
  // Return Value: None
  int setType(char st_type);

  // Name: setGender
  // Description: Set the animal's gender
  // Parameters: sg_gender - the animal's gender - input
  // Return Value: None
  int setGender(char sg_gender);

  // GET FUNCTIONS

  // Name: getName
  // Description: Get the animal's name
  // Parameters: None
  // Return Value: the animal's name
  string getName();

  // Name: getType
  // Description: Get the animal's type
  // Parameters: None
  // Return Value: the animal's type
  char getType();

  // Name: getGender
  // Description: Get the animal's gender
  // Parameters: None
  // Return Value: the penanimaluin's gender
  char getGender();


 private:
  // Data members (attributes)
  string name;       // name of the animal
  char type;        // type of the animal - 'D' or 'T'
  char gender;       // gender of the animal - 'M' or 'F'

};  // end ANIMAL class

#endif  // ANIMAL_H
