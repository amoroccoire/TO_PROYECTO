#ifndef ANDCRITERIA_H
#define ANDCRITERIA_H

#include "DynamiCriteria.h"

class AndCriteria : public DynamicCriteria{
public:
    AndCriteria(DynamicCriteria*, DynamicCriteria*);

    bool matches(PruebaCovid *node) const override;

private:
    DynamicCriteria* criteria1;
    DynamicCriteria* criteria2;
};

#endif // ANDCRITERIA_H
