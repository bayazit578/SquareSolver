#include <TXLib.h>
#include <stdio.h>
#include <math.h>

#define ACC 0.0001

int eq_zero(double a);
double solution_square(double coeff_a, double coeff_b, double coeff_c, double* x1, double* x2);
double solution_both(double coeff_a, double coeff_b, double coeff_c, double* x1, double* x2);

int main() {

    double coeff_a = 0, coeff_b = 0, coeff_c = 0;

    printf("Эта программа решает квадратные уравнения.\n");
    printf("Введите коэффициенты a, b, c:\n");

    int x = 0;
    x = scanf("%lg %lg %lg", &coeff_a, &coeff_b, &coeff_c);
    // printf("%lg %lg %lg\n", coeff_a, coeff_b, coeff_c);

    double x1 = 0, x2 = 0;

    if(x == 3) {
        int i = solution_both(coeff_a, coeff_b, coeff_c, &x1, &x2);
        switch(i) {
        case 0: printf("Уравнение не имеет решений.\n");
                break;
        case 1: printf("Корень: %f.\n", x1);
                break;
        case 2: printf("Корень 1: %f, корень 2: %f.\n", x1, x2);
                break;
        case 3: printf("Уравнение имеет бесконечное количество решений.\n");
                break;
        }
    }
    else
        printf("Вы не ввели достаточное число переменных.\n");

    return 0;
}

int eq_zero(double a) {
    a = abs(a);

    if (a >= ACC)
        return 1;
    else
        return 0;
}

double solution_square(double coeff_a, double coeff_b, double coeff_c,
                    double* x1, double* x2) {
    double dis = coeff_b*coeff_b - 4*coeff_a*coeff_c;

    if(dis < 0)
        return 0;
    else {
        if(eq_zero(dis) == 0) {
            *x1 = -coeff_b/(2*coeff_a);
            return 1;
        }
        else {
            *x1 = (-coeff_b + sqrt(dis))/(2*coeff_a);
            *x2 = (-coeff_b - sqrt(dis))/(2*coeff_a);
            return 2;
        }
    }
}

double solution_both(double coeff_a, double coeff_b, double coeff_c,
                    double* x1, double* x2) {
    if(eq_zero(coeff_a) != 0)
        return solution_square(coeff_a, coeff_b, coeff_c, x1, x2);
    else
        return solution_lynear(coeff_b, coeff_c, x1, x2);
}

int solution_lynear(double coeff_b, double coeff_c,
                    double* x1, double* x2) {
    if(eq_zero(coeff_b) != 0) {
        *x1 = -coeff_c/coeff_b;
        return 1;
    }

    else if(eq_zero(coeff_b) == 0 && eq_zero(coeff_c) == 0)
        return 3;

    else
        return 0;
}
