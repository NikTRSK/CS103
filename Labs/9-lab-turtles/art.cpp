#include "turtle.h"
#include "draw.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  draw::setpenwidth(10); // thick lines
  draw::setrange(-100, 100);
// Creates 4 turtles
  // Creates BLUE Leonardo first, because he's the best turtle
  Turtle leonardo(0, 0, 0);
  leonardo.setColor(draw::BLUE);
  // Creates PURPLE Donatelo second, because he's the brain
  Turtle donatelo(0, 0, 0);
  donatelo.setColor(draw::PURPLE);
  // Creates ORANGE Michaelangelo third, because he's the surfer dude
  Turtle michaelangelo(0, 0, 0);
  michaelangelo.setColor(draw::ORANGE);
  // Creates RED Raphael last, because he's the grumpy turtle
  Turtle raphael(0, 0, 0);
  raphael.setColor(draw::RED);

  // Seeds the random number generator
  srand(time(0));

  // arrays for the turn and move values of the four turtles
  double moveDist[4], turn[4];

  // Generate random directions
  for(int i = 0; i < 4; i++)
    turn[i] = rand()%360;

  // Starting random orientations
  leonardo.turn(turn[0]);
  donatelo.turn(turn[1]);
  michaelangelo.turn(turn[2]);
  raphael.turn(turn[3]);

  // Move the turtles in 5 steps
  for (int step = 0; step < 5; step++)
  {
    // Generate random move distances between 0 and 50
    for (int j = 0; j < 4; j++)
    {
      moveDist[j] = rand() % 51;
    }

    // Generate new random directions
    for(int i = 0; i < 4; i++)
      turn[i] = rand()%360;

    leonardo.move(moveDist[0]);
    leonardo.turn(turn[0]);
    donatelo.move(moveDist[1]);
    donatelo.turn(turn[1]);
    michaelangelo.move(moveDist[2]);
    michaelangelo.turn(turn[2]);
    raphael.move(moveDist[3]);
    raphael.turn(turn[3]);

    for (int j = 0; j < 10; j++)
    {
      for(int i = 0; i < 4; i++)
        turn[i] = rand()%360;

/*        leonardo.move(moveDist[0]);
        leonardo.turn(turn[0]);
        donatelo.move(moveDist[1]);
        donatelo.turn(turn[1]);
        michaelangelo.move(moveDist[2]);
        michaelangelo.turn(turn[2]);
        raphael.move(moveDist[3]);
        raphael.turn(turn[3]);*/
    }

    draw::show(500);

  }

  return 0;
}
