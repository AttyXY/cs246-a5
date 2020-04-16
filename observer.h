#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include "state.h"


template <typename TemplateType> class Subject;

template <typename TemplateType> class Observer {
    public:
        virtual void update(Subject<TemplateType> &whoFrom) = 0; // pass the Subject that called the notify method
        virtual ~Observer() = default;
};

#endif
