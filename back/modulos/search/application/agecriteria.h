#ifndef AGECRITERIA_H
#define AGECRITERIA_H

#include "DynamiCriteria.h"

class AgeCriteria : public DynamicCriteria {
public:
    AgeCriteria(int, int);
    bool matches(PruebaCovid *node) const override;

    void setHasCriteria(bool);

private:
    int minAge;
    int maxAge;

    bool hasCriteria;

};

#endif // AGECRITERIA_H
