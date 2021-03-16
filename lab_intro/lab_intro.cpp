#include <iostream>
#include <cmath>
#include <cstdlib>

#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include "lab_intro.h"

using namespace cs225;

/**
 * Returns an image that has been transformed to grayscale.
 *
 * The saturation of every pixel is set to 0, removing any color.
 *
 * @return The grayscale image.
 */
PNG grayscale(PNG image) {
  /// This function is already written for you so you can see how to
  /// interact with our PNG class.
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);

      // `pixel` is a pointer to the memory stored inside of the PNG `image`,
      // which means you're changing the image directly.  No need to `set`
      // the pixel since you're directly changing the memory of the image.
      pixel.s = 0;
    }
  }

  return image;
}



/**
 * Returns an image with a spotlight centered at (`centerX`, `centerY`).
 *
 * A spotlight adjusts the luminance of a pixel based on the distance the pixel
 * is away from the center by decreasing the luminance by 0.5% per 1 pixel euclidean
 * distance away from the center.
 *
 * For example, a pixel 3 pixels above and 4 pixels to the right of the center
 * is a total of `sqrt((3 * 3) + (4 * 4)) = sqrt(25) = 5` pixels away and
 * its luminance is decreased by 2.5% (0.975x its original value).  At a
 * distance over 160 pixels away, the luminance will always decreased by 80%.
 *
 * The modified PNG is then returned.
 *
 * @param image A PNG object which holds the image data to be modified.
 * @param centerX The center x coordinate of the crosshair which is to be drawn.
 * @param centerY The center y coordinate of the crosshair which is to be drawn.
 *
 * @return The image with a spotlight.
 */
PNG createSpotlight(PNG image, int centerX, int centerY) {
  // loops through image
  for (unsigned x=0; x < image.width(); x++) {
    for (unsigned y=0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);   // pixel is a pointer to the memory stored inside of png image -> you are changing the image directly
      double lum = pixel.l;

      // get distance between center and pixel, accounts for all quadrents around the given center
      // !!! WARNINGS THROWN HERE BECAUSE X AND Y ARE UNSIGNED WHILE CENTERX AND CENTERY ARE INT !!!
      int dx, dy;
      if (x < centerX) dx = centerX - x;
      else dx = x - centerX;
      if (y < centerY) dy = centerY - y;
      else dy = y - centerY;

      double distanceFromCenter = sqrt(pow(dx, 2) + pow(dy, 2));    // euclidean distance of pixel from the center points given
      if (distanceFromCenter < 160) pixel.l = lum * (1 - (distanceFromCenter * 0.005));   // pixel loses 0.5% luminance per 1 pixel distanceFromCenter
      else pixel.l = lum * 0.2;   // if farther than 160 pixels, pixel loses 80% luminance
    }
  }

  return image;
}


/**
 * Returns a image transformed to Illini colors.
 *
 * The hue of every pixel is set to the a hue value of either orange or
 * blue, based on if the pixel's hue value is closer to orange than blue.
 *
 * @param image A PNG object which holds the image data to be modified.
 *
 * @return The illinify'd image.
**/
PNG illinify(PNG image) {
  // loops through image
  for (unsigned x=0; x < image.width(); x++) {
    for (unsigned y=0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);   // pixel is a pointer to the memory stored inside of png image -> you are changing the image directly
      double hue = pixel.h;

      // determine distance from 11 and distance from 216
      double distToOrange = 360;
      if (hue < (11+180)) distToOrange = abs(hue - 11);   // distance for hues to the right of orange by <=180
      else distToOrange = (360-hue) + 11;   // accounts for wraparound
      double distToBlue = abs(hue - 216);   // wraparound doesn't need to be considered here because anything near 0/360 will be closest to orange

      // sets new hue for pixel
      if (distToOrange < distToBlue) pixel.h = 11;
      else pixel.h = 216;
    }
  }

  return image;
}


/**
* Returns an immge that has been watermarked by another image.
*
* The luminance of every pixel of the second image is checked, if that
* pixel's luminance is 1 (100%), then the pixel at the same location on
* the first image has its luminance increased by 0.2.
*
* @param firstImage  The first of the two PNGs to be averaged together.
* @param secondImage The second of the two PNGs to be averaged together.
*
* @return The watermarked image.
*/
PNG watermark(PNG firstImage, PNG secondImage) {
  // determine bounds
  unsigned width, height;
  if (firstImage.width() > secondImage.width()) width = firstImage.width();
  else width = secondImage.width();
  if (firstImage.height() > secondImage.height()) height = firstImage.height();
  else height = secondImage.height();

  // loop through only the pixels where the images overlap
  for (unsigned x=0; x < width; x++) {
    for (unsigned y=0; y < height; y++) {
      // pixel is a pointer to the memory stored inside of png image -> you are changing the image directly
      HSLAPixel & firstPixel = firstImage.getPixel(x, y);
      HSLAPixel & secondPixel = secondImage.getPixel(x, y);

      if (secondPixel.l == 1) {   // if the luminance of the second image is 1
        if (firstPixel.l <= 0.8) firstPixel.l += 0.2;   // pixel at same location has its luminance incrased by 0.2, but not exceeding 1
      }
    }
  }

  return firstImage;
}
