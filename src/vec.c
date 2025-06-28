#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "vec.h"

#define UNUSED(x) (void)x

/** 
 * @return -1 in case of fail
 */
int vecAppend(Vec_t *vec, int val) {
    if (vec->idx_max == vec->len_max) {
        size_t new_cap = vec->len_max * 2;
        int *tmp = realloc(vec->array, new_cap * sizeof *tmp);
        if (!tmp) {
            return -1;
        }
        vec->array   = tmp;
        vec->len_max = new_cap;
    }

    vec->array[vec->idx_max++] = val;
    return 0;
}

void inline vecCopy(Vec_t *vec, int *val, size_t len) {
    for (int i = 0; i < len; i++) {
        val[i] = vec->array[i];
    }
}

Vec_t* createVec(const int *array, ...) {
    Vec_t *vec = malloc(sizeof(Vec_t));
    if (!vec) {
        fprintf(stderr, "memory allocation for vector failed\n");
        return NULL;
    }

    if (!array) {
        vec->array = malloc(sizeof(int) * 2);
        if (!vec->array) {
            fprintf(stderr, "memory allocation for array failed\n"); 
            free(vec);
            return NULL;
        }
        vec->idx_max = 0;
        vec->len_max = 2;
        goto attach_methods;
    }
    va_list ap;
    va_start(ap, array);
    size_t len = va_arg(ap, size_t);
    va_end(ap);
    
    if (len == 0) {
        fprintf(stderr, "size_t len cannot be zero\n"); 
        free(vec);
        return NULL;
    }

    vec->idx_max = len;

    len--;
    len |= len >> 1;
    len |= len >> 2;
    len |= len >> 4;
    len |= len >> 8;
    len |= len >> 16;

    len++;

    vec->len_max = len; 
    vec->array = malloc(sizeof(int) * len);
    
    if (!vec->array) {
        fprintf(stderr ,"memory allocation for array failed\n"); 
        free(vec);
        return NULL;
    }

    attach_methods:
    vec->append = &vecAppend;
    vec->copy = &vecCopy;

    return vec;

}

void freeVec(Vec_t *vec) {
    free(vec->array);
    free(vec);
}
