#include <iostream>
#include <string>

#include "Exception.h"
#include "Disk.cpp"
#include "TowersOfHanoi.cpp"
#include "IterativeSolution.cpp"
#include "RecursiveSolution.cpp"

using namespace std;

template <class T>
void printStack(stack<Disk<T>*>* s)
{
    // If stack is empty then return
    if (s->empty())
        return;
 
    Disk<T>* x = s->top();
 
    // Pop the top element of the stack
    s->pop();
 
    // Recursively call the function PrintStack
    printStack(s);
 
    // Print the stack element starting
    // from the bottom
    cout << x->getLabel() << "\n";
 
    // Push the same element onto the stack
    // to preserve the order
    s->push(x);
}
static void Josh_Main(){

    cout << "Let's create a new game, shall we?" << endl;
    TowersOfHanoi<int>* gameOne = new IterativeSolution<int>(1,3);
    cout << "Adding disks" << endl;
    gameOne->addDisk(5,1);
    gameOne->addDisk(4,1);
    gameOne->addDisk(3,1);
    gameOne->addDisk(2,1);
    

    cout << "Is the game valid?" << endl;
    if (gameOne->validateGame())
        cout << "   Yeah, it is valid" << endl << endl;
    else
        cout << "   Nope. The game is not valid" << endl << endl;
    
    cout << "Let me add just one more disk" << endl;
    try { 
        gameOne->addDisk(6,1);
    } catch (Exception<int>* e) {
        cout << e->message << endl << endl;
    }

    cout << "Printing disks in the game" << endl;
    for (int i = 1; i <= 3; i++)
    {   
        cout << "Tower " << i << endl;
        printStack(gameOne->getTower(i));
    }
    cout << endl;

    cout << "SOLVE GAME: "  << endl;  
    try {
        gameOne->solveGame();
    } catch (Exception<int>* e)
    {
        cout << e->message << endl;
    }
    cout << endl;

    cout << "Printing disks in the game" << endl;
    for (int i = 1; i <= 3; i++)
    {   
        cout << "Tower " << i << endl;
        printStack(gameOne->getTower(i));
    }
    cout << endl;
}

void one()
{
    cout << "ONE\n";
    IterativeSolution<int>* itr = new IterativeSolution<int>(1,3);
    itr->addDisk(1,1);
    itr->moves(1);

    std::stack<Disk<int>*>* t1 = itr->getTower(1);
    if (t1->empty())
    {
        cout << "Correct\n";
    }
    else
    {
        cout << "Incorrect\n";
    }

    std::stack<Disk<int>*>* t2 = itr->getTower(2);
    if (t2->empty())
    {
        cout << "Correct\n";
    }
    else
    {
        cout << "Incorrect\n";
    }

    std::stack<Disk<int>*>* t3 = itr->getTower(3);
    if (!t3->empty())
    {
        cout << "Correct\n";
        std::stack<Disk<int>*>* clone = new std::stack<Disk<int>*>(*t3);
        while (!clone->empty())
        {
            cout << clone->top()->getLabel() << " ";
            clone->pop();
        }
        cout << endl;
    }
    else
    {
        cout << "Incorrect\n";
    }

    delete itr;
    cout << "---------------------------------\n";
}

void two()
{
    cout << "TWO\n";
    for (int i = 1; i <= 3; i++)
    {
        cout << "---------ITERATION "<< i << "-------------" << endl;
        IterativeSolution<int>* itr = new IterativeSolution<int>(1,3);
        itr->addDisk(2,1);
        itr->addDisk(1,1);
        itr->moves(i);
        std::stack<Disk<int>*>* t1 = itr->getTower(1);
        std::stack<Disk<int>*>* clone = new std::stack<Disk<int>*>(*t1);
        cout << "t1: ";
        while (!clone->empty())
        {
            cout << clone->top()->getLabel() << " ";
            clone->pop();
        }
        cout << endl;
        delete clone;
        std::stack<Disk<int>*>* t2 = itr->getTower(2);
        clone = new std::stack<Disk<int>*>(*t2);
        cout << "t2: ";
        while (!clone->empty())
        {
            cout << clone->top()->getLabel() << " ";
            clone->pop();
        }
        cout << endl;

        delete clone;
        std::stack<Disk<int>*>* t3 = itr->getTower(3);
        clone = new std::stack<Disk<int>*>(*t3);
        cout << "t3: ";
        while (!clone->empty())
        {
            cout << clone->top()->getLabel() << " ";
            clone->pop();
        }
        cout << endl;
        delete itr;
    }
    cout << "---------------------------------\n";
}

