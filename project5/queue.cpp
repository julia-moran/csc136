/*
    Author Name:     Julia Moran
    Major:           Computer Science
    Creation Date:   April 26, 2022
    Due Date:        May 5, 2022
    Course:          CSC136 030
    Professor Name:  Dr. Frye
    Assignment:      #5
    Filename:        queue.cpp
    Purpose:         This program serves as the implementation file for the
                     header file for the Queue class. It will provide the
                     definitions for the prototypes specified in queue.h.
*/

#include <iostream>
#include "queue.h"

using namespace std;

//CONSTRUCTORS

/*
    Function Name:  Queue
    Description:    Default constructor
    Parameters:     N/A
    Return Value:   N/A
*/
template <class E>
Queue<E>::Queue()
{
    //Initialize the front and rear to NULL
    front = NULL;
    rear = NULL;
}// end default constructor

/*
    Function Name:  Queue
    Description:    Copy constructor
    Parameters:     Queue<E> - q: the queue to be copied
    Return Value:   the new copied queue
*/
template <class E>
Queue<E>::Queue(const Queue<E> &q)
{
    //The case of the old queue being empty
    if(q.front == NULL)
    {
        front = NULL;
    }// end if

    //The case of the old queue not being empty
    else
    {
        node* temp;
        temp = q.front;

        //Loop through the queue and copy its contents to the new queue
        while(temp != NULL)
        {
            enqueue(temp->item);
            temp = temp->next;
        }// end while loop
    }// end else
}// end copy constructor

// DESTRUCTOR

/*
    Function Name:  ~Queue
    Description:    Destructor
    Parameters:     N/A
    Return Value:   N/A
*/
template <class E>
Queue<E>::~Queue()
{
    node* old_node;

    //Loop through the contents of the list
    while (front != NULL)
    {
        old_node = front;
        front = front->next;

        //Delete each node in the list
        delete old_node;
    }// end while

    //Reset the values of the pointers and variables
    front = NULL;
    rear = NULL;
}// end destructor

/*
    Function Name:  isEmpty
    Description:    Check if the queue is empty
    Parameters:     N/A
    Return Value:   bool: true if the queue is empty,
                          false if not
*/
template <class E>
bool Queue<E>::isEmpty()
{
    //Check if the front points to NULL
    if(front == NULL)
    {
        return true;
    }// end if
    else
    {
        return false;
    }// end else
}// end function isEmpty

/*
    Function Name:  enqueue
    Description:    Add a new node to the end of the queue
    Parameters:     E - item: data to be put inside the new node
    Return Value:   bool: true if the new node was successfully added to the queue,
                          false if not
*/
template <class E>
bool Queue<E>::enqueue(const E &item)
{
    //Create a new node
    node *nnode = get_node(item);

    //Check if the new node was created successfully
    if(nnode == NULL)
    {
        return false;
    }// end if

    //The case of the new node being added to an empty queue
    if(isEmpty() == true)
    {
        front = rear = nnode;
    }// end if

    //The case of adding a new node to a nonempty queue
    else
    {
        rear->next = nnode;
        rear = nnode;
    }// end else

    return true;
}// end function enqueue

/*
    Function Name:  dequeue
    Description:    Remove the node at the front of the queue from the queue
    Parameters:     E - item: the item at the front of the queue
    Return Value:   bool: true if the node was successfully removed from the queue,
                          false if the queue is empty
*/
template <class E>
bool Queue<E>::dequeue(E &item)
{
    node *old_node;

    //Return false if the queue is empty
    if(isEmpty() == true)
    {
        return false;
    }// end if

    old_node = front;
    peek(item);

    //The case of only one node being in the queue
    if(front == rear)
    {
        front = NULL;
        rear = NULL;
    }// end if

    //The case of removing a node from a nonempty queue
    else
    {
        front = front->next;
    }// end else

    delete old_node;

    return true;
}// end function dequeue

/*
    Function Name:  peek
    Description:    Look at the data for the node at the front
    Parameters:     E - item: item at the front of the queue
    Return Value:   bool: true if retrieved the data from first node,
                    false otherwise
*/
template <class E>
bool Queue<E>::peek(E &item)
{
    //Return false if the queue is empty
    if(isEmpty() == true)
    {
        return false;
    }// end if

    //Retrieve the data from the first node
    item = front->item;

    return true;
}// end function peek

/*
    Function Name:  print
    Description:    Print out the data of the queue
    Parameters:     N/A
    Return Value:   N/A
*/
template <class E>
void Queue<E>::print()
{
    node *temp;
    temp = front;

    //Loop through the queue and print its contents
    while(temp != NULL)
    {
        cout << temp->item << endl;
        temp = temp->next;
    }// end while loop
}// end function print

/*
    Function Name:  operator=
    Description:    Assign one queue to another queue
    Parameters:     Queue<E> - q: queue to be assigned
    Return Value:   Queue<E>: new queue
*/
template <class E>
Queue<E>& Queue<E>::operator=(const Queue<E> &q)
{
    node* temp;
    temp = front;

    //The case of the old queue already being equal to the new queue
    if (this == &q)
    {
        return *this;
    }// end if

    //The case of the new queue not being equal to the old queue
    //Loop through the queue and assign each node to the new queue
    while(temp != NULL)
    {
        enqueue(temp->item);
        temp = temp->next;
    }// end while loop

    //Return *this to allow chaining
    return *this;
}// end operator=

/*
    Function Name:  get_node
    Description:    Return the current node
    Parameters:     E - item: the node to be returned
    Return Value:   node: the new node
*/
template <class E>
typename Queue<E>::node* Queue<E>::get_node(const E &item)
{
    //Create a new node
    node *newNode = new node;

    //Set the new node's pointers
    if(newNode != NULL)
    {
        newNode->next = NULL;
        newNode->item = item;
    }// end if

    //Return the new node
    return newNode;
}// end funcion get_node
