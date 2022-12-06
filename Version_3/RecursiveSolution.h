#ifndef RS_H
#define RS_H

#include <stack>

#include "TowersOfHanoi.h"
#include "Disk.h"
#include <cmath>

template <typename T>
class RecursiveSolution: public TowersOfHanoi<T>
{
    private:
        void solveGame(int i, int min, int n, int auxiliary);
        int count(int tower);
        bool containsLabel(T label, int tower);
    public:
        RecursiveSolution(int startTower, int goalTower);
        void solveGame();
        int count();
        bool containsLabel(T label);
};

#endif