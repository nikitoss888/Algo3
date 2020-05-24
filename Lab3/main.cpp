#include <stdio.h>
#include <stdlib.h>
#include<Windows.h>
#include "clist.h"

void printNode(elemtype* value) {
    printf("%d ", *((int*)value));
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    elemtype a, b, c, d, e, f, g;
    elemtype tmp;

    printf("Введіть числа:\na = "); scanf_s("%d", &a);
    printf("b = "); scanf_s("%d", &b);
    printf("c = "); scanf_s("%d", &c);
    printf("d = "); scanf_s("%d", &d);
    printf("e = "); scanf_s("%d", &e);
    printf("f = "); scanf_s("%d", &f);
    printf("g = "); scanf_s("%d", &g);

    cList* mylist = createList();

    pushFront(mylist, &a);
    printList(mylist, printNode);
    printf(" - записуємо A у початок\n");

    popBack(mylist, &tmp); // видаляємо a

    pushFront(mylist, &b);
    printList(mylist, printNode);
    printf(" - видаляємо A, записуємо B\n");

    pushFront(mylist, &c);
    printList(mylist, printNode);
    printf(" - записуємо C перед B\n");

    pushBack(mylist, &d);
    printList(mylist, printNode);
    printf(" - записуємо D у кінець\n");

    popFront(mylist, &tmp);
    printList(mylist, printNode);
    printf(" - видаляємо перше число списку\n");

    pushBack(mylist, &e);
    printList(mylist, printNode);
    printf(" - записуємо E у кінець\n");

    printNode(&getNode(mylist, 1)->value); 
    printf(" - 2-е число списку (рахуємо з 1-ці)\n");

    pushInside(mylist, &f, 1);

    printNode(&getNode(mylist, 1)->value);
    printf(" - теперь це 2-е число\n");


    printList(mylist, printNode);
    printf(" - наш список\n");

    pushInside(mylist, &g, 2);
    printList(mylist, printNode);
    printf(" - додали G після 2-го\n");

    pushInside(mylist, &g, 1);
    printList(mylist, printNode);
    printf(" - додали G після 1-го\n");

    popInside(mylist, &g, 1);
    printList(mylist, printNode);
    printf(" - видалили 2-ге число\nВидаляємо список\n");

    int res = deleteList(mylist);

    printf("Розмір списку: %d\n", mylist->size);
    if (res == 0) {
        printf("Список пустий\n");
    }
    else {
        printf("Список ще не пустий\n");
    }

    printList(mylist, printNode);

    system("pause");
    return 0;
}
