
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
#include "colors.h"

// str(n)cmp str(n)cpy strcat strchr strlen strdup strstr
// itoa atoi strtod(опционально)

int main(int argc, char* argv[]) {
    if (argc > 1) {
        if (strcmp(argv[1], "--t") == 0)
            RunAll();
    }

    printf(GREEN "Эта программа решает квадратные уравнения." RESET "\n");
    printf(GREEN "Введите коэффициенты a, b, c (для завершения программы введите ctrl/Z):" RESET "\n");

    double coeff_a = 0;
    double coeff_b = 0;
    double coeff_c = 0;

    double x1 = 0;
    double x2 = 0;

    int x123 = scanf("%lg %lg %lg", &coeff_a, &coeff_b, &coeff_c);

    while(x123 != EOF) {
        if (x123 == 3) {
            int roots = solution_both(coeff_a, coeff_b, coeff_c, &x1, &x2);

            Correct_Input(roots, x1, x2);
        }
        else {
            while(getchar() != '\n') {}

            if(! Incorrect_Input())
                break;
        }
        printf(GREEN "Введите коэффициенты a, b, c (для завершения программы введите ctrl/Z):" RESET "\n");
        x123 = scanf("%lg %lg %lg", &coeff_a, &coeff_b, &coeff_c);
    }

    return 0;
}
