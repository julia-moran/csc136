/*
    Author:          Julia Moran
    Major:           Computer Science
    Creation Date:   January 27, 2022
    Due Date:        February 8, 2022
    Course:          CSC136 030
    Professor Name:  Dr. Frye
    Assignment:      #1
    Filename:        program1.cpp
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

using namespace std;

//Constants
const int MAX_NUM_OF_ANIMALS = 100;
const int NUM_OF_COLUMNS = 2;

//Function Prototypes
void openFile(ifstream&, string&);
void readFile(ifstream&, string[], char[][NUM_OF_COLUMNS], string&, int&);
char menu();
void choiceSwitch(char, string[], char[][NUM_OF_COLUMNS], int&);
int nameSearch(string[], string, int&);
void printAnimalInfo(int, string[], char[][NUM_OF_COLUMNS]);
void printAnimalsByType(char, char [][NUM_OF_COLUMNS], string[], int&);
void sortAnimalNames(string[], int&, char[][NUM_OF_COLUMNS]);
void swapNames(string&, string&);
void swapChars(char&, char&);
void printTableHeader();
void printAllAnimals(string[], char[][NUM_OF_COLUMNS], int&);

int main()
{
    //Variables
    ifstream ifs;
    string animalNames[MAX_NUM_OF_ANIMALS];
    char animalTypeAndGender[MAX_NUM_OF_ANIMALS][NUM_OF_COLUMNS];
    char choice;
    string filename;
    int numberOfAnimals = 0;

    //Open the file
    openFile(ifs, filename);

    //Read the file
    readFile(ifs, animalNames, animalTypeAndGender, filename, numberOfAnimals);

    //Print the menu and decide which action to take based on the user's selection
    choice = menu();
    choiceSwitch(choice, animalNames, animalTypeAndGender, numberOfAnimals);

    return 0;
}// end main

/*
    Function Name:  openFile
    Description:    Atttempt to open the file based on the file name inputted
                    by the user. If the file name is incorrect, halt the
                    program.
    Parameters:     ifstream - file: file that the user attempts to open
    Return Value:   N/A
*/
void openFile(ifstream& file, string& filename)
{
    //Ask for the name of the file
    cout << "Enter the name of the input file: ";
    cin >> filename;

    //Attempt to open the file
    file.open(filename);

    //Check to see if the file failed to open
    if(file.fail())
    {
        cout << "Error: Can't open file." << endl;
        exit(0);
    }
}// end function openFile

/*
    Function Name:  readFile
    Description:    Read in the animal names, types, and genders from the file.
    Parameters:     ifstream - ifs: input file stream
                    string - animalNames[]: array containing the names of the
                                            animals
                    char - animalTypeAndGender[][]: array containing the types
                                                    and genders of the animals
    Return Type:    N/A
*/
void readFile(ifstream& ifs, string animalNames[], char animalTypeAndGender[][NUM_OF_COLUMNS], string& filename, int& numberOfAnimals)
{
    //Extract the first animal name into the animalNames array
    ifs >> animalNames[numberOfAnimals];

    //Extract the type of animal and its gender to the animalTypeAndGender array
    while(!ifs.eof() && numberOfAnimals < MAX_NUM_OF_ANIMALS)
    {
        for (int col = 0; col < NUM_OF_COLUMNS; col++)
        {
            ifs >> animalTypeAndGender[numberOfAnimals][col];
        }// end for loop

        //Increment the count of the number of animals
        numberOfAnimals++;

        //Extract the next animal name to the animalNames array
        ifs >> animalNames[numberOfAnimals];
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
    }// end while loop

    return choice;

}// end function menu

