#ifndef MOVEMAP_H
#define MOVEMAP_H

#include <vector>
#include <tuple>
#include <map>

#include "element.h"
#include "move.h"

/**
 * Contains information about a sequence of moves in a convenient format
 * used in the move function of Board.
 * 
 * Holds two maps, one for inputs of the move and one for the outputs.
 * Each map has keys for the elements the spheres the gems are moving from/to,
 * and values containing map of each gem type and the number of those gems involved
 * in the move.
 * 
 * WHY??????
 * 
 */
class MoveMap {
  public:
    // takes the moves in the form of a vector containing a tuple of moves in 
    // {gem type, source, destination}.
    MoveMap(const std::vector<Move>);

    // counts the gems that fit the gemType mask moving out of the spheres that fit the sphereType mask.
    int inputCount(const int sphereType = Element::ALL, const int gemType = Element::ALL) const;

    // counts the gems that fit the gemType mask moving out of the spheres that fit the sphereType mask.
    int outputCount(const int sphereType = Element::ALL, const int gemType = Element::ALL) const;

  private:
    std::map<Element, std::map<Element, int>> _inputs;
    std::map<Element, std::map<Element, int>> _outputs;
};

#endif
