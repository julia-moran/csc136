Program Specifications:
You will be writing an application program for a carwash simulation. The car wash simulation will ask
the user the time in minutes to wash one car and the probability of a car arriving in any one minute. The
probability input can be entered as a decimal or a percentage but be sure to inform the user and then
adjust appropriately in the program.

The simulation will utilize a Queue, which must be implemented as a template class. The Queue header
file will be provided for you. You can copy queue.h from the public directory in the queues sub-
directory. When adding a car to the queue, you will add the arrival minute to the queue, so the queue
will store integers.

The car wash simulation should run for 10 hours and determine the number of cars that were washed and
the average time a car waited in the queue to be washed. Use a for loop with each iteration being the
equivalent of one minute of the simulation running. Each minute of the simulation, determine if a car
entered the car wash by using a random number generator and comparing that number to the entered
probability of a car entering the car wash. There can only be one car in the car wash at a time. The
possibilities for each loop iteration are:
• Car still in carwash – increment wash time
• Car just finished in car wash – leave wash, update variables for summary, see if cars are waiting
  to enter the carwash
• No car in carwash – see if cars are waiting to enter the carwash
