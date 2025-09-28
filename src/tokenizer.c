#include <stdio.h>

#include <stdlib.h>

#include "tokenizer.h"



int space_char(char c) {

  return (c == ' ' || c == '\t') && c != '\0';

}



int non_space_char(char c) {

  return (c != ' ' && c != '\t' && c != '\0');

}



char *token_start(char *s) {

  while (*s && space_char(*s)) s++;

  return *s ? s : 0;

}



char *token_terminator(char *s) {

  while (*s && non_space_char(*s)) s++;

  return s;

}



int count_tokens(char *s) {

  int count = 0;

  char *p = token_start(s);

  while (p){

    count++;

    p = token_terminator(p);
    p=token_start(p);
  }

  return count;

}



char *copy_str(char *inStr, short len) {

  char *copy = (char *)malloc(len + 1);

  if(!copy) return 0;

  memcpy(copy, inStr, len);
  copy[len] = '\0';
  return copy;
  
}



char **tokenize(char *s) {

  int pos = 0;
  len = count_tokens(s);

  char **token = (char **)malloc((len + 1) * sizeof(char *));


  while (pos<len) {
    s = token_start(s);

    char* copyword = copy_str(s, len + 1);

    s = token_terminator(s);
    
      token[pos++] = copyword;
      pos++;
  }


  return token;

}



void print_tokens(char **tokens) {

  int pos = 0;
  while(tokens[pos]) {

    printf("Token %d: %s\n", pos, tokens[pos]);
    pos++
  }

}



void free_tokens(char **tokens) {


  int pos = 0;

  while (tokens[pos])

    {

      // Loop through the string & individually free the chars

      free(tokens[pos]);

      pos++;

    }

  free(tokens);

  

}

