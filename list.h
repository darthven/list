#include <stdlib.h>
#include <stdio.h>

typedef struct NodeDefinition {
    int value;
    struct NodeDefinition* next;
    struct NodeDefinition* prev;
    int index;
} Node;

typedef struct ListDefinition {    
    int size;
    Node* head;
    Node* tail; 
    Node** addr;   
} List;

List* init_list(int size);

void add(List *list, int value); 

int get_value(List *list, int index); 

void insert(List *list, int value, int index); 

void print_list_values(List *list); 

void print_list_indexes(List *list); 

void print_list_addr(List *list); 

void delete(List *list, int index);

void set_value(List* list, int index, int value);

List* reverse_list(List* list);

void clear(List* list);

List* map(List* list, int (*function) (int, int, Node**));

int reduce(List* list, int (*function) (int, int, int, Node**));