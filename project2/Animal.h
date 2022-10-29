/*****************************************************************************/
/*                                                                           */
// Author: Lisa Frye
// Date Created: January 14, 2022
// Filename: Animal.h
// Purpose: Definition for Animal class for the aquarium
/*                                                                           */
/*****************************************************************************/

#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

using namespace std;

class Animal
{
 public:
  // Constructors

  // Name: Animal
  // Description: Constructor
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
  // Description: Destructor
  // Parameters: None
  // Return Value: None
  ~Animal();


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
  void setType(char st_type);

  // Name: setGender
  // Description: Set the animal's gender
  // Parameters: sg_gender - the animal's gender - input
  // Return Value: None
  void setGender(char sg_gender);



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
