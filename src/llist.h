#ifndef LLIST_H
#define LLIST_H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct Node_t {
    int val;
    struct Node_t *next;
} Node_t;

typedef struct lList_t {
    int len;
    Node_t *head;
    Node_t *tail;
 
    void (*append)(struct lList_t *self, int val);

    void (*insert)(struct lList_t *llist, int idx, int val);

    int (*remove)(struct lList_t *llist, int idx);

    int  (*popLast)(struct lList_t *llist);

    int  (*pop)(struct lList_t *llist);

    bool (*search)(struct lList_t *llist, int val);

    void (*print)(struct lList_t *llist);

} lList_t;

void lListInit(lList_t *llist);
void lListFree(lList_t *llist);

#endif //LLIST_H

