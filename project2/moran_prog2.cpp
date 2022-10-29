/*
    Author:          Julia Moran
    Major:           Computer Science
    Creation Date:   February 17, 2022
    Due Date:        February 27, 2022
    Course:          CSC136 030
    Professor Name:  Dr. Frye
    Assignment:      #2
    Filename:        moran_prog2.cpp
    Purpose:         This program will accept the filename of a file that
                     contains the names, animal types, and genders of the
                     dolphins and turtles at an aquarium. Depending on the
                     user's choice, the program will  either print one
                     searched animal's information, print the names of all the
                     animals of the user's choice of type, print all animals,
                     or quit.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Animal.h"

using namespace std;

//Define the max number of animals
#define MAX_NUM_OF_ANIMALS 100

//Function Prototypes
void openFile(ifstream&, string&);
void readFile(ifstream&, int&, Animal[]);
char menu();
void choiceSwitch(char, int&, Animal[]);
int nameSearch(string, int&, Animal[]);
void printAnimalInfo(int, Animal[], int&);
void printAnimalsByType(char, int&, Animal[]);
void sortAnimalNames(int&, Animal[]);
void printTableHeader();
void printAllAnimals(int&, Animal[]);
string typeInWordForm(int&, Animal[], int);
string genderInWordForm(int&, Animal[], int);
void swap(Animal&, Animal&);

int main()
{
    //Variables
    ifstream ifs;
    char choice;
    string filename;
    int numberOfAnimals = 0;

    //Open the file
    openFile(ifs, filename);

    //Delcare array of objects belonging to the Animal class
    Animal animals[MAX_NUM_OF_ANIMALS];

    //Read the file
    readFile(ifs, numberOfAnimals, animals);

    //Print the menu and decide which action to take based on the user's selection
    choice = menu();
    choiceSwitch(choice, numberOfAnimals, animals);

    return 0;
}// end main

/*
    Function Name:  openFile
    Description:    Atttempt to open the file based on the file name inputted
                    by the user. If the file name is incorrect, halt the
                    program.
    Parameters:     ifstream - file: file that the user attempts to open
                    string - filename: name of the file
    Return Value:   N/A
*/
void openFile(ifstream& file, string& filename)
{
    //Variable
    bool fileOpen = false;

    while(fileOpen == false)
    {
        //Ask for the name of the file
        cout << "Enter the name of the input file: ";
        cin >> filename;

        //Attempt to open the file
        file.open(filename);

        //Check to see if the file failed to open
        if(file.fail())
        {
            cout << "Error: Can't open file.\n" << endl;
        }// end if
        else
        {
            fileOpen = true;
        }// end else
    }//end while
}// end function openFile

/*
    Function Name:  readFile
    Description:    Read in the animal names, types, and genders from the file.
    Parameters:     ifstream - ifs: input file stream
                    int - numberOfAnimals: number of animals in the file
                    Animal - animals[]: array of the objects containing the animal
                                        info within the Animal class
    Return Type:    N/A
*/
void readFile(ifstream& ifs, int& numberOfAnimals, Animal animals[])
{
    //Variables
    string name;
    char type;
    char gender;

    //Read in the first animal and all its data into the animals array
    ifs >> name;
    animals[numberOfAnimals].setName(name);
    ifs >> type;
    animals[numberOfAnimals].setType(type);
    ifs >> gender;
    animals[numberOfAnimals].setGender(gender);

    while(!ifs.eof() && numberOfAnimals < MAX_NUM_OF_ANIMALS)
    {
        //Increment the count of the number of animals
        numberOfAnimals++;

        //Extract the next animals' data to the animals array
        ifs >> name;
        animals[numberOfAnimals].setName(name);
        ifs >> type;
        animals[numberOfAnimals].setType(type);
        ifs >> gender;
        animals[numberOfAnimals].setGender(gender);

    }// end while loop

    //Close the file
    ifs.close();

}// end function readFile

