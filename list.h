#include <stdlib.h>
#include <stdio.h>

/**
 * Definition of the node structure that
 * represents an elementary part of the list.
 */
typedef struct NodeDefinition {
    int value; /*integer value that is stored in node element */
    struct NodeDefinition *next; /* pointer to the next node address */
    struct NodeDefinition *prev; /* pointer to the previous node address */
    unsigned int index; /* index of the node element (its position in the list) */
} Node;

/**
 * Definition of the list structure that can be
 * represented as an array, queue, stack and linked list.
 */
typedef struct ListDefinition {    
    unsigned int size; /* current size of the list (its elements count) */
    unsigned int capacity; /* maximum limit size of the list */
    Node *head; /* pointer to the first element of the list */ 
    Node *tail; /* pointer to the last element of the list */
    Node **addr; /* array of nodes' addresses for providing array's functionality */  
} List;

/**
 * Function that creates new list.
 * @param {unsigned int} capacity of the list
 * @return {List *} pointer to the new list instance
 */
List* init_list(unsigned int capacity);

/**
 * Function that returns current size of the list.
 * @param {List *} pointer to the list 
 * @return {unsigned int} current size
 */
unsigned int size(List *list);

/**
 * Function that changes current capacity of the list.
 * If capacity is less than current list's size, it will
 * remove all elements up to the index that corresponds to
 * the new capacity of the list.
 * @param {List *} pointer to the list 
 * @param {unsigned int} new capacity 
 */
void change_capacity(List *list, unsigned int new_capacity);

/**
 * Function that returns the first node (head) of the list.
 * @param {List *} pointer to the list 
 * @return {Node *} pointer to the head of the list
 */
Node* first_node(List *list);

/**
 * Function that returns the last node (tail) of the list.
 * @param {List *} pointer to the list 
 * @return {Node *} pointer to the tail of the list
 */
Node* last_node(List *list);

/**
 * Function that returns the value of the first node of the list.
 * @param {List *} pointer to the list 
 * @return {int} value stored in the node
 */
int first(List *list);

/**
 * Function that returns the value of the last node of the list.
 * @param {List *} pointer to the list 
 * @return {int} value stored in the node
 */
int last(List *list); 

/**
 * Function that adds new node with value
 * as the new head of the list 
 * @param {List *} pointer to the list 
 * @param {int} value stored in the node
 */
void add_first(List *list, int value);

/**
 * Function that adds new node with value
 * as the new tail of the list 
 * @param {List *} pointer to the list 
 * @param {int} value stored in the node
 */
void add_last(List *list, int value);

/**
 * Function that returns the first node (head) of the list 
 * without any deletion.
 * @param {List *} pointer to the list 
 * @return {Node *} pointer to the head of the list
 */
Node* peek_node(List *list);

/**
 * Function that returns the first node (head) of the list 
 * and removes it from it.
 * @param {List *} pointer to the list 
 * @return {Node *} pointer to the head of the list
 */
Node* pop_node(List *list);

/**
 * Function that returns the first node's value of the list 
 * without any deletion.
 * @param {List *} pointer to the list 
 * @return {Node *} pointer to the head of the list
 */
int peek(List *list);

/**
 * Function that returns the first node's value of the list 
 * and removes it from it.
 * @param {List *} pointer to the list 
 * @return {Node *} pointer to the head of the list
 */
int pop(List *list);

/**
 * Function that adds new node with value to the beginning of the list.
 * @param {List *} pointer to the list 
 * @return {int} value stored in the node
 */
void push(List* list, int value);

/**
 * Function that checks if there are no elements in list.
 * @param {List *} pointer to the list 
 * @return {unsigned int} 1 if true and 0 if false
 */
unsigned int is_empty(List *list);

/**
 * Function that adds new node with value to the list.
 * @param {List *} pointer to the list 
 * @param {int} value stored in the node
 */
void add(List *list, int value); 

/**
 * Function that adds all nodes from the source list
 * to the destionation list.
 * @param {List *} pointer to the destination list 
 * @param {List *} pointer to the source list
 */
void add_list(List *dest_list, List *src_list);

/**
 * Function that returns value of the node by the following index.
 * @param {List *} pointer to the list 
 * @param {unsigned int} index of the node
 * @return {int} value stored in the node
 */
int get_value(List *list, unsigned int index); 

/**
 * Function that returns the first found index of the node 
 * with the following value.
 * @param {List *} pointer to the list 
 * @param {int} value stored in the node
 * @return {int} index (if the index will not be found, return -1 instead)
 */
