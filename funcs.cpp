#include <iostream>
#include <cmath>
#include "funcs.h"
#include "imageio.h"

//NOTE TO SELF: check for loops that use <= and change it to < !!
//double check programs with image2

//TASK A -- WORKS! need to make it into a function... and change output name!
//invert.cpp

void invert(std::string input){ //not sure what parameters...

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

  writeImage("taskA.pgm",out, h, w);

}

//TASK B -- works(?) need to turn into function and change output file name
void invert_half(std::string input){

  int img[MAX_H][MAX_W];
  int h, w;

  readImage(input, img, h, w);
  
  int out[MAX_H][MAX_W];

  //if pixel is white, turn black. if pixel is black, turn white.
  //where orginal pixel value if "neg" + 255 ex. -1 (aka 1) -> 254 and -254 (aka 254) -> 1

  int color;

  for(int row = 0; row < h; row++) {
    for(int col = 0; col <= w/2; col++) {
      out[row][col] = img[row][col];
    }
  }

  for(int row = 0; row < h; row++) {
    for(int col = w/2; col < w; col++) {
      color = img[row][col];
      color = -color;
      img[row][col] = color + 255;
      out[row][col] = img[row][col];
    }
  }

  writeImage("taskB.pgm",out, h, w);
}

//TASK C -- works... need to make proper implemation per lab instructions
void box(std::string input){

  int img[MAX_H][MAX_W];
  int h, w;

  readImage(input, img, h, w);
  
  int out[MAX_H][MAX_W];

  //if pixel is white, turn black. if pixel is black, turn white.
  //where orginal pixel value if "neg" + 255 ex. -1 (aka 1) -> 254 and -254 (aka 254) -> 1

  //left side
  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w/4; col++) {
      out[row][col] = img[row][col];
    }
  }

  //top
  for(int row = 0; row < h/4; row++) {
    for(int col = 0; col < w; col++) {
      out[row][col] = img[row][col];
    }
  }

  //bottom
  for(int row = h - h/4; row < h; row++) {
    for(int col = 0; col < w; col++) {
      out[row][col] = img[row][col];
    }
  }

  //right side
  for(int row = 0; row < h; row++) {
    for(int col = w - w/4; col < w; col++) {
      out[row][col] = img[row][col];
    }
  }

  //middle
  for(int row = h/4; row < h * 0.75; row++) {
    for(int col = w/4; col < w * 0.75; col++) {
      img[row][col] = 255;
      out[row][col] = img[row][col];
    }
  }

  writeImage("taskC.pgm",out, h, w);
}

//TASK D -- again, missing proper implementing (works with cat image)
void frame(std::string input){

  int img[MAX_H][MAX_W];
  int h, w;

  readImage(input, img, h, w);
  
  int out[MAX_H][MAX_W];

  //if pixel is white, turn black. if pixel is black, turn white.
  //where orginal pixel value if "neg" + 255 ex. -1 (aka 1) -> 254 and -254 (aka 254) -> 1

  //left side
  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w/4; col++) {
      out[row][col] = img[row][col];
    }
  }

  //top
  for(int row = 0; row < h/4; row++) {
    for(int col = 0; col < w; col++) {
      out[row][col] = img[row][col];
    }
  }

  //bottom
  for(int row = h - h/4; row < h; row++) {
    for(int col = 0; col < w; col++) {
      out[row][col] = img[row][col];
    }
  }

  //right side
  for(int row = 0; row < h; row++) {
    for(int col = w - w/4; col < w; col++) {
      out[row][col] = img[row][col];
    }
  }

  //FRAME

  //top
  for(int row = h/4; row < h/4 + 1; row++) {
    for(int col = w/4; col < w * 0.75; col++) {
      img[row][col] = 255;
      out[row][col] = img[row][col];
    }
  }

  //left side
  for(int row = h/4; row < h * 0.75; row++) {
    for(int col = w/4; col < w/4 + 1; col++) {
      img[row][col] = 255;
      out[row][col] = img[row][col];
    }
  }
  
  //bottom
  for(int row = (h - h/4) - 1; row < h - h/4; row++) {
    for(int col = w/4; col < w * 0.75; col++) {
      img[row][col] = 255;
      out[row][col] = img[row][col];
    }
  }

  //right side
  for(int row = h/4; row < h * 0.75; row++) {
    for(int col = (w - w/4) - 1; col < w - w/4; col++) {
      img[row][col] = 255;
      out[row][col] = img[row][col];
    }
  }

  //middle [filled]
  for(int row = h/4 + h/h; row < (h * 0.75) - 1; row++) {
    for(int col = w/4 + w/w; col < (w * 0.75) - 1; col++) {
      out[row][col] = img[row][col];
    }
  }

  writeImage("taskD.pgm",out, h, w);
}

//TASK E -- need for make into function and change output file name
void scale(std::string input){
 //used cat image for this.. consistency needed

  int img[MAX_H][MAX_W];
  int h, w;

  readImage(input, img, h, w);
  
  int out[MAX_H][MAX_W];

  for(int row = 0; row < h; row++){
    for(int col = 0; col < w; col++){
      //small 2x2 squares for every pixel
      out[row * 2][col * 2] = img[row][col]; //top left
      out[(row * 2) + 1][col * 2] = img[row][col]; //bottom left
      out[row * 2][(col * 2) + 1] = img[row][col]; //top right
      out[(row * 2) + 1][(col * 2) + 1] = img[row][col]; //bottom right
    }
  }

  writeImage("taskE.pgm", out, h * 2, w * 2);
}

//TASK F
void pixelate(std::string input){

  int img[MAX_H][MAX_W];
  int h, w;

  readImage(input, img, h, w);
  
  int out[MAX_H][MAX_W];

  for(int row = 0; row < h; row++){
    for(int col = 0; col < w; col++){
      //small 2x2 squares for every pixel
      double num1 = img[row * 2][col * 2];
      double num2 = img[(row * 2) + 1][col * 2];
      double num3 = img[row * 2][(col * 2) + 1];
      double num4 = img[(row * 2) + 1][(col * 2) + 1];
      
      double avg = round((num1 + num2 + num3 + num4) / 4);
	
      out[row * 2][col * 2] = avg; //top left
      out[(row * 2) + 1][col * 2] = avg; //bottom left
      out[row * 2][(col * 2) + 1] = avg; //top right
      out[(row * 2) + 1][(col * 2) + 1] = avg; //bottom right
    }
  }

  writeImage("taskF.pgm", out, h, w);
}
