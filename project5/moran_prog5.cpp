/*
    Author Name:    Julia Moran
    Major:          Computer Science
    Creation Date:  April 26, 2022
    Due Date:       May 5, 2022
    Course:         CSC136 030
    Professor Name: Dr. Frye
    Assignment:     #5
    Filename:       moran_prog5.cpp
    Purpose:        This program will ask the user for the time it takes to
                    wash one car and the probability of a car arriving in one
                    minute for a fictional car wash. It will output the number
                    of cars washed in 10 hours and the average time the cars
                    spent in line for the 10 hours.
*/

#include <iostream>
#include "queue.cpp"

using namespace std;

//Function Prototypes
void getUserInput(int &washTime, float &arrivalProbability);
void addToQueue(float arrivalProbability, Queue<int>& queue, int minute);
void checkCarTime(int& timeInWash, bool carInWash, int washTime);
void checkCarFinished(int& carsWashed, int& timeInWash, bool& carInWash, int washTime);
void addToWash(bool& carInWash, Queue<int>& queue, int minute, float& sumTime);
void displayOutput(int carsWashed, float sumTime);

int main()
{
    //Seed the random number generator using the current time
    srand(time(NULL));

    //Variables
    int washTime = 0;
    float arrivalProbability;
    Queue<int> queue;
    int timeInWash;
    int carsWashed = 0;
    bool carInWash = false;
    float sumTime = 0;

    //Get the inputed wash time and probability of one car arriving to the wash
    getUserInput(washTime, arrivalProbability);

    //Run the simulation for 10 hours, or 600 minutes
    for(int minute = 0; minute < 600; minute++)
    {
        //Function calls for the simulation
        addToQueue(arrivalProbability, queue, minute);
        checkCarTime(timeInWash, carInWash, washTime);
        checkCarFinished(carsWashed, timeInWash, carInWash, washTime);
        addToWash(carInWash, queue, minute, sumTime);
    }// end for loop

    //Display the number of cars washed and the average time spent in line
    displayOutput(carsWashed, sumTime);

    return 0;
}// end function main

/*
    Function Name:  getUserInput
    Description:    Get the user's input for the time to wash one car and
                    probability for one car arriving in one minute
    Parameters:     int - washTime: time it takes to wash one car, in minutes
                    float - arrivalProbability: probability of one car arriving
                                                to the wash in one minute
    Return Value:   N/A
*/
void getUserInput(int &washTime, float &arrivalProbability)
{
    //Get the time to wash one car
    cout << "Enter the time it takes to wash one car, in minutes: ";
    cin >> washTime;

    //Get the probability of car arriving to the wash
    cout << "\nEnter the probability of one car arriving to the car wash in one minute as a percentage.\nExample: 25\nInput: ";
    cin >> arrivalProbability;
}// end function getUserInput

/*
    Function Name:  addToQueue
    Description:    If a car arrived to the car wash, add it to the queue
    Parameters:     float - arrivalProbability: probability of one car arriving
                                                to the wash in one minute
                    Queue<int> - queue: queue of cars waiting to enter the wash
                    int - startTime: time that the car enters the queue
    Return Value:   N/A
*/
void addToQueue(float arrivalProbability, Queue<int> &queue, int startTime)
{
    //Generate a random number between 0 and 100
    int rnum = rand()%101;

    //Determine if a car arrives to the wash by comparing the random number to the arrival probability
    if(rnum < arrivalProbability)
    {
        //Add the time the car enters the queue to the queue
        queue.enqueue(startTime);
    }// end if
}// end function addToQueue

/*
    Function Name:  checkCarTime
    Description:    Increment the time the car spends in the wash if there is a
                    car in the wash and the time to wash one car has not been met
    Parameters:     int - timeInWash: time the car has spent in the wash
                    bool - carInWash: true if there is a car in the wash,
                                      false if not
                    int - washTime: time to wash one car
    Return Value:   N/A
*/
void checkCarTime(int& timeInWash, bool carInWash, int washTime)
{
    //Check if there is a car in the wash and if the time to wash the car has been met
    if((carInWash == true) && (timeInWash != washTime))
    {
        //Increment the time spent in the wash
        timeInWash++;
    }// end if
}// end checkCarTime

/*
    Function Name:  checkCarFinished
    Description:    Remove the car from the wash if there is a car in the wash
                    and the time to wash one car has been met
    Parameters:     int - carsWashed: number of cars washed
                    int - timeInWash: time the car has spent in the wash
                    bool - carInWash: true if there is a car in the wash,
                                      false if not
                    int - washTime: time it takes to wash one car
    Return Value:   N/A
*/
void checkCarFinished(int& carsWashed, int& timeInWash, bool& carInWash, int washTime)
{
    //Check if there is a car in the wash and if the time to wash one car has been met
    if((carInWash == true) && (timeInWash == washTime))
    {
        //Reset the time spent in the wash and remove the car from the wash
        timeInWash = 0;
        carInWash = false;

        //Increment the number of cars washed
        carsWashed++;
    }// end if
}// end checkCarFinished

/*
    Function Name:  addToWash
    Description:    Add the car at the front of the queue to the wash if there
                    is no car already in the wash
    Parameters:     bool - carInWash: true if a car is in the wash,
                                      false if not
                    Queue<int> - queue: queue of cars waiting to enter the wash
                    int - minute: time the car leaves the queue
                    float - sumTime: total time spent in the queue
    Return Value:   N/A
*/
void addToWash(bool &carInWash, Queue<int> &queue, int minute, float &sumTime)
{
    //Variables
    int startTime;
    float timeInLine;

    //Check if the wash is empty and if there are cars in the queue
    if((carInWash == false) && (!queue.isEmpty()))
    {
        //Remove the car at the front of the queue from the queue
        queue.dequeue(startTime);

        //Calculate the total time spent in line
        timeInLine = minute - startTime;
        sumTime = sumTime + timeInLine;

        //Put the new car into the wash
        carInWash = true;
    }// end if
}// end function addToWash

/*
    Function Name:  displayOutput
    Description:    Display the number of cars washed and average wait time for
                    cars in the queue
    Parameters:     carsWashed - int: number of cars washed
                    sumTime - float: total time spent in the queue
    Return Value:   N/A
*/
void displayOutput(int carsWashed, float sumTime)
{
    //Output the total number of cars washed
    cout << "\nCars washed: " << carsWashed << endl;

    //Calculate and output the average time spent in line
    cout << "Average time in line: " << (sumTime / carsWashed) << endl;
}// end function displayOutput
