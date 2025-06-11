#include <stdint.h>
#ifndef LIST_H
#define LIST_H

#define TYPE_LIST int32_t

typedef struct Node
{
   TYPE_LIST data;
   struct Node* _next_node;
}Node;

typedef struct List
{
   Node* _head;
   Node* _tail;
}List;

List* initializationList(void);
int8_t appendToBeginItem(List *list, TYPE_LIST data);
int8_t appendToEndItem(List *list, TYPE_LIST data);
int8_t removeFromEndItem(List *list);
Node* findItem(List *list, TYPE_LIST data);
int8_t insertItem(List *list, TYPE_LIST data, int32_t num_node, char position);

#endif