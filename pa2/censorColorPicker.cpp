/*
*  File: censorColorPicker.cpp
*  Implements the censor color picker for CPSC 221 PA2.
*
*/

#include "censorColorPicker.h"

#include <math.h> // gives access to sqrt function

/*
*  Useful function for computing the Euclidean distance between two PixelPoints
*/
double PointDistance(PixelPoint a, PixelPoint b) {
  unsigned int diff_x, diff_y;
  if (a.x > b.x)
    diff_x = a.x - b.x;
  else
    diff_x = b.x - a.x;
  if (a.y > b.y)
    diff_y = a.y - b.y;
  else
    diff_y = b.y - a.y;
  return sqrt(diff_x * diff_x + diff_y * diff_y);
}

CensorColorPicker::CensorColorPicker(unsigned int b_width, PixelPoint ctr, unsigned int rad, PNG& inputimage)
{
  // complete your implementation below
  blockwidth = b_width;
  center = ctr;
  radius = rad;
  img = inputimage;
  blockyimg = PNG(img.width()/blockwidth, img.height()/blockwidth);
  for (unsigned x = 0; x <= img.width()-blockwidth; x += blockwidth) {
      for (unsigned y = 0; y <= img.height()-blockwidth; y += blockwidth) {
            HSLAPixel avg(0,0,0,0);
            
            for (unsigned bx = 0; bx < blockwidth; ++bx) {
                for (unsigned by = 0; by < blockwidth; ++by) {
                    HSLAPixel * temp = img.getPixel(x + bx, y + by);
                    avg.h += temp->h;
                    avg.s += temp->s;
                    avg.l += temp->l;
                    avg.a += temp->a;
                }
            }
            
            HSLAPixel * curr = blockyimg.getPixel(x/blockwidth, y/blockwidth);
            curr->h = avg.h/(blockwidth*blockwidth);
            curr->s = avg.s/(blockwidth*blockwidth);
            curr->l = avg.l/(blockwidth*blockwidth);
            curr->a = avg.a/(blockwidth*blockwidth);
      }
  }
}

HSLAPixel CensorColorPicker::operator()(PixelPoint p)
{
  // complete your implementation below

  if (PointDistance(p, center) > radius) {
    return *img.getPixel(p.x, p.y);
  } else {
    return *blockyimg.getPixel(p.x/blockwidth, p.y/blockwidth);
  }
}
