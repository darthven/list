#include "list.h"

int main()
{
    List *list = init_list(10);
    printf("Size: %d\n", list->size);

    add(list, 1);
    add(list, 2);
    add(list, 3);
    add(list, 4);
    add(list, 5);
    insert(list, 6, 5);
    insert(list, 22, 0);
    insert(list, 101, 2);    

    print_list_values(list);
    print_list_indexes(list);
    print_list_addr(list);
    printf("Index 4: %d", get_value(list, 4));

    return 0;
}