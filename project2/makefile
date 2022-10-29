# Author: Lisa Frye
# Date Created: January 14, 2022
# Filename: makefile
# Purpose: Makefile for the Aquarium application
#      This is used to compile and link the two object files
#      to create the executable, making it easier to recompile.
#      Without this makefile, it would be necessary to execute
#      three separate g++ commands at the command-line each time
#      you had to recompile / relink the program files.

# Each Rule consists of two lines (this makefile contains three rules)
#      The first line is the dependency line
#            This line starts with the target
#      The second line is the recipe and tells the system how to update the target

# The folloing two lines:
#     Create the target "aquarium", which is the executable for this project
#     The target "aquarium" depends on aquarium.o and Animal.o,
#            so if either of those change, a new executable will be created
#     The recipe line (2nd line) tells the system how to create that executable
#            Create a file called "aquarium", because of the -o option
moran_prog2: moran_prog2.o Animal.o
        g++ -o moran_prog2 moran_prog2.o Animal.o

# The following two lines:
#     Create the target "aquarium.o", which is the object file for aquarium.cpp source file
#     The dependencies are aquarium.cpp and Animal.h
#     The 2nd line is the recipe line telling the system how to create that object file
#           The -c option tells the compiler to just compile (create object file), not link
moran_prog2.o: moran_prog2.cpp Animal.h
        g++ -c moran_prog2.cpp

# The following two lines are the same as the previous two for the target Animal.o
#           This creates the object file for the class definition source file
#Animal.o: Animal.cpp Animal.h
#       g++ -c Animal.cpp
