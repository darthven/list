#include "list.h"

List* init_list(unsigned int capacity) {
    List *list = malloc(capacity * sizeof(Node));
    Node **addr = malloc(capacity * sizeof(Node*));
    list->size = 0;
    list->capacity = capacity;
    list->head = NULL;
    list->tail = NULL;
    list->addr = addr;    
}

void change_capacity(List *list, unsigned int new_capacity) {
    if(new_capacity < list->size) {
        Node *it = list->tail;
        do {
            delete(list, it->index);
            it = it->prev;
        } while(it->index != new_capacity - 1);
    } else if(new_capacity > list->size) {
        list->capacity = new_capacity;
        realloc(list->addr, (list->capacity * sizeof(Node*)));
    }
}

void add_node(List *list, Node *node) {
    if(list->head == NULL) {        
        node->index = 0;
        node->prev = NULL;        
        list->head = node; 
    } else if(list->tail == NULL) {       
        node->index = list->head->index + 1;    
        node->prev = list->head;      
        list->tail = node;        
        list->head->next = node;              
    } else {
        node->index = list->tail->index + 1;
        node->prev = list->tail;        
        list->tail->next = node;       
        list->tail = node;            
    }
    list->size++;
    if(list->size > list->capacity) {
        change_capacity(list, list->capacity * 2);     
    }  
    list->addr[node->index] = node;
}

void add(List *list, int value) {
    Node *node = malloc(sizeof(Node));
    node->value = value;    
    node->next = NULL;
    add_node(list, node);   
}

void add_list(List *dest_list, List *src_list) {    
    Node *it = src_list->head;
    do {
        add_node(dest_list, it);
        it = it->next;
    } while(it != NULL);
}

void add_first(List *list, int value) {
    insert(list, value, 0);
}

void add_last(List *list, int value) {
    insert(list, value, size(list));
}

void push(List* list, int value) {
    add_first(list, value);
}

Node* peek_node(List *list) {
    return first_node(list);
}

Node* poll_node(List *list) {
    Node *node = first_node(list);
    delete_head(list);
    return node;    
}

Node* pop_node(List *list) {
    return poll_node(list);
}

int peek(List *list) {
    return peek_node(list)->value;
}

int poll(List *list) {
    return poll_node(list)->value;
}

int pop(List *list) {
    return pop_node(list)->value;
}

Node* get_node(List *list, int index) {    
    return list->addr[index];
} 

int get_index(List *list, int value) {
    if(list->size > 0) {
        Node *it = list->head;
        do {
            if(it->value == value) {
                return it->index;
            }
            it = it->next;
        } while(it != NULL);
    }
    return -1;
}

Node* first_node(List *list) {
    return list->head;
}

Node* last_node(List *list) {
    return list->tail;
}

int first(List *list) {
    return first_node(list)->value;
}

int last(List *list) {
    return last_node(list)->value;
}

int get_value(List *list, unsigned int index) {    
    return get_node(list, index)->value;
}   

void insert_head(List *list, Node *node) {    
    Node **new_addr = malloc((list->size + 1) * sizeof(Node*));    
    new_addr[0] = node;
    Node *it = list->head;
    do {   
        it->index++;
        new_addr[it->index] = it;
        it = it->next;
    } while(it != NULL);   
    node->prev = NULL;    
    node->next = list->head;
    list->head->prev = node;
    list->head = node; 
    list->addr = new_addr;
    list->size++;
}

void insert_inside(List *list, Node *node, unsigned int index) {   
    Node **new_addr = malloc((list->size + 1) * sizeof(Node*));        
    //Update element before inserted element
    Node *it1 = list->head;
    do {           
        new_addr[it1->index] = it1;
        it1 = it1->next;
    } while(it1->index < index);
    Node* prev = get_node(list, index - 1);
    node->prev = prev;
    prev->next = node;
    //Set element to the list's addresses by the current index
    new_addr[index] = node;
    //Update element after inserted element
    Node *it2 = get_node(list, index);       
    do {  
        if(it2->index == index) {
            node->next = it2;
            it2->prev = node;
        }
        it2->index++;
        new_addr[it2->index] = it2;
        it2 = it2->next;
    } while(it2 != NULL);    
    list->addr = new_addr;
    list->size++;
}

void insert(List *list, int value, unsigned int index) {
    Node *node = malloc(sizeof(Node));
    node->value = value; 
    node->index = index;
    if(index == list->tail->index + 1) {
        add(list, value);
    } else if(index == list->head->index) {
        insert_head(list, node);
    } else {
        insert_inside(list, node, index);
    }
}

void delete_head(List *list) {   
   if(list->size > 1) {
        Node *it = list->head->next;
        list->head->next->prev = NULL;
        list->head = list->head->next;   
        do {   
            it->index--;
            list->addr[it->index] = it;
            it = it->next;
        } while(it != NULL);          
   } else {
        list->head = list->tail = NULL;       
   } 
   list->size--;
}

