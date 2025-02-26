#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c){
    if (c == ' ' || c == '\t'){
      return 1; // there is a whitespace or tab
    }
    else{
      return 0;
    }
 }
 
 int non_space_char(char c){
     if (c != ' ' && c != '\t'){
       return 1; // there is a non-whitespace character
     }
     else{
       return 0;
     }
 }
char *token_start(char *str){
    while (space_char(*str)){
        str++; // 1
    }
    if (*str == '\0') {
        return 0; // Return 0 as the null pointer if no tokens are found
    }
    return str;
}

char *token_terminator(char *token){
    while(non_space_char(*token)){
        token++;
    }
    return token;
}

char *copy_str(char *inStr, short len) {
    char *newStr = (char *)malloc((len + 1) * sizeof(char)); // Allocate memory for the new string
    if (newStr == NULL) {
        return NULL; // Return NULL if memory allocation fails
    }
    for (int i = 0; i < len; i++) {
        newStr[i] = inStr[i]; // Copy each character
    }
    newStr[len] = '\0'; 
    return newStr; // returns the new string for token[index]
}

int count_tokens(char *str){
    int count = 0;
    char *token = token_start(str);
    while (token != 0 && *token != '\0') {
        count++;
        token = token_start(token_terminator(token));
    }
    return count;
}

char **tokenize(char *str) {
    int num = count_tokens(str); 
    char **tokens = malloc((num + 1) * sizeof(char *));
    if (tokens == NULL) {
        return NULL; 
    }
    char *word = str;

    for (int i = 0; i < num; i++) {
        word = token_start(word);
        char *end = token_terminator(word);
        int length = end - word; 
        tokens[i] = copy_str(word, length);
        word = end;
    }
    tokens[num] = NULL; 
    return tokens;
}

void print_tokens(char **tokens) {
    for (int i = 0; tokens[i] != 0; i++) { // prints each token token[index] = word before whitespace
        printf("%d. %s\n", i+1, tokens[i]);
    }
}

void free_tokens(char **tokens) {
    for (int i = 0; tokens[i] != 0; i++) { // deallocates memory for each token
        free(tokens[i]);
    }
    free(tokens);
}