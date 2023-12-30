#include "agecriteria.h"

AgeCriteria::AgeCriteria(int min, int max) {
    this->minAge = min;
    this->maxAge = max,
    this->hasCriteria = true;
}

bool AgeCriteria::matches(PruebaCovid *node) const {
    if (!hasCriteria)
        return true;
    return node->getEdad() >= minAge && node->getEdad() <= maxAge;
}

void AgeCriteria::setHasCriteria(bool hasCriteria) {
    this->hasCriteria = hasCriteria;
}
