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

typedef struct CircularBuf_t
{
    int data[BUFFER_MAX_SIZE];
    int head;
    int tail;
    size_t currBuffLength;
    //TODO - possibly add 'isfull' boolean.
} CircularBuf_t;

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
void peek_at_buf(CircularBuf_t *buffer, int amount_to_peak)
{
    printf("These are the first %d item(s) in the buffer\n\n", amount_to_peak);

    int index = buffer->tail;  
    
    if(amount_to_peak > buffer->currBuffLength)
    {
        printf("Error attempted to peek more than current buffer length!\n");
        return;
    }

    for(int i = 0 ; i < amount_to_peak; i++ , index++)
    {
        if(index == BUFFER_MAX_SIZE)
        {
            index = 0;
        }

        printf("Item at index %d is %d\n", index, buffer->data[index]);

    }

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
        int index = buffer->tail;

        printf("\t--------\n");
        for(int i = 0; i < buffer->currBuffLength; i++, index++)
        {
            if(index == BUFFER_MAX_SIZE)
            {
                index = 0;
            }
            printf("The buffer space %d contains the data %d\n", index , buffer->data[index]);
        }
        printf("\t--------\n");
    }
    
}
//=====================================================================
void add_to_buf(CircularBuf_t *buffer, int data)
{

    //check if head at end of buffer.
    if(buffer->head == BUFFER_MAX_SIZE)
    {
        buffer->head = 0;
    }

    //Check if buffer is full so we don't increment buffer length
    if(buffer->currBuffLength >= BUFFER_MAX_SIZE)
    {
        printf("Added %d to buffer, at space %d\n", data, buffer->head);
        buffer->data[buffer->head] = data;
        buffer->head++;
        
    }
    else
    {
        printf("Added %d to buffer, at space %d\n", data,buffer->head);
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