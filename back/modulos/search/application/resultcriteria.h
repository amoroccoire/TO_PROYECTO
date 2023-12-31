#ifndef RESULTCRITERIA_H
#define RESULTCRITERIA_H

#include "DynamiCriteria.h"

class ResultCriteria : public DynamicCriteria{
public:
    ResultCriteria(bool);
    bool matches(PruebaCovid *node) const override;
    void setHasCriteria(bool);

private:
    bool hasCriteria;
    bool result;
};

#endif // RESULTCRITERIA_H
