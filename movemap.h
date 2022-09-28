#ifndef MOVEMAP_H
#define MOVEMAP_H

#include <vector>
#include <tuple>
#include <map>

#include "element.h"
#include "move.h"

/**
 * @brief 
 * 
 */
class MoveMap {
  public:
  MoveMap(const std::vector<Move>);
  int inputCount(const int sphereType = Element::ALL, const int gemType = Element::ALL) const;
  int outputCount(const int sphereType = Element::ALL, const int gemType = Element::ALL) const;


  private:
  std::map<Element, std::map<Element, int>> _inputs;
  std::map<Element, std::map<Element, int>> _outputs;

};

#endif