/*
    Function Name:  menu
    Description:    Accept the choice from the user to decide which function
                    to use.
    Parameters:     N/A
    Return Type:    char - choice: the choice of action decided by the user
*/
char menu()
{
    //Variable
    char choice;

    //Get the user's selection from the menu choices, repeat until a valid input is made
    while(choice != 'N' && choice != 'T' && choice != 'P' && choice != 'Q')
    {
        cout << "\nPlease select one of the following options." << endl;
        cout << "N: Search for an animal by its name." << endl;
        cout << "T: Print all animals of one type." << endl;
        cout << "P: Print all animals." << endl;
        cout << "Q: Quit." << endl;

        cout << "Selection: ";
        cin >> choice;

        //Make the choice uppercase to make it case-sensitive
        choice = toupper(choice);

        //Display an error message if the user fails to enter a valid input
        if(choice != 'N' && choice != 'T' && choice != 'P' && choice != 'Q')
        {
            cout << "\nInvalid input. Please select an N, T, P, or Q." << endl;
        }// end if
    }// end while loop

    return choice;

}// end function menu

/*
    Function Name:  choiceSwitch
    Description:    Switch statement that directs to the specific function
                    based on the user's choice.
    Parameters:     char - choice: the choice of action decided by the user
                    int - numberOfAnimals: number of animals in the file
                    Animal - animals[]: array of the objects containing the animal
                                        info within the Animal class
    Return Type:    N/A
*/
void choiceSwitch(char choice, int& numberOfAnimals, Animal animals[])
{
    //Variables
    string searchValue;
    int index = -1;
    char selectedType;

    while(choice != 'Q')
    {
        //Switch statement to choose which function to run
        switch(choice)
        {
            //The case of searching for a specific animal
            case 'N':
                index = -1;

                while(index == -1)
                {
                    //Get the name of the animal to be searched
                    cout << "\nEnter the name of the animal you would like to search for: ";
                    cin >> searchValue;

                    //Find the index of the animal the user is searching for
                    index = nameSearch(searchValue, numberOfAnimals, animals);
                }//end while loop

                //Print the information of the searched animal
                printAnimalInfo(index, animals, numberOfAnimals);

                break;

            //The case of printing all animals of a specified type
            case 'T':
                selectedType = ' ';

                while(selectedType != 'T' && selectedType != 'D')
                {
                    //Get the type of animal the user wishes to print
                    cout << "\nEnter the type of animal you would like to print out." << endl;
                    cout << "T: Print all turtles." << endl;
                    cout << "D: Print all dolphins." << endl;

                    cout << "Selection: ";
                    cin >> selectedType;

                    //Make the type uppercase to make it case-sensitive
                    selectedType = toupper(selectedType);

                    //Display error message if the user enters invalid input
                    if(selectedType != 'T' && selectedType != 'D')
                    {
                        cout << "\nInvalid input. Please select a T or D." << endl;
                    }// end if
                }//end while loop

                //Print out the animals of the specified type
                printAnimalsByType(selectedType, numberOfAnimals, animals);

                break;

            //The case of printing all animals sorted by name
            case 'P':
                //Sort the animal names
                sortAnimalNames(numberOfAnimals, animals);

                //Print out the animals' data
                printAllAnimals(numberOfAnimals, animals);

                break;
        }// end switch

        choice = menu();
    }// end while
}//end function choiceSwitch

/*
    Function Name:  nameSearch
    Description:    Search for the index of the name inputed by the user.
    Parameters:     string - searchValue: name of the animal the user is
                                          searching for
                    int - numberOfAnimals: number of animals in the file
                    Animal - animals[]: array of the objects containing the animal
                                        info within the Animal class
    Return Type:    int: index of the animal searched, -1 if the animal is not
                         in the file
*/
int nameSearch(string searchValue, int& numberOfAnimals, Animal animals[])
{
    //Capitalize the first letter of the name in case the user inputted name is lowercase
    searchValue[0] = toupper(searchValue[0]);

    //Go through the animals array and search for the name the user inputed
    for(int i = 0; i < numberOfAnimals; i++)
    {
        if (animals[i].getName() == searchValue)
        {
            return i;
        }// end if
    }// end for loop

    //Display error message if the name is not in the file
    cout << "Name not found. Try again." << endl;

    return -1;
}//end function nameSearch

