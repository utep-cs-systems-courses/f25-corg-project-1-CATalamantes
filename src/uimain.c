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
  int counter; //counter for while loop to test get history
  for (counter; tokens[counter] != NULL; counter++) {
    add_history(history, tokens[counter]);
  }
  /* show history */

  printf("\nHistory:\n");
  print_history(history);

  /* test get_history */
  char input[MAX];
  int number;

  while (1) {

    printf("\nTesting get_history, USE !<NUMBER> format (1-%d), use 'q' to quite.\n", counter);
    if (!fgets(input, sizeof(input), stdin)) break;  // EOF protection

    if (input[0] == 'q') {
      printf("Exiting...\n");
      break;
    }
    // Check for '!<number>' format
    if (input[0] == '!') {

      number = atoi(&input[1]);

      if (number <= counter) {
	printf("ID %d -> %s\n", number, get_history(history, number));
      } else {
	printf("Invalid: number must be less than %d.\n", counter);
      }
    }
    else {
      printf("Invalid input. Try again (use !<number> or 'q').\n");
    }

    

  }
  /* clean up */

  free_tokens(tokens);

  free_history(history);
  return 0;

}
