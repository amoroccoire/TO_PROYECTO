#ifndef SEXCRITERIA_H
#define SEXCRITERIA_H

#include "DynamiCriteria.h"

class SexCriteria : public DynamicCriteria{
public:
    SexCriteria(bool);

    bool matches(PruebaCovid *node) const override;
    void setHasCriteria(bool);

private:
    bool isMale;
    bool hasCriteria;
};

#endif // SEXCRITERIA_H
