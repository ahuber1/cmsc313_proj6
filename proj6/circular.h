// Comments

#ifndef circular_h
#define circular_h
#define INITIAL_BUFFER_SIZE 10
#define MAX_TIME_IN_SEC 300

typedef struct {
    unsigned int time;
    double rate;
} quote;

typedef struct {
    quote ** buf;
    unsigned int head;
    unsigned int tail;
    unsigned int size;
    unsigned int num;
} cbuf;

//Initialize a circular buffer and return a pointer that can be used to specify that circular buffer in future function calls.
cbuf * cbuf_init() ;

//Deallocate all dynamically allocated memory associated with the circular buffer referenced by cb_ptr. The programmer using your ADT promises to never use the value in cb_ptr again.
void cbuf_delete(cbuf *cb_ptr) ;

//Add a new currency exchange quote to the specified circular buffer. The time is in seconds since midnight. This function should remove any quotes in the circular buffer that are more than 5 minutes older than this quote. You should assume that the timestamps given to cbuf_update() are in non-decreasing order. During a cbuf_update(), the memory for the circular buffer may have to grow or shrink according to the rules described above.To assist in grading, please print out a diagnostic message with the old and new maximum sizes of your circular buffer when you either grow or shrink the buffer.
void cbuf_update(cbuf *cb_ptr, unsigned int time, double rate) ;

//Return the average exchange rate of the quotes currently stored in the buffer.
double cbuf_average(cbuf *cb_ptr) ;

//Return a pointer to the earliest quote currently stored in the buffer. (Earliest = smallest timestamp) The programmer using your ADT promises to just "look at" the quote and not alter it in any way.
quote *cbuf_start(cbuf *cb_ptr) ;

//Return a pointer to the latest quote currently stored in the buffer. (Latest = largest timestamp) The programmer using your ADT promises to just "look at" the quote and not alter it in any way.
quote *cbuf_end(cbuf *cb_ptr) ;

//Print the contents of the circular buffer to standard output. The output should be formatted nicely and also print out the current size, maximum size and the indices of the start and end of the buffer. (See sample runs linked below.)
void cbuf_dump(cbuf *cb_ptr) ;

//Same as cbuf_dump() but does not print out the quotes.
void cbuf_stats(cbuf *cb_ptr) ;

#endif