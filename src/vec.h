#ifndef VEC_H
#define VEC_H

#include <stdarg.h>
#include <stddef.h>

#define MIN_VEC_SIZE 2

typedef struct Vec_t {
    int *array;
    size_t len_max; // 8 16 32 64...
    int idx_max;
    // methods
    int (*append)(struct Vec_t *vec, int val);

    //copies the list to primitive array "target"
    void (*copy)(struct Vec_t *vec, int* target, size_t len); 
}Vec_t;

Vec_t* createVec(const int *array, ...);
void freeVec(Vec_t *vec);

#endif //VEC_H
