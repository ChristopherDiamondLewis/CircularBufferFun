/*
*
*   Implimentation file for my simple circular buffer.
*
*   @author Christopher Lewis
*   @date 2/7/2021
*
*
*/

#include "CircularBuffer.h"

//=====================================================================
void init_buf(CircularBuf_t *buffer)
{
    for(int i = 0 ; i < BUFFER_MAX_SIZE; i++)
    {
        buffer->data[i] = 0;
    }

    buffer->head = 0;
    buffer->tail = 0;
    buffer->currBuffLength = 0;
}
//=====================================================================
void peek_at_buf(CircularBuf_t *buffer)
{
    printf("First item in buffer is: %d\n", buffer->data[buffer->tail]);
}
//=====================================================================
void print_buf(CircularBuf_t *buffer)
{

    if(buffer->currBuffLength == 0)
    {
        printf("Buffer is EMPTY!\n");
    }
    else
    {
        printf("\t--------\n");
        for(int i = buffer->tail; i < buffer->head; i++)
        {
            printf("The buffer space %d contains the data %d\n", i , buffer->data[i]);
        }
        printf("\t--------\n");
    }
    
}
//=====================================================================
void add_to_buf(CircularBuf_t *buffer, int data)
{

    //Check if buffer is full
    if(buffer->currBuffLength == BUFFER_MAX_SIZE)
    {
        // if buffer is full we will not evict, just stop from adding.
        printf("UNABLE TO ADD MORE TO BUFFER!\n");
    }
    else
    {
        printf("Added %d to buffer\n", data);
        buffer->data[buffer->head] = data;
        buffer->head++;
        buffer->currBuffLength++;
    }
}
//=====================================================================


void remove_from_buf(CircularBuf_t *buffer)
{
    printf("Removing %d from buffer\n", buffer->data[buffer->tail]);
    buffer->data[buffer->tail] = 0; //< 0 to indicate nothing in that location.
    buffer->tail++;
    buffer->currBuffLength--;

}