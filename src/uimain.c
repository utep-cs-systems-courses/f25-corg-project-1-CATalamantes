#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"                          // For testing the tokenizer.c file
#include "history.h"

int main()
{
  printf("Enter a String. Enter 'q' to exit\n>");
  char input[420];
  fgets(input, 420, stdin);
  
  if(input[0] == 'q')
    {
      printf("\nBYE! %s/n");
      return 0;
    }
  printf("\nYou Enter: %s/n", input);
  return 0;
}
