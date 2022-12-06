#ifndef DISK_H
#define DISK_H

template <typename T>
class Disk
{
    private:
        T label;
    public:
        Disk(T label);
        T getLabel() const;
};

#endif