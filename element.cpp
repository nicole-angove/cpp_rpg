#include "element.h"


bool elementInSearch(Element element, int searchMask) {
    return ((element & searchMask) == element);
}
