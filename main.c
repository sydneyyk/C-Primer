#include <stdio.h>

#include "list.h"

int main() {
  printf("\n");
  printf("Tests for linked list implementation");
  printf("\n");
  printf("---------------------------");
  printf("\n");
  
  list_t *list = list_alloc();
  
  /* Testing the addition functions to add values to the list.
   * Adding these values to different positons in the list.
   * The list would look like:
   * 0
   * 1 -> 0
   * 2 -> 1 -> 0
   * 3 -> 2 -> 1 -> 0
   * 4 -> 3 -> 2 -> 1 -> 0
   * 4 -> 3 -> 2 -> 1 -> 0 -> 9 
   * 4 -> 3 -> 2 -> 1 -> 0 -> 9 -> 7
   * 4 -> 3 -> 2 -> 1 -> 0 -> 9 -> 7 -> 8
   * 4 -> 3 -> 2 -> 1 -> 0 -> 9 -> 7 -> 8 -> 6
   * 4 -> 3 -> 2 -> 1 -> 0 -> 9 -> 7 -> 8 -> 6 -> 5
   * */
  list_add_to_front(list, 0); 
  list_add_to_front(list, 1);
  list_add_to_front(list, 2);
  list_add_to_front(list, 3);
  list_add_to_front(list, 4);
  list_add_to_back(list, 9);
  list_add_to_back(list, 7);
  list_add_to_back(list, 8);
  list_add_to_back(list, 6);
  list_add_to_back(list, 5);
  
  /* Testing printing, index, and search functions.
   */
  printf("The element at index[2] is: %d\n", list_get_elem_at(list, 2)); //Should be 2.
  printf("The element at index[100] is: %d\n", list_get_elem_at(list, 100)); //Alerts the user that this index is out of bounds.
  printf("The index of element '4' is: [%d]\n", list_get_index_of(list, 4)); //Prints 0.
  printf("The index of element '9' is: [%d]\n", list_get_index_of(list, 9)); //Prints 5.

  printf("\n");
  
  list_print(list);
  printf("\n");
  
  printf("List length: %d\n", list_length(list)); //10 values in list.
  printf("Is 7 in the list? (0: true, 1: false): %d\n", list_is_in(list, 7)); //Prints 0 because 7 is in the list.       
  printf("Is 69 in the list? (0: true, 1: false): %d\n", list_is_in(list, 5)); //Prints 1 because 69 is not in the list.
  
  list_t *empty_list = list_alloc();
  printf("The empty list is: \n");
  list_print(empty_list);
  printf("The spot above should be empty above if all went correct. \n");
  
  list_remove_from_back(empty_list); //Can't remove from empty list.
  list_remove_from_front(empty_list); //Can't remove from empty list.
  list_remove_at_index(empty_list, 0); //Can't remove from empty list.
                 
  printf("The element at index[1] is: %d\n", list_get_elem_at(empty_list, 1)); //Out of bounds alert for empty list.         
  printf("\n");
  
  list_free(list); //Clears up the list. 
  list_free(empty_list); //Clears up the empty list.
  
  printf("Output: %p \n", list);
  printf("Output: %p \n", empty_list);
  printf("\n");
  printf("Test to see if this hw worked!!!!\n");
  return 0;
}