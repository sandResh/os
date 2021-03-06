
#include <stdlib.h>


#include <stdio.h>

#include "list.h"

list_t *list_alloc() 
{ 
  list_t *tempNode = malloc(sizeof(node_t));
  
  return tempNode; 
}
void listFree(node_t *l)
{
  {
  if(!l)
  {
    return;
  }
  if(l->next)
  {
    listFree(l->next);
  }
  free(l);
}
}
void list_free(list_t *l) 
{
  node_t* temp = l->head;
  listFree(temp);
}

void list_print(list_t *l) 
{
  node_t* temp = l->head;
  while(temp)
  {
    int num = temp->value;
    printf("Node is: %d \n", num);;
    temp = temp->next;
  }
}
int list_length(list_t *l) 
{ 
  node_t *temp = l->head;
  int lenL;
  while(temp)
  {
    lenL++;
    temp = temp->next;
  }
  return lenL;
}

void list_add_to_back(list_t *l, elem value) 
{
  node_t *temp = l->head;
  while(temp->next != NULL)
  {
    temp = temp->next;
  }
  
  temp->next = malloc(sizeof(node_t));
  temp->next->value = value;
  
  
}
void list_add_to_front(list_t *l, elem value) 
{
  node_t* head1 = malloc(sizeof(node_t)); 
  head1->value = value;
  head1->next = l->head;
  l->head = head1;
  printf("%d \n", l->head->value);

}
void list_add_at_index(list_t *l, elem value, int index) 
{

  if(index == 0)
  {
    list_add_to_front(l, value);
  }
  else
  {
    node_t *temp = l->head;
    int lenIndex = 1;
    while(!(lenIndex == index) )
    {
      temp = temp->next;
      lenIndex++;
    }
    node_t *temp2 = malloc(sizeof(node_t));
    temp2->next = temp->next;
    temp->next = temp2;
    temp2->value = value;
    

  }
}

elem list_remove_from_back(list_t *l) 
{
  node_t *temp = l->head;
  while(temp->next->next != NULL)
  {
    temp = temp->next;
  }
  int temp1 = temp->next->value;
  free(temp->next);
  temp->next =NULL;
  return temp1;
}
elem list_remove_from_front(list_t *l) 
{
  list_t *temp = list_alloc();
  temp = l;
  elem result = l->head->value;
  l->head = l->head->next;
  free(temp);
  return result;
   
}
elem list_remove_at_index(list_t *l, int index) 
{ 
  if (index == 0)
  {
    return list_remove_from_front(l);
  }
  else
  {
    node_t *temp = l->head;
    int lenL = 1;
    while (lenL != index)
    {
      temp = temp->next;
      lenL++;
    }
    int temp1 = temp->next->value;
    node_t *temp2;
    temp2 = temp->next;
    if(temp->next->next)
    {
      
      temp->next = temp->next->next;
    }
    free(temp2);
    return temp1;
  }
  
  
  
}

bool list_is_in(list_t *l, elem value) 
{
   node_t *temp = l->head;
   while(temp)
   {
     if (temp->value == value)
     {
       return true;
       printf("TRUE");
     }
     temp = temp->next;
   }
  printf("False");
  return false;
}


elem list_get_elem_at(list_t *l, int index) 
{
  node_t *temp = l->head;
  int lenL = 0;
  while (lenL != index)
  {
    temp = temp->next;
    lenL++;
  }
  return temp->value;
  
}
int list_get_index_of(list_t *l, elem value) 
{
  int lenL = 0;
  node_t *temp = l->head;
  while (temp->value != value)
  {
    temp = temp->next;
    lenL++;
  }
  return lenL;
  
}