/*
*   @author Christopher Lewis  
*
*   @date 2/6/21 
*
*
*   Just some fun making a simple circular buffer and testing it out :)
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define BUFFER_MAX_SIZE 10

typedef struct CircularBuf_t
{
    int data[BUFFER_MAX_SIZE];
    int head;
    int tail;
    size_t currBuffLength;

} CircularBuf_t;

void init_buf(CircularBuf_t *buffer);
void print_buf(CircularBuf_t *buffer);
void add_to_buf(CircularBuf_t *buffer, int data);
void remove_from_buf(CircularBuf_t *buffer);
void peek_at_buf(CircularBuf_t *buffer);

int main()
{
    srand(time(0));

    CircularBuf_t circular_buff;

    init_buf(&circular_buff);

    add_to_buf(&circular_buff, 42);
    add_to_buf(&circular_buff, 73);
    add_to_buf(&circular_buff, rand() % 100);
    peek_at_buf(&circular_buff);

    print_buf(&circular_buff);

    remove_from_buf(&circular_buff);
    peek_at_buf(&circular_buff);
    print_buf(&circular_buff);

    add_to_buf(&circular_buff, rand() % 100);
    add_to_buf(&circular_buff, rand() % 100);
    add_to_buf(&circular_buff, rand() % 100);
    add_to_buf(&circular_buff, rand() % 100);
    print_buf(&circular_buff);

    peek_at_buf(&circular_buff);
    remove_from_buf(&circular_buff);
    peek_at_buf(&circular_buff);
    print_buf(&circular_buff);



    return 0;
}

void peek_at_buf(CircularBuf_t *buffer)
{
    printf("First item in buffer is: %d\n", buffer->data[buffer->tail]);
}
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
        buffer->data[buffer->head] = data;
        buffer->head++;
        buffer->currBuffLength++;
    }

   
}


void remove_from_buf(CircularBuf_t *buffer)
{
    buffer->data[buffer->tail] = 0; //< 0 to indicate nothing in that location.
    buffer->tail++;
    buffer->currBuffLength--;

}