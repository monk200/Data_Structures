#include <iterator>
#include <cmath>

#include <list>
#include <queue>
#include <stack>
#include <vector>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "DFS.h"


/**
 * Initializes a depth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 *
 * @param png The image this DFS is going to traverse
 * @param start The start point of this DFS
 * @param tolerance If the current point is too different (difference larger than tolerance) with the start point,
 * it will not be included in this DFS
 */
DFS::DFS(const PNG & png, const Point & start, double tolerance) {
  /** @todo [Part 1] */
  explored.push(start);
}

/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator DFS::begin() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator();
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator DFS::end() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator();
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void DFS::add(const Point & point) {
  /** @todo [Part 1] */
  // gets pixel info of start point
  HSLAPixel start = png.getPixel(start.x, start.y);

  // addPoint bitset indicates which points should be added to the traversal
  std::bitset<4> addPoint = 1111;
  // verify which points are within tolerance
  if (calculateDelta(start, png.getPixel(point.x + 1, point.y)) >= tolerance) addPoint[0] = 0;    // right
  if (calculateDelta(start, png.getPixel(point.x, point.y + 1)) >= tolerance) addPoint[1] = 0;    // below
  if (calculateDelta(start, png.getPixel(point.x - 1, point.y)) >= tolerance) addPoint[2] = 0;    // left
  if (calculateDelta(start, png.getPixel(point.x, point.y - 1)) >= tolerance) addPoint[3] = 0;    // above

  // iterate through explored points
  for (std::list<Point>::iterator it=explored.begin(); it != explored.end(); ++it) {
    if (addPoint == 0000) break;    // no need to keep looking if we know no points need to be added
    if ((*it.x == (point.x + 1)) && (*it.y == point.y)) addPoint[0] = 0;    // right
    if ((*it.x == point.x) && (*it.y == (point.y + 1))) addPoint[1] = 0;    // below
    if ((*it.x == (point.x - 1)) && (*it.y == point.y)) addPoint[2] = 0;    // left
    if ((*it.x == point.x) && (*it.y == (point.y - 1))) addPoint[3] = 0;    // above
  }

  // only add points that are within tolerance and have not been expored yet
  if (addPoint[0] == 1) unexplored.push(new Point(point.x + 1, point.y));   // right
  if (addPoint[1] == 1) unexplored.push(new Point(point.x, point.y + 1));   // below
  if (addPoint[2] == 1) unexplored.push(new Point(point.x - 1, point.y));   // left
  if (addPoint[3] == 1) unexplored.push(new Point(point.x, point.y - 1));   // above
}

/**
 * Removes and returns the current Point in the traversal.
 */
Point DFS::pop() {
  /** @todo [Part 1] */
  return unexplored.pop();
}

/**
 * Returns the current Point in the traversal.
 */
Point DFS::peek() const {
  /** @todo [Part 1] */
  return unexplored.top();
}

/**
 * Returns true if the traversal is empty.
 */
bool DFS::empty() const {
  /** @todo [Part 1] */
  return unexplored.empty();
}
