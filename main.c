#include <stdio.h>

#include "list.h"

int main() 
{
  list_t* realHead;
  node_t* item1;
  node_t* item2;
  node_t* item3;
  node_t* item4;
  node_t* item5;
  realHead->head = item1;
  item1->next = item2;
  item2->next = item3;
  item3->next = item4;
  list_length(realHead);
  list_free(realHead);

}