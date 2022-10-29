//Source Cited
/********************************************************************/
/*                                                                  */
/*  File:    queue.h                                                */
/*  Author:  Lisa Frye                                              */
/*  Course:  CSC136                                                 */
/*  Date:    November 20, 2000                                      */
/*  Updated: April 2022                                             */
/*  Purpose: This is the header file for a generic queue class.     */
/*                                                                  */
/********************************************************************/

/*****************************************************************************/
/*  Retrieved by:   Julia Moran                                              */
/*  Major:          Computer Science                                         */
/*  Creation Date:  April 26, 2022                                           */
/*  Due Date:       May 4, 2022                                              */
/*  Course:         CSC136 030                                               */
/*  Professor Name: Dr. Frye                                                 */
/*  Assignment:     #5                                                       */
/*  Filename:       queue.h                                                  */
/*  Purpose:        Header file for the queue class. Provides the prototypes */
/*                  for the member functions within that class.              */
/*****************************************************************************/

 /* Citation source: This header file was retrieved from the Kutztown CSIT
    public directory on April 26, 2022 and authored by Dr. Lisa Frye. All content
    was authored by Dr. Frye. */


#ifndef QUEUE_H
#define QUEUE_H


template <class E>
class Queue
{
 public:
  // Name: Queue
  // Purpose: Default constructor
  // Parameters: None
  // Return value: None
  Queue();

  // Name: Queue
  // Purpose: Copy constructor
  // Parameters: A queue to copy
  // Return value: The new queue
  Queue(const Queue<E> &q);

  // Name: ~Queue
  // Purpose: Destructor
  // Parameters: None
  // Return value: None
  ~Queue();

  // Name: isEmpty
  // Purpose: Determine if the queue is empty
  // Parameters: None
  // Return value: true if the queue is empty; false otherwise
  bool isEmpty();

  // Name: enqueue
  // Purpose: Add a node to the back of the queue
  // Parameters: Item to be added to the queue
  // Return value: true if node was added to queue; false otherwise
  bool enqueue(const E &item);

  // Name: dequeue
  // Purpose: Remove a node from the front of the queue
  // Parameters: Item removed from the queue
  // Return value: true if node was removed from queue; false otherwise
  bool dequeue(E &item);

  // Name: peek
  // Purpose: Look at the item at the front of the queue
  // Parameters: Item at the front of the queue
  // Return value: true if retrieved the data from first node; false otherwise
  bool peek(E &item);

  // Name: print
  // Purpose: Print the contents of the queue
  // Parameters: None
  // Return value: None
  void print();

  // Name: operator =
  // Purpose: Assign one queue to another queue
  // Parameters: queue to be assigned
  // Return value: new queue
  Queue<E>& operator = (const Queue<E> &q);


 private:
  // the class node for each node of the queue
  class node
  {
    public:
      node() { next = NULL; }   // default constructor for node

      E item;                           // the data in the node
      node *next;                       // pointer to the next node in list
  };   // end class nodeclass node

  node *front;
  node *rear;

  // Name: get_node
  // Description: Return the current node
  // Parameters: item - the node to be returned
  // Return Value: The node
  node* get_node(const E &item);
};

#endif
