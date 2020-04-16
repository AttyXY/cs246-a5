#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "state.h"


template <typename TemplateType> class Observer;

template <typename TemplateType> class Subject {
    std::vector<Observer<TemplateType>*> observers;
    TemplateType state;

    public:
        void attach(Observer<TemplateType> *o);
        void notify();

        void setState(TemplateType newS);
        TemplateType getState() const;
};

template <typename TemplateType>
void Subject<TemplateType>::attach(Observer<TemplateType> *o) {
    observers.emplace_back(o);
}

template <typename TemplateType>
void Subject<TemplateType>::notify() {
    for (auto &ob : observers) ob->update(*this);
}

template <typename TemplateType>
void Subject<TemplateType>::setState(TemplateType newS) {
    state = newS;
}

template <typename TemplateType>
TemplateType Subject<TemplateType>::getState() const {
    return state;
}

#endif
