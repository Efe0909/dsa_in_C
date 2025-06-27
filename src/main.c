#include <stdio.h>
#include "llist.h"

int main() {
    lList_t list;

    lListInit(&list);

    list.append(&list, 0);
    list.append(&list, 1);
    list.append(&list, 2);
    
    list.insert(&list, 3, 33);

    list.append(&list, 3);
    list.append(&list, 4);

    list.print(&list);

    printf("poped 1st element: %d\n", list.pop(&list));

    list.remove(&list, 4);
    list.print(&list);
    lListFree(&list);
    return 0;
}
