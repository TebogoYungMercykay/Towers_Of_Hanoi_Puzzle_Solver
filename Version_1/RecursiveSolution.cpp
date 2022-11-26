#include "RecursiveSolution.h"
#include <cmath>

template <class T>
RecursiveSolution<T>::RecursiveSolution(int startTower, int goalTower): TowersOfHanoi<T>(startTower, goalTower)
{}

template <class T>
void RecursiveSolution<T>::solveGame()
{
    if (this->validateGame() == true)
    {
        int  auxiliary = 6 - (this->startTower + this->goalTower);

        int even_odd = count() % 2;

        int n = count();
        int min = pow(2,n) - 1;
        solveGame(1,min, even_odd, auxiliary);
    }
    else
    {
        throw Exception<T>::invalidGame();
    }
}

template <class T>
int RecursiveSolution<T>::count()
{
    return countt1() + countt2() + countt3();
}

template <class T>
bool RecursiveSolution<T>::containsLabel(T label)
{
    bool flag = containsLabelt1(label);
    if (!flag)
    {
        flag = containsLabelt2(label);
        if (!flag)
        {
            flag = containsLabelt3(label);
        }
    }
    return flag;
}

template <class T>
void RecursiveSolution<T>::solveGame(int i, int n, int even_odd, int auxiliary)
{
    if (i <= n)
    {
        if (i%3 == 1)
        {
            if (even_odd == 0)
            {
                this->moveDisk(this->startTower, auxiliary);
            }
            else
            {
                this->moveDisk(this->startTower, this->goalTower);
            }
        }

        else if (i % 3 == 2)
        {
            if (even_odd == 0)
            {
                this->moveDisk(this->startTower, this->goalTower);
            }
            else
            {
                this->moveDisk(this->startTower, auxiliary);
            }
        }

        else if (i % 3 == 0)
        {
            if (even_odd == 0)
            {
                this->moveDisk(auxiliary, this->goalTower);
            }
            else
            {
                this->moveDisk(this->goalTower, auxiliary);
            }
        }
        solveGame(i+1, n, even_odd, auxiliary);
    }
}

template <class T>
int RecursiveSolution<T>::countt1()
{
    int count = 0;
    if (!TowersOfHanoi<T>::t1->empty())
    {
        Disk<T>* temp = TowersOfHanoi<T>::t1->top();
        TowersOfHanoi<T>::t1->pop();
        count = 1 + countt1();
        TowersOfHanoi<T>::t1->push(temp);
    }
    return count;
}

template <class T>
int RecursiveSolution<T>::countt2()
{
    int count = 0;
    if (!TowersOfHanoi<T>::t2->empty())
    {
        Disk<T>* temp = TowersOfHanoi<T>::t2->top();
        TowersOfHanoi<T>::t2->pop();
        count = 1 + countt2();
        TowersOfHanoi<T>::t2->push(temp);
    }
    return count;
}

template <class T>
int RecursiveSolution<T>::countt3()
{
    int count = 0;
    if (!TowersOfHanoi<T>::t3->empty())
    {
        Disk<T>* temp = TowersOfHanoi<T>::t3->top();
        TowersOfHanoi<T>::t3->pop();
        count = 1 + countt3();
        TowersOfHanoi<T>::t3->push(temp);
    }
    return count;
}

template <class T>
bool RecursiveSolution<T>::containsLabelt1(T label)
{
    bool flag = false;
    if (!TowersOfHanoi<T>::t1->empty())
    {
        Disk<T>* temp = TowersOfHanoi<T>::t1->top();
        TowersOfHanoi<T>::t1->pop();
        if (temp->getLabel() == label)
        {
            flag = true;
        }
        else
        {
            flag = containsLabelt1(label);
        }
        TowersOfHanoi<T>::t1->push(temp);
    }
    return flag;
}

template <class T>
bool RecursiveSolution<T>::containsLabelt2(T label)
{
    bool flag = false;
    if (!TowersOfHanoi<T>::t2->empty())
    {
        Disk<T>* temp = TowersOfHanoi<T>::t2->top();
        TowersOfHanoi<T>::t2->pop();
        if (temp->getLabel() == label)
        {
            flag = true;
        }
        else
        {
            flag = containsLabelt2(label);
        }
        TowersOfHanoi<T>::t2->push(temp);
    }
    return flag;
}

template <class T>
bool RecursiveSolution<T>::containsLabelt3(T label)
{
    bool flag = false;
    if (!TowersOfHanoi<T>::t3->empty())
    {
        Disk<T>* temp = TowersOfHanoi<T>::t3->top();
        TowersOfHanoi<T>::t3->pop();
        if (temp->getLabel() == label)
        {
            flag = true;
        }
        else
        {
            flag = containsLabelt3(label);
        }
        TowersOfHanoi<T>::t3->push(temp);
    }
    return flag;
}