void delete_inside(List *list, unsigned int index) {   
    Node *prev = get_node(list, index - 1);
    Node *next = get_node(list, index + 1);
    prev->next = next;
    next->prev = prev;
    Node *it = next;    
    do {   
        it->index--;
        list->addr[it->index] = it;
        it = it->next;
    } while(it != NULL);      
    list->size--;
}

void delete_tail(List *list) {  
    if(list->size > 1) {       
        Node *it = list->tail->prev;  
        list->tail->prev->next = NULL;
        list->tail = list->tail->prev;       
    } else {     
       list->head = list->tail = NULL;       
    }    
    list->size--;  
}

void delete(List *list, unsigned int index) {   
    if(index == 0) {
        delete_head(list);
    } else if(index == list->tail->index) {
        delete_tail(list);
    } else {
        delete_inside(list, index);
    }    
}

void delete_by_predicate(List *list, unsigned int (*function) (int, unsigned int, Node**)) {
    if(list->size > 0) {        
        Node *it = list->head;       
        do {
            if(function(it->value, it->index, list->addr) == 1) {
                delete(list, it->index);
            }            
            it = it->next;
        } while(it != NULL);
    }   
}

void delete_range(List *list, unsigned int from_index, unsigned int to_index) {
    if(list->size > 0) {        
        Node *it = get_node(list, from_index);  
        Node *last_node = get_node(list, to_index); 
        int counter = 0;
        do {            
            delete(list, it->index);      
            it = it->next;               
        } while(it != last_node->next);
    }   
}

void set_value(List *list, unsigned int index, int value) {
    list->addr[index]->value = value;
}

List* reverse_list(List *list) {
    List *reversed = init_list(list->size);
    Node *it = list->tail;
    do {
      add(reversed, it->value);  
      it = it->prev;  
    } while(it != NULL);
    return reversed;
}

void clear(List *list) {    
    do {
        delete_head(list);            
    } while(list->size > 0);
}

void print_list_values(List *list) {
    if(list->size > 0) {
        Node *it = list->head;
        printf("[");    
        do {   
            if(it->next == NULL) {
                printf("%d", it->value);
            } else {
                printf("%d, ", it->value);     
            }       
            it = it->next;
        } while(it != NULL);   
        printf("]\n"); 
    } else {
        printf("[]\n"); 
    }   
}

void print_list_indexes(List *list) {
    if(list->size > 0) {
        Node *it = list->head;
        printf("[");    
        do {   
            if(it->next == NULL) {
                printf("%d", it->index);
            } else {
                printf("%d, ", it->index);     
            }       
            it = it->next;
        } while(it != NULL);   
        printf("]\n"); 
    } else {
        printf("[]\n"); 
    }      
}

void print_list_addr(List *list) {
    if(list->size > 0) {
        unsigned int index = 0;
        printf("[");    
        do {
            if(index == list->size - 1) {
                printf("%d", list->addr[index]);
            } else {
                printf("%d, ", list->addr[index]);     
            }   
            index++;    
        } while(index < list->size);
        printf("]\n"); 
    } else {
        printf("[]\n");
    }  
}

void print_list_info(List *list) {
    print_list_values(list);
    print_list_indexes(list);
    print_list_addr(list);
}

void for_each(List* list, void (*function) (int, unsigned int, Node**)) {
    if(list->size > 0) {        
        Node *it = list->head;       
        do {
            function(it->value, it->index, list->addr);
            it = it->next;
        } while(it != NULL);
    }   
}

List* map(List *list, int (*function) (int, unsigned int, Node**)) {
    List *new_list = init_list(list->size);
    if(list->size > 0) {        
        Node *it = list->head;       
        do {
            add(new_list, function(it->value, it->index, list->addr));
            it = it->next;
        } while(it != NULL);
    }   
    return new_list;
}

int reduce(List *list, int (*function) (int, int, unsigned int, Node**)) {
    int result = 0;
    if(list->size > 0) {        
        Node *it = list->head;       
        do {
            result = function(result, it->value, it->index, list->addr);           
            it = it->next;
        } while(it != NULL);
    }   
    return result;
}

unsigned int contains(List *list, int value) {
    if(list->size > 0) {
        Node *it = list->head;
        do {
            if(it->value == value) {
                return 1;
            }
            it = it->next;
        } while(it != NULL);
    }
    return 0;
}

unsigned int is_empty(List *list) {
    return list->size == 0;
}

unsigned int size(List *list) {
    return list->size;
}

int* to_array(List *list) {
    int *array = (int*) malloc(list->size);    
    if(list->size > 0) {
        Node *it = list->head;
        do {
            array[it->index] = it->value;  
            it = it->next;
        } while(it != NULL);
    }    
    return array;
}

List* clone(List *list) {
    List *cloned_list = init_list(list->size);
    if(list->size > 0) {
        Node *it = list->head;
        do {
            add(cloned_list, it->value);  
            it = it->next;
        } while(it != NULL);
    }
    return cloned_list;
}