#ifndef ORCRITERIA_H
#define ORCRITERIA_H

#include "DynamiCriteria.h"

class OrCriteria : public DynamicCriteria{
public:
    OrCriteria(DynamicCriteria*, DynamicCriteria*);

    bool matches(PruebaCovid *node) const override;

private:
    DynamicCriteria* criteria1;
    DynamicCriteria* criteria2;
};

#endif // ORCRITERIA_H
