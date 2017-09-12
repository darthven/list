#include "list.h"

int sqr(int, unsigned int, Node **);
int reducer(int, int, unsigned int, Node **);
void print_values(int, unsigned int, Node **);
unsigned int predicate(int, unsigned int, Node **); 

int main() {
    List *list = init_list(10);
    printf("Before Size: %d\n", size(list));

    add(list, 1);
    add(list, 2);
    add(list, 3);
    add(list, 4);
    add(list, 5);
    insert(list, 6, 5);
    insert(list, 22, 0);
    insert(list, 101, 2);    

    printf("After Size: %d\n", size(list));
    
    print_list_info(list);
    printf("Index 4: %d\n", get_value(list, 4));

    delete(list, 0);
    insert(list, 666, 0);
    set_value(list, 1, 555);
    print_list_info(list);

    List *reversed = reverse_list(list);
    printf("REVERSED\n");
    print_list_info(reversed);

    printf("CLEARED\n");
    clear(list);
    print_list_info(list);
    printf("After Clear: %d\n", size(list));    
    printf("IS EMPTY\n");
    printf("%d\n", is_empty(list));

    printf("MAP\n");
    List *map_list = map(reversed, sqr);
    print_list_info(map_list);

    printf("FOR_EACH\n");
    for_each(reversed, print_values);

    printf("CONTAINS value 255: %d\n", contains(map_list, 255));
    printf("CONTAINS value 25: %d\n", contains(map_list, 25));
    printf("INDEX OF 166: %d\n", get_index(map_list, 166));
    printf("INDEX OF 16: %d\n", get_index(map_list, 16));


    printf("REDUCE\n");
    int result = reduce(reversed, reducer);
    printf("Reduce result %d\n", result);

    printf("CLONE\n");
    printf("ORIGINAL:\n");
    print_list_info(reversed);
    printf("COPY:\n");
    List *cloned = clone(reversed);
    print_list_info(cloned);

    printf("DELETE BY PREDICATE\n");
    List *cloned2 = clone(reversed);
    delete_by_predicate(cloned2, predicate);
    print_list_info(cloned2);

    printf("DELETE BY RANGE\n");
    printf("BEFORE:\n");
    print_list_info(cloned);
    delete_range(cloned, 2, 5);
    printf("AFTER:\n");
    print_list_info(cloned);

    printf("TO ARRAY\n");
    int *int_array = to_array(cloned);
    for(int i = 0; i < size(cloned); i++) {
        printf("%d ", int_array[i]);
    }   

    printf("ADD LIST\n");
    printf("DESTINATION LIST:\n");
    List *cloned3 = clone(reversed);
    print_list_info(cloned3);
    printf("SOURCE LIST:\n");
    List *cloned4 = clone(reverse_list(reversed));
    print_list_info(cloned4);
    printf("RESULT LIST:\n");
    add_list(cloned3, cloned4);
    print_list_info(cloned3);


    printf("FIRST/LAST\n");
    List *cloned5 = clone(reversed);
    print_list_info(cloned5);
    add_first(cloned5, 111);
    add_last(cloned5, 999);
    print_list_info(cloned5);

    printf("PEEK/POLL/POP");
    printf("BEFORE:\n");
    print_list_info(cloned5);    
    printf("Peek value %d\n", peek(cloned5));
    print_list_info(cloned5);    
    printf("Poll value %d\n", poll(cloned5));
    print_list_info(cloned5);  
    printf("Pop value %d\n", pop(cloned5));
    print_list_info(cloned5);  
    printf("Push value %d\n", 123);
    push(cloned5, 123);
    print_list_info(cloned5); 

    printf("CHANGE CAPACITY\n");
    change_capacity(cloned5, 4);
    print_list_info(cloned5);   


    return 0;
}

unsigned int predicate(int value, unsigned int index, Node **array_of_nodes) {
    if(value >= 2 && value <= 6) {
        return 1;
    }
    return 0;
}

void print_values(int value, unsigned int index, Node **array_of_nodes) {
    printf("Element[%d] = %d\n", index, value);
}

int sqr(int value, unsigned int index, Node **array_of_nodes) {
    return value * value;
}

int reducer(int prev_value, int next_value, unsigned int index, Node **array_of_nodes) {
    return prev_value + next_value;
}