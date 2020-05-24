#ifndef _CLIST_H_
#define _CLIST_H_

#include <stdlib.h>
#include <stdbool.h>

typedef int elemtype;       // ��� �������� ������

struct elem {
    elemtype value;        // �������� ����������
    struct elem* next;      // ������ �� ��������� ������� ������
    struct elem* prev;      // ������ �� ���������� ������� ������
};

struct myList {
    struct elem* head;      // ������ ������� ������
    struct elem* tail;      // ��������� ������� ������
    size_t size;            // ���������� ��������� � ������
};

typedef struct elem cNode;
typedef struct myList cList;

// �������� ������� ������
cList* createList(void);
// �������� ������
int deleteList(cList* list);
// �������� ������ �� �������
bool isEmptyList(cList* list);
// ���������� ������ ���� � ������ ������
int pushFront(cList* list, elemtype* data);
// ���������� ���� �� ������ ������
int popFront(cList* list, elemtype* data);
// ���������� ������ ���� � ����� ������
int pushBack(cList* list, elemtype* data);
// ���������� ���� �� ����� ������
int popBack(cList* list, elemtype* data);
// ���������� ������ ���� � ������ ����� (index), ������� � 0 � ���������� ��������� � ������
int pushInside(cList* list, elemtype* data, int index);
// ���������� ���� �� ������� ����� (index) � ������
int popInside(cList* list, elemtype* data, int index);
// ������ ������������� ���� ������
cNode* getNode(cList* list, int index);
// ����� ������ � �������
void printList(cList* list, void (*fun)(elemtype*));

#endif  //_CLIST_H_
