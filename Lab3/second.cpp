#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "clist.h"
#include <string>
#include <string.h>

void printNode(elemtype* value) {
    printf("%d ", *((int*)value));
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("¬вед≥ть вираз в оберненому польскому запис≥ (числа та знаки розд≥л€йте проб≥лами): ");
    char expression[50];
    char num[20];
    gets_s(expression);

    cList* stack = createList();

    int k = 0;
    for (int i = 0; i < strlen(expression); i++) {
        if (expression[i] == ' ' && i == 0) {
            for (int j = 0; j < strlen(expression); j++) {
                expression[j] = expression[j + 1];
            }
            i--;
            continue;
        }

        if (expression[i] != ' ' && expression[i] != '+' && expression[i] 
            != '-' && expression[i] != '*' && expression[i] != '/') {
            num[k] = expression[i];
            k++;
        }
        else if (expression[i] == ' ') {
            num[k] = NULL;
            int a = atoi(num);
            pushBack(stack, &a);
            for (int j = 0; j < k; j++) {
                num[j] = NULL;
            }
            k = 0;
        }
        else {
            int tmp;
            switch (expression[i])
            {
            case '+':
                stack->tail->prev->value += stack->tail->value;
                popBack(stack, &tmp);
                break;
            case '-':
                stack->tail->prev->value -= stack->tail->value;
                popBack(stack, &tmp);
                break;
            case '*':
                stack->tail->prev->value *= stack->tail->value;
                popBack(stack, &tmp);
                break;
            case '/':
                stack->tail->prev->value /= stack->tail->value;
                popBack(stack, &tmp);
                break;
            default:
                break;
            }
        }
    }
    popBack(stack, &k);
    printf("%d", k);
}