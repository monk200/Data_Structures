/**
 * @file HSLAPixel.h
 *
 * @author CS 225: Data Structures
 * @version 2018r1-lab1
 */

#ifndef CS225_HSLAPIXEL_H_
#define CS225_HSLAPIXEL_H_

#include <iostream>
#include <sstream>

namespace cs225 {
  class HSLAPixel {
    public:
      HSLAPixel();    // opaque (non-transparant) and white pixel
      HSLAPixel(double hue, double saturation, double luminance);
      HSLAPixel(double hue, double saturation, double luminance, double alpha);
      double h;   // hue [0, 360)
      double s;   // saturation [0, 1]
      double l;   // luminance [0, 1]
      double a;   // alpha = transparancy [0, 1]
  };
}

#endif
