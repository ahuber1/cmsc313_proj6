#ifndef circular_c
#define circular_c

#include <stdio.h>
#include <stdlib.h>
#include "circular.h"

//Initialize a circular buffer and return a pointer that can be used to specify that circular buffer in future function calls.
cbuf * cbuf_init() {
    cbuf * cbuf_ptr = (cbuf*) malloc(sizeof(cbuf));
    cbuf buf = *cbuf_ptr;
    
    buf.buf = (cbuf_data*) malloc(sizeof(cbuf_data) * INITIAL_BUFFER_SIZE);
    buf.first = 0;
    buf.size = INITIAL_BUFFER_SIZE;
    buf.num = 0;
    
    int i;
    
    for (i = 0; i < INITIAL_BUFFER_SIZE; i++) {
        cbuf_data data = buf.buf[i];
        data.next = 0;
        data.q_ptr = 0;
    }
    
    return cbuf_ptr;
}

//Deallocate all dynamically allocated memory associated with the circular buffer referenced by cb_ptr. The programmer using your ADT promises to never use the value in cb_ptr again.
void cbuf_delete(cbuf *cb_ptr) {
    if (cb_ptr != 0) {
        cbuf buf = *cb_ptr;
        
        int i = 0;
        
        for (i = 0; i < buf.size; i++) {
            cbuf_data data = buf.buf[i];
            quote * q_ptr = data.q_ptr;
            free(q_ptr);
            free(&data);
        }
        
        void * ptr = cb_ptr;
        free(ptr);
    }
}

#endif