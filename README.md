________________________________________________________________________________________
#                        Towers Of Hanoi In C++                              
________________________________________________________________________________________
## Description

- Towers of Hanoi is a popular puzzel game that consists out of two main components: three towers
and n number of disks. The goal of this puzzel game is to move the tower of disks from one tower to
another tower with only moving a single disk at a time. Also a constraint that is placed at all times
on the game is that no disk may be placed on another disk if the bottom disk is smaller then the top
disk.

- ### More information can be found at some of the following links:
  - https://en.wikipedia.org/wiki/Tower_of_Hanoi
  - https://www.tutorialspoint.com/data_structures_algorithms/tower_of_hanoi.htm
  - https://www.geeksforgeeks.org/c-program-for-tower-of-hanoi/
  - https://www.mathsisfun.com/games/towerofhanoi.htm
________________________________________________________________________________________
## UML Diagram And Functions
<img width="849" alt="UML diagram and functions" src="https://github.com/TebogoYungMercykay/Towers_Of_Hanoi----Recursion_And_STL_Stacks/blob/main/UML_Diagram.png">

________________________________________________________________________________________
- ### Requirements before running code:
    - Install an IDE that compiles and runs C++ codes. Recommendation VS Code
    - How to setup WSL Ubuntu terminal shell and run it from Visual Studio Code: https://www.youtube.com/watch?v=fp45HpZuhS8&t=112s
- ### About Codes:
    - The code is all written by myself only
    - I hard code them as part of my practice code, practical and assignemnts for my coding modules.
- ###  About Me: 
    - Tebogo Sello Selepe
    - Computer Sciences at Tuks
________________________________________________________________________________________
 ## Makefile
 ##### NB: A makefile Is Included to compile and run the codes on the terminal with the following commands:=
- make clean
- make
- make run


```C++
main:
	g++ -g *.cpp -std=c++98 -pedantic -o main

clean:
	rm -f *.o *.tar.gz main
	reset
	clear

run:
	valgrind --leak-check=full ./main

tar:
	tar -cvz *.* -f Towers_of_Hanoi.tar.gz
	
untar:
	tar -zxvf *.tar.gz
```
________________________________________________________________________________________
