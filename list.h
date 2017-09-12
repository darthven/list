#include <stdlib.h>
#include <stdio.h>

typedef struct NodeDefinition {
    int value;
    struct NodeDefinition *next;
    struct NodeDefinition *prev;
    int index;
} Node;

typedef struct ListDefinition {    
    int size;
    Node *head;
    Node *tail; 
    Node **addr;   
} List;

List* init_list(int size);

int size(List *list);

Node* first_node(List *list);

Node* last_node(List *list);

int first(List *list);

int last(List *list); 

void add_first(List *list, int value);

void add_last(List *list, int value);

Node* peek_node(List *list);

Node* poll_node(List *list); 

unsigned int is_empty(List *list);

void add(List *list, int value); 

void add_list(List *dest_list, List *src_list);

int get_value(List *list, int index); 

int get_index(List *list, int value);

void insert(List *list, int value, int index); 

void print_list_values(List *list); 

void print_list_indexes(List *list); 

void print_list_addr(List *list); 

void delete_head(List *list);

void delete(List *list, int index);

void delete_by_predicate(List *list, unsigned int (*function) (int, int, Node**));

void delete_range(List *list, int from_index, int to_index);

void set_value(List *list, int index, int value);

List* reverse_list(List *list);

void clear(List *list);

void for_each(List* list, void (*function) (int, int, Node**));

List* map(List *list, int (*function) (int, int, Node **));

int reduce(List *list, int (*function) (int, int, int, Node **));

unsigned int contains(List *list, int value);

int* to_array(List *list);

List* clone(List *list);