/*
    Function Name:  printAnimalInfo
    Description:    Print the name, type, and gender of the animal the user
                    searched for.
    Parameters:     int - index: index of the searched animal in the
                                 animalNames array
                    Animal - animals[]: array of the objects containing the animal
                                        info within the Animal class
                    int - numberOfAnimals: number of animals in the file
    Return Type:    N/A
*/
void printAnimalInfo(int index, Animal animals[], int& numberOfAnimals)
{
    //Variables
    string type;
    string gender;

    //Set the types and genders of the animals to their word form
    type = typeInWordForm(numberOfAnimals, animals, index);
    gender = genderInWordForm(numberOfAnimals, animals, index);

    //Make the type and gender of the animal lowercase
    type[0] = tolower(type[0]);
    gender[0] = tolower(gender[0]);

    //Print out the inputed animal's information in sentence form
    cout << animals[index].getName() << " is a " << gender << " " << type << "." << endl;
}//end function printAnimalInfo

/*
    Function Name:  printAnimalsByType
    Description:    Print all the names of the animals of the type chosen by
                    the user.
    Parameters:     char - selectedType: type of the animal the user wishes to print
                    Animal - animals[]: array of the objects containing the animal
                                        info within the Animal class
                    int - numberOfAnimals: number of animals in the file
    Return Type:    N/A
*/
void printAnimalsByType(char selectedType, int& numberOfAnimals, Animal animals[])
{
    //Variables
    string type;
    string gender;

    //Sort the animal names into alphabetical order
    sortAnimalNames(numberOfAnimals, animals);

    //Turtle output
    if(selectedType == 'T')
    {
        //Print out the title of the table
        cout << "\n     All Turtles at the Aquarium" << endl;
        cout << setw(37) << setfill('-')  << '-' << setfill(' ') << endl;

        //Print out the titles of the columns in the table header
        printTableHeader();

        for(int i = 0; i < numberOfAnimals; i++)
        {
            //Check if the animal type is a turtle
            if(animals[i].getType() == 'T')
            {
                //Convert the types and genders of the turtles to their word forms
                type = typeInWordForm(numberOfAnimals, animals, i);
                gender = genderInWordForm(numberOfAnimals, animals, i);

                //Print out each row of the table
                cout << setfill(' ') << setw(15) << animals[i].getName() << setw(15) << type << setw(15) << gender << endl;
            }// end if
        }// end for loop
    }// end if

    //Dolphin output
    if(selectedType == 'D')
    {
        //Print out the title of the table
        cout << "\n     All Dolphins at the Aquarium" << endl;
        cout << setw(37) << setfill('-') << '-' << setfill(' ') << endl;

        //Print out the titles of the columns in the table header
        printTableHeader();

        for(int i = 0; i < numberOfAnimals; i++)
        {
            //Check if the animal type is a dolphin
            if(animals[i].getType() == 'D')
            {
                //Convert the types and genders of the dolphins to their word forms
                type = typeInWordForm(numberOfAnimals, animals, i);
                gender = genderInWordForm(numberOfAnimals, animals, i);

                //Print out each row of the table
                cout << setfill(' ') << setw(15) << animals[i].getName() << setw(15) << type << setw(15) << gender << endl;
            }// end if
        }// end for loop
    }// end if
}//end function printAnimalsByType

/*
    Function Name:  printTableHeader
    Description:    Print the header line containing the titles of the columns.
    Parameters:     N/A
    Return Value:   N/A
*/
void printTableHeader()
{
    //Print out the titles for each column for tables
    cout << left << setfill(' ') << '\n' << setw(15) << "Name" << setw(15) << "Type" << setw(15) << "Gender" << endl;

    //Print out the underlines for each column
    cout << setw(4) << setfill('-') << '-' << setw(11) << setfill(' ') << ' ' << setw(4) << setfill('-') << '-' << setw(11) << setfill(' ') << ' ';
    cout << setw(6) << setfill('-') << '-' << endl;
    cout << setfill(' ') << endl;
}// end function printTableHeader

