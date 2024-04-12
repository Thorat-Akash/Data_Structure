/**
 * @file use_list.c
 * @author Akash_Thorat
 * @brief A program to demonstrate the usage of the linked list implementation.
 * @version 0.1
 * @date 2024-04-12
 *
 * This program demonstrates various operations on a singly linked list, including
 * insertion, deletion, popping, sorting, and searching. It also verifies the functionality
 * of the linked list implementation provided in the "list.h" header file.
 *
 * The program starts by creating an empty list and then performs a series of operations
 * such as inserting elements, removing elements, popping elements, and sorting the list.
 * Finally, it destroys the list and frees the memory.
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

int main(void)
{
    list_t* p_list = NULL;
    data_t data = 0;
    len_t length = 0;
    status_t status;

    // Start of the program
    puts("PROGRAM START");

    // Create an empty list
    p_list = create_list(); 
    
    // Assertions to verify the initial state of the list
    assert(p_list != NULL);
    assert(is_list_empty(p_list));
    assert(LIST_EMPTY == get_start(p_list, &data));
    assert(LIST_EMPTY == get_end(p_list, &data));
    assert(LIST_EMPTY == remove_start(p_list));
    assert(LIST_EMPTY == remove_end(p_list));
    assert(LIST_EMPTY == pop_start(p_list, &data));
    assert(LIST_EMPTY == pop_end(p_list, &data));
    assert(0 == size(p_list));

    // Insert 20 random elements at the end of the list
    for(int i = 0; i < 20; ++i)
        assert(SUCCESS == insert_end(p_list, rand()/10000));
    show(p_list, "After insert 20 elements at the end of list : ");

    // Get the length of the list
    length = size(p_list);
    printf("length of list = %d\n", length);

    // Insert 0 at the beginning of the list
    assert(SUCCESS == insert_start(p_list, 0));
    show(p_list, "After insert 0 at the beginning of the list : ");
    
    // Search for element 12345 in the list
    if(search_data(p_list, 12345))
        puts("List contains 12345");
    else    
        puts("List does not contain 12345");
    
    // Get the length of the list
    length = size(p_list);
    printf("length of list = %d\n", length);

    // Insert 20 random elements at the beginning of the list
    for(int i = 0; i < 20; ++i)
        assert(SUCCESS == insert_start(p_list, rand()/10000));
    show(p_list, "After insert 20 elements at the beginning of the list : ");

    // Get the length of the list
    length = size(p_list);
    printf("length of list = %d\n", length);

    // Insert 12345 after 0
    assert(SUCCESS == insert_after(p_list, 0, 12345));
    show(p_list, "After inserting 12345 after 0 : ");

    // Insert -12345 before 0
    assert(SUCCESS == insert_before(p_list, 0, -12345));
    show(p_list, "After inserting -12345 before 0 : ");

    // Get the starting element of the list
    assert(SUCCESS == get_start(p_list, &data));
    printf("Starting element of list is : %d\n", data);

    // Get the ending element of the list
    assert(SUCCESS == get_end(p_list, &data));
    printf("End element of the list is : %d\n", data);

    // Remove the starting element of the list
    assert(SUCCESS == remove_start(p_list));
    show(p_list, "After removing starting element : ");    

    // Remove the ending element of the list
    assert(SUCCESS == remove_end(p_list));
    show(p_list, "After removing ending element : ");

    // Remove element 0 from the list
    assert(SUCCESS == remove_data(p_list, 0));
    show(p_list, "After removing 0 : ");

    // Pop the starting element of the list
    assert(SUCCESS == pop_start(p_list, &data));
    printf("After pop_start() : popped data = %d\n", data);
    show(p_list, "After pop_start() : ");

    // Pop the ending element of the list
    assert(SUCCESS == pop_end(p_list, &data));
    printf("After pop_end() : popped data = %d\n", data);
    show(p_list, "After pop_end() : ");

    // Check if the list is empty
    if(is_list_empty(p_list))
        puts("List is empty");
    else    
        puts("List is not empty");

    // Get the length of the list
    length = size(p_list);
    printf("length of list = %d\n", length);

    // Sort the list
    sort(p_list);
    show(p_list, "After sorting the list : ");

    // Search for elements in the sorted list
    if(search_data(p_list, 12345))
        puts("List contains 12345");
    else    
        puts("List does not contain 12345");

    if(search_data(p_list, -12345))
        puts("List contains -12345");
    else    
        puts("List does not contain -12345");

    if(search_data(p_list, 0))
        puts("List contains 0");
    else    
        puts("List does not contain 0");

    // Destroy the list and free memory
    destroy_list(&p_list);
    
    // End of the program
    puts("PROGRAM END");
    return (EXIT_SUCCESS);
}
