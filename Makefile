program : main.o tests.o solver.o dialogue.o supportive.o
	g++ main.o tests.o solver.o dialogue.o supportive.o -o program

main.o : main.cpp
	g++ -c main.cpp -o main.o

tests.o : tests.cpp
	g++ -c tests.cpp -o tests.o

solver.o : solver.cpp
	g++ -c solver.cpp -o solver.o

dialogue.o : dialogue.cpp
	g++ -c dialogue.cpp -o dialogue.o

supportive.o : supportive.cpp
	g++ -c supportive.cpp -o supportive.o


