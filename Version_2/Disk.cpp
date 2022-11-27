#include "Disk.h"

template <class T>
Disk<T>::Disk(T label)
{
    Disk<T>::label = label;
}

template <class T>
T Disk<T>::getLabel() const
{
    return this->label;
}