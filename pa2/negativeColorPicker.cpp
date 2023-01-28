/*
*  File: negativeColorPicker.cpp
*  Implements the negative color picker for CPSC 221 PA2.
*
*/

#include "negativeColorPicker.h"

NegativeColorPicker::NegativeColorPicker(PNG& inputimg)
{
  // complete your implementation below
  img = inputimg;
}

HSLAPixel NegativeColorPicker::operator()(PixelPoint p)
{
  // complete your implementation below
    HSLAPixel colour = *img.getPixel(p.x, p.y);
    colour.h = fmod((colour.h + 180), 360);
    colour.l = 1.0 - colour.l;
    return colour; // REPLACE THIS STUB
}
