Program Specifications:
This program will continue with the previous program. You will convert the driver program of the previous
program to utilize a linked list instead of an array.

The driver program will do the following:
• Read the animal information from a file using the extraction operator (>>) and the same file format as
the previous program (a comma-delimited file with one line per animal).
• Store the animals in a linked list, sorted in alphabetical order by animal name.
• Provide a menu to the user to allow the following tasks:
  o Add a new animal – prompt user for all animal information with appropriate instructions for
    format so you can use the >> operator you wrote. Insert into the linked list in sorted order.
  o Delete an animal – prompt user for animal information (name, type and gender) to delete. Delete
    for this program means moving the animal to a second linked list called archived. This is one list
    containing all deleted animals (dolphins and turtles).
  o Print any of the following: all animals, all dolphins, all turtles, all archived animals. All print
    functions should utilize the insertion operator (<<).
  o Search for an animal by name and print the animal information (name, type and gender).
