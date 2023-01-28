/*
*  File: imageTileColorPicker.cpp
*  Implements the image tile color picker for CPSC 221 PA2.
*
*/

#include "imageTileColorPicker.h"

ImageTileColorPicker::ImageTileColorPicker(PNG& otherimage) {
  // complete your implementation below
  img_other = otherimage;
}

HSLAPixel ImageTileColorPicker::operator()(PixelPoint p) {
  // complete your implementation below
  int otherX = img_other.width();
  int otherY = img_other.height();
  HSLAPixel colour = *img_other.getPixel(p.x % otherX, p.y % otherY);
  return colour; // REPLACE THIS STUB
}