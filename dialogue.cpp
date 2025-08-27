#include "dialogue.h"
#include "solver.h"

#include <TXLib.h>
#include <stdio.h>

void Correct_Input(int roots, double x1, double x2) {
    switch (roots) {
        case Quantity_Zero:
            printf("Уравнение не имеет решений.\n");
            break;
        case Quantity_One:
            printf("Корень: %f.\n", x1);
            break;
        case Quantity_Two:
            printf("Корень 1: %f, корень 2: %f.\n", x1, x2);
            break;
        case Quantity_Infinity:
            printf("Уравнение имеет бесконечное количество решений.\n");
            break;
        default:
            assert(0);
            break;
    }
}

bool Incorrect_Input() {
    printf("Коэффициенты введены неправильно. "
            "Хотите ли вы попробовать снова? (y-да, n-нет)\n");

    int ch = 0;
    while((ch = getchar()) != '\n')
        ;

    ch = getchar();

    if (ch == 'n')
        return false;
    else if (ch == 'y')
        return true;
    else {
        printf("че\n");
        return false;
    }
}
