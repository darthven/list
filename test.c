#include "list.h"

int sqr(int, int, Node **);
int reducer(int, int, int, Node **);

int main() {
    List *list = init_list(10);
    printf("Before Size: %d\n", list->size);

    add(list, 1);
    add(list, 2);
    add(list, 3);
    add(list, 4);
    add(list, 5);
    insert(list, 6, 5);
    insert(list, 22, 0);
    insert(list, 101, 2);    

    printf("After Size: %d\n", list->size);
    
    print_list_values(list);
    print_list_indexes(list);
    print_list_addr(list);
    printf("Index 4: %d\n", get_value(list, 4));

    delete(list, 0);
    insert(list, 666, 0);
    set_value(list, 1, 555);
    print_list_values(list);
    print_list_indexes(list);
    print_list_addr(list);

    List *reversed = reverse_list(list);
    printf("REVERSED\n");
    print_list_values(reversed);
    print_list_indexes(reversed);
    print_list_addr(reversed);

    printf("CLEARED\n");
    clear(list);
    print_list_values(list);
    print_list_indexes(list);
    print_list_addr(list);
    printf("After Clear: %d\n", list->size);

    printf("MAP\n");
    List *map_list = map(reversed, sqr);
    print_list_values(map_list);
    print_list_indexes(map_list);
    print_list_addr(map_list);

    printf("CONTAINS value 255: %d\n", contains(map_list, 255));
    printf("CONTAINS value 25: %d\n", contains(map_list, 25));
    printf("INDEX OF 166: %d\n", get_index(map_list, 166));
    printf("INDEX OF 16: %d\n", get_index(map_list, 16));


    printf("REDUCE\n");
    int result = reduce(reversed, reducer);
    printf("Reduce result %d\n", result);
    return 0;
}

int sqr(int value, int index, Node **array_of_nodes) {
    return value * value;
}

int reducer(int prev_value, int next_value, int index, Node **array_of_nodes) {
    return prev_value + next_value;
}