/*
    Function Name:  choiceSwitch
    Description:    Switch statement that directs to the specific function
                    based on the user's choice.
    Parameters:     char - choice: the choice of action decided by the user
                    string - animalNames[]: array containing the names of the
                                            animals
                    char - animalTypeAndGender[][]: array containing the types
                                                    and genders of the animals
    Return Type:    N/A
*/
void choiceSwitch(char choice, string animalNames[], char animalTypeAndGender[][NUM_OF_COLUMNS], int& numberOfAnimals)
{
    //Variables
    string searchValue;
    int index = -1;
    char type;

    //Switch statement to choose which function to run
    switch(choice)
    {
        //The case of searching for a specific animal
        case 'N':
            while(index == -1)
            {
                //Get the name of the animal to be searched
                cout << "\nEnter the name of the animal you would like to search for: ";
                cin >> searchValue;

                //Find the index of the animal the user is searching for
                index = nameSearch(animalNames, searchValue, numberOfAnimals);
            }//end while loop

            //Print the information of the searched animal
            printAnimalInfo(index, animalNames, animalTypeAndGender);

            //Get the next choice
            choice = menu();
            choiceSwitch(choice, animalNames, animalTypeAndGender, numberOfAnimals);

            break;

        //The case of printing all animals of a specified type
        case 'T':
            while(type != 'T' && type != 'D')
            {
                //Get the type of animal the user wishes to print
                cout << "\nEnter the type of animal you would like to print out." << endl;
                cout << "T: Print all turtles." << endl;
                cout << "D: Print all dolphins." << endl;

                cout << "Selection: ";
                cin >> type;

                //Make the type uppercase to make it case-sensitive
                type = toupper(type);
            }//end while loop

            //Print out the animals of the specified type
            printAnimalsByType(type, animalTypeAndGender, animalNames, numberOfAnimals);

            //Get the next choice
            choice = menu();
            choiceSwitch(choice, animalNames, animalTypeAndGender, numberOfAnimals);

            break;

        //The case of printing all animals sorted by name
        case 'P':
            //Sort the animal names
            sortAnimalNames(animalNames, numberOfAnimals, animalTypeAndGender);

            //Print out the animal names
            printAllAnimals(animalNames, animalTypeAndGender, numberOfAnimals);

            //Get the next choice
            choice = menu();
            choiceSwitch(choice, animalNames, animalTypeAndGender, numberOfAnimals);

            break;

        //The case of quitting the program
        case 'Q':
            exit(0);
    }// end switch
}//end function choiceSwitch

