/*
    Author:         Julia Moran
    Major:          Computer Science
    Creation Date:  April 7, 2022
    Due Date:       April 24, 2022
    Course:         CSC136 030
    Professor Name: Dr. Frye
    Assignment:     #4
    Filename:       LinkedList.cpp
    Purpose:        This program serves as the implementation file for the class
                    header file for the LinkedList class. It will provide the
                    definitions for the prototypes specified in LinkedList.h.
*/
//Source Cited:
/***************************************************************************/
/*
    Author Name: Dr. Lisa Frye
    Dates Created: April 7, 12, and 14, 2022
    Dates Retrieved: April 7, 12, and 14, 2022
    Title: Linked Lists Code
    Retrieved from Dr. Frye’s CSC136 Spring 2022 Class Notebook
*/
/*****************************************************************************/

/*
    Citation Source: The default constructor, destructor, get_node, insert, retrieve,
    remove, and traverse functions are based on Dr. Frye's examples in class titled
    "Linked Lists Code," written and retrieved on April 7, 12, and 14, 2022
*/


#include <iostream>
#include "LinkedList.h"
#include "Animal.h"
#include <errno.h>

using namespace std;

// CONSTRUCTORS

/*
    Function Name:  LinkedList
    Description:    Default constructor
    Parameters:     N/A
    Return Value:   N/A
*/
LinkedList::LinkedList()
{
    //Give the variables and pointers default values
    length = 0;
    current = NULL;
    head = NULL;
    previous = NULL;
}// end default constructor

/*
    Function Name:  LinkedList
    Description:    Copy Constructor
    Parameters:     LinkedList - list: list object in the LinkedList
                                       class
    Return Value:   N/A
*/
LinkedList::LinkedList(const LinkedList &list)
{
    node *temp;

    LinkedList();

    temp = list.head;

    //Copy the contents of the old list to the new list
    while (temp != NULL)
    {
        insert(temp->data);
        temp = temp->next;
      //  list = list->next;
    }// end while
}// end copy constructor

//DESTRUCTOR

/*
    Function Name:  ~LinkedList
    Description:    Destructor
    Parameters:     N/A
    Return Value:   N/A
*/
LinkedList::~LinkedList()
{
    current = head;

    //Loop through the contents of the list
    while (current != NULL)
    {
        previous = current;
        current = current->next;

        //Delete each node in the list
        delete previous;
    }// end while

    //Reset the values of the pointers and variables
    length = 0;
    head = NULL;
    current = NULL;
    previous = NULL;
}// end destructior

/*
    Function Name:  empty
    Description:    Check if the list is empty, returns true if it is
    Parameters:     N/A
    Return Value:   bool: true if the list is empty, false if not
*/
bool LinkedList::empty()
{
    //Check if the list is empty by checking if the length is 0
    if(length == 0)
    {
        return true;
    }// end if
    else
    {
        return false;
    }// end else
}// end function empty

/*
    Function Name:  atEnd
    Description:    Check if the current pointer is at the end of the
                    list
    Parameter:      N/A
    Return Value:   bool - true if at the end, false if not
*/
bool LinkedList::atEnd()
{
    //Check if the current points to NULL or the next pointer points to NULL to see
    //if the list is at its end
    if((current == NULL) || (current->next == NULL))
    {
        return true;
    }// end if
    else
    {
        return false;
    }// end else
}// end function atEnd

/*
    Function Name:  first
    Description:    Set the current pointer to the first node in the
                    list
    Parameters:     N/A
    Return Value:   N/A
*/
void LinkedList::first()
{
    //Set the current pointer to the head
    current = head;

    //Set the previous pointer to NULL
    previous = NULL;
}// end function first

/*
    Function Name:  next
    Description:    Move the current pointer to the next node in the
                    list
    Parameters:     N/A
    Return Value:   N/A
*/
void LinkedList::next()
{
    if(current != NULL)
    {
        //Set the previous as the current pointer
        previous = current;

        //Set the current pointer to the next node
        current = current->next;
    }// end if
}// end function next

/*
    Function Name:  find
    Description:    Search for the specified object in the list
    Parameters:     Animal - item: object of the Animal class
    Return Value:   bool - true if the animal was found, false if not
*/
bool LinkedList::find(Animal &item)
{
    node*nnode;

    first();

    //Loop through the contents of the list
    while(current != NULL)
    {
        //Return true if the item is found in the list
        if(item == current->data)
        {
            return true;
        }// end if
        next();
    }// end while loop

    return false;
}// end function find

