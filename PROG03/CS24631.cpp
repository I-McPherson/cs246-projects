//**********************************************************************
//*                                                                    *
//* Program Name: PROG03 - Draw a rectangle and show specifications    *
//* Author:       Ian McPherson                                        *
//* Installation: Pensacola Christian College, Pensacola, Florida      *
//* Course:       CS246, Object-Oriented Programming and Design        *
//* Date Written: February 17, 2020                                    *
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
//* This program asks for the length and width of a rectangle,         *
//* calculates its area and perimeter, draws a picture of the          *
//* rectangle, and prints its specifications.                          *
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
#define PROGRAM_NUMBER   3       // Teacher assigned program number
#define RECTANGLE_BORDER '*'     // Rectangle border symbol
#define RECTANGLE_CENTER ' '     // Center symbol for the rectangle
#define SCALE_FACTOR     1.5f    // Length multiplier for the rectangle

//**********************************************************************
//*                        Program Structures                          *
//**********************************************************************
// A rectangle class specification
class rectangle_spec
{
   float area,      // Area for a rectangle
         length,    // Length measurement for a rectangle
         perimeter, // The perimeter for a rectangle
         width;     // Width measurement for a rectangle

public:
   // Constructor, create a rectangle
      rectangle_spec            (float user_length, float user_width);

   // Destructor, delete a rectangle
      ~rectangle_spec           ();

   // Draw the rectangle
      void draw_rectangle       ();

   // Print the specifications for the rectangle
      void print_rectangle_specs();
};

//**********************************************************************
//*                        Create a rectangle                          *
//**********************************************************************
rectangle_spec::rectangle_spec(float user_length, float user_width)
{
   length    = user_length;
   width     = user_width;
   area      = width * length;
   perimeter = (width + length) * 2.0f;
}

//**********************************************************************
//*                        Delete a rectangle                          *
//**********************************************************************
rectangle_spec::~rectangle_spec()
{
   cout << "\nThe rectangle object is being destructed now.";
}

//**********************************************************************
//*            Draw the rectangle from the given dimensions            *
//**********************************************************************
void rectangle_spec::draw_rectangle()
{
   int i_length, // The integer value from the float length
       i_width,  // Integer value from the float width
       columns,  // Length specification counter
       rows;     // Width specification counter

   // Check to see if the dimensions are above the minimums
   if (length < MIN_RECT_LENGTH || width < MIN_RECT_WIDTH)
   {
      cout <<"\n\nA " << length << " by "  << width << " rectangle"
           <<   " is too small to draw.";
      cout <<  "\nIt must be at least size " << MIN_RECT_LENGTH 
           <<   " by " << MIN_RECT_WIDTH     << " (length by width).";
   }
   else
   {
      // Convert the float dimensions into integers
      i_length = (int)(length * SCALE_FACTOR);
      i_width  = (int) width;
      
      // Print the rectangle's title
      cout << "\n\nHere is a picture of your rectangle:";

      // Print the top row of the rectangle
      cout << "\n";
      for (columns = 1; columns <= i_length; columns++)
         cout << RECTANGLE_BORDER;

      // Print the middle row(s) of the rectangle
      for (rows = 1; rows <= (i_width - 2); rows++)
      {
         cout << "\n" << RECTANGLE_BORDER;
         for (columns = 1; columns <= (i_length - 2); columns++)
            cout << RECTANGLE_CENTER;
         cout << RECTANGLE_BORDER;
      }

      // Print the bottom row if needed
      if (i_width >= 2)
      {
         cout << "\n";
         for (columns = 1; columns <= i_length; columns++)
            cout << RECTANGLE_BORDER;
      }
   }
   return;
}

//**********************************************************************
//*                Show the rectangle's specifications                 *
//**********************************************************************
void rectangle_spec::print_rectangle_specs()
{
   cout << "\n\nThe rectangle specifications are:";
   cout <<   "\n        Length = " << length    << " units";
   cout <<   "\n         Width = " << width     << " units";
   cout <<   "\n          Area = " << area
        <<   " sq. units";
   cout <<   "\n     Perimeter = " << perimeter << " units";
   return;
}

//**********************************************************************
//*                       Function Prototypes                          *
//**********************************************************************
void print_heading        (); 
   // Print the program heading
void get_rectangle_specs  (float *length, float *width);
   // Get the dimensions of the rectangle

//**********************************************************************
//*                          Main Function                             *
//**********************************************************************
int main()
{
   float length, // The length dimension of a rectangle
         width;  // The width dimension of a rectangle

   // Print the program heading
   print_heading();

   // Get the rectangle's dimensions
   get_rectangle_specs(&length, &width);

   // Create a rectangle object
   rectangle_spec rectangle(length, width);

   // Draw the rectangle and print its specifications
   rectangle.draw_rectangle       ();
   rectangle.print_rectangle_specs();

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
   cout << "\n\n\n\n\n\n\n        " << COURSE_NUMBER 
        << " "                      << COURSE_NAME              
        << " - Program "            << PROGRAM_NUMBER;
   cout << "\n\n                     This program draws a rectangle";
   cout <<   "\n                     ==============================";
   return;
}

//**********************************************************************
//*   Get the rectangle dimensions and calculate the specifications    *
//**********************************************************************
void get_rectangle_specs(float *length, float *width)
{
   cout << "\n\n\nEnter the rectangle length now: ";
   cin  >> *length;
   cout <<       "Enter the rectangle width here: ";
   cin  >> *width;
   return;
}