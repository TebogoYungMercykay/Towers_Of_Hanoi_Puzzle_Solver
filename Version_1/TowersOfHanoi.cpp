#include "TowersOfHanoi.h"

template <class T>
TowersOfHanoi<T>::TowersOfHanoi()
{
    t1 = new std::stack<Disk<T>*>();
    t2 = new std::stack<Disk<T>*>();
    t3 = new std::stack<Disk<T>*>();
    this->startTower = 0;
    this->goalTower = 0;
}

template <class T>
void TowersOfHanoi<T>::moveDisk(int dep, int dest)
{
    if (dep > 0 && dep <=3 && dest > 0 && dest <= 3 && dep != dest)
    {
        std::stack<Disk<T>*>* depDist;
        std::stack<Disk<T>*>* destDist;
        if (dep == 1)  depDist = t1;
        else if (dep == 2) depDist = t2;
        else depDist = t3;
        if (dest == 1) destDist = t1;
        else if (dest == 2) destDist = t2;
        else destDist = t3;

        if (depDist->empty() && destDist->empty())
        {
            Exception<T>::emptyStack(dep);
        }
        else if (depDist->empty())
        {
            depDist->push(destDist->top());
            destDist->pop();
            Exception<T>::movePlan(depDist->top(),dest,dep);
        }
        else if (destDist->empty())
        {
            destDist->push(depDist->top());
            depDist->pop();
            Exception<T>::movePlan(destDist->top(),dep,dest);
        }
        else
        {
            if (depDist->top()->getLabel() < destDist->top()->getLabel())
            {
                destDist->push(depDist->top());
                depDist->pop();
                Exception<T>::movePlan(destDist->top(),dep,dest);
            }
            else
            {
                depDist->push(destDist->top());
                destDist->pop();
                Exception<T>::movePlan(depDist->top(),dest,dep);
            }
        }
    }
    else
    {
        throw Exception<T>::incorrectDiskMove(dep,dest);
    }
}

template <class T>
TowersOfHanoi<T>::TowersOfHanoi(int startTower, int goalTower)
{
    this->startTower = startTower;
    this->goalTower = goalTower;
    t1 = new std::stack<Disk<T>*>();
    t2 = new std::stack<Disk<T>*>();
    t3 = new std::stack<Disk<T>*>();
}

template <class T>
void TowersOfHanoi<T>::addDisk(T diskData, int tower)
{
    if (tower > 0 && tower <=3 )
    {
        std::stack<Disk<T>*>* dist;
        if (tower == 1)  dist = t1;
        else if (tower == 2) dist = t2;
        else dist = t3;

        if (dist->empty()) 
        {
            dist->push(new Disk<T>(diskData));
        }
        else
        {
            if (diskData < dist->top()->getLabel())
            {
                dist->push(new Disk<T>(diskData));
            }
            else
            {
                throw Exception<T>::invalidTower(tower);
            }
        }
    }
    else
    {
        throw Exception<T>::invalidDiskAdd(tower, diskData);
    }
}

template <class T>
bool TowersOfHanoi<T>::validateGame()
{
    if (this->startTower != this->goalTower && this->startTower > 0 && this->startTower < 4 
    && this->goalTower > 0 && this->goalTower < 4)
    {
        if (this->startTower == 1 && !t1->empty() && t2->empty() && t3->empty())
        {
            return true;
        }
        else if (this->startTower == 2 && t1->empty() && !t2->empty() && t3->empty())
        {
            return true;
        }

        else if (this->startTower == 3 && t1->empty() && t2->empty() && !t3->empty())
        {
            return true;
        }
    }
    return false;
}

template <class T>
TowersOfHanoi<T>::~TowersOfHanoi()
{
    delete t1;
    delete t2;
    delete t3;
}

template <class T>
std::stack<Disk<T>*>* TowersOfHanoi<T>::getTower(int tower)
{
    if (tower == 1)
    {
        return t1;
    }
    else if (tower == 2)
    {
        return t2;
    }
    else
    {
        return t3;
    }
}