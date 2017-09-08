#include "list.h"

int main()
{
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

    List* reversed = reverse_list(list);
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

    return 0;
}