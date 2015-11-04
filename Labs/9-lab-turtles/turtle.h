/*
turtle.h

Author: Nikica Trajkovski

Description:
*/

#include "draw.h"

#ifndef TURTLE_H
#define TURTLE_H

// a class that contains a series of Locations
class Turtle {
   public: // API:

   // construct new Turtle with initial position and direction
   Turtle(double x, double y, double dir);

   // move the Turtle forward dist steps
   void move(double dist);

   // turn the Turtle counterclockwise/left deg degrees
   void turn(double deg);

   // change line color that this Turtle draws from now on
   void setColor(Color c);

   // make this Turtle stop drawing lines when it moves
   void off();

   // make this Turtle resume drawing lines when it moves
   void on();


   // member variables of an Turtle, for implementation:
   private:
   double x; // the starting x coordinate of the Turtle
   double y; // the starting y coordinate of the Turtle
   double dir; // the initial direction of the Turtle

   bool visible;    // sets the visibility of the Turtle
   Color lineColor; // sets the color of the line
};

#endif
