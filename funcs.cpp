#include <iostream>

#include "funcs.h"
#include "imageio.h"

//TASK A -- WORKS! need to make it into a function...
//invert.cpp

void invert(std::string filename){ //not sure what parameters...

  std::string input = "image1.pgm";

  int img[MAX_H][MAX_W];
  int h, w;

  readImage(input, img, h, w);
  
  int out[MAX_H][MAX_W];

  //if pixel is white, turn black. if pixel is black, turn white.
  //where orginal pixel value if "neg" + 255 ex. -1 (aka 1) -> 254 and -254 (aka 254) -> 1

  int color;

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      color = img[row][col];
      color = -color;
      img[row][col] = color + 255;
      out[row][col] = img[row][col];
    }
  }

  writeImage("outImage.pgm",out, h, w);

}
