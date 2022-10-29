/*
    Author:         Julia Moran
    Major:          Computer Science
    Creation Date:  March 7, 2022
    Due Date:       March 29, 2022
    Course:         CSC136 030
    Professor Name: Dr. Frye
    Assignment:     #3
    Filename:       Animal.cpp
    Purpose:        This program serves as the implementation file for the class
                    header file for the Animal class. It will provide the
                    definitions for the prototypes specified in Animal.h.
*/

#include "Animal.h"
#include <iostream>
#include <iomanip>
#include <errno.h>

using namespace std;

// CONSTRUCTORS

/*
    Function Name: Animal
    Description:   Default constructor for the Animal class
    Parameters:    N/A
    Return Value:  N/A
*/
Animal::Animal()
{
    //Initialize the data memebrs to a default value
    setName(" ");
    setType(' ');
    setGender(' ');
}// end default constructor

/*
    Function Name: Animal
    Description:   Constructor
    Parameters:    string - a_name: name of the animal - input
                   char - a_type: type of the animal - input
                   char - a_gender: gender of the animal - input
    Return Value:  N/A
*/
Animal::Animal(string a_name, char a_type, char a_gender)
{
    //Set each data memebr to the inputted values
    setName(a_name);
    setType(a_type);
    setGender(a_gender);
}// end constructor

/*
    Function Name: Animal
    Description:   Copy constructor
    Parameters:    Animal - animal: animal object in the Animal class
    Return Value:  N/A
*/
Animal::Animal(const Animal& animal)
{
    //Set the animal's name, type, and gender to the copied animal
    setName(animal.name);
    setType(animal.type);
    setGender(animal.gender);
}// end copy constructor

// DESTRUCTOR

/*
    Function Name: ~Animal
    Description:   Destructor
    Parameters:    N/A
    Return Value:  N/A
*/
Animal::~Animal()
{
}// end destructor

// OVERLOADED OPERATORS

/*
    Function Name: operator>>
    Description:   Overloaded operator for the extraction operator
    Parameters:    istream - in: input stream variable
                   Animal - animal: animal object in the Animal class
    Return Value:  istream - in: input stream variable
*/
istream& operator>>(istream& in, Animal& animal)
{
    //Variables
    string nameTemp;
    char typeTemp;
    char comma;
    char genderTemp;

    //Read in the name of an animal in a CSV file
    getline(in, nameTemp, ',');

    //Check if at eof
    if(in.eof())
    {
        errno = 2;
        return in;
    }// end if

    //Read in the type and gender
    in >> typeTemp >> comma >> genderTemp;

    //Set the values read in from the file as the animal's name, type, and gender
    animal.setName(nameTemp);

    //Check if the values for the type and gender are valid
    if((animal.setType(typeTemp) == -1) || (animal.setGender(genderTemp) == -1))
    {
        errno = 1;
    }// end if

    //Skip to the next line
    in.ignore(100, '\n');

    return in;
}// end operator>>

/*
    Function Name: operator<<
    Description:   Overloaded operator for the insertion operator
    Parameters:    ostream - out: output stream variable
                   Animal - animal: animal object in the Animal class
    Return Value:  ostream - out: ouput stream variable
*/
ostream& operator<<(ostream& out, const Animal& animal)
{
    //Variables
    string typeWord;
    string genderWord;

    //Assign the animal's type to its word form
    if(animal.type == 'T')
    {
        typeWord = "Turtle";
    }// end if
    else
    {
        typeWord = "Dolphin";
    }// end else

    //Assign the animal's gender to its word form
    if(animal.gender == 'F')
    {
        genderWord = "Female";
    }// end if
    else
    {
        genderWord = "Male";
    }// end else

    //Output the animal's information in a table format
    out << setfill(' ') << setw(15) << animal.name << setw(15) << typeWord << setw(15) << genderWord << endl;

    return out;
}// end function operator<<

/*
    Function Name: operator=
    Description:   Overloaded operator for the assignment operator
    Parameters:    Animal - animal: animal object in the Animal class
    Return Value:  N/A
*/
Animal& Animal::operator=(const Animal& animal)
{
    //Check if current object is the same as the argument
    if (this == &animal)
    {
        return *this;
    }// end if

     //Assign each aspect to the animal object
    setName(animal.name);
    setType(animal.type);
    setGender(animal.gender);

    //Allow operator chaining
    return *this;
}// end function operator=

/*
    Function Name: operator==
    Description:   Checks to see if each part of the animal object is
                   equivalent to the current object
    Parameters:    Animal - animal: animal object in the Animal class
    Return Value:  bool - true or false depending on if the objects are
                          equivalent to one another
*/
bool Animal::operator==(const Animal& animal)
{
    //Check if the name, type, and gender of the animal is equivalent to the current object
    if((name == animal.name) && (type == animal.type) && (gender == animal.gender))
    {
        return true;
    }// end if
    else
    {
        return false;
    }// end else
}// end function operator==

/*
    Function Name: operator!=
    Description:   Checks to see if each part of the animal object is not
                   equivalent to the current object
    Parameters:    Animal - animal: animal object in the Animal class
    Return Value:  bool - true or false depending on if the objects are
                          unequivalent to one another
*/
bool Animal::operator!=(const Animal& animal)
{
    return !(*this == animal);
}// end function operator!=

// SET FUNCTIONS

/*
    Function Name: setName
    Description:   Sets the animal's name
    Parameters:    string - sn_name: name of the animal - input
    Return Value:  N/A
*/
void Animal::setName(string sn_name)
{
    name = sn_name;
}// end function setName

/*
    Function Name: setType
    Description:   Sets the animal's type
    Parameters:    char - st_type: type of the animal - input
    Return Value:  N/A
*/
int Animal::setType(char st_type)
{
    //Check if the type is either a T or D, for turtle or dolphin
    if(st_type == 'T' || st_type == 'D')
    {
        //Set the animal's type if it is a T or D
        type = st_type;
        return 0;
    }// end if
    else
    {
        return -1;
    }// end else
}// end function setType

/*
    Function Name: setGender
    Description:   Sets the animal's gender
    Parameters:    char - sg_gender: gender of the animal - input
    Return Value:  N/A
*/
int Animal::setGender(char sg_gender)
{
    //Check if the gender is an F or M, for female or male
    if(sg_gender == 'F' || sg_gender == 'M')
    {
        //Set the animal's gender if it is F or M
        gender = sg_gender;
        return 0;
    }// end if
    else
    {
        return -1;
    }// end else
}// end function setGender

// GET FUNCTIONS

/*
    Function Name: getName
    Description:   Returns the animal's name
    Parameters:    N/A
    Return Value:  string - name: the name of the animal
*/
string Animal::getName()
{
    return name;
}// end function getName

/*
    Function Name: getType
    Description:   Returns the animal's type
    Parameters:    N/A
    Return Value:  char - type: the animal's species
*/
char Animal::getType()
{
    return type;
}// end function getType

/*
    Function Name: getGender
    Description:   Returns the animal's gender
    Parameter:     N/A
    Return Value:  char - gender: the animal's gender
*/
char Animal::getGender()
{
    return gender;
}// end function getGender
