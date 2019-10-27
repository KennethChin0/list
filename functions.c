#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void print_list(struct node *n){
  if (n == NULL){
    printf("Empty list []\n");
  }else{
    printf("[");
    while (n -> next != NULL){
      printf("%d, ", n->i);
      n = n->next;
    }
    printf("%d ", n->i);
    printf("]\n");
  }
}

struct node * insert_front(struct node *n,int x){
  struct node *new = malloc(sizeof(struct node));
  new -> i = x;
  new -> next = n;
  return new;
}


struct node * free_list(struct node *n){
  if (n == NULL){
    free(n);
    return NULL;
  }
  else{
    struct node *new = n -> next;
    printf("Freeing node: %d\n", n->i);
    free(n);
    return free_list(new);
  }

}

struct node * remove_node(struct node *front, int data){
  struct node *current = front;
  struct node *after = front -> next;
  if (front != NULL && front -> i == data){
    current = front -> next;
    free(front);

    return current;
  }
else{
  while(after != NULL){
    if (after -> i == data){
    current -> next = after -> next;
    free(after);
    return front;
  }
  current = after;
  after = after -> next;
  }
  return front;
}
}
