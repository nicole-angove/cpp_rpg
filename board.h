#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <tuple>
#include <map>

#include "element.h"
#include "sphere.h"
#include "move.h"

/**
 * Represents a game board containing spheres (see 'sphere.h').
 * Has functionality to allow access to spheres, as well as the
 * ability to move gems between spheres.
 * 
 * A board contains a sphere for each element, represented as a 
 * map of elements to spheres.
 * 
 * When constructed, each sphere contains 1 gem of the same element as 
 * the sphere. Any changes to the gems must be effected after construction.
 */
class Board {
  public: 
    Board();

    // count accepts int inputs rather than Element so that it can
    // deal with bitwise operations on inputs.
    int count(const int sphereType=Element::ALL, const int gemType=Element::ALL) const;
  
    // Each move in the vector is in the order {gemType, source, destination}
    bool isMoveValid(const std::vector<Move>) const;
    void doMoves(const std::vector<Move>);

    void setSphere(const Element, const Sphere);
    Sphere getSphere(const Element) const;


  private:
    // The spheres included in the board.
    std::map<Element, Sphere> _spheres;
};

#endif
