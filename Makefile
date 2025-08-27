
program : main.o tests.o solver.o dialogue.o supportive.o assert.o
	g++ main.o tests.o solver.o dialogue.o supportive.o assert.o -o program

main.o : main.cpp
	g++ -I. -c main.cpp -o main.o

tests.o : tests.cpp tests.h
	g++ -c tests.cpp -o tests.o

solver.o : solver.cpp solver.h
	g++ -c solver.cpp -o solver.o

dialogue.o : dialogue.cpp dialogue.h
	g++ -c dialogue.cpp -o dialogue.o

supportive.o : supportive.cpp supportive.h
	g++ -c supportive.cpp -o supportive.o

assert.o : assert.cpp assert.h
	g++ -c assert.cpp -o assert.o

clean :
	rm program.exe *.o
