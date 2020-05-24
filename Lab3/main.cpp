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

    printf("������ �����:\na = "); scanf_s("%d", &a);
    printf("b = "); scanf_s("%d", &b);
    printf("c = "); scanf_s("%d", &c);
    printf("d = "); scanf_s("%d", &d);
    printf("e = "); scanf_s("%d", &e);
    printf("f = "); scanf_s("%d", &f);
    printf("g = "); scanf_s("%d", &g);

    cList* mylist = createList();

    pushFront(mylist, &a);
    printList(mylist, printNode);
    printf(" - �������� A � �������\n");

    popBack(mylist, &tmp); // ��������� a

    pushFront(mylist, &b);
    printList(mylist, printNode);
    printf(" - ��������� A, �������� B\n");

    pushFront(mylist, &c);
    printList(mylist, printNode);
    printf(" - �������� C ����� B\n");

    pushBack(mylist, &d);
    printList(mylist, printNode);
    printf(" - �������� D � �����\n");

    popFront(mylist, &tmp);
    printList(mylist, printNode);
    printf(" - ��������� ����� ����� ������\n");

    pushBack(mylist, &e);
    printList(mylist, printNode);
    printf(" - �������� E � �����\n");

    printNode(&getNode(mylist, 1)->value); 
    printf(" - 2-� ����� ������ (������ � 1-��)\n");

    pushInside(mylist, &f, 1);

    printNode(&getNode(mylist, 1)->value);
    printf(" - ������ �� 2-� �����\n");


    printList(mylist, printNode);
    printf(" - ��� ������\n");

    pushInside(mylist, &g, 2);
    printList(mylist, printNode);
    printf(" - ������ G ���� 2-��\n");

    pushInside(mylist, &g, 1);
    printList(mylist, printNode);
    printf(" - ������ G ���� 1-��\n");

    popInside(mylist, &g, 1);
    printList(mylist, printNode);
    printf(" - �������� 2-�� �����\n��������� ������\n");

    int res = deleteList(mylist);

    printf("����� ������: %d\n", mylist->size);
    if (res == 0) {
        printf("������ ������\n");
    }
    else {
        printf("������ �� �� ������\n");
    }

    printList(mylist, printNode);

    system("pause");
    return 0;
}
