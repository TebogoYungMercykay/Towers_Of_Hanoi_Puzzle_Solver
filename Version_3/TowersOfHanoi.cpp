#include "TowersOfHanoi.h"
#include <cmath>

template <class T>
TowersOfHanoi<T>::TowersOfHanoi(){}

template <class T>
void TowersOfHanoi<T>::moveDisk(int dep, int dest)
{
    bool check1, check2, check3, check = (dep >= 1 && dep <=3 && dest >= 1 && dest <= 3 && dep != dest) == true;
    if (check)
    {
        check1 = (this->getTower(dep)->empty() && this->getTower(dest)->empty()) == true;
        check2 = (this->getTower(dest)->empty()) == true;
        check3 = (this->getTower(dep)->empty()) == true;
        if (check1)
        {
            Exception<T>::emptyStack(dep);
        }
        else if (check3)
        {
            this->getTower(dep)->push(this->getTower(dest)->top());
            this->getTower(dest)->pop();
            Exception<T>::movePlan(this->getTower(dest)->top(),dest,dep);
        }
        else if (check2)
        {
            this->getTower(dest)->push(this->getTower(dep)->top());
            this->getTower(dep)->pop();
            Exception<T>::movePlan(this->getTower(dest)->top(),dep,dest);
        }
        else
        {
            check3 = (this->getTower(dep)->top()->getLabel() < this->getTower(dest)->top()->getLabel());
            if (!check3)
            {
                this->getTower(dep)->push(this->getTower(dest)->top());
                this->getTower(dest)->pop();
                Exception<T>::movePlan(this->getTower(dep)->top(),dest,dep);
            }
            else
            {
                this->getTower(dest)->push(this->getTower(dep)->top());
                this->getTower(dep)->pop();
                Exception<T>::movePlan(this->getTower(dest)->top(),dep,dest);
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
    this->t1 = new std::stack<Disk<T>*>();
    this->t2 = new std::stack<Disk<T>*>();
    this->t3 = new std::stack<Disk<T>*>();
}

template <class T>
void TowersOfHanoi<T>::addDisk(T diskData, int tower)
{
    bool check = (tower >= 1 && tower <= 3) == true;
    if (check)
    {
        if (this->getTower(tower)->empty()) {
            this->getTower(tower)->push(new Disk<T>(diskData));
        }
        else
        {
            check = (diskData < this->getTower(tower)->top()->getLabel()) == true;
            if (check)
            {
                this->getTower(tower)->push(new Disk<T>(diskData));
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
    return ((this->startTower!=this->goalTower && this->startTower>0 && this->startTower<4 && this->goalTower>0 && this->goalTower<4) && ((this->startTower == 1 && !t1->empty() && t2->empty() && t3->empty()) || (this->startTower == 2 && t1->empty() && !t2->empty() && t3->empty()) || (this->startTower == 3 && t1->empty() && t2->empty() && !t3->empty()))) == true;
}
template <class T>
std::stack<Disk<T>*>* TowersOfHanoi<T>::getTower(int tower)
{
    std::stack<Disk<T>*>* temp = t3;
    if (tower == 1) temp = t1;
    else if (tower == 2) temp = t2;
    return temp;
}
template <class T>
TowersOfHanoi<T>::~TowersOfHanoi()
{
    delete t1;
    delete t2;
    delete t3;
}