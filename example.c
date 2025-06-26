#include "list.h"
#include <stdio.h>

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
    insertItem(list, 37, 7, 'a');
    insertItem(list, 74, 9, 'b');

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