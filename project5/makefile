# Source Cited:
################################################################
# Author:         Lisa Frye                                    #
# Description:    Makefile for carwash application             #
################################################################

################################################################
# Retrieved by:   Julia Moran                                  #
# Major:          Computer Science                             #
# Retrieved:      April 26, 2022                               #
# Due Date:       May 5, 2022                                  #
# Course:         CSC136 030                                   #
# Professor Name: Dr. Frye                                     #
# Assignment:     #5                                           #
# Filename:       makefile                                     #
# Purpose:        Makefile to compile assignment #4            #
################################################################

# Citation source: This makefile was retrieved from the Kutztown CSIT
# public directory on April 26, 2022 and authored by Dr. Lisa Frye. All content
# except for the changed filenames was authored by Dr. Frye.

all: moran_prog5

moran_prog5: moran_prog5.o queue.o
        g++ moran_prog5.o queue.o  -o moran_prog5

moran_prog5.o: moran_prog5.cpp queue.h
        g++ -c moran_prog5.cpp

queue.o: queue.cpp queue.h
        g++ -c queue.cpp


clean:
        /bin/rm *.o
        /bin/rm moran_prog5
