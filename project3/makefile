# Author:         Julia Moran
# Major:          Computer Science
# Creation Date:  March 3, 2022
# Due Date:       March 29. 2022
# Course:         CSC136 030
# Professor Name: Dr. Frye
# Assignment:     #3
# Filename:       makefile
# Purpose:        Makefile to compile assignment #3

# Source Cited:
#####################################################################################
# Author: Lisa Frye
# Date Created: January 14, 2022
# Date Retrieved: March 3, 2022
# Title: makefile
# Purpose: Makefile for the Aquarium application
#      This is used to compile and link the two object files
#      to create the executable, making it easier to recompile.
#      Without this makefile, it would be necessary to execute
#      three separate g++ commands at the command-line each time
#      you had to recompile / relink the program files.
# Retrieved from Dr. Frye's public directory under csc136/aquariumS22

# Citation source: This makefile was retrieved from the Kutztown CSIT
# public directory on March 3, 2022 and authored by Dr. Lisa Frye. All content except
# for the changed filenames was authored by Dr. Frye.


# Each Rule consists of two lines (this makefile contains three rules)
#      The first line is the dependency line
#            This line starts with the target
#      The second line is the recipe and tells the system how to update the target

# The following two lines:
#     Create the target "moran_prog3", which is the executable for this project
#     The target "moran_prog3" depends on moran_prog3.o and Animal.o,
#            so if either of those change, a new executable will be created
#     The recipe line (2nd line) tells the system how to create that executable
#            Create a file called "moran_prog3", because of the -o option
moran_prog3: moran_prog3.o Animal.o
        g++ -o moran_prog3 moran_prog3.o Animal.o

# The following two lines:
#     Create the target "moran_prog3.o", which is the object file for moran_prog3.cpp source file
#     The dependencies are moran_prog3.cpp and Animal.h
#     The 2nd line is the recipe line telling the system how to create that object file
#           The -c option tells the compiler to just compile (create object file), not link
moran_prog3.o: moran_prog3.cpp Animal.h
        g++ -c moran_prog3.cpp

# The following two lines are the same as the previous two for the target Animal.o
#           This creates the object file for the class definition source file
Animal.o: Animal.cpp Animal.h
        g++ -c Animal.cpp
