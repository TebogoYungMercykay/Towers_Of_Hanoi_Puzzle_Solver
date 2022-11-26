main:
	g++ -g main.cpp -std=c++98 -pedantic -o main

clean:
	rm -f *.o *.tar.gz main
	reset
	clear

run:
	./main

tar:
	tar -cvz *.h *.cpp -f Recursion_&_STL_Stacks.tar.gz