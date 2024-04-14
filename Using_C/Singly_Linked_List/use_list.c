/**
 * @file use_list.c
 * @author Akash_Thorat
 * @brief A program to demonstrate the usage of the linked list implementation.
 * @version 0.1
 * @date 2024-04-12
 *
 * This program demonstrates various operations on a singly linked list, including
 * insertion, deletion, popping, adding, concating, revering, sorting, and searching. It also verifies the functionality
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
    list_t* l1 = NULL;
    list_t* l2 = NULL;
    list_t* l3 = NULL;

    data_t data = 0;
    len_t length = 0;

    // Start of the program
    puts("PROGRAM START");


    //----------------------------- list l1 operations -------------------------
    // Create an empty list l1
    l1 = create_list(); 
    
    // Assertions to verify the initial state of the list l1
    assert(l1 != NULL);
    assert(is_list_empty(l1));
    assert(LIST_EMPTY == get_start(l1, &data));
    assert(LIST_EMPTY == get_end(l1, &data));
    assert(LIST_EMPTY == remove_start(l1));
    assert(LIST_EMPTY == remove_end(l1));
    assert(LIST_EMPTY == pop_start(l1, &data));
    assert(LIST_EMPTY == pop_end(l1, &data));
    assert(0 == size(l1));

    // Insert 20 random elements at the end of the list l1
    for(int i = 0; i < 20; ++i)
        assert(SUCCESS == insert_end(l1, rand()/10000));
    show(l1, "After insert 20 elements at the end of l1 : ");

    // Get the length of the list l1
    length = size(l1);
    printf("length of list l1 = %d\n", length);

    // Insert 0 at the beginning of the list l1
    assert(SUCCESS == insert_start(l1, 0));
    show(l1, "After insert 0 at the beginning of the l1: ");
    
    // Search for element 12345 in the list l1
    if(search_data(l1, 12345))
        puts("l1 contains 12345");
    else    
        puts("l1 does not contain 12345");
    
    // Get the length of the list l1
    length = size(l1);
    printf("length of l1 = %d\n", length);

    // Insert 20 random elements at the beginning of the list l1
    for(int i = 0; i < 20; ++i)
        assert(SUCCESS == insert_start(l1, rand()/10000));
    show(l1, "After insert 20 elements at the beginning of the l1 : ");

    // Get the length of the list l1
    length = size(l1);
    printf("length of l1 = %d\n", length);

    // Insert 12345 after 0 in the list l1
    assert(SUCCESS == insert_after(l1, 0, 12345));
    show(l1, "After inserting 12345 after 0 in l1: ");

    // Insert -12345 before 0 in the list l1
    assert(SUCCESS == insert_before(l1, 0, -12345));
    show(l1, "After inserting -12345 before 0 in l1 : ");

    // Get the starting element of the list l1
    assert(SUCCESS == get_start(l1, &data));
    printf("Starting element of l1 is : %d\n", data);

    // Get the ending element of the list l1
    assert(SUCCESS == get_end(l1, &data));
    printf("End element of the l1 is : %d\n", data);

    // Remove the starting element of the list l1
    assert(SUCCESS == remove_start(l1));
    show(l1, "After removing starting element from l1 : ");    

    // Remove the ending element of the list l1
    assert(SUCCESS == remove_end(l1));
    show(l1, "After removing ending element form l1 : ");

    // Remove element 0 from the list l1
    assert(SUCCESS == remove_data(l1, 0));
    show(l1, "After removing 0 from l1: ");

    // Pop the starting element of the list l1
    assert(SUCCESS == pop_start(l1, &data));
    printf("After pop_start() in l1 : popped data = %d\n", data);
    show(l1, "After pop_start() : l1 ");

    // Pop the ending element of the list l1
    assert(SUCCESS == pop_end(l1, &data));
    printf("After pop_end() in l1 : popped data = %d\n", data);
    show(l1, "After pop_end() : l1 ");

    // Check if the list l1 is empty
    if(is_list_empty(l1))
        puts("l1 is empty");
    else    
        puts("l1 is not empty");

    // Get the length of the list l1
    length = size(l1);
    printf("length of l1 = %d\n", length);

    // Search for elements in the sorted list l1
    if(search_data(l1, 12345))
        puts("l1 contains 12345");
    else    
        puts("l1 does not contain 12345");

    if(search_data(l1, -12345))
        puts("l1 contains -12345");
    else    
        puts("l1 does not contain -12345");

    if(search_data(l1, 0))
        puts("l1 contains 0");
    else    
        puts("l1 does not contain 0");


    //----------------------------- list l2 operations -------------------------
    // Create an empty list l2
    l2 = create_list(); 
    
    // Assertions to verify the initial state of the list l2
    assert(l2 != NULL);
    assert(is_list_empty(l2));
    assert(LIST_EMPTY == get_start(l2, &data));
    assert(LIST_EMPTY == get_end(l2, &data));
    assert(LIST_EMPTY == remove_start(l2));
    assert(LIST_EMPTY == remove_end(l2));
    assert(LIST_EMPTY == pop_start(l2, &data));
    assert(LIST_EMPTY == pop_end(l2, &data));
    assert(0 == size(l2));

    // Insert 20 random elements at the end of the list l2
    for(int i = 0; i < 20; ++i)
        assert(SUCCESS == insert_end(l2, rand()/10000));
    show(l2, "After insert 20 elements at the end of l2 : ");

    // Get the length of the list l2
    length = size(l2);
    printf("length of list l2 = %d\n", length);

    // Insert 0 at the beginning of the list l2
    assert(SUCCESS == insert_start(l2, 0));
    show(l2, "After insert 0 at the beginning of the l2: ");
    
    // Search for element 12345 in the list l2
    if(search_data(l2, 12345))
        puts("l2 contains 12345");
    else    
        puts("l2 does not contain 12345");
    
    // Get the length of the list l2
    length = size(l2);
    printf("length of l2 = %d\n", length);

    // Insert 20 random elements at the beginning of the list l2
    for(int i = 0; i < 20; ++i)
        assert(SUCCESS == insert_start(l2, rand()/10000));
    show(l2, "After insert 20 elements at the beginning of the l2 : ");

    // Get the length of the list l2
    length = size(l2);
    printf("length of l2 = %d\n", length);

    // Insert 12345 after 0 in the list l2
    assert(SUCCESS == insert_after(l2, 0, 12345));
    show(l2, "After inserting 12345 after 0 in l2: ");

    // Insert -12345 before 0 in the list l2
    assert(SUCCESS == insert_before(l2, 0, -12345));
    show(l2, "After inserting -12345 before 0 in l2 : ");

    // Get the starting element of the list l2
    assert(SUCCESS == get_start(l2, &data));
    printf("Starting element of l2 is : %d\n", data);

    // Get the ending element of the list l2
    assert(SUCCESS == get_end(l2, &data));
    printf("End element of the l2 is : %d\n", data);

    // Remove the starting element of the list l2
    assert(SUCCESS == remove_start(l2));
    show(l2, "After removing starting element from l2 : ");    

    // Remove the ending element of the list l2
    assert(SUCCESS == remove_end(l2));
    show(l2, "After removing ending element form l2 : ");

    // Remove element 0 from the list l2
    assert(SUCCESS == remove_data(l2, 0));
    show(l2, "After removing 0 from l2: ");

    // Pop the starting element of the list l2
    assert(SUCCESS == pop_start(l2, &data));
    printf("After pop_start() in l2 : popped data = %d\n", data);
    show(l2, "After pop_start() : l2 ");

    // Pop the ending element of the list l2
    assert(SUCCESS == pop_end(l2, &data));
    printf("After pop_end() in l2 : popped data = %d\n", data);
    show(l2, "After pop_end() : l2 ");

    // Check if the list l2 is empty
    if(is_list_empty(l2))
        puts("l2 is empty");
    else    
        puts("l2 is not empty");

    // Get the length of the list l2
    length = size(l2);
    printf("length of l2 = %d\n", length);

    // Search for elements in the sorted list l2
    if(search_data(l2, 12345))
        puts("l2 contains 12345");
    else    
        puts("l2 does not contain 12345");

    if(search_data(l2, -12345))
        puts("l2 contains -12345");
    else    
        puts("l2 does not contain -12345");

    if(search_data(l2, 0))
        puts("l2 contains 0");
    else    
        puts("l2 does not contain 0");

    //------------------------------ Combine operations for l1, l2-----------------

    // Add elements of l1 and l2 and store in l3
    l3 = add_lists(l1, l2);
    show(l3, "After adding l1, l2 : l3 is ");
    
    // Getting mearge list of l1 and l2
    l3 = get_merged_list(l1, l2);
    show(l3, "After mearing l1, l2 in l3 : ");
    
    // Concatenate lists l1 and l2
    concat_lists(l1, l2);
    show(l1, "After Concatenating l1 and l2 : l1 is ");
    
    // Sort the list l1
    sort(l1);
    show(l1, "After sorting the l1 : ");
    
    // Sort the list l3
    sort(l3);
    show(l3, "After sorting the l3 : ");

    // Destroy list l3 and free memory
    destroy_list(&l3);
    
    // Get the reversed list l1 and store it in l3
    l3 = get_reversed_list(l1);
    show(l1, "After reversing l1 and storing in l3 : l3 is");

    // Reverse list l1
    reverse_list(l1);
    show(l1, "After reversing l1 : ");

    // Destroy the lists l1, l2, and l3 and free memory
    destroy_list(&l1);
    destroy_list(&l2);
    destroy_list(&l3);
    
    // End of the program
    puts("PROGRAM END");
    return (EXIT_SUCCESS);
}