/*
    Function Name:  retrieve
    Description:    Retrieve the data from the current node
    Parameters:     Animal - item: object of the Animal class
    Return Value:   bool - false if the current points to NULL,
                           true if the item was successfully
                           retrieved
*/
bool LinkedList::retrieve(Animal &item)
{
    if (current == NULL)
    {
        return false;
    }// end if

    //Set the item to the data of the current node
    item = current->data;

    return true;
}// end function retrieve

/*
    Function Name:  get_node
    Description:    Create a new node
    Parameters:     Animal - item: object of the Animal class
    Return Value:   node - newNode: a new node
*/
LinkedList::node* LinkedList::get_node(const Animal &item)
{
    //Create a new node
    node *newNode = new node();

    //Assign the data of the new node to the item
    if(newNode != NULL)
    {
        newNode->data = item;
        newNode->next = NULL;
    }// end if

    return newNode;
}// end function get_node

/*
    Function Name:  modify
    Description:    Modify the data in the current node by assigning data
                    to the parameter object
    Parameters:     Animal - item: object of the Animal class
    Return Value:   N/A
*/
void LinkedList::modify(const Animal &item)
{
    //Set the data in the current node to the item passed
    if(current != NULL)
    {
        current->data = item;
    }// end if
}// end function modify

/*
    Function Name:  orderedInsert
    Description:    Inserts new nodes into the list in alphabetical
                    order by name
    Parameters:     Animal - item: object of the Animal class
    Return Value:   bool - true when the new node is added into the
                           list
*/
bool LinkedList::orderedInsert(const Animal &item)
{
    first();

    //Insert the item into the list if it's name is larger than the name in the data current is pointing to
    while((current != NULL) && (current->data < item))
    {
        next();
    }// end while loop
    insert(item);

    return true;
}// end function orderedInsert

/*
    Function Name:  insert
    Description:    Insert a new node into the list
    Parameter:      Animal - item: object of the Animal class
    Return Value:   bool - true if the node was added to the list,
                           false if the new node is NULL
*/
bool LinkedList::insert(const Animal &item)
{
    //Create a new node with the passed Animal's data
    node*nnode = get_node(item);

    //Check if the new node is NULL
    if(nnode == NULL)
    {
        return false;
    }// end if

    nnode->next = current;

    //Check if the new node is at the head of the list
    if(current == head)
    {
        head = nnode;
    }// end if
    else
    {
        previous->next = nnode;
    }// end else

    //Point the current pointer to the new node
    current = nnode;

    //Increment the length
    length++;

    return true;
}// end function insert

/*
    Function Name:  remove
    Description:    Remove the specified item from the list
    Parameter:      Animal - item: object of the Animal class
    Return Value:   bool - true if the item was successfully removed
                           from the list
                           false if the list is empty
                           false if the item was not found in the list
*/
bool LinkedList::remove(Animal &item)
{
    node *old_node;

    find(item);

    if (empty())
        return false;

    // if item not found, return false
    if (find(item) == false)
        return false;

    current = current->next;

    // adjust the node pointers in the list surrounding the node to be deleted
    old_node = current;

    if (head == old_node)
        head = current;
    else
        previous->next = current->next;

    //current = current->next;

    // delete the node
    delete old_node;

     // update the length
    length--;

    return true;
} // end function remove

/*
    Function Name:  traverse
    Description:    Traverses the list and applies the function process
                    to each node
    Parameters:     void - process: the function called to the function
                    Animal - item: object of the Animal class
    Return Value:   N/A
*/
void LinkedList::traverse(void (*process) (Animal item))
{
    // start at the beginning of the list
    node *ptr = head;

    // go through the list, one node at a time
    while (ptr != NULL) {

         // call the function with the data from the current node
         process(ptr->data);

         ptr = ptr->next;

    }// end while

}// end function traverse

/*
    Function Name:  operator=
    Description:    Overloaded assignment operator for the linked list,
                    assigns one linked list to another
    Parameters:     LinkedList - list: list object in the LinkedList
                                       class
    Return Value:   this - pointer to current object
*/
LinkedList& LinkedList::operator=(const LinkedList &list)
{
    node *temp;

    LinkedList();

    //Start at the head of the list
    temp = list.head;

    //Copy the contents of the old list into the new list
    while (temp != NULL)
    {
        insert(temp->data);
        temp = temp->next;
    }// end while loop

    return *this;
}// end operator=

/*
    Function Name:  getLength
    Description:    Returns the length of the list
    Parameters:     N/A
    Return Value:   int - length: length of the linked list
*/
int LinkedList::getLength()
{
    return length;
}// end function getLength
