#ifndef SOLVER_H
#define SOLVER_H

int solution_square(double coeff_a, double coeff_b, double coeff_c,
                    double* x1, double* x2);
int solution_linear(double coeff_b, double coeff_c, double* x1);
int solution_both(double coeff_a, double coeff_b, double coeff_c,
                  double* x1, double* x2);

enum Quantity {
    Quantity_Zero = 0,
    Quantity_One = 1,
    Quantity_Two = 2,
    Quantity_Infinity = 3
};

#endif // SOLVER_H
