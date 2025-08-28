#include "solver.h"

#include <TXLib.h>
#include <math.h>
#include <stdlib.h>

#include "supportive.h"
#include "assert.h"

int solution_both(double coeff_a, double coeff_b, double coeff_c,
                    double* x1, double* x2) {
    MY_ASSERT((x1 != NULL || x2 != NULL) && "Error: pointer is NULL");

    if (is_equal(coeff_a, 0))
        return solution_linear(coeff_b, coeff_c, x1);
    else
        return solution_square(coeff_a, coeff_b, coeff_c, x1, x2);
}

int solution_square(double coeff_a, double coeff_b, double coeff_c,
                    double* x1, double* x2) {
    MY_ASSERT((x1 != NULL || x2 != NULL) && "Error: pointer is NULL");

    double dis = coeff_b*coeff_b - 4*coeff_a*coeff_c;
    if(dis < 0) {
        *x1 = 0;
        *x2 = 0;
        return Quantity_Zero;
    }
    else {
        if (is_equal(dis, 0)) {
            *x1 = -coeff_b / (2*coeff_a);
            *x2 = 0;

            return Quantity_One;
        }
        else {
            *x1 = (-coeff_b + sqrt(dis))/(2*coeff_a);
            *x2 = (-coeff_b - sqrt(dis))/(2*coeff_a);

            return Quantity_Two;
        }
    }
}

int solution_linear(double coeff_b, double coeff_c,
                    double* x1) {
    MY_ASSERT((x1 != NULL) && "Error: pointer is NULL");

    if(!(is_equal(coeff_b, 0))) {
        if (is_equal(coeff_c, 0)) {
        *x1 = 0;
        return Quantity_One;
        }
        *x1 = -coeff_c/coeff_b;
        return Quantity_One;
    }
    else if (is_equal(coeff_b, 0) && is_equal(coeff_c, 0)) {
        *x1 = 0;
        return Quantity_Infinity;
    }
    else {
        *x1 = 0;
        return Quantity_Zero;
    }
}
