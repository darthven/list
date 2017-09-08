#include "list.h"

List* init_list(int size) 
{
    List *list = malloc(size * sizeof(Node));
    Node** addr = malloc(size * sizeof(Node*));
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    list->addr = addr;    
}

void add(List *list, int value) 
{
    Node *node = malloc(sizeof(Node));
    node->value = value;    
    node->next = NULL;
    if(list->head == NULL) 
    {        
        node->index = 0;
        node->prev = NULL;        
        list->head = node; 
    } else if(list->tail == NULL) 
    {       
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
    list->addr[node->index] = node;
}

Node* get_node(List *list, int index) 
{    
    return list->addr[index];
} 

int get_value(List *list, int index) 
{    
    return get_node(list, index)->value;
}   

void insert_head(List* list, Node* node) 
{    
    Node** new_addr = malloc((list->size + 1) * sizeof(Node*));    
    new_addr[0] = node;
    Node *it = list->head;
    do 
    {   
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

void insert_inside(List* list, Node* node, int index) 
{   
    Node** new_addr = malloc((list->size + 1) * sizeof(Node*));        
    //Update element before inserted element
    Node *it1 = list->head;
    do 
    {           
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
    do 
    {  
        if(it2->index == index) 
        {
            node->next = it2;
            it2->prev = node;
        }
        it2->index++;
        new_addr[it2->index] = it2;
        it2 = it2->next;
    } while(it2 != NULL); 
    
    //Update list addresses
    list->addr = new_addr;
    list->size++;
}

void insert(List *list, int value, int index) 
{
    Node *node = malloc(sizeof(Node));
    node->value = value; 
    node->index = index;
    if(index == list->tail->index + 1) 
    {
        add(list, value);
    } else if(index == list->head->index) 
    {
        insert_head(list, node);
    } else 
    {
        insert_inside(list, node, index);
    }
}

void delete_head(List *list)
{   
   if(list->size > 1)
   {
        Node *it = list->head->next;
        list->head->next->prev = NULL;
        list->head = list->head->next;   
        do 
        {   
            it->index--;
            list->addr[it->index] = it;
            it = it->next;
        } while(it != NULL);      
        list->size--;
   } else
   {
        list->head = list->tail = NULL;
        list->size--;
   } 
}

void delete_inside(List *list, int index)
{   
    Node* prev = get_node(list, index - 1);
    Node* next = get_node(list, index + 1);
    prev->next = next;
    next->prev = prev;
    Node *it = next;    
    do 
    {   
        it->index--;
        list->addr[it->index] = it;
        it = it->next;
    } while(it != NULL);      
    list->size--;
}

void delete_tail(List *list)
{  
    if(list->size > 1)
    {       
        Node *it = list->tail->prev;  
        list->tail->prev->next = NULL;
        list->tail = list->tail->prev;
        list->size--;  
    } else
    {     
       list->head = list->tail = NULL;
       list->size--;
    }    
}

void delete(List *list, int index)
{   
    if(index == 0) 
    {
        delete_head(list);
    } else if(index == list->tail->index)
    {
        delete_tail(list);
    } else 
    {
        delete_inside(list, index);
    }    
}

void set_value(List* list, int index, int value)
{
    list->addr[index]->value = value;
}

List* reverse_list(List* list) 
{
    List* reversed = init_list(list->size);
    Node* it = list->tail;
    do 
    {
      add(reversed, it->value);  
      it = it->prev;  
    } while(it != NULL);
    return reversed;
}

void clear(List* list)
{    
    do
    {
        delete_head(list);            
    } while(list->size > 0);
}

void print_list_values(List *list) 
{
    if(list->size > 0)
    {
        Node *it = list->head;
        printf("[");    
        do 
        {   
            if(it->next == NULL) 
            {
                printf("%d", it->value);
            } else 
            {
                printf("%d, ", it->value);     
            }       
            it = it->next;
        } while(it != NULL);   
        printf("]\n"); 
    } else 
    {
        printf("[]\n"); 
    }   
}

void print_list_indexes(List *list) 
{
    if(list->size > 0) {
        Node *it = list->head;
        printf("[");    
        do 
        {   
            if(it->next == NULL) 
            {
                printf("%d", it->index);
            } else 
            {
                printf("%d, ", it->index);     
            }       
            it = it->next;
        } while(it != NULL);   
        printf("]\n"); 
    } else
    {
        printf("[]\n"); 
    }      
}

void print_list_addr(List *list) 
{
    if(list->size > 0) 
    {
        int index = 0;
        printf("[");    
        do {
            if(index == list->size - 1)
            {
                printf("%d", list->addr[index]);
            } else 
            {
                printf("%d, ", list->addr[index]);     
            }   
            index++;    
        } while(index < list->size);
        printf("]\n"); 
    } else
    {
        printf("[]\n");
    }  
}