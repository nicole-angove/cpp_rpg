#include <algorithm>

#include "board.h"
#include "movemap.h"

Board::Board() {
  for (auto element : ELEMENTLIST) {
    Sphere sphere({element});
    _spheres.insert({element, sphere});
  };
}

Sphere Board::getSphere(const Element sphereType) const {
  for (auto sphere : _spheres) {
    if (elementInSearch(sphere.first, sphereType)) {
      return(sphere.second);
    }
  }
  return {};
}

void Board::setSphere(const Element sphereType, const Sphere gems) {
  for (auto sphere : _spheres) {
    if (elementInSearch(sphere.first, sphereType)) {
      _spheres.at(sphereType) = gems;
    }
  }
}

int Board::count(const int sphereType, const int gemType) const {
  int count = 0;
  for (auto& sphere : _spheres) {
    if (elementInSearch(sphere.first, sphereType)) {
      count = count + sphere.second.count(gemType);
    }    
  }

  return count;
}

bool Board::isMoveValid(const std::vector<std::tuple<Element, Element, Element>> moves) const {

  MoveMap moveMap(moves);
  for (auto element : ELEMENTLIST) {
    for (auto element2 : ELEMENTLIST) {
      if (moveMap.inputCount(element, element2) > count(element, element2)) {
        return false;
      }
    }
  }
  
  return true;
}

void Board::move(std::vector<std::tuple<Element, Element, Element>> moves) {
  MoveMap moveMap(moves);
  for (auto element : ELEMENTLIST) {
    for (auto element2 : ELEMENTLIST) {
      int newNumGems = count(element, element2) - moveMap.inputCount(element, element2);
      newNumGems = newNumGems + moveMap.outputCount(element, element2);
      _spheres.at(element).at(element2) = newNumGems;
    }
  } 
}
