#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define MAX 300



int main(void)

{

  char user_input_buffer[MAX];
  List *history = init_history();


  printf("Enter a String. Enter '0' to exit\n> ");
  fgets(user_input_buffer, MAX, stdin);



  if (user_input_buffer[0] == '0') {
    printf("Terminating Program...\n");
    return 0;

  }



  printf("\nInput: %s\n\n", user_input_buffer);



  /* test space_char and non_space_char on the first character */

  printf("space_char on first char '%c': %d\n", user_input_buffer[0],
	 space_char(user_input_buffer[0]));

  printf("non_space_char on first char '%c': %d\n", user_input_buffer[0],
	 non_space_char(user_input_buffer[0]));



  printf("Number of words: %d\n", count_tokens(user_input_buffer));

  printf("Start of Word: %s\n", token_start(user_input_buffer));

  printf("Token terminator: %s\n", token_terminator(token_start(user_input_buffer)));

  printf("First token via copy_str: %s\n",
	 copy_str(token_start(user_input_buffer),
		  token_terminator(token_start(user_input_buffer)) - token_start(user_input_buffer)));



  printf("\nAll tokens:\n");
  char **tokens = tokenize(user_input_buffer);
  print_tokens(tokens);

  /* save tokens into history */
  for (int i = 0; tokens[i] != NULL; i++) {
    add_history(history, tokens[i]);
  }
  /* show history */

  printf("\nHistory:\n");
  print_history(history);

  /* test get_history */

  printf("\nTesting get_history:\n");
  printf("ID 1 -> %s\n", get_history(history, 1));

  /* clean up */

  free_tokens(tokens);

  free_history(history);
  return 0;

}
