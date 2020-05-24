#ifndef _CLIST_H_
#define _CLIST_H_

#include <stdlib.h>
#include <stdbool.h>

typedef int elemtype;       // Тип элемента списка

struct elem {
    elemtype value;        // Значение переменной
    struct elem* next;      // Ссылка на следующий элемент списка
    struct elem* prev;      // Ссылка на предыдущий элемент списка
};

struct myList {
    struct elem* head;      // Первый элемент списка
    struct elem* tail;      // Последний элемент списка
    size_t size;            // Количество элементов в списке
};

typedef struct elem cNode;
typedef struct myList cList;

// Создание пустого списка
cList* createList(void);
// Удаление списка
int deleteList(cList* list);
// Проверка списка на пустоту
bool isEmptyList(cList* list);
// Добавление нового узла в начало списка
int pushFront(cList* list, elemtype* data);
// Извлечение узла из начала списка
int popFront(cList* list, elemtype* data);
// Добавление нового узла в конец списка
int pushBack(cList* list, elemtype* data);
// Извлечение узла из конца списка
int popBack(cList* list, elemtype* data);
// Добавление нового узла в нужное место (index), начиная с 0 и заканчивая последним в списке
int pushInside(cList* list, elemtype* data, int index);
// Извлечение узла из нужного места (index) в списке
int popInside(cList* list, elemtype* data, int index);
// Чтение произвольного узла списка
cNode* getNode(cList* list, int index);
// Вывод списка в консоль
void printList(cList* list, void (*fun)(elemtype*));

#endif  //_CLIST_H_
