#include "RecursiveSolution.h"
#include <cmath>

template <typename T>
RecursiveSolution<T>::RecursiveSolution(int startTower, int goalTower): TowersOfHanoi<T>(startTower, goalTower){}
template <typename T>
void RecursiveSolution<T>::solveGame(){
    if (this->validateGame() == true){
        int n = count();
        solveGame(1 ,(pow(2, n) - 1), n, (6 - (this->startTower + this->goalTower)));
    }
    else{
        throw Exception<T>::invalidGame();
    }
}
template <typename T>
int RecursiveSolution<T>::count(){
    int temp = count(1) + count(2) + count(3);
    return temp;
}
template <typename T>
bool RecursiveSolution<T>::containsLabel(T label){
    bool temp = (containsLabel(label, 1) == false && containsLabel(label, 2) == false && containsLabel(label, 3) == false);
    if (temp == true){
        return false;
    }
    return true;
}
template <typename T>
void RecursiveSolution<T>::solveGame(int i, int min, int n, int auxiliary){
    if (i <= min){
        if (i % 3 == 0){
            if (n == 0){
                RecursiveSolution<T>::moveDisk(auxiliary, RecursiveSolution<T>::goalTower);
            }
            else{
                RecursiveSolution<T>::moveDisk(RecursiveSolution<T>::goalTower, auxiliary);
            }
        }
        else if (i % 3 == 1){
            if (n == 0){
                RecursiveSolution<T>::moveDisk(RecursiveSolution<T>::startTower, auxiliary);
            }
            else{
                RecursiveSolution<T>::moveDisk(RecursiveSolution<T>::startTower, RecursiveSolution<T>::goalTower);
            }
        }
        else if (i % 3 == 2){
            if (n == 0){
                RecursiveSolution<T>::moveDisk(RecursiveSolution<T>::startTower, RecursiveSolution<T>::goalTower);
            }
            else{
                RecursiveSolution<T>::moveDisk(RecursiveSolution<T>::startTower, auxiliary);
            }
        }
        solveGame(i+1, min, n, auxiliary);
    }
}
template <typename T>
int RecursiveSolution<T>::count(int tower){
    int counter = 0;
    if(tower == 1){
        if (TowersOfHanoi<T>::t1->empty() == false){
            Disk<T>* temp = TowersOfHanoi<T>::t1->top();
            TowersOfHanoi<T>::t1->pop();
            counter = 1 + count(1);
            TowersOfHanoi<T>::t1->push(temp);
        }
    }
    else if(tower == 2){
        if (TowersOfHanoi<T>::t2->empty() == false){
            Disk<T>* temp = TowersOfHanoi<T>::t2->top();
            TowersOfHanoi<T>::t2->pop();
            counter = 1 + count(2);
            TowersOfHanoi<T>::t2->push(temp);
        }
    }
    else{
        if (TowersOfHanoi<T>::t3->empty() == false){
            Disk<T>* temp = TowersOfHanoi<T>::t3->top();
            TowersOfHanoi<T>::t3->pop();
            counter = 1 + count(3);
            TowersOfHanoi<T>::t3->push(temp);
        }
    }
    return counter;
}
template <typename T>
bool RecursiveSolution<T>::containsLabel(T label, int tower){
    if(tower == 1){
        bool foundLabel = false;
        if (TowersOfHanoi<T>::t1->empty() == false){
            Disk<T>* temp = TowersOfHanoi<T>::t1->top();
            TowersOfHanoi<T>::t1->pop();
            if (temp->getLabel() == label){
                foundLabel = true;
            }
            else{
                foundLabel = containsLabel(label, 1);
            }
            TowersOfHanoi<T>::t1->push(temp);
        }
        return foundLabel;
    }
    else if(tower == 2){
        bool foundLabel = false;
        if (TowersOfHanoi<T>::t2->empty() == false){
            Disk<T>* temp = TowersOfHanoi<T>::t2->top();
            TowersOfHanoi<T>::t2->pop();
            if (temp->getLabel() == label){
                foundLabel = true;
            }
            else{
                foundLabel = containsLabel(label, 2);
            }
            TowersOfHanoi<T>::t2->push(temp);
        }
        return foundLabel;
    }
    else {
        bool foundLabel = false;
        if (TowersOfHanoi<T>::t3->empty() == false){
            Disk<T>* temp = TowersOfHanoi<T>::t3->top();
            TowersOfHanoi<T>::t3->pop();
            if (temp->getLabel() == label){
                foundLabel = true;
            }
            else{
                foundLabel = containsLabel(label, 3);
            }
            TowersOfHanoi<T>::t3->push(temp);
        }
        return foundLabel;
    }
}