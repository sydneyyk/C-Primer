// list/list.c
// 
// Implementation for linked list.
//
// <Sydney Kadegnon>

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int list_size = 0;
int size = 0;

/* Allocate space for the list_t by casting the 
 * byte size of the list to the pointer variable.
 * We return the initialized list. */
list_t *list_alloc() { 
  list_t *myList = (list_t *) malloc(sizeof(list_t));
  return myList;
}

/* Function to free the list of all values. 
 * We set the first node to the head pointer of the list.
 * Then while the value of the the node is not null (has a value), 
 * we use the free function to clear up the list.
 * */
void list_free(list_t *l) { 
  node_t *current_node = l->head;
  while (current_node != NULL) {
    node_t *node = current_node;
    current_node = current_node->next;
    free(node);
  }
  free(l);
}

/* Printing values in the list.
 * Setting the 'l' as the head node. 
 * While the node is not null (has a value) and there is 
 * a node with a value after it, print the value.
 * */
void list_print(list_t *l) { 
  node_t *current_node = malloc(sizeof(node_t));
  current_node = l->head;
  
  while(current_node != NULL) {
    if (current_node->next !=NULL) {
      printf("%d -> ", current_node->value);
    }
    else {
      printf("%d \n", current_node->value);
    }
    current_node = current_node->next;
  }
  return;
}

/* Printing the length of the list. 
 * Checking to see if the head node is null, 
 * and if so then the list is empty and has zero values. 
 * Return that length.
 * If the nodes are not null (have values) then increment 
 * through the nodes and return the numerical number found.
 * */
int list_length(list_t *l) {
  node_t *current_node = malloc(sizeof(node_t));
  current_node = l->head;
  if (current_node == NULL) {
    return 0;
  }
  int list_length = 0;
  while (current_node != NULL) {
    list_length++;
    current_node = current_node->next;
  }
  return list_length;
}

/* Adds a value to the back of the given list.
 * If the head node has no value (we have an empty list) 
 * then we add that value to the list and make it the current head of the list.
 * If the list already has values in it, we start from the head 
 * and iterate through the list to keep checking to see if we've reached the end of the list.
 * We add the value to the back of the list when we reach the end.
 * */
void list_add_to_back(list_t *l, elem value) {
  node_t *current_node = malloc(sizeof(node_t));
  current_node -> value = value;
  current_node -> next = NULL;
  if(l -> head == NULL){
    l -> head = current_node;
  }
  else {
    node_t *ptr = l -> head;
    while(ptr -> next != NULL ) {
      ptr = ptr-> next;
    }
    ptr -> next = current_node;
  }
    size++;
}

/* Adds a value to the front of the given list.
 * If the head node has no value (we have an empty list) 
 * then we add that value to the list and make it the current head of the list.
 * If the list already has values in it, we start from the head 
 * and make the value a new node the head node.
 * */
void list_add_to_front(list_t *l, elem value) {
 node_t *new_node = malloc(sizeof(node_t));
  new_node->value = value;
  node_t *current_node = malloc(sizeof(node_t));
  if (l->head == NULL) {
    l->head = new_node;
    list_size++;
    return;
  }
  new_node->next = l->head;
  l->head = new_node;
  list_size++;
  return;
}

/* Adds a value to the list at a specific index.
 * If the head node has no value (we have an empty list) 
 * then we add that value to the list and make it the current head of the list.
 * If the index provided is less than zero (an impossible index) then we alert the user.
 * If the index provided is zero, then we can call our 'add to front' function to add
 * the value at the front of the list. 
 * If the index provided is greater than the list size (length of list), then we alert the user.
 * If the list already has values in it, we start from the head and iterate through the list 
 * until we reach the specifred index position. We use minus one to account for zero based indexing.
 * We place the value at that index.
 * */
void list_add_at_index(list_t *l, elem value, int index) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->value = value;
  if (l->head == NULL){
    l->head = new_node;
    return;
  }
  if (index < 0){
    printf("This index value is out of bounds.\n");
    return;
  } 
  if (index == 0){
    list_add_to_front(l, value);
    return;
  }
  if (index >= list_size){
    printf("This index value is out of bounds.\n");
    return;
  }
  int current_index = 0;
  node_t *current_node = malloc(sizeof(node_t));
  current_node = l->head;
  while (current_node != NULL){
    if (current_index == index - 1){
      node_t *original_next = malloc(sizeof(node_t));
      original_next = current_node->next;
      current_node->next = new_node;
      new_node->next = original_next;
      return;
    }
    current_node = current_node->next;
    current_index++;
  }
}


