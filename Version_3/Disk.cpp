#include "Disk.h"

template <class T>
Disk<T>::Disk(T label)
{
    this->label = label;
}

template <class T>
T Disk<T>::getLabel() const
{
    return this->label;
}