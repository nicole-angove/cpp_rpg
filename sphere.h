#ifndef SPHERE_H
#define SPHERE_H

#include <map>

#include "element.h"


/**
 * @brief 
 * 
 */
class Sphere : public std::map<Element, int> {
    public:
    Sphere();
    Sphere(std::map<Element, int>);
    Sphere(std::vector<Element>);

    bool equal(Sphere) const;
    int count(int gemType = Element::ALL) const;
};


#endif
