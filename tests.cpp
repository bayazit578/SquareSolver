#include "tests.h"

#include <TXLib.h>
#include <math.h>
#include <stdlib.h>

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

    fails += Run_KBADPATKA();
    fails += Run_LNHENKA();

    printf("%d fails founded\n", fails);
}

//run'ит тест по квадратке
int Run_KBADPATKA() {
    FILE *test_data;
    test_data = fopen("test_data.txt", "r");

    //struct TestSqu quadro[] {
    //    {5.678, -2.954, -6.192, 1.3363, -0.8161, 2},
    //    {2.718,  0.000, -4.156, 1.2366, -1.2366, 2},
    //    {3.141, -2.485,  0.000, 0.7911,   0.000, 2},
    //    {5.915,  1.254,  6.437,    NAN,     NAN, 0},
    //    {1.000,  2.000,  1.000,-1.0000,     NAN, 1}
    //};
    struct TestSqu quadro[] ;
    int fails = 0;
    int step = 0;
    while (!feof(test_data)) {
        fscanf(test_data, "%lg %lg &lg %lg %lg %d", &quadro[step].a,
                                                    &quadro[step].b,
                                                    &quadro[step].c,
                                                    &quadro[step].norm_x1,
                                                    &quadro[step].norm_x2);
        fails += Test_KBADPATKA(&quadro[step]);
        step++;
    }
    fclose(test_data);
    return fails;

    //for (size_t step = 0; step < size; step++) {
    //    fails += Test_KBADPATKA(&quadro[step]);
    //}
    //return fails;
}

//run'ит тест по линейке
int Run_LNHENKA() {
    struct TestLine line[] {
        {5.672, -4.156, 0.7327, 1},
        {0.000,  5.000,    NAN, 0},
        {0.000,  0.000,    NAN, 3},
        {5.000,  0.000, 0.0000, 1}
    };
    size_t size = sizeof(line) / sizeof(line[0]);
    int fails = 0;

    for (size_t step = 0; step < size; step++) {
        fails += Test_LNHENKA(&line[step]);
    }
    return fails;
}

//тестит квадратку
int Test_KBADPATKA(struct TestSqu* quadro) {

    double x1 = 0;
    double x2 = 0;

    int number = solution_square(quadro->a, quadro->b, quadro->c, &x1, &x2);
    if (!(is_equal(x1, quadro->norm_x1) && is_equal(x2, quadro->norm_x2) && number == quadro->count)) {
        printf("FAILED solution_square: count = %d, x1 = %lg, x2 = %lg. "
            "(should be count = %d, x1 = %lg, x2 = %lg)\n", number, x1, x2, quadro->count, quadro->norm_x1, quadro->norm_x2);
        return 1;
    }
    return 0;
}

//тестит линейку
int Test_LNHENKA(struct TestLine* line) {
    double x = 0;

    int number = solution_linear(line->b, line->c, &x);
    if (!(is_equal(x, line->norm_x) && number == line->count)) {
        printf("FAILED solution_linear: count = %d, x = %lg. "
            "(should be count = %d, x = %lg)\n", number, x, line->count, line->norm_x);
        return 1;
    }
    return 0;
}