int get_index(List *list, int value);

/**
 * Function that inserts node with value to the following position
 * in the list. 
 * @param {List *} pointer to the list 
 * @param {int} value stored in the node
 * @param {unsigned int} index of the node
 */
void insert(List *list, int value, unsigned int index); 

/**
 * Function prints all nodes' values in the list. 
 * @param {List *} pointer to the list 
 */
void print_list_values(List *list); 

/**
 * Function prints all nodes' indexes in the list. 
 * @param {List *} pointer to the list 
 */
void print_list_indexes(List *list); 

/**
 * Function prints all nodes' addresses in the list. 
 * @param {List *} pointer to the list 
 */
void print_list_addr(List *list);

/**
 * Function prints all nodes' values, indexes and addresses in the list. 
 * @param {List *} pointer to the list 
 */
void print_list_info(List *list);

/**
 * Function that removes first element (head) of the list.
 * @param {List *} pointer to the list 
 */
void delete_head(List *list);

/**
 * Function that removes node with the following index in the list.
 * @param {List *} pointer to the list
 * @param {unsigned int} index of the node
 */
void delete(List *list, unsigned int index);

/**
 * Function that removes node with by the following
 * predicate function from the list.
 * @param {List *} pointer to the list
 * @param {unsigned int (*function)} predicate function that 
 * returns 1 if its clause returns true and 0 - if false:
 *  the 1st argument is value of the node;
 *  the 2nd argument is index of the node;
 *  the 3rd argument is the pointers to array of pointers to all nodes' addresses
 */
void delete_by_predicate(List *list, unsigned int (*function) (int, unsigned int, Node**));

/**
 * Function removes range of the nodes from the list according to the following indexes.
 * @param {List *} pointer to the list 
 * @param {unsigned int} index from which deletion starts
 * @param {unsigned int} index to which deletion ends
 */
void delete_range(List *list, unsigned int from_index, unsigned int to_index);

/**
 * Function that set new value to the element of the list.
 * @param {List *} pointer to the list 
 * @param {unsigned int} index of the node element
 * @param {int} new value of the node
 */
void set_value(List *list, unsigned int index, int value);

/**
 * Function that creates new list based on the reversion of the current list.
 * @param {List *} pointer to the current list 
 * @param {List *} pointer to the new reversed list 
 */
List* reverse_list(List *list);

/**
 * Function that removes all elements from the list.
 * @param {List *} pointer to the list 
 */
void clear(List *list);

/**
 * Function that iterates all the list's nodes and executes 
 * the following function during iteration.
 * @param {List *} pointer to the list
 * @param {void (*function)} function that is executed
 * after each iteration:
 *  the 1st argument is value of the node;
 *  the 2nd argument is index of the node;
 *  the 3rd argument is the pointers to array of pointers to all nodes' addresses
 */
void for_each(List* list, void (*function) (int, unsigned int, Node**));

/**
 * Function that creates new list based on the results of the following function.
 * @param {List *} pointer to the list
 * @param {int (*function)} function that creates new nodes with values which were got
 * by some actions of the current list nodes' values:
 *  the 1st argument is value of the node;
 *  the 2nd argument is index of the node;
 *  the 3rd argument is the pointers to array of pointers to all nodes' addresses
 * @return {List *} pointer to the new list
 */
List* map(List *list, int (*function) (int, unsigned int, Node **));

/**
 * Function that collects all values of the nodes by the following function.
 * @param {List *} pointer to the list
 * @param {int (*function)} predicate function that 
 * returns 1 if its clause returns true and 0 - if false:
 *  the 1st argument is one of values of the nodes;
 *  the 2nd argument is another one of values of the nodes;
 *  the 3nd argument is index of the node;
 *  the 3rd argument is the pointers to array of pointers to all nodes' addresses
 */
int reduce(List *list, int (*function) (int, int, unsigned int, Node **));

/**
 * Function that checks if any element of the list has the following value.
 * @param {List *} pointer to the current list 
 * @param {int} value stored in the node
 * @return {unsigned int} 1 if true and 0 if false  
 */
unsigned int contains(List *list, int value);

/**
 * Function that creates an array based on values of the list's elements.
 * @param {List *} pointer to the current list 
 * @return {int *} pointer to the first element of created array
 */
int* to_array(List *list);

/**
 * Function that return the copy of the current list.
 * @param {List *} pointer to the current list 
 * @return {List *} pointer to the new cloned list 
 */
List* clone(List *list);

