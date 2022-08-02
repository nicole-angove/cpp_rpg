#ifndef ELEMENT_H
#define ELEMENT_H

#include <vector>

enum Element {
  FIRE=0b10000,
  WATER=0b01000,
  EARTH=0b00100,
  SPIRIT=0b00010,
  LIGHTNING=0b00001,
  ALL=Element::FIRE | Element::WATER | Element::EARTH | Element::SPIRIT | Element::LIGHTNING,
};

const std::vector<Element> ELEMENTLIST = {Element::FIRE, Element::WATER, Element::LIGHTNING, Element::EARTH, Element::SPIRIT};

bool elementInSearch(const Element, const int);

#endif