void four()
{
    cout << "FOUR\n";
    for (int i = 1; i <= 15; i++)
    {
        cout << "---------ITERATION "<< i << "-------------" << endl;
        IterativeSolution<int>* itr = new IterativeSolution<int>(1,3);
        itr->addDisk(4,1);
        itr->addDisk(3,1);
        itr->addDisk(2,1);
        itr->addDisk(1,1);
        itr->moves(i);
        std::stack<Disk<int>*>* t1 = itr->getTower(1);
        std::stack<Disk<int>*>* clone = new std::stack<Disk<int>*>(*t1);
        cout << "t1: ";
        while (!clone->empty())
        {
            cout << clone->top()->getLabel() << " ";
            clone->pop();
        }
        cout << endl;
        delete clone;
        std::stack<Disk<int>*>* t2 = itr->getTower(2);
        clone = new std::stack<Disk<int>*>(*t2);
        cout << "t2: ";
        while (!clone->empty())
        {
            cout << clone->top()->getLabel() << " ";
            clone->pop();
        }
        cout << endl;

        delete clone;
        std::stack<Disk<int>*>* t3 = itr->getTower(3);
        clone = new std::stack<Disk<int>*>(*t3);
        cout << "t3: ";
        while (!clone->empty())
        {
            cout << clone->top()->getLabel() << " ";
            clone->pop();
        }
        cout << endl;
        delete itr;
    }
    cout << "---------------------------------\n";
}

void five()
{
    cout << "FIVE\n";
    for (int i = 1; i <= 31; i++)
    {
        cout << "---------ITERATION "<< i << "-------------" << endl;
        IterativeSolution<int>* itr = new IterativeSolution<int>(1,2);
        itr->addDisk(5,1);
        itr->addDisk(4,1);
        itr->addDisk(3,1);
        itr->addDisk(2,1);
        itr->addDisk(1,1);
        itr->moves(i);
        std::stack<Disk<int>*>* t1 = itr->getTower(1);
        std::stack<Disk<int>*>* clone = new std::stack<Disk<int>*>(*t1);
        cout << "t1: ";
        while (!clone->empty())
        {
            cout << clone->top()->getLabel() << " ";
            clone->pop();
        }
        cout << endl;
        delete clone;
        std::stack<Disk<int>*>* t2 = itr->getTower(2);
        clone = new std::stack<Disk<int>*>(*t2);
        cout << "t2: ";
        while (!clone->empty())
        {
            cout << clone->top()->getLabel() << " ";
            clone->pop();
        }
        cout << endl;

        delete clone;
        std::stack<Disk<int>*>* t3 = itr->getTower(3);
        clone = new std::stack<Disk<int>*>(*t3);
        cout << "t3: ";
        while (!clone->empty())
        {
            cout << clone->top()->getLabel() << " ";
            clone->pop();
        }
        cout << endl;
        delete itr;
    }
    cout << "---------------------------------\n";
}

void six()
{
    cout << "SIX\n";
    for (int i = 1; i <= 63; i++)
    {
        cout << "---------ITERATION "<< i << "-------------" << endl;
        IterativeSolution<int>* itr = new IterativeSolution<int>(1,2);
        itr->addDisk(6,1);
        itr->addDisk(5,1);
        itr->addDisk(4,1);
        itr->addDisk(3,1);
        itr->addDisk(2,1);
        itr->addDisk(1,1);
        itr->moves(i);
        // std::stack<Disk<int>*>* t1 = itr->getTower(1);
        // std::stack<Disk<int>*>* clone = new std::stack<Disk<int>*>(*t1);
        // cout << "t1: ";
        // while (!clone->empty())
        // {
        //     cout << clone->top()->getLabel() << " ";
        //     clone->pop();
        // }
        // cout << endl;
        // delete clone;
        // std::stack<Disk<int>*>* t2 = itr->getTower(2);
        // clone = new std::stack<Disk<int>*>(*t2);
        // cout << "t2: ";
        // while (!clone->empty())
        // {
        //     cout << clone->top()->getLabel() << " ";
        //     clone->pop();
        // }
        // cout << endl;

        // delete clone;
        // std::stack<Disk<int>*>* t3 = itr->getTower(3);
        // clone = new std::stack<Disk<int>*>(*t3);
        // cout << "t3: ";
        // while (!clone->empty())
        // {
        //     cout << clone->top()->getLabel() << " ";
        //     clone->pop();
        // }
        // cout << endl;
        delete itr;
        cout << "---------------------------------\n";
    }
    cout << "--------------END-----------------\n";
}

