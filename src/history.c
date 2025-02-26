#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List *init_history()
{
    List *list = malloc(sizeof(List));
    list -> root = malloc(sizeof(Item));
    return list;
}
void add_history(List *list, char *str)
{
    int id = 1;
    Item *temp = list -> root;
    while (temp){
        temp = temp -> next;
        id++;
    }
    temp = malloc(sizeof(Item));
    temp -> id = id;
    temp -> str = str;
    
}

char *get_history(List *list, int id)
{
    Item *temp = list -> root;
    
    if(!list){
        return '\0';
    }

    while (temp){
        if (temp -> id == id){
            return temp -> str;
        }
        temp = temp -> next;
    }

    return '\0';
}

void print_history(List *list)
{
    if(!list){
        printf("null");
    }

    Item *temp = list -> root;

    while (temp){
        printf("%d. %s\n", temp -> id, temp -> str);
        temp = temp -> next;
    }
    
}

void free_history(List *list)
{
    Item *temp = list -> root;
    Item *next = '\0';

    while (temp){
        next = temp -> next;
        free(temp -> str);
        free(temp);
        temp = next;
    }
    free(list);
}