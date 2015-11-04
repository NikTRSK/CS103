/*
turtle.cpp

Author: Nikica Trajkovski

Description: Defines the member functions of the Turtle class
*/

#include "turtle.h"

#include <cmath>

Turtle::Turtle(double x0, double y0, double dir0) {
  x = x0;
  y = y0;
  dir = dir0;

  // the turtle starts with the black color
  setColor(draw::BLACK);

  // the turtle starts as visible
  visible = true;
}

void Turtle::move(double dist) {
  // values for use with teh draw::line function
  double x1, y1;

  x1 = x + (dist * cos(dir*M_PI/180));
  y1 = y + (dist * sin(dir*M_PI/180));


  // draw only if the line is set to visible
  draw::setcolor(lineColor);
  if (visible) {
    draw::line(x, y, x1, y1);
  }

  // set the new position of the turtle
  x = x1;
  y = y1;
}

void Turtle::turn(double deg) {
  dir += deg;
}

void Turtle::setColor(Color c) {
  lineColor = c;
}

void Turtle::off() {
  visible = false;
}

void Turtle::on() {
  visible = true;
}