/*
    Function Name:  printAllAnimals
    Description:    Print out all animals at the aquarium, sorted by name, in
                    a table format.
    Parameters:     Animal - animals[]: array of the objects containing the animal
                                        info within the Animal class
                    int - numberOfAnimals: number of animals in the file
    Return Value:   N/A
*/
void printAllAnimals(int& numberOfAnimals, Animal animals[])
{
    //Variables
    string type;
    string gender;

    //Print the title of the table
    cout << "\n     All Animals at the Aquarium" << endl;
    cout << setw(37) << setfill('-')  << '-' << endl;

    //Print the header containing the names of the columns for the table
    printTableHeader();

    for(int i = 0; i < numberOfAnimals; i++)
    {
        //Convert the types and genders of the animals to their word forms
        type = typeInWordForm(numberOfAnimals, animals, i);
        gender = genderInWordForm(numberOfAnimals, animals, i);

        //Print out the animal's name, type, and gender on a row
        cout << setfill(' ') << setw(15) << animals[i].getName() << setw(15) << type << setw(15) << gender << endl;
    }// end for loop
}//end function printAllAnimals

/*
    Function Name:  sortAnimalNames
    Description:    A sorting function that sorts the array of animals into
                    alphabetical order by name.
    Parameters:     int - numberOfAnimals: number of animals in the array
                    Animal - animals[]: array of the objects containing the animal
                                        info within the Animal class
    Return Value:   N/A
*/
/*
    Author Name:    Dr. Lisa Frye
    Title:          Selection Sort Pseudocode
    Date:           February 3, 2022
    Retrieved February 3, 2022 from the CSC136 Spring 2022 Class Notebook
*/
void sortAnimalNames(int& numberOfAnimals, Animal animals[])
{
    /*
    The following function is based off of Dr. Frye's example in class
    titled "Selection Sort Pseudocode," written and retrieved on February 3,
    2022.
    */

    //Variables
    int minIndex;
    int startingIndex = 0;

    //Loop to increment the starting value each time
    for(int i = 0; i < numberOfAnimals - 1; i++)
    {
        //Set the starting index
        startingIndex = i;

        //Set the minimum index to the starting index to compare the values
        minIndex = startingIndex;

        //Loop through the array to find the smallest value
        for(int j = startingIndex + 1; j < numberOfAnimals; j++)
        {
            //Compare the current value in the array to the current smallest value. If it is smaller, set the minimum value to that value
            if(animals[j].getName() < animals[minIndex].getName())
            {
                minIndex = j;
            }// end if
        }// end for loop

        //Swap the smallest value with the starting value
        if(startingIndex != minIndex)
        {
            swap(animals[startingIndex], animals[minIndex]);
        }// end if
    }// end for loop
}// end function sortAnimalNames

/*
    Function Name:  swap
    Description:    Swap two objects from the Animal class.
    Parameters:     Animal - an1: one of the objects that will be swapped
                    Animal - an2: the other object to be swapped
    Return Value:   N/A
*/
void swap(Animal& an1, Animal& an2)
{
    //Temporary variable
    Animal tempAn;

    //Swap the two objects
    tempAn = an1;
    an1 = an2;
    an2 = tempAn;
}// end function swap

/*
    Function Name:  typeInWordForm
    Description:    Convert the types of the animals to their word forms
    Parameters:     int - numberOfAnimals: number of animals in the array
                    Animal - animals[]: array of objects containing the animal
                                        info within the Animal class
                    int - index: index of the object
    Return Value:   string - type: type of the object at the given index in
                                    word form
*/
string typeInWordForm(int& numberOfAnimals, Animal animals[], int index)
{
    //Variable
    string type;

    //Set the type to its word form based on what the type of the animal is
    if(animals[index].getType() == 'T')
    {
        type = "Turtle";
    }// end if
    else
    {
        type = "Dolphin";
    }//end else

    return type;
}// end function typeInWordForm

/*
    Function Name:  genderInWordForm
    Description:    Convert the genders of the animals to their word forms
    Parameters:     int - numberOfAnimals: number of animals in the array
                    Animal - animals[]: array of objects containing the animal
                                        info within the Animal class
                    int - index: index of the object
    Return Value:   string - gender: gender of the object at the given index in
                                     word form
*/

string genderInWordForm(int& numberOfAnimals, Animal animals[], int index)
{
    //Variable
    string gender;

    //Set the gender to its word form based on what the gender of the animal is
    if(animals[index].getGender() == 'F')
    {
        gender = "Female";
    }// end if
    else
    {
        gender = "Male";
    }// end else

    return gender;
}// end function genderInWordForm
