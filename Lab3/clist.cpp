#include "clist.h"

// Создание пустого списка
cList* createList(void) {
	cList* list = (cList*) malloc(sizeof(cList));
	if(list) {
        list->size = 0;
        list->head = list->tail = NULL;
	}
    return list;
}

// Удаление списка
int deleteList(cList *list) {
    cNode* head = list->head;
    cNode* next = NULL;
    while (head) {
        next = head->next;
        free(head);
        head = next;
    }
    free(list);
    list->head = list->tail = NULL;
    list->size = 0;
    if (list->head == NULL) {
        return 0;
    }
    else
    {
        return -1;
    }
}

// Проверка списка на пустоту
bool isEmptyList(cList* list) {
	return ((list->head == NULL) || (list->tail == NULL));
}

// Добавление нового узла в начало списка
int pushFront(cList* list, elemtype* data) {
    cNode* node = (cNode*) malloc(sizeof(cNode));
    if (!node) {
        return(-1);
    }
    node->value = *data;
    node->next = list->head;
    node->prev = NULL;

    if (!isEmptyList(list)) {
        list->head->prev = node;
    }
    else {
        list->tail = node;
    }
    list->head = node;

    list->size++;
    return(0);
}

// Извлечение узла из начала списка
int popFront(cList* list, elemtype* data) {
    cNode* node;

    if (isEmptyList(list)) {
        return(-2);
    }

    node = list->head;
    list->head = list->head->next;

    if (!isEmptyList(list)) {
        list->head->prev = list->tail;
    }
    else {
        list->tail = NULL;
    }

    *data = node->value;
    list->size--;
    free(node);

    return(0);
}

// Добавление нового узла в конец списка
int pushBack(cList* list, elemtype* data) {
    cNode* node = (cNode*) malloc(sizeof(cNode));
    if (!node) {
        return(-3);
    }

    node->value = *data;
    node->next = NULL;
    node->prev = list->tail;
    if (!isEmptyList(list)) {
        list->tail->next = node;
    }
    else {
        list->head = node;
    }
    list->tail = node;

    list->size++;
    return(0);
}

// Извлечение узла из конца списка
int popBack(cList* list, elemtype* data) {
    cNode *node = NULL;

    if (isEmptyList(list)) {
        return(-4);
    }

    node = list->tail;
    list->tail = list->tail->prev;
    if (!isEmptyList(list)) {
        list->tail->next = list->head;
    }
    else {
        list->head = NULL;
    }

    *data = node->value;
    list->size--;
    free(node);

    return(0);
}

// Добавление нового узла в нужное место (index), начиная с 0 и заканчивая последним в списке.
int pushInside(cList* list, elemtype* data, int index) {
    cNode* newNode = (cNode*)malloc(sizeof(cNode));
    if (!newNode) {
        return(-5);
    }
    if (index >= list->size || isEmptyList(list)) {
        return(NULL);
    }

    cNode* node;
    if (index == 0) {
        pushFront(list, data);
        return 0;
    }
    else if (index == list->size-1) {
        pushBack(list, data);
        return 0;
    }
    else if (index < list->size / 2) {
        int i = 0;
        node = list->head;
        while (node && i != index - 1)
        {
            node = node->next;
            i++;
        }
        newNode->value = *data;
        newNode->next = node->next;
        newNode->prev = node;

        node->next->prev = newNode;
        node->next = newNode;
    }
    else {
        int i = list->size - 1;
        cNode* node = list->tail;
        while (node && i != index)
        {
            node = node->prev;
            i--;
        }
        newNode->value = *data;
        newNode->prev = node->prev;
        newNode->next = node;

        node->prev->next = newNode;
        node->prev = newNode;
    }

    list->size++;
    return(0);
}

// Извлечение узла из нужного места (index) в списке
int popInside(cList* list, elemtype* data, int index) {
    cNode* node;

    if (isEmptyList(list)) {
        return(-6);
    }
    if (index == 0) {
        popFront(list, data);
        return(0);
    }
    else if (index == list->size - 1) {
        popBack(list, data);
        return(0);
    }
    else if (index < list->size/2) {
        int i = 0;
        node = list->head;
        while (node && i < index)
        {
            node = node->next;
            i++;
        }
    }
    else {
        int i = list->size - 1;
        node = list->head;
        while (node && i > index)
        {
            node = node->prev;
            i--;
        }
    }

    node->prev->next = node->next;
    node->next->prev = node->prev;

    *data = node->value;
    list->size--;
    free(node);

    return(0);
}

// Чтение произвольного узла списка
cNode* getNode(cList* list, int index) {
    cNode *node = NULL;
    int i;

    if (index >= list->size) {
        return (NULL);
    }

    if (index < list->size/2) {
        i = 0;
        node = list->head;
        while (node && i < index) {
            node = node->next;
            i++;
        }
    }
    else {
        i = list->size - 1;
        node = list->tail;
        while (node && i > index) {
            node = node->prev;
            i--;
        }
    }

    return node;
}

// Вывод списка в консоль
void printList(cList* list, void (*func)(elemtype*)) {
    cNode* node = list->head;

    if (isEmptyList(list)) {
        return;
    }

    int i = 0;
    while (node && i < list->size) {
        func(&node->value);
        node = node->next;
        i++;
    }
}