/* Adds a value to the back of the given list.
 * If the head node has no value (we have an empty list) 
 * then we add that value to the list and make it the current head of the list.
 * If the list already has values in it, we start from the head 
 * and iterate through the list to keep checking to see if we've reached the end of the list.
 * We add the value to the back of the list when we reach the end.
 * */
elem list_remove_from_back(list_t *l) {   
  if (l->head == NULL){
    printf("Can't remove from empty list.\n");
    return;
  }
  int current_index = 0;
  node_t *current_node = malloc(sizeof(node_t));
  current_node = l->head;
  while (current_node != NULL){
    if (current_index == list_size - 1){
      node_t *original_next = malloc(sizeof(node_t));
      original_next = current_node->next;
      current_node->next = NULL;
      list_size--;
      return original_next->value;
    }
    current_node = current_node->next;
    current_index++;
  }
}

/* Removes element from the front of the list.
 * If the head node has no value (we have an empty list) then we can not remove anything.
 * We alert the user if this is the case.
 * If the list is not null (has values in it), we start from the head and remove the value there.
 * We make the next node the head node.
 * */
elem list_remove_from_front(list_t *l) {  
  if (l->head == NULL){
    printf("Can't remove from empty list.\n");
    return;
  }
  node_t *original_head = malloc(sizeof(node_t));
  original_head = l->head;
  l->head = l->head->next;
  list_size--;
  return original_head->value;
}

/* Removes element from the front of the list.
 * If the head node has no value (we have an empty list) then we can not remove anything.
 * We alert the user if this is the case.
 * If the list is not null (has values in it), we start from the head and remove the value there.
 * We make the next node the head node.
 * */
elem list_remove_at_index(list_t *l, int index) {
  if (l->head == NULL){
    printf("Can't remove from empty list.\n");
    return;
  }
  if (index < 0){
    printf("This index value is out of bounds.\n");
    return;
  }
  if (index == 0){
    return list_remove_from_front(l);
  } 
  if (index >= list_size){
    printf("This index value is out of bounds.\n");
    return;
  } 
  int current_index = 0;
  node_t *current_node = malloc(sizeof(node_t));
  current_node = l->head;
  while (current_node != NULL){
    if (current_index == index - 1){
      node_t *original_next = malloc(sizeof(node_t));
      original_next = current_node->next;
      current_node->next = current_node->next->next;
      list_size--;
      return original_next->value;
    }
    current_node = current_node->next;
    current_index++;
  }
}

/* Checks to see if the provided element is in the list.
 * If there is no list them or no element in the list then we alert the user.  
 * */
bool list_is_in(list_t *l, elem value) { 
  if (!l) {
    printf("The list does not exist.");
    return false;
  }
  node_t *t = l->head;
  while (t->next) {
    t = t->next;
  }
  return t->value == value;
}

/* Returns the element/value at a specific index position. 
 * If the given value is greater than the size of the list or 
 * less than zero (impossible indices) then we alert the user if this is the case.
 * If the list is not null (has values in it), we start from the head.
 * If the given index is zero then we add that value to the list and make it the new
 * head. If the index is greater than zero, then we use a counter get to the 
 * desired index and return the element.
 * */
elem list_get_elem_at(list_t *l, int index) {
  int size;
  if (index > size || index < 0) {
    printf("Index[%d] range is out of bounds \n", index);
    return;
  }
  node_t *ptr = l -> head;
  int counter = 0;
  int val;
  if (index == 0) {
    val = ptr -> value;
  }
  else {
    while (counter < index) {
      ptr = ptr -> next;
      val = ptr -> value;
      counter++;
    }
    printf("%d is at index[%d]\n", val, index);
  }
  return -1; 
}

/* Returns the index position of a element/value in our list.
 * If the head of the list is null (list is empty), then we alert the user.
 * If the list is not null (has values in it), we start from the head.
 * If the index is greater than zero, then we use a counter to search for the desired value/element.
 * Once we found the element, we return the specific index at which the value is positioned.
 * */
int list_get_index_of(list_t *l, elem value) {
  if (l->head == NULL) {
    printf ("List is empty. Can not search list.\n");
    return -1;
  } 
  int current_index = 0;
  node_t *current_node = malloc(sizeof(node_t));
  current_node = l->head;
  while (current_node != NULL) {
    if (current_node->value == value) {
      return current_index;
    }
    current_node = current_node->next;
    current_index++;
  }
  printf("The element was not found in list.\n");
  return -1;
}