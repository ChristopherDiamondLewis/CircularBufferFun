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

    add_to_buf(&circular_buff, 10);
    add_to_buf(&circular_buff, 15);
    add_to_buf(&circular_buff, 20);
    add_to_buf(&circular_buff, 70);
    add_to_buf(&circular_buff, 23);
    add_to_buf(&circular_buff, 75);
    add_to_buf(&circular_buff, 78);
    add_to_buf(&circular_buff, 47);
    add_to_buf(&circular_buff, 18);
    add_to_buf(&circular_buff, 98);
    add_to_buf(&circular_buff, 105);

    printf("Current buffer length is :%ld\n", circular_buff.currBuffLength);        
    print_buf(&circular_buff);
    
    printf("Current buffer length is :%ld\n", circular_buff.currBuffLength);
    add_to_buf(&circular_buff, 412);


    peek_at_buf(&circular_buff, 7);
    
    print_buf(&circular_buff);
    printf("Current buffer length is :%ld\n", circular_buff.currBuffLength);


   

    return 0;
}