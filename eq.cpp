#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define ACC 0.0001

bool is_equal(double a, double b);
int solution_square(double coeff_a, double coeff_b, double coeff_c,
                    double* x1, double* x2);
int solution_linear(double coeff_b, double coeff_c, double* x1);
int solution_both(double coeff_a, double coeff_b, double coeff_c,
                double* x1, double* x2);

void RunAll();
void Run_KBADPATKA(int* fails_square);
void Run_LNHENKA(int* fails_linear);
void Test_KBADPATKA(double a, double b, double c, double norm_x1,
                    double norm_x2, int count, int* logic);
void Test_LNHENKA(double b, double c,
                  double norm_x, int count, int* logic);

int main() {
    RunAll();

    printf("Эта программа решает квадратные уравнения.\n");
    printf("Введите коэффициенты a, b, c:\n");

    double coeff_a = 0;
    double coeff_b = 0;
    double coeff_c = 0;

    double x1 = 0;
    double x2 = 0;

    int x123 = scanf("%lg %lg %lg", &coeff_a, &coeff_b, &coeff_c);

    while(x123 != EOF) {
        if (x123 == 3) {
            int i = solution_both(coeff_a, coeff_b, coeff_c, &x1, &x2);
            // assert((isnan(x1) || isnan(x2)) && "Error: x1 or x2 is NAN.\n");

            switch (i) {
            case 0: printf("Уравнение не имеет решений.\n");
                    break;
            case 1: printf("Корень: %f.\n", x1);
                    break;
            case 2: printf("Корень 1: %f, корень 2: %f.\n", x1, x2);
                    break;
            case 3: printf("Уравнение имеет бесконечное количество решений.\n");
                    break;
            default: assert(0);
            }
        }
        else {
            printf("Коэффициенты введены неправильно. "
            "Хотите ли вы попробовать снова? (y-да, n-нет)\n");

            int ch = 0;
            while((ch = getchar()) != '\n');
                ;

            ch = getchar();

            if (ch == 'n')
                break;
            else if (ch == 'y')
                ;
            else {
                printf("че\n");
                break;
            }
        }

        printf("Введите коэффициенты a, b, c:\n");
        x123 = scanf("%lg %lg %lg", &coeff_a, &coeff_b, &coeff_c);
    }
    return 0;
}

bool is_equal(double a, double b) {
    if (isnan(a) || isnan(b)) {
        if (isnan(a) && isnan(b))
            return true;

        return false;
    }
    else {
        double x = fabs(a - b);
        if (x >= ACC)
            return false;

        return true;
    }
}

int solution_both(double coeff_a, double coeff_b, double coeff_c,
                    double* x1, double* x2) {
    assert((x1 != NULL || x2 != NULL) && "Error: pointer is NULL");

    if (is_equal(coeff_a, 0))
        return solution_linear(coeff_b, coeff_c, x1);
    else
        return solution_square(coeff_a, coeff_b, coeff_c, x1, x2);
}

int solution_square(double coeff_a, double coeff_b, double coeff_c,
                    double* x1, double* x2) {
    assert((x1 != NULL || x2 != NULL) && "Error: pointer is NULL");

    double dis = coeff_b*coeff_b - 4*coeff_a*coeff_c;
    if(dis < 0)
        return 0;
    else {
        if (is_equal(dis, 0)) {
            *x1 = -coeff_b / (2*coeff_a);

            return 1;
        }
        else {
            *x1 = (-coeff_b + sqrt(dis))/(2*coeff_a);
            *x2 = (-coeff_b - sqrt(dis))/(2*coeff_a);

            return 2;
        }
    }
}

int solution_linear(double coeff_b, double coeff_c,
                    double* x1) {
    assert((x1 != NULL) && "Error: pointer is NULL");

    if(!(is_equal(coeff_b, 0))) {
        *x1 = -coeff_c/coeff_b;

        return 1;
    }
    else if (is_equal(coeff_b, 0) && is_equal(coeff_c, 0)) {
        *x1 = NAN;
        return 3;
    }
    else {
        *x1 = NAN;
        return 0;
    }
}

void RunAll() {
    int fails_square = 0;
    int fails_linear = 0;

    Run_KBADPATKA(&fails_square);
    Run_LNHENKA(&fails_linear);

    printf("%d fails", fails_square + fails_linear);
}

struct TestSqu {
    double a;
    double b;
    double c;
    double x1;
    double x2;
    int count;
    int logic;
};

//run'ит тест по квадратке
void Run_KBADPATKA(int* fails_square) {
    struct TestSqu quadro[] {
        {5.678, -2.954, -6.192, 1.3363, -0.8161, 2},
        {2.718,  0.000, -4.156, 1.2366, -1.2366, 2},
        {3.141, -2.485,  0.000, 0.7911,   0.000, 2}
    };
    // посчитать размер массива
    for (int step = 0; step <= 2; step++)
        Test_KBADPATKA(
            quadro[step].a,
            quadro[step].b,
            quadro[step].c,
            quadro[step].x1,
            quadro[step].x2,
            quadro[step].count,
            &quadro[step].logic
        );

    *fails_square = quadro[3].logic;
}


struct TestLine {
    double b;
    double c;
    double x;
    int count;
    int logic;
};

//run'ит тест по линейке
void Run_LNHENKA(int* fails_linear) {
    struct TestLine line[] {
        {5.672, -4.156, 0.7327, 1},
        {0.000,  5.000,    NAN, 0},
        {0.000,  0.000,    NAN, 3}
    };

    line[0].logic = 0;
    int step;

    for (step = 0; step <= 2; step++) {
        Test_LNHENKA(
            line[step].b,
            line[step].c,
            line[step].x,
            line[step].count,
            &line[step].logic
        );
    }
    *fails_linear = line[3].logic;
}

//тестирует квадратку
void Test_KBADPATKA(double a, double b, double c, double norm_x1,
                    double norm_x2, int count, int* logic) {

    double x1 = 0;
    double x2 = 0;

    int number = solution_square(a, b, c, &x1, &x2);
    if (!(is_equal(x1, norm_x1) && is_equal(x2, norm_x2) && number == count)) {
        printf("FAILED solution_square: count = %d, x1 = %lg, x2 = %lg. "
        "(should be count = %d, x1 = %lg, x2 = %lg)\n", number, x1, x2, number, norm_x1, norm_x2);
        (*logic)++;
    }
}

//тестит линейку
void Test_LNHENKA(double b, double c,
                  double norm_x, int count, int* logic) {

    double x = 0;

    int number = solution_linear(b, c, &x);
    if (!(is_equal(x, norm_x) && number == count)) {
        printf("FAILED solution_linear: count = %d, x = %lg. "
        "(should be count = %d, x = %lg)\n", number, x, count, norm_x);
        (*logic)++;
    }
}
