#include "sphere.h"

Sphere::Sphere() {
  for (Element element : ELEMENTLIST) {
    insert({element, 0});
  }
}

Sphere::Sphere(std::map<Element, int> gems) {
  for (Element element : ELEMENTLIST) {
    if (gems.find(element) != gems.end())
      insert({element, gems.at(element)});
    else
      insert({element, 0});
  }
}

Sphere::Sphere(std::vector<Element> gems) {
  for (Element element : ELEMENTLIST) {
    insert({element, 0});
  }
  for (auto gem : gems) {
    at(gem)++;
  }
}

bool Sphere::equal(Sphere compare) const {
  for (auto gemTypeItr = this -> begin(); gemTypeItr != this -> end(); gemTypeItr++) {
    if (gemTypeItr -> second != compare.at(gemTypeItr -> first))
      return false;
  }

  for (auto gemType : compare) {
    if (gemType.second != at(gemType.first))
      return false;
  }

  return true;
}

int Sphere::count(int gemType) const {
  int count = 0;
  for (auto element : ELEMENTLIST) {
    if (elementInSearch(element, gemType)) {
      count = count + at(element);
    }
  }
  return count;
}

