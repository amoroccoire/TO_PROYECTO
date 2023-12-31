#include "orcriteria.h"

OrCriteria::OrCriteria(DynamicCriteria* c1, DynamicCriteria* c2) {
    criteria1 = c1;
    criteria2 = c2;
}

bool OrCriteria::matches(PruebaCovid *node) const {
    return criteria1->matches(node) || criteria2->matches(node);
}
