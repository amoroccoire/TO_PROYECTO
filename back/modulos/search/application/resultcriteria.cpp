#include "resultcriteria.h"

ResultCriteria::ResultCriteria(bool result) {
    this->result = result;
    this->hasCriteria = true;
}

bool ResultCriteria::matches(PruebaCovid *node) const {
    if (!hasCriteria)
        return true;
    return node->getResultado() == result;
}
void ResultCriteria::setHasCriteria(bool has) {
    this->hasCriteria = has;
}
