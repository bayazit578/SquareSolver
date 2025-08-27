#include "dialogue.h"
#include "solver.h"

#include <TXLib.h>
#include <stdio.h>

void Correct_Input(int roots, double x1, double x2) {
    switch (roots) {
        case Quantity_Zero:
            printf("��������� �� ����� �������.\n");
            break;
        case Quantity_One:
            printf("������: %f.\n", x1);
            break;
        case Quantity_Two:
            printf("������ 1: %f, ������ 2: %f.\n", x1, x2);
            break;
        case Quantity_Infinity:
            printf("��������� ����� ����������� ���������� �������.\n");
            break;
        default:
            assert(0);
            break;
    }
}

bool Incorrect_Input() {
    printf("������������ ������� �����������. "
            "������ �� �� ����������� �����? (y-��, n-���)\n");

    int ch = 0;
    while((ch = getchar()) != '\n')
        ;

    ch = getchar();

    if (ch == 'n')
        return false;
    else if (ch == 'y')
        return true;
    else {
        printf("��\n");
        return false;
    }
}
