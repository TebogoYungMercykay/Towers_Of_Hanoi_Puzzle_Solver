#ifndef DISK_H
#define DISK_H

template <class T>
class Disk
{
private:
    T label;
public:
    Disk(T label);
    T getLabel() const;
};

#endif