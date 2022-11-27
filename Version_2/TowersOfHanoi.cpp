#include "TowersOfHanoi.h"
#include <cmath>

template <typename T>
TowersOfHanoi<T>::TowersOfHanoi(){}

template <typename T>
void TowersOfHanoi<T>::moveDisk(int dep, int dest){
    if (dep >= 1 && dep <=3 && dest >= 1 && dest <= 3 && dep != dest){
        if (TowersOfHanoi<T>::getTower(dep)->empty() && TowersOfHanoi<T>::getTower(dest)->empty()){
            Exception<T>::emptyStack(dep);
        }
        else if (TowersOfHanoi<T>::getTower(dest)->empty()){
            TowersOfHanoi<T>::getTower(dest)->push(TowersOfHanoi<T>::getTower(dep)->top());
            TowersOfHanoi<T>::getTower(dep)->pop();
            Exception<T>::movePlan(TowersOfHanoi<T>::getTower(dest)->top(),dep,dest);
        }
        else if (TowersOfHanoi<T>::getTower(dep)->empty()){
            TowersOfHanoi<T>::getTower(dep)->push(TowersOfHanoi<T>::getTower(dest)->top());
            TowersOfHanoi<T>::getTower(dest)->pop();
            Exception<T>::movePlan(TowersOfHanoi<T>::getTower(dest)->top(),dest,dep);
        }
        else{
            if (TowersOfHanoi<T>::getTower(dep)->top()->getLabel() < TowersOfHanoi<T>::getTower(dest)->top()->getLabel()){
                TowersOfHanoi<T>::getTower(dest)->push(TowersOfHanoi<T>::getTower(dep)->top());
                TowersOfHanoi<T>::getTower(dep)->pop();
                Exception<T>::movePlan(TowersOfHanoi<T>::getTower(dest)->top(),dep,dest);
            }
            else{
                TowersOfHanoi<T>::getTower(dep)->push(TowersOfHanoi<T>::getTower(dest)->top());
                TowersOfHanoi<T>::getTower(dest)->pop();
                Exception<T>::movePlan(TowersOfHanoi<T>::getTower(dep)->top(),dest,dep);
            }
        }
    }
    else{
        throw Exception<T>::incorrectDiskMove(dep,dest);
    }
}

template <typename T>
TowersOfHanoi<T>::TowersOfHanoi(int startTower, int goalTower){
    TowersOfHanoi<T>::startTower = startTower;
    TowersOfHanoi<T>::goalTower = goalTower;
    TowersOfHanoi<T>::t1 = new std::stack<Disk<T>*>();
    TowersOfHanoi<T>::t2 = new std::stack<Disk<T>*>();
    TowersOfHanoi<T>::t3 = new std::stack<Disk<T>*>();
}

template <typename T>
void TowersOfHanoi<T>::addDisk(T diskData, int tower){
    if (tower >= 1 && tower <= 3){
        if (TowersOfHanoi<T>::getTower(tower)->empty()) {
            TowersOfHanoi<T>::getTower(tower)->push(new Disk<T>(diskData));
        }
        else{
            if (diskData < TowersOfHanoi<T>::getTower(tower)->top()->getLabel()){
                TowersOfHanoi<T>::getTower(tower)->push(new Disk<T>(diskData));
            }
            else{
                throw Exception<T>::invalidTower(tower);
            }
        }
    }
    else{
        throw Exception<T>::invalidDiskAdd(tower, diskData);
    }
}
template <typename T>
bool TowersOfHanoi<T>::validateGame(){
    bool isValid = false;
    if (TowersOfHanoi<T>::startTower!=TowersOfHanoi<T>::goalTower && TowersOfHanoi<T>::startTower>0 && TowersOfHanoi<T>::startTower<4 && TowersOfHanoi<T>::goalTower>0 && TowersOfHanoi<T>::goalTower<4){
        if ((TowersOfHanoi<T>::startTower == 1 && !t1->empty() && t2->empty() && t3->empty()) || (TowersOfHanoi<T>::startTower == 2 && t1->empty() && !t2->empty() && t3->empty()) || (TowersOfHanoi<T>::startTower == 3 && t1->empty() && t2->empty() && !t3->empty())){
            isValid = true;
        }
    }
    return isValid;
}
template <typename T>
std::stack<Disk<T>*>* TowersOfHanoi<T>::getTower(int tower){
    if (tower == 1) return t1;
    else if (tower == 2) return t2;
    return t3;
}
template <typename T>
TowersOfHanoi<T>::~TowersOfHanoi(){
    delete t1;
    delete t2;
    delete t3;
}