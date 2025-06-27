#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "vec.h"

#define UNUSED(x) (void)x

void vecAppend(Vec_t *vec, int val) {
    printf("not implemented yet\n");
    UNUSED(vec);
    UNUSED(val);
}

void vecCopy(Vec_t *vec, int *val, size_t len) {
    printf("not implemented yet\n");
    UNUSED(vec);
    UNUSED(val);
    UNUSED(len);
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
