//**********************************************************************
//*                                                                    *
//* Program Name: PROG02 - Calculate geometric shape areas and volume  *
//* Author:       Ian McPherson                                        *
//* Installation: Pensacola Christian College, Pensacola, Florida      *
//* Course:       CS246, Object-Oriented Programming and Design        *
//* Date Written: February 7, 2020                                     *
//*                                                                    *
//**********************************************************************

//**********************************************************************
//*                                                                    *
//* I pledge this assignment is my own first time work.                *
//* I pledge I did not copy or try to copy any work from the Internet. *
//* I pledge the only person I asked for help from was my teacher.     *
//* I pledge I did not attempt to help any student on this assignment. *
//* I understand if I violate this pledge I will receive a 0 grade.    *
//*                                                                    *
//*                                                                    *
//*                      Signed: _____________________________________ *
//*                                           (signature)              *
//*                                                                    *
//*                                                                    *
//**********************************************************************

//**********************************************************************
//*                                                                    *
//* This program asks for geometric shape dimensions then calculates   *
//* and prints the area of a circle, the area of a rectangle, and the  *
//* volume of a rectangular solid.                                     *
//*                                                                    *
//**********************************************************************

#include <iostream>
using namespace std;

//**********************************************************************
//*                         Symbolic Constants                         *
//**********************************************************************
#define COURSE_NAME    "Object-Oriented Programming and Design"
                                 // PCC assigned course name
#define COURSE_NUMBER  "CS246"   // PCC assigned course number
#define PI             3.141593f // Mathematical constant pi
#define PROGRAM_NUMBER 2         // Teacher assigned program number
 
//**********************************************************************
//*                       Function Prototypes                          *
//**********************************************************************
void print_heading           ();
   // Print the program heading
void get_dimensions          (float *p_depth,  float *p_diameter,
                              float *p_length, float *p_width);
   // Get the dimensions of geometric shapes
void calculate_specifications(float diameter);
   // Calculate the area of a circle
void calculate_specifications(float length, float width);
   // Calculate the area of a rectangle
void calculate_specifications(float length, float width, float depth);
   // Calculate the volume of a rectangular solid

//**********************************************************************
//*                          Main Function                             *
//**********************************************************************
int main()
{
   float depth,    // The depth of a of a rectangular solid
         diameter, // The diameter of a circle
         length,   // The length of a rectangle and rectangular solid
         width;    // The width of a rectangle and rectangular solid

   // Print the program heading
   print_heading();

   // Get the dimensions of the geometric shapes
   get_dimensions(&depth, &diameter, &length, &width);

   // Calculate the specifications of the geometric shapes
   cout << "\n\nHere are the requested areas and volume:";
   cout <<   "\n----------------------------------------";
   calculate_specifications(diameter);
   calculate_specifications(length, width);
   calculate_specifications(length, width, depth);

   // Say goodbye and terminate
   cout << "\n\n\nThanks for calculating geometric shapes today ;)";
   cout << "\n\n\n\n\n\n";
   return 0;
}

//**********************************************************************
//*                      Print the program heading                     *
//**********************************************************************
void print_heading()
{
   cout << "\n\n\n\n\n\n\n" << COURSE_NUMBER
        << " "              << COURSE_NAME
        << " - Program "    << PROGRAM_NUMBER;
   cout << "\n========================================================";
   cout << "\n       Calculate geometric shape areas and volume";
   return;
}

//**********************************************************************
//*                  Get the dimensions of the shapes                  *
//**********************************************************************
void get_dimensions(float *p_depth, float *p_diameter, float *p_length,
                    float *p_width)
{
   cout << "\n\nEnter the geometric shape dimensions as follows:";
   cout <<   "\n    Circle diameter: "; 
   cin  >> *p_diameter;
   cout <<     "   Rectangle length: ";
   cin  >> *p_length;
   cout <<     "    Rectangle width: ";
   cin  >> *p_width;
   cout <<     "    Rectangle depth: ";
   cin  >> *p_depth;
   return;
}

//**********************************************************************
//*              Calculate and print the area of a circle              *
//**********************************************************************
void calculate_specifications(float diameter)
{
   cout << "\nArea of a circle with diameter " 
                   << diameter                         << ":";
   cout << "\n   " << 0.25f * PI * diameter * diameter << " square units";
   return;
}

//**********************************************************************
//*             Calculate and print the area of a rectangle            *
//**********************************************************************
void calculate_specifications(float length, float width)
{
   cout << "\nArea of a rectangle of "
        << " length "   << length
        << " by width " << width           << ":";
   cout << "\n   "      <<  length * width << " square units";
   return;
}

//**********************************************************************
//*       Calculate and print the volume of a rectangular solid        *
//**********************************************************************
void calculate_specifications(float length, float width, float depth)
{
   cout << "\nVolume of a rectangular solid of "
        << " length " << length
        << ", width " << width
        << ", depth " << depth;
   cout << "\n   "    << length * width * depth << " square units";
   return;
}