#include <stdio.h>
#include "llist.h"
#include "vec.h"

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

    Vec_t *vec1 = createVec(NULL);
    Vec_t *vec2 = createVec((int[]){1,2,3,4,5,6}, 6);

    vec1->append(vec1, 3);

    printf("vec1 len: %d, vec1 idx: %d\n", vec1->len_max, vec1->idx_max);
    freeVec(vec1);
    printf("vec2 len: %d, vec2 idx: %d\n", vec2->len_max, vec2->idx_max);
    freeVec(vec2);

    return 0;
}