/*
    Function Name:  nameSearch
    Description:    Search for the index of the name inputed by the user.
    Parameters:     string - animalNames[]: array containing the names of the
                                            animals
                    string - searchValue: name of the animal the user is
                                          searching for
    Return Type:    int: index of the animal searched, -1 if the animal is not
                         in the file
*/
int nameSearch(string animalNames[], string searchValue, int& numberOfAnimals)
{
    //Capitalize the first letter of the name in case the user inputted name is lowercase
    searchValue[0] = toupper(searchValue[0]);

    //Go through the animalNames array and search for the name the user inputed
    for(int i = 0; i < numberOfAnimals; i++)
    {
        if (animalNames[i] == searchValue)
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
                    string - animalNames[]: array containing the names of the
                                             animals
                    char - animalTypeAndGender[][]: array containing the types
                                                    and genders of the animals
    Return Type:    N/A
*/
void printAnimalInfo(int index, string animalNames[], char animalTypeAndGender[][NUM_OF_COLUMNS])
{
    //Variables
    string type;
    string gender;

    //Set the animal type in word form based on the character in the data file
    if(animalTypeAndGender[index][0] == 'T')
    {
        type = "turtle";
    }// end if
    else
    {
        type = "dolphin";
    }// end else

    //Set the gender of the animal in word form based on the character in the data
    if(animalTypeAndGender[index][1] == 'F')
    {
        gender = "female";
    }// end if
    else
    {
        gender = "male";
    }// end else

    //Print out the inputed animal's information in sentence form
    cout << animalNames[index] << " is a " << gender << " " << type << "." << endl;
}//end function printAnimalInfo

/*
    Function Name:  printAnimalsByType
    Description:    Print all the names of the animals of the type chosen by
                    the user.
    Parameters:     char - type: type of the animal the user wishes to print
                    char - animalTypeAndGender[][]: array containing the types
                                                    and genders of the animals
                    string - animalNames[]: array containing the names of the
                                            animals
    Return Type:    N/A
*/
void printAnimalsByType(char type, char animalTypeAndGender[][NUM_OF_COLUMNS], string animalNames[], int& numberOfAnimals)
{
    //Sort the animal names into alphabetical order
    sortAnimalNames(animalNames, numberOfAnimals, animalTypeAndGender);

    //Turtle output
    if(type == 'T')
    {
        //Print out the title of the table
        cout << "\n     All Turtles at the Aquarium" << endl;
        cout << setw(37) << setfill('-')  << '-' << setfill(' ') << endl;

        //Print out the titles of the columns in the table header
        printTableHeader();

        for(int i = 0; i < numberOfAnimals; i++)
        {
            //Check if the animal type is a turtle
            if(animalTypeAndGender[i][0] == 'T')
            {
                //Output the animal's name and type
                cout << setw(15) << animalNames[i] << setw(15) << "Turtle";

                //Check the animal's gender and output it
                if(animalTypeAndGender[i][1] == 'F')
                {
                    cout << setw(15) << "Female" << endl;
                }//end if
                else
                {
                    cout << setw(15) << "Male" << endl;
                }// end else
            }// end if
        }// end for loop
    }// end if

    //Dolphin output
    if(type == 'D')
    {
        //Print out the title of the table
        cout << "\n     All Dolphins at the Aquarium" << endl;
        cout << setw(37) << setfill('-') << '-' << setfill(' ') << endl;

        //Print out the titles of the columns in the table header
        printTableHeader();

        for(int i = 0; i < numberOfAnimals; i++)
        {
            //Check if the animal type is a dolphin
            if(animalTypeAndGender[i][0] == 'D')
            {
                //Output the animal's name and type
                cout << setw(15) << animalNames[i] << setw(15) << "Dolphin";

                //Check the animal's gender and output it
                if(animalTypeAndGender[i][1] == 'F')
                {
                    cout << setw(15) << "Female" << endl;
                }// end if
                else
                {
                    cout << setw(15) << "Male" << endl;
                }// end else
            }// end if
        }// end for loop
    }// end if
}//end function printAnimalsByType

/*
    Function Name:  printTableHeader
    Description:    Print the header line containing the titles of the
                    columns.
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
    Parameters:     string - animalNames[]: array containing the names of the
                                            animals
                    char - animalTypeAndGender[][]: array containing the types
                                                    and genders of the animals
                    int - numberOfAnimals: number of animals in the file
    Return Value:   N/A
*/
void printAllAnimals(string animalNames[], char animalTypeAndGender[][NUM_OF_COLUMNS], int& numberOfAnimals)
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
        //Set the animal's type to its word form based on the character in the array
        if(animalTypeAndGender[i][0] == 'T')
        {
            type = "Turtle";
        }// end if
        else
        {
            type = "Dolphin";
        }//end else

        //Set animal's gender to its word form based on the character in the array
        if(animalTypeAndGender[i][1] == 'F')
        {
            gender = "Female";
        }// end if
        else
        {
            gender = "Male";
        }// end else

        //Print out the animal's name, type, and gender on a row
        cout << setfill(' ') << setw(15) << animalNames[i] << setw(15) << type << setw(15) << gender << endl;
    }// end for loop
}//end function printAllAnimals

/*
    Function Name:  sortAnimalNames
    Description:    A sorting function that sorts the array of animal names into
                    alphabetical order.
    Parameters:     string - animalNames[]: array containing the names of all
                                            the animals
                    int - numberOfAnimals: number of animals in the array
    Return Value:   N/A
*/
/*
    Author Name:    Dr. Lisa Frye
    Title:          Selection Sort Pseudocode
    Date:           February 3, 2022
    Retrieved February 3, 2022 from the CSC136 Spring 2022 Class Notebook
*/
void sortAnimalNames(string animalNames[], int& numberOfAnimals, char animalTypeAndGender[][NUM_OF_COLUMNS])
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
            if(animalNames[j] < animalNames[minIndex])
            {
                minIndex = j;
            }// end if
        }// end for loop

        //Swap the minimum value with the starting value
        swapNames(animalNames[startingIndex], animalNames[minIndex]);
        swapChars(animalTypeAndGender[startingIndex][0], animalTypeAndGender[minIndex][0]);
        swapChars(animalTypeAndGender[startingIndex][1], animalTypeAndGender[minIndex][1]);
    }// end for loop
}// end function sortAnimalNames

/*
    Function Name:  swapNames
    Description:    Swap two animal names.
    Parameters:     string - name1: one of the names that will be swapped
                    string - name2: the other name to be swapped
    Return Value:   N/A
*/
void swapNames(string& name1, string& name2)
{
    //Variable
    string tempName;

    //Swap the two names, using the temporary variable
    tempName = name1;
    name1 = name2;
    name2 = tempName;
}// end function swapNames

void swapChars(char& char1, char& char2)
{
    char tempChar;

    tempChar = char1;
    char1 = char2;
    char2 = tempChar;
}
