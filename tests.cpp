#include "tests.h"

#include <TXLib.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "colors.h"
#include "assert.h"
#include "solver.h"
#include "supportive.h"

struct TestSqu {
    double a;
    double b;
    double c;
    double norm_x1;
    double norm_x2;
    int count;
};

struct TestLine {
    double b;
    double c;
    double norm_x;
    int count;
};

void RunAll() {
    int fails = 0;
    FILE *test_data = fopen("test_data.txt", "r");
    MY_ASSERT(test_data != NULL);
    fails += Run_KBADPATKA(test_data);
    fails += Run_LNHENKA(test_data);

    printf(RED "%d fails founded" RESET "\n", fails);
}

//run'ит тест по квадратке
int Run_KBADPATKA(FILE* test_data) {
    struct TestSqu quadro;
    int fails = 0;
    for (int step = 1; step <= 5; step++) {
        fscanf(test_data, "%lg %lg %lg %lg %lg %d", &(quadro.a),
                                                    &(quadro.b),
                                                    &(quadro.c),
                                                    &(quadro.norm_x1),
                                                    &(quadro.norm_x2),
                                                    &(quadro.count));
        fails += Test_KBADPATKA(&quadro);
    }
    return fails;
}

//run'ит тест по линейке
int Run_LNHENKA(FILE* test_data) {
    int fails = 0;
    struct TestLine line;
    for (int step = 1; step <= 4; step++) {
        fscanf(test_data, "%lg %lg %lg %d", &line.b,
                                            &line.c,
                                            &line.norm_x,
                                            &line.count);
        fails += Test_LNHENKA(&line);
    }
    fclose(test_data);
    return fails;
}

//тестит квадратку
int Test_KBADPATKA(struct TestSqu* quadro) {

    double x1 = 0;
    double x2 = 0;

    int number = solution_square(quadro->a, quadro->b, quadro->c, &x1, &x2);
    if (!(is_equal(x1, quadro->norm_x1) && is_equal(x2, quadro->norm_x2) && number == quadro->count)) {
        printf(RED "FAILED solution_square: count = %d, x1 = %lf, x2 = %lf. "
            "(should be count = %d, x1 = %lf, x2 = %lf)" RESET "\n", number, x1, x2, quadro->count, quadro->norm_x1, quadro->norm_x2);
        return 1;
    }
    return 0;
}

//тестит линейку
int Test_LNHENKA(struct TestLine* line) {
    double x = 0;

    int number = solution_linear(line->b, line->c, &x);
    if (!(is_equal(x, line->norm_x) && number == line->count)) {
        printf(RED "FAILED solution_linear: count = %d, x = %lf. "
            "(should be count = %d, x = %lf)" RESET "\n", number, x, line->count, line->norm_x);
        return 1;
    }
    return 0;
}
