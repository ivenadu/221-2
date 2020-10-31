// File:        testrr.cpp
// Author:      Will Evans and Cinda Heeren
// Date:        2020-10-16
// Description: Partial test of PA2.RainbowRipple functionality
//              Reads Point data from external files
//              Produces PNG images of the point sets


#include "rr.h"

int main()
{

  PNG im1;
  im1.readFromFile("images/geo.png");
  pair<int,int> start1(2,2);
  rainbowRipple(im1,start1,"0r0o0y0g0b0i0v");
  im1.writeToFile("images/georr.png");

  PNG im2;
  im2.readFromFile("images/stanley-totem-poles.png");
  pair<int,int> start2(100,150);
  rainbowRipple(im2,start2,"1r2o3y4g3b2i1v");
  im2.writeToFile("images/stanley-totem-polesrr.png");

  PNG im3;
  im3.readFromFile("images/blank.png");
  pair<int,int> start3(320,200);
  rainbowRipple(im3,start3,"5r5o5y5g5b5i5v");
  im3.writeToFile("images/blankrr.png");

  return 0;
}
