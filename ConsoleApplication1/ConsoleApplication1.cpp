#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string>
#include <string.h>
#include <D:\LRs\Algo\Lab3\Lab3\clist.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("Обернений польский запис виразів: знак дії знаходиться після операндів (А Б (+, -, *, /, ^). sqrt знаходить корінь з числа перед ним\n");
    printf("Введіть вираз в оберненому польскому записі (числа та знаки розділяйте пробілами): ");
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
            != '-' && expression[i] != '*' && expression[i] != '/' && expression[i] != 's' && expression[i] != '^') {
            num[k] = expression[i];
            k++;
        }
        else if (expression[i] == ' ' && expression[i - 1] != '+' && expression[i - 1] != '-'
            && expression[i - 1] != '*' && expression[i - 1] != '/' && expression[i - 1] != 't' && expression[i - 1] != '^') {
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
            case '^':
                stack->tail->prev->value = pow(stack->tail->prev->value, stack->tail->value);
                popBack(stack, &tmp);
                break;
            case 's':
                if (expression[i + 1] == 'q' && expression[i + 2] == 'r' && expression[i + 3] == 't') {
                    stack->tail->value = sqrt(stack->tail->value);
                    i += 4;
                }
                else {
                    do {
                        i++;
                    } while (expression[i] != ' ');
                }
                break;
            default:
                break;
            }
        }
    }
    popBack(stack, &k);
    printf("Відповідь: %d", k);
}