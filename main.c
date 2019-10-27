#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){
  printf("\n");
  struct node *end = NULL;
  printf("Printing Empty List:  \n");
  print_list(end);
  printf("\n");

  printf("Adding #s 0-9 to list:  \n");
  int i;
  for (i  = 0; i < 10; i++){
    end = insert_front(end, i);
  }
  printf("Printing List:  \n");
  print_list(end);

  printf("Removing 9:  \n");
  end = remove_node(end, 9);
  print_list(end);

  printf("Removing 4:  \n");
  end = remove_node(end, 4);
  print_list(end);

  printf("Removing 0:  \n");
  end = remove_node(end, 0);
  print_list(end);

  printf("Removing -1:  \n");
  end = remove_node(end, -1);
  print_list(end);

  printf("\n");
  printf("Freeing list.  \n");
  end = free_list(end);
  printf("Printing List:  \n");
  print_list(end);
}
