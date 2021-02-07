/*
*   @author Christopher Lewis  
*
*   @date 2/6/21 
*
*
*   Just some fun making a simple circular buffer and testing it out :)
*/

#include "CircularBuffer.h"

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