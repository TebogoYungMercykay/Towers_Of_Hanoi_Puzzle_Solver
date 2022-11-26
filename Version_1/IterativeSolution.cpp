#include "IterativeSolution.h"
#include <cmath>

template <class T>
IterativeSolution<T>::IterativeSolution(int startTower, int goalTower): TowersOfHanoi<T>(startTower, goalTower)
{

}

template <class T>
void IterativeSolution<T>::solveGame()
{
    if (this->validateGame() == true)
    {
        int  auxiliary = 6 - (this->startTower + this->goalTower);
        std::stack<Disk<T>*>* source = this->getTower(this->startTower);

        int n = this->t1->size() + this->t2->size() + this->t3->size();
        int even_odd = n % 2;
        int min = pow(2,n) - 1;
        
        for (int i = 1; i <= min; i++)
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
        }
    }
    else
    {
        throw Exception<T>::invalidGame();
    }
}

template <class T>
void IterativeSolution<T>::moves(int numMoves)
{
    int  auxiliary = 6 - (this->startTower + this->goalTower);
    std::stack<Disk<T>*>* source = this->getTower(this->startTower);
    int n = this->t1->size() + this->t2->size() + this->t3->size();
    int even_odd = n % 2;
    
    int min = pow(2,n) - 1;
    
    if (numMoves < 0)
    {
        throw Exception<T>::invalidMoves(numMoves);
    }
    else
    {
        
        if (min > numMoves)
        {
            min = numMoves;
        }

        if (this->validateGame() == true)
        {
            for (int i = 1; i <= min; i++)
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
            }
        }
        else
        {
            throw Exception<T>::invalidGame();
        }
    }
}