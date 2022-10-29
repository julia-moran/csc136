Program Specifications:

This program will continue from the previous program. You are to write the class implementation for the animal
class. It will help the local aquarium keep track of their bottlenose dolphins and loggerhead sea turtles. For each
animal, you are to store the following characteristics: name, type (D or T) and gender (F or M).
The program must read from a file into an array of objects. The file should contain three lines for each animal:
the first line being the animals name, the second the animal species and the third the animal’s gender. The file
should not contain any blank lines. You can assume the animal type and gender will be a single character and
will be an appropriate character.

The class implementation file must implement all the class methods provided in the supplied header file for
program #2 (Animal.h). You will add the following methods to this class, which means you must also add them
to your header file:
• Overloaded operators
o Overload the assignment (=) operator
o Overload the equals (==) operator
o Overload the not equals (!=) operator
  The driver program must do the following:
• Read all animal information from a text file into an array of objects.
• Provide a menu to the user with options for searching, print by animal type or print all.
• Searching will allow the user to search for an animal by name; the program should then print that
  animal’s information.
• Print by animal type will print all the animals of the entered type (dolphin or turtle). This output must be
  in a nicely formatted table form.
• Print all will print all the animals at the aquarium sorted by name. This output must be in a nicely
  formatted table form.
  
To test the new methods, add the following to the driver program:
o Create a new dolphin animal, dolphinTemp, in the driver program. This male dolphin has been
  named Jimmy. Assign those values to the dolphinTemp object.
o Create a new turtle animal, turtleTemp, in the driver program. This female turtle has been named
  Laney. Assign those values to the turtleTemp object.
o Create another animal object, testAnimal.
o Assign testAnimal to dolphinTemp
o Check if testAnimal is equal to dolphinTemp. Display an appropriate message.
o Check if testAnimal is equal to turtleTemp. Display an appropriate message.
o Check if dolphinTemp is not equal to turtleTemp (use !=). Display an appropriate message.
