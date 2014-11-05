#ifndef circular_c
#define circular_c
#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>
#include "circular.h"

cbuf * cbuf_init_with_size(unsigned int size) {
    if (size < INITIAL_BUFFER_SIZE) {
        return cbuf_init_with_size(INITIAL_BUFFER_SIZE);
    }
    else {
        cbuf * cbuf_ptr = (cbuf*) malloc(sizeof(cbuf));
        cbuf buf = *cbuf_ptr;
        
        buf.head = 0;
        buf.tail = 0;
        buf.num = 0;
        buf.size = size;
        buf.buf = (quote **) malloc(sizeof(sizeof(quote*) * buf.size));

        int i;
        
        for(i = 0; i < buf.size; i++) {
            buf.buf[i] = 0;
        }
        
        return cbuf_ptr;
    }
}

int compare_quotes(quote * quote1_ptr, quote * quote2_ptr) {
    quote quote1 = *quote1_ptr;
    quote quote2 = *quote2_ptr;
    return ((int) quote1.time) - ((int) quote2.time);
}

unsigned int increment_index(unsigned int index, unsigned int size) {
    if (index + 1 == size)
        return 0;
    else
        return index + 1;
}

//unsigned int decrement_index(unsigned int index, unsigned int size) {
//    if (index == 0) {
//        return size - 1;
//    }
//    else {
//        return index - 1;
//    }
//}

void remove_from_head(cbuf * cb_ptr) {
    cbuf cb = *cb_ptr;
    cb.buf[cb.head] = 0;
    cb.head = increment_index(cb.head, cb.size);
    cb.num--;
}

void add_to_tail(cbuf * cb_ptr, quote * q) {
    cbuf cb = *cb_ptr;
    cb.buf[cb.tail] = q;
    cb.tail = increment_index(cb.tail, cb.size);
    cb.num++;
}

void cbuf_update_with_quote_ptr(cbuf * cb_ptr, quote * quote_to_add, quote * quote_to_compare) {
    cbuf cb = *cb_ptr;
    int i = cb.head;
    
    while (i != cb.tail) {
        if (compare_quotes(cb.buf[i], quote_to_compare) <= 0) {
            remove_from_head(cb_ptr);
        }
    }
    
    add_to_tail(cb_ptr, quote_to_add);
}

void cb_move(cbuf * orig_ptr, cbuf * new_ptr) {
    cbuf orig = *orig_ptr;
    
    unsigned int counter;
    unsigned int index;
    
    for (counter = 0, index = orig.head; counter < orig.size; counter++, index = increment_index(index, orig.size)) {
        add_to_tail(new_ptr, orig.buf[index]);
    }
    
    free(orig_ptr);
}

unsigned int num_digits(int num) {
    const unsigned int SIZE = 10;
    char str[SIZE];
    sprintf(str, "%d", num);
    unsigned int counter;
    
    for (counter = 0; counter < SIZE; counter++) {
        if (str[counter] == '\0') {
            return counter;
        }
    }
    
    return SIZE;
}

cbuf * cbuf_init() {
    return cbuf_init_with_size(INITIAL_BUFFER_SIZE);
}

void cbuf_delete(cbuf *cb_ptr) {
    if (cb_ptr != 0) {
        cbuf buf = *cb_ptr;        
        free(buf.buf);
        free(cb_ptr);
    }
}

void cbuf_update(cbuf *cb_ptr, unsigned int time, double rate) {
    if (cb_ptr != 0) {
        quote * new_quote_ptr = (quote *) malloc(sizeof(quote));
        quote new_quote = *new_quote_ptr;
        new_quote.time = time;
        new_quote.rate = rate;
        
        unsigned int min_time;
        
        if(time <= MAX_TIME_IN_SEC)
            min_time = 0;
        else
            min_time = time - MAX_TIME_IN_SEC;
        
        quote * compare_quote_ptr = (quote *) malloc(sizeof(quote));
        quote compare_quote = *compare_quote_ptr;
        compare_quote.time = min_time;
        compare_quote.rate = 0.0;
        
        cbuf_update_with_quote_ptr(cb_ptr, new_quote_ptr, compare_quote_ptr);
        
        cbuf cb = *cb_ptr;
        
        if(cb.size != INITIAL_BUFFER_SIZE && cb.num < (cb.size / 4)) {
            printf("Shrinking buffer from size %d to size %d\n", cb.size, cb.size / 2);
            cbuf * new_ptr = cbuf_init_with_size(cb.size / 2);
            cb_move(cb_ptr, new_ptr);
            cb_ptr = new_ptr;
        }
        else if(cb.size == cb.num) {
            printf("Expanding buffer from size %d to size %d\n", cb.size, cb.size * 2);
            cbuf * new_ptr = cbuf_init_with_size(cb.size * 2);
            cb_move(cb_ptr, new_ptr);
            cb_ptr = new_ptr;
        }
    }
}

double cbuf_average(cbuf *cb_ptr) {
    if(cb_ptr != 0) {
        cbuf cb = *cb_ptr;
        quote * q_ptr;
        quote q;
        
        double sum = 0.0;
        int index;
        int counter;
        
        for (counter = 0, index = cb.head; counter < cb.num; counter++, index = increment_index(index, cb.size)) {
            q_ptr = cb.buf[index];
            q = *q_ptr;
            sum = sum + q.rate;
        }
        
        return sum / cb.num;
    }
    else
        return 0.0;
}

quote * cbuf_start(cbuf *cb_ptr) {
    if (cb_ptr != 0) {
        cbuf cb = *cb_ptr;
        return cb.buf[cb.head];;
    } else {
        return 0;
    }
}

quote * cbuf_end(cbuf *cb_ptr) {
    if (cb_ptr != 0) {
        cbuf cb = *cb_ptr;
        return cb.buf[cb.tail];;
    } else {
        return 0;
    }
}

void print_header(cbuf * cb_ptr) {
    cbuf cb = *cb_ptr;
    printf("*** Circular Buffer Dump ***\n");
    printf("size = %d, max = %d\n", cb.num, cb.size);
    printf("start = %d, end = %d\n", cb.head, cb.tail);
    printf("\n");
}

void print_footer() {
   printf("******************************\n\n\n");
}

void cbuf_dump(cbuf *cb_ptr) {
    if (cb_ptr != 0) {
        cbuf cb = *cb_ptr;
        quote * q_ptr;
        quote q;
        
        int index;
        int counter;
        
        char format_str[50];
        sprintf(format_str, "%%%dd: time = %%d, rate = %%d\n", num_digits(cb.size - 1));
        
        print_header(cb_ptr);
        
        for (counter = 0, index = cb.head; counter < cb.num; counter++, index = increment_index(index, cb.size)) {
            q_ptr = cb.buf[index];
            q = *q_ptr;
            printf(format_str, index, q.time, q.rate);
        }
        
        print_footer();
    }
}

//Same as cbuf_dump() but does not print out the quotes.
void cbuf_stats(cbuf *cb_ptr) {
    if (cb_ptr != 0) {
        print_header(cb_ptr);
        print_footer();
    }
}

#endif