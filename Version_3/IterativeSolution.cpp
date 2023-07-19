#include "IterativeSolution.h"
#include <cmath>

template <class T>
IterativeSolution<T>::IterativeSolution(int startTower, int goalTower): TowersOfHanoi<T>(startTower, goalTower){}

template <class T>
void IterativeSolution<T>::solveGame(){
    bool pole = (this->validateGame() == true);
    if (pole){
        int s1 = this->t1->size();
        int s2 = this->t2->size();
        int s3 = this->t3->size();
        int numMoves = s1 + s2 + s3;
        s1 = (pow(2, numMoves) - 1);
        this->moves(s1);
    } else{
        throw Exception<T>::invalidGame();
    }
}

template <class T>
void IterativeSolution<T>::moves(int numMoves){
    int aux = (this->startTower + this->goalTower);
    int n = this->t1->size() + this->t2->size() + this->t3->size();
    int min = pow(2,n) - 1;
    if (numMoves < 0) 
    {
        throw Exception<T>::invalidMoves(numMoves);
    } else {
        if (numMoves < min) 
        {
            min = numMoves;
        }
        if (this->validateGame() == false) 
        {
            throw Exception<T>::invalidGame();
        } else {
            int i = 1;
            while (i < min + 1) 
            {
                bool pole = (i % 3 == 2);
                bool pole2 = (i % 3 == 0);
                bool pole3 = (i % 3 == 1);
                bool even = ((n % 2) == 0);
                if (pole) 
                {
                    if (!even == false) 
                    {
                        this->moveDisk(this->startTower, this->goalTower);
                    } else {
                        this->moveDisk(this->startTower, (6 - aux));
                    }
                } else if (pole3) {
                    if (!even == false) 
                    {
                        this->moveDisk(this->startTower, (6 - aux));
                    } else {
                        this->moveDisk(this->startTower, this->goalTower);
                    }
                } else if (pole2) {
                    if (!even == false) 
                    {
                        this->moveDisk((6 - aux), this->goalTower);
                    } else {
                        this->moveDisk(this->goalTower, (6 - aux));
                    }
                }
                i = i + 1;
            }
        }
    }
}