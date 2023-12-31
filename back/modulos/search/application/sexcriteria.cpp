#include "sexcriteria.h"

SexCriteria::SexCriteria(bool isMale) {
    this->isMale = isMale;
    this->hasCriteria = true;
}

bool SexCriteria::matches(PruebaCovid *node) const {
    if(!hasCriteria)
        return true;

    return node->getSexo() == isMale; //true:hombre, false:femenino
}

void SexCriteria::setHasCriteria(bool hasCriteria) {
    this->hasCriteria = hasCriteria;
}
