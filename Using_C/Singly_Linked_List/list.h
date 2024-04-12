/**
 * @file list.h
 * @author Akash_Thorat
 * @brief Header file defining a linked list data structure and associated functions.
 * @version 0.1
 * @date 2024-04-12
 *
 * This header file contains the declarations for a linked list data structure and
 * various functions that can be used to manipulate and operate on the linked list.
 * It provides typedefs for clarity and abstraction, as well as function prototypes
 * for creating a new list, inserting elements, removing elements, searching for
 * elements, sorting the list, and more.
 * 
 * Additionally, the header file defines helper routines used internally by the
 * interface functions and includes necessary typedefs and structure definitions.
 * 
 * This header file serves as the interface for using the linked list data structure
 * and is intended to be included in source files where linked list functionality
 * is required. It should be used in conjunction with the corresponding source file
 * (list.c) for full functionality.
 */


#ifndef _LIST_H
#define _LIST_H

// Define the structure of a node in the linked list
struct node {
    int data;            // Data stored in the node
    struct node* next;   // Pointer to the next node in the list
};

// Define typedefs for clarity and abstraction
typedef enum status {SUCCESS = 1, LIST_EMPTY, LIST_DATA_NOT_FOUND} status_t;  // Status codes for list operations
typedef struct node node_t;  // Typedef for node structure
typedef node_t list_t;        // Typedef for the entire linked list
typedef int data_t;           // Typedef for data stored in nodes
typedef int len_t;            // Typedef for length/size of the list

// Function prototypes for the operations that can be performed on the list
list_t* create_list(void);  // Create a new linked list
status_t insert_start(list_t* p_list, data_t new_data);     // Insert data at the beginning of the list
status_t insert_end(list_t* p_list, data_t new_data);       // Insert data at the end of the list
status_t insert_after(list_t* p_list, data_t e_data, data_t new_data);  // Insert data after a specific value
status_t insert_before(list_t* p_list, data_t e_data, data_t new_data); // Insert data before a specific value
status_t get_start(list_t* p_list, data_t* p_start_data);   // Get the first element of the list
status_t get_end(list_t* p_list, data_t* p_end_data);       // Get the last element of the list
status_t pop_start(list_t* p_list, data_t* p_start_data);   // Remove and retrieve the first element of the list
status_t pop_end(list_t* p_list, data_t* p_end_data);       // Remove and retrieve the last element of the list
status_t remove_start(list_t* p_list);                      // Remove the first element of the list
status_t remove_end(list_t* p_list);                        // Remove the last element of the list
status_t remove_data(list_t* p_list, data_t r_data);         // Remove a specific value from the list
int search_data(list_t* p_list, data_t f_data);             // Search for a specific value in the list
void sort(list_t* p_list);                                  // Sort the list
int is_list_empty(list_t* p_list);                          // Check if the list is empty
len_t size(list_t* p_list);                                 // Get the size/length of the list
void show(list_t* p_list, const char* msg);                  // Display the contents of the list
status_t destroy_list(list_t** pp_list);                    // Destroy the list and free memory


// Helper routines used internally by the interface functions
static void generic_insert(node_t* beg, node_t* mid, node_t* end);  // Generic insert function
static void generic_delete(list_t* p_list, node_t* p_delete_node);  // Generic delete function
static node_t* search_node(list_t* p_list, data_t s_data);           // Search for a node containing specific data
static node_t* get_new_node(data_t new_data);                        // Create a new node with given data
static node_t* get_end_node(list_t* p_list);                        // Get the last node in the list
static void merge_sort(list_t* p_list);                             // Merge sort algorithm for the list
static void merge(list_t* l1, list_t* l2, list_t* p_list);          // Merge two sorted lists
void* xcalloc(int nr_of_elemet, len_t size_per_element);             // Helper function to allocate memory

#endif /*_LIST_H*/
