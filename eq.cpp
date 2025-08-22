#include <TXLib.h>
#include <stdio.h>
#include <math.h>

#define ACC 0.0001

int eq_zero(double a);

int main() {

    double coeff_a = 0, coeff_b = 0, coeff_c = 0; // FIXME возможно стоит переименовать в coeff_a и так далее

    printf("Эта программа решает квадратные уравнения.\n");
    printf("Введите коэффициенты a, b, c:\n");

    int x = 0;
    x = scanf("%g %g %g", &coeff_a, &coeff_b, &coeff_c);
    if(x == 3) {
        double x1 = 0, x2 = 0;

        if(eq_zero(coeff_a) == 0) {
            double dis = coeff_b*coeff_b - 4*coeff_a*coeff_c;

            if(dis < 0)
                printf("У этого уравнения нет решений.\n");

            else {
                x1 = (-coeff_b + sqrt(dis))/(2*coeff_a);
                x2 = (-coeff_b - sqrt(dis))/(2*coeff_a);

                printf("Корень 1: %f, корень 2: %f \n", x1, x2);
            }
        }

        else
            if(eq_zero(coeff_b) == 0)
                x1 = -coeff_c/coeff_b;
            else if(eq_zero(coeff_b) != 0 && eq_zero(coeff_c) != 0)
                printf("Уравнение имеет бесконечное количество решений.\n");
            else
                printf("Уравнение не имеет решений.\n");
    }
    else
        printf("Вы не ввели достаточное число переменных.\n");

    return 0;
}

int eq_zero(double a) {
    a = abs(a);

    if (a >= ACC)
        return 0;
    else
        return 1;
}
