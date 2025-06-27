#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

void lListAppend(lList_t *llist, int val) {
    Node_t *new_node = malloc(sizeof(Node_t));
    if (!new_node) {
        printf("mem alloc failed for new node.\n");
        return;
    }

    new_node->next = NULL;
    new_node->val = val;

    llist->len++;
    if (!llist->head) {
        llist->head = new_node;
        llist->tail = new_node;
    }else {
        llist->tail->next = new_node;
        llist->tail = new_node;
    }
}

void lListInsert(lList_t *llist, int idx, int val) {
    if (idx < 0 || idx > llist->len) {
        printf("Index out of bounds.\n");
        return;
    }
    Node_t *new_node = malloc(sizeof(Node_t));
    if (!new_node) {
        printf("mem alloc failed for new node.\n");
        return;
    }
    new_node->val = val;
    new_node->next = NULL;

    if (idx == 0) {
        new_node->next = llist->head;
        llist->head = new_node;
        if (llist->len == 0) llist->tail = new_node;
    }else {
        Node_t *curr = llist->head;
        for (int i = 0; i < idx - 1; i++) {
            curr = curr->next; 
        }
        new_node->next = curr->next;
        curr->next = new_node;
        if (new_node->next == NULL) llist->tail = new_node;
    }
    llist->len++;
}

int lListRemove(lList_t *llist, int idx) {
    if (!llist->len) {
        printf("the linked list is already empty\n");
        return -1;
    }
    if (idx < 0 || idx >= llist->len) {
        printf("Index out of bounds.\n");
        return -1;
    }

    int val;
    if (idx == 0) {
        Node_t *old_node = llist->head;
        val = old_node->val;
 
        llist->head = old_node->next;
        free(old_node);
        if (llist->head == NULL) llist->tail = NULL;

    }else {
        Node_t *curr = llist->head;
        for (int i = 0; i < idx - 1 ; i++) {
            curr = curr->next;
        }

        Node_t *old_node = curr->next;
        val = old_node->val;

        curr->next = old_node->next;

        free(old_node);
        if (curr->next == NULL) llist->tail = curr;
    }
    llist->len--;
    return val;
}

int lListPopLast(lList_t *llist) {
    return lListRemove(llist, llist->len - 1);
}

int lListPop(lList_t *llist){
    return lListRemove(llist, 0);
}

bool lListSearch(lList_t *llist, int val) {
    Node_t *curr = llist->head;
    while (curr) {
        if (curr->val == val) return true;
        curr = curr->next;
    }
    return false;
}

void lListPrint(lList_t *llist) {
    printf("[");
    for (Node_t *n = llist->head; n; n = n->next)
        printf("%d%s", n->val, n->next ? ", " : "");
    printf("]\n");
}

void lListInit(lList_t *llist){
    llist->len = 0;
    llist->head = NULL;
    llist->tail = NULL;

    llist->append = &lListAppend;
    llist->insert = &lListInsert;
    llist->remove = &lListRemove;
    llist->popLast= &lListPopLast;
    llist->pop    = &lListPop;
    llist->search = &lListSearch;
    llist->print  = &lListPrint;
}

void lListFree(lList_t *llist){
    Node_t* curr = llist->head;
    while (curr) {
        Node_t *next = curr->next;
        free(curr);
        curr = next;
    }
    llist->head = NULL;
    llist->tail = NULL;
    llist->len = 0;
}





