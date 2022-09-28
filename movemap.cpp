#include <map>

#include "movemap.h"

MoveMap::MoveMap(std::vector<Move> moves) {
    for (auto element : ELEMENTLIST) {
        _inputs.insert({element, {}});
        _outputs.insert({element, {}});
        for (auto element2 : ELEMENTLIST) {
            _inputs.at(element).insert({element2, 0});
            _outputs.at(element).insert({element2, 0});
        }
    }

    for (auto move : moves) {
        _inputs.at(move.source).at(move.gem)++;
        _outputs.at(move.destination).at(move.gem)++;
    }
}

int MoveMap::inputCount(const int sphereType, const int gemType) const {
  int count = 0;
  
  for (auto sphere : _inputs) {
    Element sphere2 = sphere.first;
    std::map<Element, int> gems = sphere.second;
    if (elementInSearch(sphere2, sphereType)) {
      for (auto gem : gems) {
        if (elementInSearch(gem.first, gemType)) {
          count += gem.second;
        }
      }
    }
  }

  return count;
}

int MoveMap::outputCount(const int sphereType, const int gemType) const {
  int count = 0;
  
  for (auto sphere : _outputs) {
    Element sphere2 = std::get<0>(sphere);
    std::map<Element, int> gems = std::get<1>(sphere);
    if (elementInSearch(sphere2, sphereType)) {
      for (auto gem : gems) {
        if (elementInSearch(std::get<0>(gem), gemType)) {
          count += std::get<1>(gem);
        }
      }
    }
  }

  return count;
}
