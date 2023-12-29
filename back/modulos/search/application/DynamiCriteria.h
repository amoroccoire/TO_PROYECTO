#ifndef DYNAMICRITERIA_H
#define DYNAMICRITERIA_H

#include "../../../../back/modulos/upload/nodeavl.h"

class DynamicCriteria {
public:
    virtual ~DynamicCriteria() {}
    virtual bool matches(PruebaCovid* node) const = 0;
};

#endif // DYNAMICRITERIA_H
