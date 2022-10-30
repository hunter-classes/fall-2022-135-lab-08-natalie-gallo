#include <iostream>
#include <cmath>
#include "funcs.h"
#include "imageio.h"


int main()
{
  invert("inImage.pgm");
  invert_half("inImage.pgm");
  box("inImage.pgm");
  frame("inImage.pgm");
  scale("inImage.pgm");
  pixelate("inImage.pgm");
  
  return 0;
}
