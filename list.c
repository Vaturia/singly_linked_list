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
    Node *newNode = calloc(1, sizeof(Node));
    if(!newNode) {return -1;};
    
    newNode->data = data;
    newNode->_next_node = list->_head;
    list->_head = newNode;

    return 0;
}
int8_t appendToEndItem(List *list, TYPE_LIST data)
{
    if(!list){return -1;};

    Node *newNode = calloc(1, sizeof(Node));
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
int main()
{
    List *list = initializationList();
    for(int8_t i = 0; i < 10; ++i)
    {
        appendToEndItem(list, i);
    }
    int i = 0;
    for(Node *item = list->_head; item != 0 ;++i, item = item->_next_node)
    {
        
        printf("Узел номер:%d; Адрес узла:%u; Значение узла:%d Сл. узел:%u;\n", i, item, item->data, item->_next_node);

        
    }
    appendToBeginItem(list, 66);
    i = 0;
    printf("\n");
    removeFromEndItem(list);
    appendToEndItem(list, 77);
    for(Node *item = list->_head; item != 0 ;++i, item = item->_next_node)
    {
        
        printf("Узел номер:%d; Адрес узла:%u; Значение узла:%d Сл. узел:%u;\n", i, item, item->data, item->_next_node);

        
    }
    printf("%u , %u\n", list->_head, list->_tail);

    Node* node_to_find = findItem(list, 10);

    if(node_to_find)
    {
        printf("Обнаружен элемент по запросу; Адрес:%u; Значение:%d;\n",node_to_find,node_to_find->data);
    }
    else
    {
        printf("Элемент не обнаружен\n");
    }
}