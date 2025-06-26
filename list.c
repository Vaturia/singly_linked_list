#include <stdio.h>
#include <stdint.h>
#include <malloc.h>

#include "list.h"

List* initializationList(void)
{
    return (List*)calloc(1, sizeof(List));
}
int8_t appendToBeginItem(List *list, TYPE_LIST data)
{
    if(!list) {return -1;};
    Node *newNode = (Node*)calloc(1, sizeof(Node));
    if(!newNode) {return -1;};
    
    newNode->data = data;
    newNode->_next_node = list->_head;
    list->_head = newNode;

    return 0;
}
int8_t appendToEndItem(List *list, TYPE_LIST data)
{
    if(!list){return -1;};

    Node *newNode = (Node*)calloc(1, sizeof(Node));
    if(!newNode){return -1;};
    newNode->data = data;
    if(!list->_head)
    {
        list->_head = list->_tail = newNode;
        return 0;
    }

    list->_tail->_next_node = newNode;
    list->_tail = newNode;
    list->_tail->_next_node = NULL;

    return 0;
}
int8_t removeFromEndItem(List *list)
{
    if(!list){return -1;};
    Node *node = list->_head;

    for(; node->_next_node != list->_tail; node = node->_next_node) {};

    free(list->_tail);
    list->_tail = 0x00;

    node->_next_node = 0x00;
    list->_tail = node;
    
    return 0;
}
Node* findItem(List *list, TYPE_LIST data)
{
    if(!list){return 0x00;};
    for(Node* node = list->_head; node->_next_node != 0; node = node->_next_node)
    {
        if(node->data == data){return node;};
    }

    return 0x00;
}
int8_t insertItem(List *list, TYPE_LIST data, int32_t num_node, char position)
{
    if(!list){return -1;};

    int32_t i = 0;
    Node *buf = list->_head, *newNode = 0x00;

    newNode = (Node*)calloc(1, sizeof(Node));

    if(!newNode){return -1;};
    for(; (i != num_node - 1) && buf != NULL; buf = buf->_next_node, ++i);

    if(buf == NULL)
    {
        free(newNode);
        return -1;
    };

    switch (position)
    {
        case 'a': buf = buf->_next_node; break;
        case 'b': break;
        default: 
            free(newNode);
            return -1;
    }

    newNode->data = data;
    newNode->_next_node = buf->_next_node;
    buf->_next_node = newNode;

    return 0;

};