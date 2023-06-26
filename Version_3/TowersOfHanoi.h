#ifndef TOH_H
#define TOH_H

#include <stack>

#include "Exception.h"
#include "Disk.h"
#include <cmath>

template <typename T>
class TowersOfHanoi
{
    protected:
        int startTower;
        int goalTower;
        TowersOfHanoi();
        std::stack<Disk<T>*>* t1;
        std::stack<Disk<T>*>* t2;
        std::stack<Disk<T>*>* t3;
    public:
        void moveDisk(int dep, int dest);
        TowersOfHanoi(int startTower, int goalTower);
        void addDisk(T diskData, int tower);
        bool validateGame();
        ~TowersOfHanoi();
        std::stack<Disk<T>*>* getTower(int tower);
        virtual void solveGame() = 0;
};

#endif