CFLAGS= -DTX_COMPILED -Wall -Wextra -I. -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline\
-Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g\
-pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers\
-Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo\
-Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG\
-D_EJUDGE_CLIENT_SIDE

program : main.o tests.o solver.o dialogue.o supportive.o assert.o txlib.o
	g++ ${CFLAGS} main.o tests.o solver.o dialogue.o supportive.o assert.o txlib.o -o program

run: program
	.\program.exe

main.o : main.cpp colors.h
	g++ ${CFLAGS} -c main.cpp -o main.o

tests.o : tests.cpp tests.h colors.h
	g++ ${CFLAGS} -c tests.cpp -o tests.o

solver.o : solver.cpp solver.h
	g++ ${CFLAGS} -c solver.cpp -o solver.o

dialogue.o : dialogue.cpp dialogue.h
	g++ ${CFLAGS} -c dialogue.cpp -o dialogue.o

supportive.o : supportive.cpp supportive.h colors.h
	g++ ${CFLAGS} -c supportive.cpp -o supportive.o

assert.o : assert.cpp assert.h
	g++ ${CFLAGS} -c assert.cpp -o assert.o

txlib.o : txlib.cpp
	g++ ${CFLAGS} -c txlib.cpp -o $@

clean :
	rm program.exe *.o
