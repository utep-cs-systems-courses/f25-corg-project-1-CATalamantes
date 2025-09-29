#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"


// check space
int space_char(char c) {
  return (c == ' ' || c == '\t') && c != '\0';
}


// check non space
int non_space_char(char c) {
  return (c != ' ' && c != '\t' && c != '\0');
}


// checks start onwards
char *token_start(char *s) {

  if (!s) return 0;
  while (*s && space_char(*s)) s++;
  return *s ? s : 0;

}


// check after start
char *token_terminator(char *s) {
  while (*s && non_space_char(*s)) s++;
  return s; /* first space or '\0' after token */
}


// counts every token
int count_tokens(char *s) {

  int count = 0;
  char *p = token_start(s);

  while (p) {
    count++;
    p = token_terminator(p);
    p = token_start(p);
  }

  return count;

}


// copys duh
char *copy_str(char *inStr, short len) {

  char *copy = (char *)malloc((int)len + 1);
  
  if (!copy) return 0;

  /* manual copy (no string.h) */
  for (int i = 0; i < len; i++) copy[i] = inStr[i];
  
  copy[len] = '\0';

  return copy;

}


// main logic
char **tokenize(char *s) {

  int ct = count_tokens(s);
  char **tokens = (char **)malloc((ct + 1) * sizeof(char *)); // store all token

  if (!tokens)return 0;

  int pos = 0;
  char *start = token_start(s);


  while (start) {
    char *end = token_terminator(start);   // find end of token
    short len = (short)(end - start); //find exact len
    tokens[pos++] = copy_str(start, len); //copy
    start = token_start(end); //move to next

  }



  tokens[pos] = 0; // null terminate

  return tokens;

}


// system.out.print
void print_tokens(char **tokens) {

  int pos = 0;
  while (tokens && tokens[pos]) {
    printf("Token %d: %s\n", pos, tokens[pos]);
    pos++;

  }

}


//clears
void free_tokens(char **tokens) {

  if (!tokens) return;

  int pos = 0;

  while (tokens[pos]) {
    free(tokens[pos]);
    pos++;
  }

  free(tokens);

}
