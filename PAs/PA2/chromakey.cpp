/*********************************************************************
   File:         chromakey.cpp

   Author:      Nikica Trajkovski

   Email address:   trajkovs@usc.edu

   Usage:   program_name in.bmp background.bmp dist_threshold out1.bmp out2.bmp

   Notes:
   This program performs the chroma key operation on an input
   using two different methods.

   Method 1 Utilize a user-defined distance threshold from the
               chromakey value as a discriminator

   Method 2 Devise a method that to determine the chromakey mask
               that doesn't require a user-input threshold
********************************************************************/

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "bmplib.h"

using namespace std;

// Prototypes
// IMPORTANT: you must exactly use these input types, function names, and
// return types. Otherwise the grader can't test them.
void method1(unsigned char inImage[][SIZE][RGB],
            bool mask[][SIZE],
            double threshold);

void method2(unsigned char inImage[][SIZE][RGB],
            bool mask[][SIZE]);

void replace(bool mask[][SIZE],
            unsigned char inImage[][SIZE][RGB],
            unsigned char bgImage[][SIZE][RGB],
            unsigned char outImage[][SIZE][RGB]);

int main(int argc, char *argv[])
{
   // Image data array
  // Note:  DON'T use the static keyword except where we expressly say so.
  //            It puts the large array in a separate, fixed, area of memory.
  //            It is bad practice. But useful until we have dynamic allocation.
   static unsigned char inputImage[SIZE][SIZE][RGB];
  static unsigned char bgrndImage[SIZE][SIZE][RGB];
  static unsigned char outputImage[SIZE][SIZE][RGB];
  static bool chromaMask[SIZE][SIZE];

  double threshold;

  if (argc < 6) {
      cerr << "usage: program_name in.bmp background.bmp dist_threshold "
           << "out1.bmp out2.bmp" << endl;
      return 0;
  }

   if (readRGBBMP(argv[1], inputImage)) {
      cerr << "Error reading file: " << argv[1] << endl;
      return 1;
  }

  if (readRGBBMP(argv[2], bgrndImage)) {
    cout << "Error reading file: " << argv[2] << endl;
    return 1;
  }

  // Write code to convert the threshold (argv[3])
  //  from string format to a double and assign the 'threshold'
   threshold = atof(argv[3]);      // wouldn't compile using stoi

  // Call Method 1 Function
   method1(inputImage, chromaMask, threshold);

  // Produce the output by calling replace()
   replace(chromaMask, inputImage, bgrndImage, outputImage);

  // Write the output image to a file using the filename argv[4]
  if (writeRGBBMP(argv[4], outputImage)) {
    cout << "Error writing file: " << argv[4] << endl;
    exit(1);
  }

  // Call Method 2 Function
   method2(inputImage, chromaMask);

  // Produce the output by calling replace()
   replace(chromaMask, inputImage, bgrndImage, outputImage);

  // Write the output image to a file using the filename argv[5]
  if (writeRGBBMP(argv[5], outputImage)) {
    cout << "Error writing file: " << argv[5] << endl;
    exit(1);
  }

  return 0;
}

// Use user-provided threshold for chroma-key distance
// The "output" of this method is to produce a valid mask array
//  where entries in the mask array are 1 for foreground image
//  and 0 for 'background'
void method1(unsigned char inImage[][SIZE][RGB],
         bool mask[][SIZE],
         double threshold)
{
   // Take a samples of spaces
   int sampleSize = 50;
   double average[3] = {0};
   double distance;

   // Generates a sample green color for comparrison with the background image
   for (int i = 0; i < sampleSize; i++)
   {
      for (int j = 0; j < sampleSize; j++)
      {
         for (int color = 0; color <3; color++)
         {
            average[color] += ( inImage[i][j][color] / pow(sampleSize, 2) );
         }
      }
   }

   // Creates the mask
   for (int i = 0; i < SIZE; i++)
   {
      for (int j = 0; j < SIZE; j++)
      {
         // takes the average distance for each color
         double averageColorDistance = 0;
         for (int color = 0; color < 3; color++)
            {
               averageColorDistance += pow( average[color] -
                                            inImage[i][j][color], 2 );
            }

            // stored in a variable before comparrison for clarity purposes
            distance = sqrt(averageColorDistance);

            if (distance < threshold)
               mask[i][j] = 0;
            else
               mask[i][j] = 1;
         }
      }
}

// Devise a method to automatically come up with a threshold
//  for the chroma key determination
// The "output" of this method is to produce a valid mask array
//  where entries in the mask array are 1 for foreground image
//  and 0 for 'background'
void method2(unsigned char inImage[][SIZE][RGB],
         bool mask[][SIZE])
{
   double average[3] = {0.0, 0.0, 0.0};
   int sampleSize = 15;
   double numOfPixels = sampleSize * SIZE;
      // without defining numOfPixels average returns 0
   double variance = 0, avgVariance = 0;
   double deviation = 0, stdDeviation = 0;
   double distance = 0;

   // Generates a sample green color for comparrison with the background image
   for (int i = 0; i < sampleSize; i++)
   {
      for (int j = 0; j < SIZE; j++)
      {
         for (int color = 0; color < 3; color++)
         {
            // takes the average for each color
            average[color] +=  inImage[i][j][color] / (numOfPixels) ;
         }
      }
   }

   // Calculates the average distance between the chromakey and the pixels (mu)
   for (int i = 0; i < SIZE; i++)
   {
      for (int j = 0; j < SIZE; j++)
      {
         for (int color = 0; color < 3; color++ )
         {
            variance += pow( average[color] - inImage[i][j][color], 2 );
         }
         avgVariance +=  sqrt(variance) / pow(SIZE, 2);
         variance = 0;
      }
   }

   // Calculates standard deviation
   for ( int i = 0; i < SIZE; i++)
   {
      for ( int j = 0; j < SIZE; j++)
      {
         for (int color = 0; color < 3; color++)
         {
            deviation += pow( average[color] - inImage[i][j][color], 2 );
         }
         stdDeviation +=  pow ( (sqrt(deviation) - avgVariance), 2 ) / pow(SIZE, 2);
         deviation = 0;
      }
   } //
   stdDeviation = sqrt(stdDeviation);

   // Creates the mask
   for (int i = 0; i < SIZE; i++)
   {
      for (int j = 0; j < SIZE; j++)
      {
         // takes the average distance for each color
         double averageColorDistance = 0;
         for (int color = 0; color < 3; color++)
            {
               averageColorDistance += pow( average[color] -
                                            inImage[i][j][color], 2 );
            }

            // stored in a variable before comparrison for clarity purposes
            distance = sqrt(averageColorDistance);

            if (distance < stdDeviation)
               mask[i][j] = 0;
            else
               mask[i][j] = 1;
         }
      }
}

// If mask[i][j] = 1 use the input image pixel for the output image
// Else if mask[i][j] = 0 use the background image pixel
void replace(bool mask[SIZE][SIZE],
         unsigned char inImage[SIZE][SIZE][RGB],
         unsigned char bgImage[SIZE][SIZE][RGB],
         unsigned char outImage[SIZE][SIZE][RGB])
{
  // Create the output image using the mask to determine
  //  whether to use the pixel from the Input or Background image
   for (int i = 0; i < SIZE; i++)
   {
      for (int j = 0; j < SIZE; j++)
      {
         for (int color = 0; color < 3; color++)
         {
            if (mask[i][j] == 1)
               outImage[i][j][color] = inImage[i][j][color];
            else
               outImage[i][j][color] = bgImage[i][j][color];
         }
      }
   }
}
