/**
 * @file list.c
 * @author Akash_Thorat
 * @brief Implementation of a linked list data structure and associated functions.
 * @version 0.1
 * @date 2024-04-12
 *
 * This file contains the implementation of a linked list data structure along with
 * various functions for manipulating and operating on the linked list. It provides
 * functions for creating a new list, inserting elements at the beginning and end,
 * removing elements, searching for elements, adding two list, concating one list to another,
 * revering the list, sorting the list, and more.
 * 
 * The implementation uses a dummy node approach for better management of the list
 * and employs helper routines for common operations such as inserting, deleting, and
 * searching for nodes. Additionally, the file implements the merge sort algorithm
 * for sorting the list efficiently.
 * 
 * This file serves as the backend implementation for the linked list data structure
 * and is intended to be used in conjunction with the corresponding header file (list.h).
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Function to create a new list with a dummy node
list_t* create_list(void)
{
    list_t* p_list = NULL;
    
    p_list = get_new_node(0);
    p_list->next = p_list;

    return (p_list); // Initialize with dummy node

}

// Insert a new node with data at the beginning of the list
status_t insert_start(list_t* p_list, data_t new_data)
{
    generic_insert(p_list, get_new_node(new_data), p_list->next);
    return (SUCCESS);
}

// Insert a new node with data at the end of the list
status_t insert_end(list_t* p_list, data_t new_data)
{
    generic_insert(get_end_node(p_list), get_new_node(new_data), p_list);
    return (SUCCESS);
}

// Insert a new node with new_data after the first occurrence of e_data in the list
status_t insert_after(list_t* p_list, data_t e_data, data_t new_data)
{
    node_t* e_node = NULL;
    e_node = search_node(p_list, e_data);
    if (e_node == NULL)
        return (LIST_DATA_NOT_FOUND);
    generic_insert(e_node, get_new_node(new_data), e_node->next);
    return (SUCCESS);
}

// Insert a new node with new_data before the first occurrence of e_data in the list
status_t insert_before(list_t* p_list, data_t e_data, data_t new_data)
{
    node_t* p_run = NULL;
    for (p_run = p_list; p_run->next != p_list; p_run = p_run->next)
    {
        if (p_run->next->data == e_data)
            break;
    }
    if (p_run->next == p_list)
        return (LIST_DATA_NOT_FOUND);
    generic_insert(p_run, get_new_node(new_data), p_run->next);
    return (SUCCESS);
}

// Get the data from the first node in the list
status_t get_start(list_t* p_list, data_t* p_start_data)
{
    if (is_list_empty(p_list))
        return (LIST_EMPTY);
    *p_start_data = p_list->next->data;
    return (SUCCESS);
}

// Get the data from the last node in the list
status_t get_end(list_t* p_list, data_t* p_end_data)
{
    node_t* p_end_node = NULL;
    if (is_list_empty(p_list))
        return (LIST_EMPTY);
    p_end_node = get_end_node(p_list);
    *p_end_data = p_end_node->data;
    return (SUCCESS);
}

// Remove and return the data from the first node in the list
status_t pop_start(list_t* p_list, data_t* p_start_data)
{
    if (is_list_empty(p_list))
        return (LIST_EMPTY);
    *p_start_data = p_list->next->data;
    generic_delete(p_list, p_list->next);
    return (SUCCESS);
}

// Remove and return the data from the last node in the list
status_t pop_end(list_t* p_list, data_t* p_end_data)
{
    node_t* p_end_node = NULL;
    if (is_list_empty(p_list))
        return (LIST_EMPTY);
    p_end_node = get_end_node(p_list);
    *p_end_data = p_end_node->data;
    generic_delete(p_list, p_end_node);
    return (SUCCESS);
}

// Remove the first node in the list
status_t remove_start(list_t* p_list)
{
    if (is_list_empty(p_list))
        return (LIST_EMPTY);
    generic_delete(p_list, p_list->next);
    return (SUCCESS);
}

// Remove the last node in the list
status_t remove_end(list_t* p_list)
{
    node_t* p_end_node = NULL;
    if (is_list_empty(p_list))
        return (LIST_EMPTY);
    p_end_node = get_end_node(p_list);
    generic_delete(p_list, p_end_node);
    return (SUCCESS);
}

// Remove the first occurrence of a node with data equal to r_data from the list
status_t remove_data(list_t* p_list, data_t r_data)
{
    node_t* p_remove_node = NULL;
    if (is_list_empty(p_list))
        return (LIST_EMPTY);
    p_remove_node = search_node(p_list, r_data);
    if (p_remove_node == NULL)
        return (LIST_DATA_NOT_FOUND);
    generic_delete(p_list, p_remove_node);
    return (SUCCESS);
}

// Search for a node containing data equal to f_data in the list
int search_data(list_t* p_list, data_t f_data)
{
    node_t* p_search_node = NULL;
    p_search_node = search_node(p_list, f_data);
    return (p_search_node != NULL);
}

// Add given two list in new list and retuen new list
list_t* add_lists(list_t* p_list_1, list_t* p_list_2)
{
    list_t* p_new_list = NULL;
    node_t* p_run = NULL;

    p_new_list = create_list();
    
    for(p_run = p_list_1->next; p_run != p_list_1; p_run = p_run->next)
        insert_end(p_new_list, p_run->data);

    for(p_run = p_list_2->next; p_run != p_list_2; p_run = p_run->next)
        insert_end(p_new_list, p_run->data);
    
    return (p_new_list);

}

// Concatenates the second list to the end of the first list     
void concat_lists(list_t* p_list_1, list_t* p_list_2)
{
    node_t* p_run = NULL;

    p_run = p_list_1;
    while( p_run->next != p_list_1)
        p_run = p_run->next;

    p_run->next = p_list_2->next;
    while( p_run->next != p_list_2)
        p_run = p_run->next;
    p_run->next = p_list_1;
    p_list_2->next = p_list_2;
}

// Return new list by merging two list
list_t* get_merged_list(list_t* p_list_1, list_t* p_list_2)
{
    list_t* p_list = NULL;

    p_list = add_lists(p_list_1, p_list_2);
    sort(p_list);

    return (p_list);
}

// Return Reversed List(Reversed by value)
list_t* get_reversed_list(list_t* p_list)
{
    list_t* p_new_list = NULL;
    node_t* p_run1 = NULL;
    node_t* p_run2 = NULL;
    data_t temp = 0;
    len_t length = 0;

    p_new_list = create_list();
    length = size(p_list);

    if(is_list_empty(p_list))
        return p_new_list;
    
    p_run1 = p_list;
    for(len_t i = 0; i < length/2; ++i)
    {
        p_run1 = p_run1->next;
        p_run2 = p_list;
        for(len_t j = length - i; j > 0; --j)
            p_run2 = p_run2->next;
        
        temp = p_run1->data;
        p_run1->data = p_run2->data;
        p_run2->data = temp;
    }

    return (p_new_list);
}

// reverce the list(Reversed by node)           
void reverse_list(list_t* p_list)
{
    node_t* p_run = NULL;
    node_t* p_run_next = NULL;
    node_t* p_last_node = NULL;
    len_t length = 0;

    length = size(p_list);
    if(length <= 1)
        return;

    p_last_node = get_end_node(p_list);
    p_run = p_list; 

    while(p_run->next != p_last_node)
    {
        p_run_next = p_run->next;
        p_run->next = p_run_next->next;
        p_run_next->next = NULL;
        generic_insert(p_last_node, p_run_next, p_last_node->next);
    }    
}                     

// Sort the list using merge sort algorithm
void sort(list_t* p_list)
{
    merge_sort(p_list);
}

// Check if the list is empty
int is_list_empty(list_t* p_list)
{
    return (p_list->next == p_list);
}

// Get the size/length of the list
len_t size(list_t* p_list)
{
    node_t* p_run = NULL;
    len_t length = 0;
    for (p_run = p_list->next; p_run != p_list; p_run = p_run->next)
        length = length + 1;
    return length;
}

// Display the contents of the list
void show(list_t* p_list, const char* msg)
{
    node_t* p_run = NULL;
    if (msg)
        puts(msg);
    printf("[START]->");
    for (p_run = p_list->next; p_run != p_list; p_run = p_run->next)
        printf("[%d]->", p_run->data);
    puts("[END]");
}

// Destroy the list and free memory
status_t destroy_list(list_t** pp_list)
{
    node_t* p_run = NULL;
    node_t* p_run_next = NULL;
    for (p_run = (*pp_list)->next; p_run != *pp_list; p_run = p_run_next)
    {
        p_run_next = p_run->next;
        free(p_run);
    }
    free(*pp_list);
    *pp_list = NULL;
}

//----------------HELPER RUTINES-----------------

// Generic insert function to insert a new node between beg and end
static void generic_insert(node_t* beg, node_t* mid, node_t* end)
{
    beg->next = mid;
    mid->next = end;
}

// Generic delete function to delete a node from the list
static void generic_delete(list_t* p_list, node_t* p_delete_node)
{
    node_t* p_delete_prev = NULL;
    for (p_delete_prev = p_list; p_delete_prev != p_list; p_delete_prev = p_delete_prev->next)
        if (p_delete_prev->next == p_delete_node)
            break;
    if (p_delete_prev == p_list)
        return;
    p_delete_prev->next = p_delete_node->next;
    free(p_delete_node);
}

// Search for a node containing data equal to s_data in the list
static node_t* search_node(list_t* p_list, data_t s_data)
{
    node_t* p_search_node = NULL;
    for (p_search_node = p_list->next; p_search_node != p_list; p_search_node = p_search_node->next)
        if (p_search_node->data == s_data)
            break;
    if(p_search_node != p_list)
        return (p_search_node);
    return (NULL);
}

// Create a new node with data equal to new_data
static node_t* get_new_node(data_t new_data)
{
    node_t* p_new_node = NULL;
    p_new_node = (node_t*) xcalloc(1, sizeof(node_t));
    p_new_node->data = new_data;
    p_new_node->next = NULL;
    return (p_new_node);
}

// Get the last node in the list
static node_t* get_end_node(list_t* p_list)
{
    node_t* p_end_node = NULL;
    p_end_node = p_list;
    while (p_end_node->next != p_list)
        p_end_node = p_end_node->next;
    return (p_end_node);
}

// Allocate memory for an array with specified number of elements and size per element
void* xcalloc(int nr_of_element, len_t size_per_element)
{
    void* p = NULL;
    p = calloc(nr_of_element, size_per_element);
    if (p == NULL)
    {
        puts("ERROR while allocating memory ..!");
        exit(EXIT_FAILURE);
    }
    return p;
}

// Merge sort algorithm to sort the list
static void merge_sort(list_t* p_list)
{
    len_t length = 0;
    list_t* l1 = NULL;
    list_t* l2 = NULL;
    node_t* p_run = NULL;

    length = size(p_list);
    
    if (length <= 1)
        return;
    
    l1 = create_list();
    l2 = create_list();

    p_run = p_list->next;
    for (len_t i = 0; i < length / 2; ++i)
    {
        insert_end(l1, p_run->data);
        p_run = p_run->next;
    }

    for (len_t i = length / 2; i < length; ++i)
    {
        insert_end(l2, p_run->data);
        p_run = p_run->next;
    }

    p_list->next = p_list;
    merge_sort(l1);
    merge_sort(l2);
    merge(l1, l2, p_list);
}

// Merge two sorted lists l1 and l2 into the list p_list
static void merge(list_t* l1, list_t* l2, list_t* p_list)
{
    node_t* p_run1 = NULL;
    node_t* p_run2 = NULL;
    p_run1 = l1->next;
    p_run2 = l2->next;

    while (p_run1 != l1 && p_run2 != l2)
    {
        if (p_run1->data < p_run2->data)
        {
            insert_end(p_list, p_run1->data);
            p_run1 = p_run1->next;
        }
        else
        {
            insert_end(p_list, p_run2->data);
            p_run2 = p_run2->next;
        }
    }

    while (p_run1 != l1)
    {
        insert_end(p_list, p_run1->data);
        p_run1 = p_run1->next;
    }

    while (p_run2 != l2)
    {
        insert_end(p_list, p_run2->data);
        p_run2 = p_run2->next;
    }
}
