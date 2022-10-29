//Source Cited:
/*****************************************************************************/
/*                                                                           */
//  Author:         Lisa Frye
//  Date Created:   March 24, 2022
//  Date Retrieved: April 7, 2022
//  Title:          LinkedList.h
//  Purpose:        Class declaration for LinkedList class
//  Retrieved from Dr. Frye's public directory under csc136/aquariumS22
/*                                                                           */
/*****************************************************************************/

//  Retrieved by:   Julia Moran
//  Major:          Computer Science
//  Creation Date:  April 7, 2022
//  Due Date:       April 24, 2022
//  Course:         CSC136 030
//  Professor Name: Dr. Frye
//  Assignment:     #4
//  Filename:       LinkedList.h
//  Purpose:        Header file for the LinkedList class. Provides the
//                  prototypes for the member functions within that class.
/*****************************************************************************/

 /* Citation source: This header file was retrieved from the Kutztown CSIT
    public directory on April 7, 2022 and authored by Dr. Lisa Frye. All content was
    authored by Dr. Frye. */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Animal.h"

class LinkedList
{
 public:
  // Constructors

  // Name: LinkedList
  // Description: Default Constructor
  // Parameters: None
  // Return Value: None
  LinkedList();

  // Name: LinkedList
  // Description: Copy Constructor
  // Parameters: list - the object to be copied - input
  // Return Value: None
  LinkedList(const LinkedList &list);

  // Name: ~LinkedList
  // Description: Destructor
  // Parameters: None
  // Return Value: None
  ~LinkedList();

  // Name: empty
  // Description: Determines if the list is empty or not
  // Parameters: None
  // Return Value: true if the list is empty, otherwise false
  bool empty();

  // Name: atEnd
  // Description: Determines if the current pointer is the last node
  // Parameters: None
  // Return Value: true if current points to the end of the list or NULL,
  //               otherwise false
  bool atEnd();

  // Name: getLength
  // Description: Returns the length of the list
  // Parameters: None
  // Return Value: the number of nodes in the list
  int getLength();

  // Name: first
  // Description: Sets the current pointer to the first node in the list
  //              and previous to NULL.
  // Parameters: None
  // Return Value: None
  void first();

  // Name: next
  // Description: Moves the current pointer to the next node in the list.
  //        Also updates previous to the node before the new current node.
  // Parameters: None
  // Return Value: None
  void next();

  // Name: find
  // Description: Find a specific item in the list; will update the current
  //              pointer to point to the node with the specific item, if found,
  //              otherwise, current will be NULL
  // Parameters: item - the node / element to find in the list
  //              input/output; will be udpated with data from item in list, if found
  // Return value: true if item is found, otherwise false
  bool find(Animal &item);

  // Name: retrieve
  // Description: Get the data in the current node
  // Parameters: item - the data in the current node - output
  // Return Value: true if there is a current node, otherwise false
  bool retrieve(Animal &item);

  // Name: modify
  // Description: Modify the data in the current node by assigning data
  //              to the parameter object.
  // Parameters: item - the data to store in the current node - input
  // Return Value: None
  void modify(const Animal &item);

  // Name: orderedInsert
  // Description: Add a node to the list in alphabetical order and update
  //              current, previous, and head, if appropriate.
  // Parameters: item - the data to be put in the node that is being added
  // Return Value: true if the node was succecssfully added to the list,
  //               otherwise false
  bool orderedInsert(const Animal &item);

  // Name: insert
  // Description: Add a node to the list at the current position and update current,
  //              previous, and head, if appropriate.
  // Parameters: item - the data to be put in the node that is being added
  // Return Value: true if the node was succecssfully added to the list, otherwise false
  bool insert(const Animal &item);

  // Name: remove
  // Description: Remove the specified node from the list and update current,
  //              previous, and head, if appropriate.
  // Parameters: item - the data item to remove from the list
  // Return Value: true if the node was successfully removed from the list,
  //               otherwise false
  bool remove(Animal &item);

  // Name: traverse
  // Description: Traverses the list and calls the function 'process' on each node
  // Parameters: process - the function to be called for each node
  // Return Value: None
  void traverse(void (*process) (Animal item));

  // Name: operator =
  // Description: The assignment operator; assigns one linked list to another
  //              linked list
  // Parameters: list - the linked list to be assigned
  // Return Value: the new linked list
  LinkedList& operator = (const LinkedList &list);

 private:
  // the class node for each node of the linked list
  class node
  {
    public:
      node() { next = NULL; }   // default constructor for node

      Animal data;                              // the data in the node
      node *next;                               // pointer to the next node in list
  };   // end class node

  int  length;             // length of the linked list
  node *head;          // pointer to the head of the linked list
  node *current;       // pointer to the current node
  node *previous;      // pointer to the previous node


  // UTILITY FUNCTIONS

  // Name: get_node
  // Description: Create a new node
  // Parameters: item - the data for the node
  // Return Value: A pointer to the new node; NULL if an error
  node* get_node(const Animal &item);

};

#endif
