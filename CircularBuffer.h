#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#ifndef CIRCULAR_BUF_H_
#define CIRCULAR_BUF_H_

#define BUFFER_MAX_SIZE 10

typedef struct CircularBuf_t
{
    int data[BUFFER_MAX_SIZE];
    int head;
    int tail;
    size_t currBuffLength;

} CircularBuf_t;

/*
*   Function to initialize buffer, it will set all values of the circular buffer
*       to 0 and run loop to inittialize interal data array to 0 just to be safe.
*
*   @param - buffer , of type pointer to a CircularBuf_t
*
*   @TODO Want to eventually make this dynamic so that making a new buffer you can
*           initialize it to any max capacity you want.
*/
        void init_buf(CircularBuf_t *buffer);

/*
*   Function will print the entirety of used space on a passed in circular buffer,
*       meaning this will print from the tail of the buffer up to the head. 
*
*   @param -  buffer , of type pointer to a CircularBuf_t
*
*/
        void print_buf(CircularBuf_t *buffer);

/*
*   Function that will add to the head of the buffer, if the buffer is at max capacity
*       the function will not add the passed in data, until another space is free'd up.
*
*   @param -  buffer , of type pointer to a CircularBuf_t
*   @param -  data   , of type int meant to be the data wanted to be added.
*
*   @TODO - eventually want to add 'eviction' so when trying to add data past capacity, it will overwrite
*               data instead of failing.
*   
*/
        void add_to_buf(CircularBuf_t *buffer, int data);

/*
*   Function that will remove the data from the tail of the buffer.
*
*   @param -  buffer , of type pointer to a CircularBuf_t
* 
*   @TODO - figure out some edge cases to check before removing from the tail.
*/
        void remove_from_buf(CircularBuf_t *buffer);

/*
*   Function that will print or 'peek' at the element located at the tail of the buffer.
*
*   @param -  buffer , of type pointer to a CircularBuf_t
* 
*   @TODO - figure out some edge cases to check before removing from the tail.
*/
        void peek_at_buf(CircularBuf_t *buffer);

#endif