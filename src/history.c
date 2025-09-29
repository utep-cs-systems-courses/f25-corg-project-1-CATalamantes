#include <stdio.h>
#include <stdlib.h>
#include "history.h"



// creates the linked list

List* init_history()
{
  List *newList = (List*)malloc(sizeof(List));   

  if (!newList) return NULL;

  newList->root = NULL;                          

  return newList;
}

//list = the linked list and str = the string we storing
void add_history(List* list, char* str)
{
  Item* addItem=(Item*)malloc(sizeof(Item));

  addItem->str=str;
  addItem->next = NULL;
  
  if(list->root==NULL)
    {
      addItem->id=1;
      list->root=addItem;
      return;
    }

  Item* cur = list->root;

  while (cur->next != NULL)
   {
    cur = cur->next;
   }

  addItem->id = cur->id + 1; /* next id */
  cur->next   = addItem;
}

//gets the stringed that is stored
//list = linked list and id = the id of the item to find

char* get_history(List* list, int id)

{
  Item* cur = list->root;
  
  while (cur != NULL) {

    if (cur->id == id) return cur->str;

    cur = cur->next;
  }
  return 0;
}

// prints list
void print_history(List* list)

{
  Item* cur = list->root;       

  while (cur != NULL) {

    printf("History ID:%d, Name:%s\n", cur->id, cur->str);
    cur = cur->next;
  }
}

// free
void free_history(List* list)

{
  Item* cur = list->root;

  while (cur != NULL) {

    Item* next = cur->next;
    free(cur);
    cur = next;
  }
  free(list);
}
