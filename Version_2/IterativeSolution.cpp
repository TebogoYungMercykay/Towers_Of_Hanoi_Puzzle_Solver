#include "IterativeSolution.h"
#include <cmath>

template <typename T>
IterativeSolution<T>::IterativeSolution(int startTower, int goalTower): TowersOfHanoi<T>(startTower, goalTower){}

template <typename T>
void IterativeSolution<T>::solveGame(){
    if (IterativeSolution<T>::validateGame() == true){
        int numMoves = IterativeSolution<T>::t1->size() + IterativeSolution<T>::t2->size() + IterativeSolution<T>::t3->size();
        try{
            IterativeSolution<T>::moves((pow(2, numMoves) - 1));
        }
        catch(Exception<T>* e){
            throw e;
        }
    }
    else{
        throw Exception<T>::invalidGame();
    }
}

template <typename T>
void IterativeSolution<T>::moves(int numMoves){
    int aux = (IterativeSolution<T>::startTower + IterativeSolution<T>::goalTower);
    int n = IterativeSolution<T>::t1->size() + IterativeSolution<T>::t2->size() + IterativeSolution<T>::t3->size();
    int min = pow(2,n) - 1;
    if (numMoves < 0) {
        throw Exception<T>::invalidMoves(numMoves);
    }
    else {
        if (numMoves < min) {
            min = numMoves;
        }
        if (IterativeSolution<T>::validateGame() == false) {
            throw Exception<T>::invalidGame();
        }
        else {
            int i = 1;
            for (; i <= min; ) {
                if (i%3 == 1) {
                    if ((n % 2) == 0) {
                        IterativeSolution<T>::moveDisk(IterativeSolution<T>::startTower, (6 - aux));
                    }
                    else {
                        IterativeSolution<T>::moveDisk(IterativeSolution<T>::startTower, IterativeSolution<T>::goalTower);
                    }
                }
                else if (i % 3 == 2) {
                    if ((n % 2) == 0) {
                        IterativeSolution<T>::moveDisk(IterativeSolution<T>::startTower, IterativeSolution<T>::goalTower);
                    }
                    else {
                        IterativeSolution<T>::moveDisk(IterativeSolution<T>::startTower, (6 - aux));
                    }
                }
                else if (i % 3 == 0) {
                    if ((n % 2) == 0) {
                        IterativeSolution<T>::moveDisk((6 - aux), IterativeSolution<T>::goalTower);
                    }
                    else {
                        IterativeSolution<T>::moveDisk(IterativeSolution<T>::goalTower, (6 - aux));
                    }
                }
                i += 1;
            }
        }
    }
}