#include "andcriteria.h"

AndCriteria::AndCriteria(DynamicCriteria* c1, DynamicCriteria* c2) {
    criteria1 = c1;
    criteria2 = c2;
}

bool AndCriteria::matches(PruebaCovid *node) const {
    return criteria1->matches(node) && criteria2->matches(node);
}
