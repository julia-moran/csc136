/*
    Author:          Julia Moran
    Major:           Computer Science
    Creation Date:   April 11, 2022
    Due Date:        April 24, 2022
    Course:          CSC136 030
    Professor Name:  Dr. Frye
    Assignment:      #4
    Filename:        moran_prog4.cpp
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
#include <errno.h>
#include "LinkedList.h"

using namespace std;

//Function Prototypes
void openFile(ifstream&, string&);
void readFile(ifstream&, LinkedList&);
char menu();
void choiceSwitch(char, LinkedList&, LinkedList&);
void addAnimal(LinkedList&);
void deleteAnimal(LinkedList&, LinkedList&);
void nameSearch(LinkedList&);
void printAnimalInfo(Animal&, LinkedList&);
char getSelection();
void printAnimalsByType(char, LinkedList&);
void printTableHeader();
void printAllAnimals(LinkedList&);

int main()
{
    //Variables
    ifstream ifs;
    char choice;
    string filename;

    //Open the file
    openFile(ifs, filename);

    //Delcare array of objects belonging to the Animal class
    LinkedList animalsList;
    LinkedList archive;

    LinkedList newOne(archive);

    //Read the file
    readFile(ifs, animalsList);

    //Print the menu and decide which action to take based on the user's selection
    choice = menu();
    choiceSwitch(choice, animalsList, archive);

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
                    LinkedList - animalsList: list of animals in the linked list
    Return Type:    N/A
*/
void readFile(ifstream& ifs, LinkedList& animalsList)
{
    //Variables
    Animal tempAnimal;
    errno = 0;

    //Start at the beginning of the list
    animalsList.first();

    //Read in the first animal from the file to a temporary Animal object
    ifs >> tempAnimal;

    while(!ifs.eof())
    {
        switch(errno)
        {
            //Successful read of the data
            case 0:
                //Insert the new animal into the list in alphabetical order
                animalsList.orderedInsert(tempAnimal);
                animalsList.next();

                //Read in the next animal
                ifs >> tempAnimal;
                continue;
                break;

            //Case of the data being invalid
            case 1:
                //Print error message
                cout << "Error reading data. Invalid data skipped." << endl;

                //Reset the errno variable
                errno = 0;

                animalsList.next();

                //Read in the next animal
                ifs >> tempAnimal;
                continue;
                break;

            case 2:
                break;
        }// end switch
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
    while(choice != 'N' && choice != 'T' && choice != 'P' && choice != 'Q' && choice != 'A' && choice != 'D' && choice != 'R')
    {
        cout << "\nPlease select one of the following options." << endl;
        cout << "A: Add an animal." << endl;
        cout << "D: Delete an animal." << endl;
        cout << "N: Search for an animal by its name." << endl;
        cout << "T: Print all animals of one type." << endl;
        cout << "P: Print all animals." << endl;
        cout << "R: Print archived animals." << endl;
        cout << "Q: Quit." << endl;

        cout << "Selection: ";
        cin >> choice;

        //Make the choice uppercase to make it case-sensitive
        choice = toupper(choice);

        //Display an error message if the user fails to enter a valid input
        if(choice != 'N' && choice != 'T' && choice != 'P' && choice != 'Q' && choice != 'A' && choice != 'D' && choice != 'R')
        {
            cout << "\nInvalid input. Please select an A, D, N, T, P, R, or Q." << endl;
        }// end if
    }// end while loop

    return choice;

}// end function menu

/*
    Function Name:  choiceSwitch
    Description:    Switch statement that directs to the specific function
                    based on the user's choice.
    Parameters:     char - choice: the choice of action decided by the user
                    LinkedList - animalsList: list of animals in the linked
                                              list
                    LinkedList - archive: list of animals deleted from the
                                          animals list linked list
    Return Type:    N/A
*/
void choiceSwitch(char choice, LinkedList& animalsList, LinkedList& archive)
{
    //Variables
    char selectedType;
    bool check;

    while(choice != 'Q')
    {
        //Switch statement to choose which function to run
        switch(choice)
        {
            //The case of adding an animal to the list
            case 'A':
                addAnimal(animalsList);
                break;

            //The case of deleting an animal from the list
            case 'D':
                deleteAnimal(archive, animalsList);
                break;

            //The case of searching for a specific animal
            case 'N':
                nameSearch(animalsList);
                break;

            //The case of printing all animals of a specified type
            case 'T':
                selectedType = getSelection();

                //Print out the animals of the specified type
                printAnimalsByType(selectedType, animalsList);
                break;

            //The case of printing all animals sorted by name
            case 'P':
                cout << "\n     All Animals at the Aquarium" << endl;
                cout << setw(37) << setfill('-')  << '-' << endl;

                //Print out the animals' data
                printAllAnimals(animalsList);
                break;

            //The case of printing the archived animals
            case 'R':
                if(archive.empty() == false)
                {
                    cout << "\n  Archived Animals at the Aquarium" << endl;
                    cout << setw(37) << setfill('-')  << '-' << endl;

                    //Print out the data of the archived animals
                    printAllAnimals(archive);
                }// end if
                else
                {
                    cout << "\nThere are no animals in the archive." << endl;
                }// end else
                break;
        }// end switch

        choice = menu();
    }// end while
}//end function choiceSwitch

/*
    Function Name:  addAnimal
    Dexcription:    Add the animal specified by the user input to the linked list
    Parameter:      LinkedList - animalsList: list of animals in the linked list
    Return Value:   N/A
*/
void addAnimal(LinkedList& animalsList)
{
    //Variables
    Animal addedAnimal;
    errno = 0;

    animalsList.first();

    //Get the user's input
    cout << "\nEnter the name, type, and gender of the animal you would like to add, seperated by commas: " << endl;
    cout << "Example: Name,T,F" << endl;
    cin.ignore(10,'\n');
    cin >> addedAnimal;

    //Check if the user's input had errors
    switch(errno)
    {
        //Successful read of the data
        case 0:
            //Add the new animal to the list
            animalsList.orderedInsert(addedAnimal);
            cout << "Animal added." << endl;
            break;

        //Case of the data being invalid
        case 1:
            //Print error message
            cout << "Error reading data. Invalid data entered." << endl;
            errno = 0;
            break;

        case 2:
            break;
    }// end switch
}// end function addAnimal

/*
    Function Name:  deleteAnimal
    Description:    Delete the animal specified by the user input from the linked list
    Parameters:     LinkedList - archive: list of archived animals in animalsList
                    LinkedList - animalsList: list of animals in the linked list
    Return Value:   N/A

*/
void deleteAnimal(LinkedList& archive, LinkedList& animalsList)
{
    //Variables
    Animal deletedAnimal;
    bool check;

    //Get the user input
    cout << "\nEnter the name, type, and gender of the animal you would like to delete, seperated by commas." << endl;
    cout << "Example: Name,T,F" << endl;
    cin.ignore(10,'\n');
    cin >> deletedAnimal;

    //Search for the animal to be deleted
    if(animalsList.find(deletedAnimal) == true)
    {
        //Put the deleted animal into the archive
        animalsList.retrieve(deletedAnimal);
        archive.insert(deletedAnimal);

        //Remove the deleted animal from the animals list
        animalsList.remove(deletedAnimal);
        cout << "Animal deleted." << endl;
    }// end if
    else
    {
        cout << "Animal not found." << endl;
    }// end else
}// end function deleteAnimal
/*
    Function Name:  nameSearch
    Description:    Search for and output the name inputed by the user.
    Parameters:     LinkedList - animalsList: list of animals in the linked list
    Return Type:    N/A
*/

void nameSearch(LinkedList& animalsList)
{
    //Variables
    Animal searchedAnimal;
    bool check = false;

    animalsList.first();

    //Get the name of the animal to be searched
    cout << "\nEnter the name, type, and gender of the animal you would like to search for, seperated by commas: " << endl;
    cout << "Example: Name,T,F" << endl;
    cin.ignore(10,'\n');
    cin >> searchedAnimal;

    //Find the animal the user is searching for
    check = animalsList.find(searchedAnimal);

    //Print the searched animal or report that it was not found
    if(check == true)
    {
        printAnimalInfo(searchedAnimal, animalsList);
    }// end if
    else
    {
        cout << "Animal not found." << endl;
    }// end else
}//end function nameSearch

/*
    Function Name:  printAnimalInfo
    Description:    Print the name, type, and gender of the animal the user
                    searched for.
    Parameters:     Animal - foundAnimal: the animal the user searched for
                    LinkedList - animalsList: list of animals in the linked
                    list
    Return Type:    N/A
*/
void printAnimalInfo(Animal& foundAnimal, LinkedList& animalsList)
{
    //Print out the title of the table
    cout << "\n          Searched Animal" << endl;
    cout << setw(37) << setfill('-')  << '-' << endl;

    //Print out the column header names
    printTableHeader();

    //Print out the searched animal's data
    animalsList.retrieve(foundAnimal);
    cout << foundAnimal;
}//end function printAnimalInfo

/*
    Function Name:  getSelection
    Description:    Get the choice from the user on whether to print the
                    turtles or the dolphins.
    Parameters:     N/A
    Return Value:   char - selectedType: character, a D or a T, that represents
                           what type of animals the user wants to ptrint out
*/
char getSelection()
{
    //Type of animal selected by the user
    char selectedType = ' ';

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

    return selectedType;
}

/*
    Function Name:  printAnimalsByType
    Description:    Print all the names of the animals of the type chosen by
                    the user.
    Parameters:     char - selectedType: type of the animal the user wishes to print
                    LinkedList - animalsList: list of animals in the linked list
    Return Type:    N/A
*/
void printAnimalsByType(char selectedType, LinkedList& animalsList)
{
    //Current animal in the list
    Animal currentAnimal;

    animalsList.first();

    //Turtle output
    if(selectedType == 'T')
    {
        //Print out the title of the table
        cout << "\n     All Turtles at the Aquarium" << endl;
        cout << setw(37) << setfill('-')  << '-' << setfill(' ') << endl;

        //Print out the titles of the columns in the table header
        printTableHeader();

        //Print the information of the turtles
        while(!animalsList.atEnd())
        {
            //Get the data of the current animal
            animalsList.retrieve(currentAnimal);

            //Print the turtles' info
            if(currentAnimal.getType() == 'T')
            {
                cout << currentAnimal;
            }// end if

            animalsList.next();
        }// end while loop

        if((animalsList.retrieve(currentAnimal) == true) && (currentAnimal.getType() == 'T'))
        {
            cout << currentAnimal;
        }// end if
    }// end if

    //Dolphin output
    if(selectedType == 'D')
    {
        //Print out the title of the table
        cout << "\n     All Dolphins at the Aquarium" << endl;
        cout << setw(37) << setfill('-') << '-' << setfill(' ') << endl;

        //Print out the titles of the columns in the table header
        printTableHeader();

        //Print the information of the dolphins
        while(!animalsList.atEnd())
        {
            //Get the current animals' data
            animalsList.retrieve(currentAnimal);

            //Print the dolphins' data
            if(currentAnimal.getType() == 'D')
            {
                cout << currentAnimal;
            }// end if

            animalsList.next();
        }// end for loop

        if((animalsList.retrieve(currentAnimal) == true) && (currentAnimal.getType() == 'D'))
        {
            cout << currentAnimal;
        }// end if
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
    Parameters:     LinkedList - animalsList: list of animals in a linked list
    Return Value:   N/A
*/
void printAllAnimals(LinkedList& animalsList)
{
    //Current animal in the list
    Animal currentAnimal;

    //Print the header containing the names of the columns for the table
    printTableHeader();

    animalsList.first();

    //Print out the data for each animal in the list
    while(!animalsList.atEnd())
    {
        animalsList.retrieve(currentAnimal);
        cout << currentAnimal;
        animalsList.next();
    }// end while loop

    if(animalsList.retrieve(currentAnimal) == true)
    {
        cout << currentAnimal;
    }// end if
}//end function printAllAnimals