void test1()
{
    cout << "TEST ONE\n";
    cout << "---------------------------------\n";
    for (int i = 1; i <= 7; i++)
    {
        cout << "---------ITERATION "<< i << "-------------" << endl;
        IterativeSolution<int>* itr = new IterativeSolution<int>(1,3);
        itr->addDisk(3,1);
        itr->addDisk(2,1);
        itr->addDisk(1,1);
        itr->moves(i);
        std::stack<Disk<int>*>* t1 = itr->getTower(1);
        std::stack<Disk<int>*>* clone = new std::stack<Disk<int>*>(*t1);
        cout << "t1: ";
        while (!clone->empty())
        {
            cout << clone->top()->getLabel() << " ";
            clone->pop();
        }
        cout << endl;
        delete clone;
        std::stack<Disk<int>*>* t2 = itr->getTower(2);
        clone = new std::stack<Disk<int>*>(*t2);
        cout << "t2: ";
        while (!clone->empty())
        {
            cout << clone->top()->getLabel() << " ";
            clone->pop();
        }
        cout << endl;

        delete clone;
        std::stack<Disk<int>*>* t3 = itr->getTower(3);
        clone = new std::stack<Disk<int>*>(*t3);
        cout << "t3: ";
        while (!clone->empty())
        {
            cout << clone->top()->getLabel() << " ";
            clone->pop();
        }
        cout << endl;
        delete itr;
    }
    cout << "---------------------------------\n";
}

void test2()
{
    cout << "TEST TWO\n";
    cout << "---------------------------------\n";
    IterativeSolution<int>* itr = new IterativeSolution<int>(1,3);
    itr->addDisk(3,1);
    itr->addDisk(2,1);
    itr->addDisk(1,1);
    itr->solveGame();
    std::stack<Disk<int>*>* t1 = itr->getTower(1);
    if (t1->empty())
    {
        cout << "Correct\n";
    }
    else
    {
        cout << "Incorrect\n";
    }

    std::stack<Disk<int>*>* t2 = itr->getTower(2);
    if (t2->empty())
    {
        cout << "Correct\n";
    }
    else
    {
        cout << "Incorrect\n";
    }

    std::stack<Disk<int>*>* t3 = itr->getTower(3);
    if (!t3->empty())
    {
        cout << "Correct\n";
        std::stack<Disk<int>*>* clone = new std::stack<Disk<int>*>(*t3);
        while (!clone->empty())
        {
            cout << clone->top()->getLabel() << " ";
            clone->pop();
        }
        cout << endl;
    }
    else
    {
        cout << "Incorrect\n";
    }
}

void test3()
{
    RecursiveSolution<int>* rec = new RecursiveSolution<int>(1,3);
    rec->addDisk(3,1);
    rec->addDisk(2,1);
    rec->addDisk(1,1);
    bool flag = rec->containsLabel(3);
    if (flag)
    {
        cout << "Correct\n";
    }
    else
    {
        cout << "Incorrect\n";
    }
    
    rec->solveGame();
    std::stack<Disk<int>*>* t1 = rec->getTower(1);
    if (t1->empty())
    {
        cout << "Correct\n";
    }
    else
    {
        cout << "Incorrect\n";
    }

    std::stack<Disk<int>*>* t2 = rec->getTower(2);
    if (t2->empty())
    {
        cout << "Correct\n";
    }
    else
    {
        cout << "Incorrect\n";
    }

    std::stack<Disk<int>*>* t3 = rec->getTower(3);
    if (!t3->empty())
    {
        cout << "Correct\n";
        std::stack<Disk<int>*>* clone = new std::stack<Disk<int>*>(*t3);
        while (!clone->empty())
        {
            cout << clone->top()->getLabel() << " ";
            clone->pop();
        }
        cout << endl;
    }
    else
    {
        cout << "Incorrect\n";
    }
}

void test4()
{
    RecursiveSolution<int>* rec = new RecursiveSolution<int>(1,2);
    rec->addDisk(6,1);
    rec->addDisk(5,1);
    rec->addDisk(4,1);
    rec->addDisk(3,1);
    rec->addDisk(2,1);
    rec->addDisk(1,1);
    bool flag = rec->containsLabel(3);
    if (flag)
    {
        cout << "Correct\n";
    }
    else
    {
        cout << "Incorrect\n";
    }
    
    rec->solveGame();
    std::stack<Disk<int>*>* t1 = rec->getTower(1);
    if (t1->empty())
    {
        cout << "Correct\n";
    }
    else
    {
        cout << "Incorrect\n";
    }

    std::stack<Disk<int>*>* t2 = rec->getTower(2);
    if (t2->empty())
    {
        cout << "Correct\n";
    }
    else
    {
        cout << "Incorrect\n";
    }

    std::stack<Disk<int>*>* t3 = rec->getTower(3);
    if (!t3->empty())
    {
        cout << "Correct\n";
        std::stack<Disk<int>*>* clone = new std::stack<Disk<int>*>(*t3);
        while (!clone->empty())
        {
            cout << clone->top()->getLabel() << " ";
            clone->pop();
        }
        cout << endl;
    }
    else
    {
        cout << "Incorrect\n";
    }
}

int main(){
    // one();
    // two();
    // test1();
    // four();
    // five();
    six();
    test2();
    test3();
    test4();
    return 0;
}