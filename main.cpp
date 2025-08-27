#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "solver.h"
#include "supportive.h"
#include "dialogue.h"
#include "tests.h"
#include "assert.h"

int main(int argc, char* argv[]) {
    RunAll();

    printf("Эта программа решает квадратные уравнения.\n");
    printf("Введите коэффициенты a, b, c (для завершения программы введите ctrl/Z):\n");

    double coeff_a = 0;
    double coeff_b = 0;
    double coeff_c = 0;

    double x1 = 0;
    double x2 = 0;

    int x123 = scanf("%lg %lg %lg", &coeff_a, &coeff_b, &coeff_c);

    while(x123 != EOF) {
        if (x123 == 3) {
            int roots = solution_both(coeff_a, coeff_b, coeff_c, &x1, &x2);
            // assert((isnan(x1) || isnan(x2)) && "Error: x1 or x2 is NAN.\n");

            Correct_Input(roots, x1, x2);
        }
        else {
            if(! Incorrect_Input())
                break;
        }
        printf("Введите коэффициенты a, b, c (для завершения программы введите ctrl/Z):\n");
        x123 = scanf("%lg %lg %lg", &coeff_a, &coeff_b, &coeff_c);
    }

    return 0;
}
