//**********************************************************************
//*                                                                    *
//* Program Name: PROG01 - Draw a rectangle and show specifications    *
//* Author:       Ian McPherson                                        *
//* Installation: Pensacola Christian College, Pensacola, Florida      *
//* Course:       CS246, Object-Oriented Programming and Design        *
//* Date Written: January 29, 2020                                     *
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
//* This program asks for the dimensions of a rectangle.  It will then *
//* draw that triangle and calculate its specifications.  The          *
//* specifications that will be calculated are its length, width,      *
//* area, and perimeter.  It will show those specifications and print  *
//* a goodbye message.                                                 *
//*                                                                    *
//**********************************************************************

#include <iostream>
using namespace std;

//**********************************************************************
//*                         Symbolic Constants                         *
//**********************************************************************
#define COURSE_NAME      "Object-Oriented Programming and Design" 
                                 // PCC assigned course name
#define COURSE_NUMBER    "CS246" // PCC assigned course number
#define MIN_RECT_LENGTH  1.0f    // Minimum length for the rectangle
#define MIN_RECT_WIDTH   1.0f    // Minimum width for the rectangle
#define PROGRAM_NUMBER   1.0f    // Teacher assigned program number
#define RECTANGLE_BORDER '*'     // Rectangle border symbol
#define RECTANGLE_CENTER ' '     // Center symbol for the rectangle
#define SCALE_FACTOR     1.5f    // Length multiplier for the rectangle

//**********************************************************************
//*                        Program Structures                          *
//**********************************************************************
// A rectangle specification
struct rectangle_spec
{
   float f_area,      // Area for a rectangle
         f_length,    // Length measurement for a rectangle
         f_perimeter, // The perimeter for a rectangle
         f_width;     // Width measurement for a rectangle
};

//**********************************************************************
//*                       Function Prototypes                          *
//**********************************************************************
void print_heading        (); 
   // Print the program heading
void get_rectangle_specs  (rectangle_spec *p_rectangle);
   // Get the dimensions of the rectangle
void draw_rectangle       (float f_length, float f_width);        
   // Draw the rectangle
void print_rectangle_specs(rectangle_spec rectangle); 
   // Print the specifications for the rectangle

//**********************************************************************
//*                          Main Function                             *
//**********************************************************************
int main()
{
   struct rectangle_spec rectangle; // The specifications of a rectangle

   // Print the program heading
   print_heading();

   // Get the rectangle's dimensions
   get_rectangle_specs(&rectangle);

   // Draw the rectangle and print its specifications
   draw_rectangle(rectangle.f_length, rectangle.f_width);
   print_rectangle_specs(rectangle);

   // Say goodbye and terminate
   cout << "\n\nThanks for drawing a rectangle today ;)";
   cout << "\n\n\n\n\n\n";
   return 0;
}

//**********************************************************************
//*                 Print the program heading Heading                  *
//**********************************************************************
void print_heading()
{
   cout << "\n\n\n\n\n\n\n        " << COURSE_NUMBER << " " 
        << COURSE_NAME              << " - Program " << PROGRAM_NUMBER;
   cout << "\n\n                     This program draws a rectangle";
   cout <<   "\n                     ==============================";
   return;
}

//**********************************************************************
//*   Get the rectangle dimensions and calculate the specifications    *
//**********************************************************************
void get_rectangle_specs(rectangle_spec *p_rectangle)
{
   cout << "\n\n\nEnter the rectangle length now: ";
   cin  >> p_rectangle->f_length;
   cout <<       "Enter the rectangle width here: ";
   cin  >> p_rectangle->f_width;
   p_rectangle->f_area = p_rectangle->f_width * p_rectangle->f_length;
   p_rectangle->f_perimeter = 
                     (p_rectangle->f_width + p_rectangle->f_length) * 2.0f;
   return;
}

//**********************************************************************
//*            Draw the rectangle from the given dimensions            *
//**********************************************************************
void draw_rectangle(float f_length, float f_width)
{
   int i_length,       // The integer value from the float length
       i_width,        // Integer value from the float width
       length_counter, // Length specification counter
       width_counter;  // Width specification counter

   // Check to see if the dimensions are above the minimums
   if (f_length < MIN_RECT_LENGTH || f_width < MIN_RECT_WIDTH)
   {
      cout <<"\n\nA " << f_length << " by "  << f_width << " rectangle"
           <<   " is too small to draw.";
      cout <<  "\nIt must be at least size " << MIN_RECT_LENGTH 
           <<   " by " << MIN_RECT_WIDTH     << " (length by width).";
   }
   else
   {
      // Convert the float dimensions into integers
      i_length = (int)(f_length * SCALE_FACTOR);
      i_width  = (int) f_width;
      
      // Print the rectangle's title
      cout << "\n\nHere is a picture of your rectangle:";

      // Print the top row of the rectangle
      cout << "\n";
      for (length_counter = 0; length_counter < i_length; 
                                                       length_counter++)
         cout << RECTANGLE_BORDER;

      // Print the middle row(s) of the rectangle
      for (width_counter = 0; width_counter < (i_width - 2); 
                                                        width_counter++)
      {
         cout << "\n" << RECTANGLE_BORDER;
         for (length_counter = 0; length_counter < (i_length - 2); 
                                                       length_counter++)
            cout << RECTANGLE_CENTER;
         cout << RECTANGLE_BORDER;
      }

      // Print the bottom row if needed
      if (width_counter == (i_width - 2))
      {
         cout << "\n";
         for (length_counter = 0; length_counter < i_length; 
                                                       length_counter++)
            cout << RECTANGLE_BORDER;
      }
   }
   return;
}

//**********************************************************************
//*                Show the rectangle's specifications                 *
//**********************************************************************
void print_rectangle_specs(rectangle_spec rectangle)
{
   cout << "\n\nThe rectangle specifications are:";
   cout <<   "\n        Length = " << rectangle.f_length    << " units";
   cout <<   "\n         Width = " << rectangle.f_width     << " units";
   cout <<   "\n          Area = " << rectangle.f_area
        <<   " sq. units";
   cout <<   "\n     Perimeter = " << rectangle.f_perimeter << " units";
   return;
}