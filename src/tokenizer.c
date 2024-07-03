#include <stdio.h>
#include<stdlib.h>
#include "tokenizer.h"

int space_char(char c){
  if(c == ' ' || c == '\t'){ //checks for blank space
    return 1;
  }
  else{
    return 0;
  }
}

int non_space_char(char c){
  if(c != ' ' && c != '\t' && c != '\0'){ //checks for chars that or not a space
    return 1;
  }
  else{
    return 0;
  }
}

char *token_start(char *str){
  char *point = str;
  while(*point == ' '|| *point == '\t'){
    point++;
  }
  if(*point == '\0'){
    return NULL;
  }
  else{
    return point;
  }
}

char *token_terminator(char *token){
  if(token == NULL){
    return NULL;
  }
  while(*token != '\0'){
    token++;
  }
  return token;
}

int count_tokens(char *str){
  int count = 0;
  char *token = token_start(str);
  while(token != NULL){
    count++;
    token = token_terminator(token);
    token = token_start(token);
  }
  return count;
}

char *copy_str(char *inStr, short len){
  if(inStr == NULL || len <= 0){
    return NULL;
  }
  char *newStr = malloc(len + 1);
  if(newStr == NULL){
    return NULL;
  }
  for (int i = 0; i < len; i++){
    newStr[i] = inStr[i];
  }
  newStr[len] ='\0';
  return newStr;
}

char **tokenize(char *str){
  int size = count_tokens(str);
  char **c = (char**)malloc((size + 1) * sizeof(char*));
  for (int i = 0; i < size; i++){
    str = token_start(str);
    char *temp = token_terminator(str);
    char len = temp-str;
    char *t = copy_str(str, len);
    
    c[i] = 0;
    str = token_terminator(str);
  }
  c[size] = 0;
  return c;
}

void print_tokens(char **tokens){
  while (*tokens != 0){
    char *t = *tokens;
    while (*t != 0){
      printf("%c", *t);
      *t++;
    }
    putchar('\n');
    tokens++;
  }
}

void free_tokens(char **tokens){

} 

