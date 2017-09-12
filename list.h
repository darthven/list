#include <stdlib.h>
#include <stdio.h>

typedef struct NodeDefinition {
    int value;
    struct NodeDefinition *next;
    struct NodeDefinition *prev;
    unsigned int index;
} Node;

typedef struct ListDefinition {    
    unsigned int size;
    unsigned int capacity;
    Node *head;
    Node *tail; 
    Node **addr;   
} List;

List* init_list(unsigned int capacity);

unsigned int size(List *list);

void change_capacity(List *list, unsigned int new_capacity);

Node* first_node(List *list);

Node* last_node(List *list);

int first(List *list);

int last(List *list); 

void add_first(List *list, int value);

void add_last(List *list, int value);

Node* peek_node(List *list);

Node* poll_node(List *list); 

Node* pop_node(List *list);

int peek(List *list);

int poll(List *list);

int pop(List *list);

void push(List* list, int value);

unsigned int is_empty(List *list);

void add(List *list, int value); 

void add_list(List *dest_list, List *src_list);

int get_value(List *list, unsigned int index); 

int get_index(List *list, int value);

void insert(List *list, int value, unsigned int index); 

void print_list_values(List *list); 

void print_list_indexes(List *list); 

void print_list_addr(List *list);

void print_list_info(List *list);

void delete_head(List *list);

void delete(List *list, unsigned int index);

void delete_by_predicate(List *list, unsigned int (*function) (int, unsigned int, Node**));

void delete_range(List *list, unsigned int from_index, unsigned int to_index);

void set_value(List *list, unsigned int index, int value);

List* reverse_list(List *list);

void clear(List *list);

void for_each(List* list, void (*function) (int, unsigned int, Node**));

List* map(List *list, int (*function) (int, unsigned int, Node **));

int reduce(List *list, int (*function) (int, int, unsigned int, Node **));

unsigned int contains(List *list, int value);

int* to_array(List *list);

List* clone(List *list);

