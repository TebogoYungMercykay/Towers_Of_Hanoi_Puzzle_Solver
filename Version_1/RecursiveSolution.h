#ifndef RS_H
#define RS_H

#include <stack>

#include "TowersOfHanoi.h"
#include "Disk.h"

template <class T>
class RecursiveSolution: public TowersOfHanoi<T>
{
private:
    void solveGame(int i, int n, int even_odd, int auxiliary);
    int countt1();
    int countt2();
    int countt3();
    bool containsLabelt1(T label);
    bool containsLabelt2(T label);
    bool containsLabelt3(T label);
public:
    RecursiveSolution(int startTower, int goalTower);
    void solveGame();
    int count();
    bool containsLabel(T label);
};

#endif