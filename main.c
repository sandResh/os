#include <stdio.h> 
#include <stdlib.h>
#include "list.h"
int main() 
{
  list_t* top = list_alloc();
  node_t* head = malloc(sizeof(node_t));
  // Set value for head.
  
  node_t* second = malloc(sizeof(node_t));
  top->head = head;
  second->value = 6;

  node_t* third = malloc(sizeof(node_t));
  third->value = 8;
  head->next = second;
  second->next = third;
  
  list_add_to_back(top, 12);
  list_add_to_front(top, 2);
  printf("%d \n", top->head->value);

  list_add_at_index(top, 99, 1);
  list_remove_from_back(top);
  list_remove_at_index(top, 2);
  list_is_in(top, 6);
  printf("%d \n", list_is_in(top, 6));  

  list_get_elem_at(top, 0);
  printf("%d \n",list_get_elem_at(top, 1));
  printf("%d \n",list_get_index_of(top, 6));
  list_print(top);


  // node_t* second = NULL;
  // node_t* third = NULL;
  // top->head = head;
  // head->value = 7;
  // head->next = second;
  // second->value = 8;
  // second->next = third;
  // third->value = 9;
  return 0;
}