Program Specifications:

The program must read from a comma-delimited text file into an array of objects. You will have to create a file
to test your program. The file should contain one line for each animal with each piece of data separated by a
comma. Do not include blank lines in the file or spaces in the data. You can assume the animal type and gender
will be a single character and will be an appropriate character.

The class implementation file must implement all the class methods provided in the supplied header file
(animal.h) and the member functions added for program 3a (operator overload for assignment (=), equals (==)
and not equals (!=)). For this version, operator = must be implemented with this and return reference to object to
support chaining of the assignment operator (for example: obj1 = obj2 = obj3; )

You will add the following member functions to this class, which means you must also add them to your header
file. The last two (extraction and insertion operators) will be friend member functions.
• Copy constructor
• Overload the extraction operator (>>) to read animal information in a comma-delimited format.
• Overload the insertion operator (<<) to print the animal information in an appropriate user-friendly
  format. This operator should print the information for just one animal. This operator will print the
  animal information in table format. It can be used in the print and search functions of the application
  program.
 
The driver program must do the following:
• Read all animal information from a comma-delimited text file into an array of objects using the
  extraction operator (>>).
• Provide a menu to the user with options for searching, print by animal type or print all.
• Searching for an animal and display appropriate information using the insertion operator (<<).
• Print by animal type will print all the animals of the entered type (dolphin or turtle) sorted by name. This
  output must be in a nicely formatted table form using the insertion operator (<<).
• Print all will print all the animals at the aquarium sorted by name. This output must be in a nicely
  formatted table form using the insertion operator (<<).
